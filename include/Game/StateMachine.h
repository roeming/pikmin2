#ifndef _GAME_STATEMACHINE_H
#define _GAME_STATEMACHINE_H

#include "types.h"

#define GETCURRSTATE(obj)               (obj)->getCurrentState()
#define RESETCURRSTATE(obj)             (obj)->resetCurrentState()
#define INITSTATE(obj, state, stateArg) (obj)->initState((obj), (state), (stateArg))

namespace Game {
template <typename T>
struct StateMachine;

// if it gets used, it's a derived struct.
struct StateArg {
};

template <typename T>
struct FSMState {
	inline FSMState(int id)
	    : mId(id)
	    , mStateMachine(nullptr)
	{
	}

	virtual void init(T*, StateArg*) { }                          // _08
	virtual void exec(T*) { }                                     // _0C
	virtual void cleanup(T*) { }                                  // _10
	virtual void resume(T*) { }                                   // _14
	virtual void restart(T*) { }                                  // _18
	virtual void transit(T* obj, int stateID, StateArg* stateArg) // _1C
	{
		mStateMachine->transit(obj, stateID, stateArg);
	}

	// _00 VTBL
	int mId;                        // _04
	StateMachine<T>* mStateMachine; // _08
};

template <typename T>
struct StateMachine {
	inline StateMachine()
	    : mCurrentID(-1)
	{
	}

	virtual void init(T*) { }                                   // _08
	virtual void start(T* obj, int stateID, StateArg* stateArg) // _0C
	{
		RESETCURRSTATE(obj);
		transit(obj, stateID, stateArg);
	}
	virtual void exec(T* obj) // _10
	{
		if (GETCURRSTATE(obj)) {
			GETCURRSTATE(obj)->exec(obj);
		}
	}

	// yes this is ordered like this. no i dont like it. yes it's necessary afaik for weak generation in itemBarrel
	// #pragma dont_inline on
	void create(int limit);
	virtual void transit(T* obj, int stateID, StateArg* stateArg); // _14
	void registerState(FSMState<T>* state);
	// #pragma dont_inline reset

	int getCurrID(T*);

	// _00	= VTBL
	FSMState<T>** mStates; // _04
	int mCount;            // _08, count of registered states
	int mLimit;            // _0C, max states that can be registered
	int* mIndexToIDArray;  // _10, state ID array, indexed by index in mStates
	int* mIdToIndexArray;  // _14, state indices array, indexed by state ID
	int mCurrentID;        // _18, ID of current/active state
};

template <typename T>
void StateMachine<T>::create(int limit)
{
	mLimit          = limit;
	mCount          = 0;
	mStates         = new FSMState<T>*[mLimit];
	mIndexToIDArray = new int[mLimit];
	mIdToIndexArray = new int[mLimit];
}

template <typename T>
void StateMachine<T>::registerState(FSMState<T>* state)
{
	if (mCount >= mLimit) {
		return;
	}
	mStates[mCount] = state;
	bool inBounds;
	if (state->mId < 0 || state->mId >= mLimit) {
		inBounds = false;
	} else {
		inBounds = true;
	}

	if (!inBounds) {
		return;
	}

	state->mStateMachine        = this;
	mIndexToIDArray[mCount]     = state->mId;
	mIdToIndexArray[state->mId] = mCount;
	mCount++;
}

template <typename T>
void StateMachine<T>::transit(T* obj, int stateID, StateArg* stateArg) // _14
{
	int stateIndex            = mIdToIndexArray[stateID];
	FSMState<T>* currentState = GETCURRSTATE(obj);
	if (currentState) {
		currentState->cleanup(obj);
		mCurrentID = currentState->mId;
	}
	if (stateIndex >= mLimit) {
		while (true)
			;
	}
	INITSTATE(obj, mStates[stateIndex], stateArg);
}

} // namespace Game
#endif
