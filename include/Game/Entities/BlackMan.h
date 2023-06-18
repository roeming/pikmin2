#ifndef _GAME_ENTITIES_BLACKMAN_H
#define _GAME_ENTITIES_BLACKMAN_H

#include "Game/EnemyStateMachine.h"
#include "Game/EnemyAnimatorBase.h"
#include "Game/EnemyParmsBase.h"
#include "Game/EnemyMgrBase.h"
#include "Game/JointFuncs.h"
#include "Game/EnemyBase.h"
#include "Game/WalkSmokeEffect.h"
#include "SysShape/Animator.h"
#include "Sys/MatBaseAnimation.h"
#include "Sys/MatBaseAnimator.h"
#include "efx/TKage.h"

/**
 * --Header for Waterwraith (BlackMan)--
 * Note: Rollers are a separate enemy/struct (Tyre).
 */

#include "Game/Entities/Tyre.h"

namespace Game {
struct PathNode;

namespace BlackMan {
struct Parms;

struct FSM : public EnemyStateMachine {
	virtual void init(EnemyBase*); // _08

	// _00		= VTBL
	// _00-_1C	= EnemyStateMachine
};

bool lHandCallBack(J3DJoint*, int);
bool rHandCallBack(J3DJoint*, int);
bool lFootCallBack(J3DJoint*, int);
bool rFootCallBack(J3DJoint*, int);
bool bodyCallBack(J3DJoint*, int);

struct Obj : public EnemyBase {
	Obj();

	//////////////// VTABLE
	virtual void onInit(CreatureInitArg* settings);          // _30
	virtual void onKill(CreatureKillArg* settings);          // _34
	virtual void doEntry();                                  // _40
	virtual void doSimulation(f32);                          // _4C
	virtual void doDirectDraw(Graphics& gfx);                // _50
	virtual bool isUnderground();                            // _D0
	virtual void collisionCallback(CollEvent& event);        // _EC
	virtual void getShadowParam(ShadowParam& settings);      // _134
	virtual ~Obj() { }                                       // _1BC (weak)
	virtual void birth(Vector3f&, f32);                      // _1C0
	virtual void setInitialSetting(EnemyInitialParamBase*);  // _1C4 (weak)
	virtual void doUpdate();                                 // _1CC
	virtual void doAnimationCullingOff();                    // _1DC
	virtual void doDebugDraw(Graphics&);                     // _1EC
	virtual void changeMaterial();                           // _200
	virtual void setParameters();                            // _228
	virtual void initWalkSmokeEffect();                      // _230
	virtual WalkSmokeEffect::Mgr* getWalkSmokeEffectMgr();   // _234
	virtual void updateEfxHamon();                           // _24C (weak)
	virtual void createEfxHamon();                           // _250 (weak)
	virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID();      // _258 (weak)
	virtual void doGetLifeGaugeParam(LifeGaugeParam&);       // _260
	virtual void throwupItemInDeathProcedure();              // _270 (weak)
	virtual bool damageCallBack(Creature*, f32, CollPart*);  // _278
	virtual bool hipdropCallBack(Creature*, f32, CollPart*); // _284
	virtual bool earthquakeCallBack(Creature*, f32);         // _28C
	virtual bool bombCallBack(Creature*, Vector3f&, f32);    // _294 (weak)
	virtual void doStartStoneState();                        // _2A4
	virtual void doFinishStoneState();                       // _2A8
	virtual void setFSM(FSM* fsm) {
		mFSM = fsm;
		mFSM->init(this);
		mCurrentLifecycleState = nullptr;
	};                               // _2F8 (weak)
	//////////////// VTABLE END

	void walkFunc();
	bool isReachToGoal(f32);
	void findNextRoutePoint();
	void findNextTraceRoutePoint();
	bool isEndPathFinder();
	void setPathFinder(bool);
	void releasePathFinder();
	void jointMtxCalc(int);
	void bodyMtxCalc();
	bool isTyreFreeze();
	bool isTyreDead();
	bool isFallEnd();
	void moveRestart();
	void escape();
	void setTimer(f32);
	f32 getTimer();
	void collisionStOn();
	void collisionStOff();
	void flick();
	void recover();
	void recoverFlick();
	void tyreFlick();
	void deadEffect();
	void deadTraceEffect();
	void tyreUpEffect();
	void tyreDownEffect();
	void bendEffect();
	void createTraceEffect();
	void fadeTraceEffect();
	void createFlickEffect();
	void fadeFlickEffect();
	bool isFinalFloor();
	void appearFanfare();

	inline Parms* getParms() { return C_PARMS; }


	// _00 		= VTBL
	// _00-_2BC	= EnemyBase
	Matrixf* mLeftHandMtx;                  // _2BC
	Matrixf* mRightHandMtx;                 // _2C0
	Matrixf* mLeftFootMtx;                  // _2C4
	Matrixf* mRightFootMtx;                 // _2C8
	int mFreezeTimer;                       // _2CC
	Vector3f _2D0;                          // _2D0
	int mPostFlickState;                    // _2DC
	int _2E0;                               // _2E0
	u32 _2E4;                               // _2E4, unknown
	u32 _2E8;                               // _2E8, unknown
	u32 _2EC;                               // _2EC, unknown
	u32 _2F0;                               // _2F0, unknown
	u32 _2F4;                               // _2F4, unknown
	Vector3f _2F8;                          // _2F8
	u8 _304[0xC];                           // _304, unknown
	Vector3f _310[2];                       // _310
	Vector3f _328;                          // _328
	u32 _334;                               // _334
	bool _338;                              // _338
	f32 _33C;                               // _33C, timer?
	s16 _340;                               // _340, next or current waypoint idx?
	s16 _342;                               // _342, next or current waypoint idx?
	s16 _344;                               // _344, unknown
	u32 _348;                               // _348
	u8 _34C;                                // _34C, unknown
	WalkSmokeEffect::Mgr mWalkSmokeMgr;     // _350
	Sys::MatLoopAnimator* mMatLoopAnimator; // _358
	PathNode* _35C;                         // _35C
	FSM* mFSM;                              // _360
	Tyre::Obj* mTyre;                       // _364
	u16 mWaistJointIndex;                   // _368, unknown
	u16 mChestJointIndex;                   // _36A
	u16 mLeftHandJointIndex;                // _36C
	u16 mRightHandJointIndex;               // _36E
	u16 mLeftFootJointIndex;                // _370
	u16 mRightFootJointIndex;               // _372
	f32 _374;                               // _374
	f32 _378;                               // _374
	J3DMaterial* _37C;                      // _37C
	Color4 mUsingColor;                            // _380
	Color4 mTargetColor;                            // _384
	Color4 _388;                            // _388
	Color4 _38C;                            // _38C
	efx::TKageMove* mEfxMove;               // _390
	efx::TKageRun* mEfxRun;                 // _394
	efx::TKageTyreup* mEfxTyreup;           // _398
	efx::TKageDead1* mEfxDead;              // _39C
	efx::TKageFlick* mEfxFrontFlick;        // _3A0
	efx::TKageFlick* mEfxBackFlick;         // _3A4
	u8 _3A8;                                // _3A8, unknown
	u8 _3A9;                                // _3A9
	u8 _3AA;                                // _3AA
	u8 _3AB;                                // _3AB
	                                        // _3AC = PelletView
};

struct Mgr : public EnemyMgrBase {
	Mgr(int objLimit, u8 modelType);

	//////////////// VTABLE
	// virtual ~Mgr();                                     // _58 (weak)
	virtual EnemyBase* birth(EnemyBirthArg&);          // _70
	virtual void doAlloc();                            // _A8
	virtual SysShape::Model* createModel();            // _B0
	virtual void loadModelData();                      // _C8
	virtual void loadTexData();                        // _D0
	virtual J3DModelData* doLoadBmd(void*);            // _D4
	virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID() // _AC (weak)
	{
		return EnemyTypeID::EnemyID_BlackMan;
	}
	virtual void createObj(int count) // _A0 (weak)
	{
		mObj = new Obj[count];
	}
	virtual EnemyBase* getEnemy(int index) // _A4 (weak)
	{
		return &mObj[index];
	}
	//////////////// VTABLE END

	// _00 		= VTBL
	// _00-_44	= EnemyMgrBase
	Sys::MatTexAnimation* mTexAnimation; // _44
	Obj* mObj;                           // _48
};

struct Parms : public EnemyParmsBase {
	struct ProperParms : public Parameters {
		ProperParms()
		    : Parameters(nullptr, "EnemyParmsBase")
		    // Pod?
		    , mPodMoveSpeed(this, 'fp01', "�|�b�h�ړ����x", 10.0f, 0.0f, 100.0f)
		    // Running away (escape)
		    , mEscapeSpeed(this, 'fp02', "�������x", 10.0f, 0.0f, 1000.0f)
		    , mEscapeRotationSpeed(this, 'fp03', "������]���x��", 0.1f, 0.0f, 1.0f)
		    , mMaxEscapeRotationStep(this, 'fp04', "������]�ő呬�x", 10.0f, 0.0f, 360.0f)
		    // Normal movement
		    , mTravelSpeed(this, 'fp05', "2�i�K���x", 200.0f, 10.0f, 500.0f)
		    , mRotationSpeed(this, 'fp06', "2�i�K��]���x��", 0.1f, 0.0f, 1.0f)
		    , mMaxRotationStep(this, 'fp07', "2�i�K��]�ő呬�x", 10.0f, 0.0f, 360.0f)
		    // Walking speed
		    , mWalkingSpeed(this, 'fp11', "�������x", 10.0f, 0.0f, 100.0f)
		    , mTimerToTwoStep(this, 'ip01', "2�i�K�ւ̃^�C�}�[", 300, 0, 3000)
		    , mDosinStopTimerLength(this, 'ip03', "�h�V����~�^�C�}�[", 200, 0, 600)
		    , mFreezeTimerLength(this, 'ip04', "������~�^�C�}�[", 200, 0, 600)
		    , mContinuousEscapeTimerLength(this, 'ip05', "�A�������^�C�}�[", 200, 0, 600)
		    , mStandStillTimerLength(this, 'ip06', "�����~�^�C�}�[", 200, 0, 600)
		{
		}

		Parm<f32> mPodMoveSpeed;                // _804
		Parm<f32> mEscapeSpeed;                 // _82C
		Parm<f32> mEscapeRotationSpeed;         // _854
		Parm<f32> mMaxEscapeRotationStep;       // _87C
		Parm<f32> mTravelSpeed;                 // _8A4
		Parm<f32> mRotationSpeed;               // _8CC
		Parm<f32> mMaxRotationStep;             // _8F4
		Parm<f32> mWalkingSpeed;                // _91C
		Parm<int> mTimerToTwoStep;              // _944
		Parm<int> mDosinStopTimerLength;        // _96C
		Parm<int> mFreezeTimerLength;           // _994
		Parm<int> mContinuousEscapeTimerLength; // _9BC
		Parm<int> mStandStillTimerLength;       // _9E4
	};

	Parms()
	{
		_A10 = 1;
		_A11 = 0;
		_A12 = 1;
		_A14 = 1;
		_A15 = 0;
		_A16 = 1;
		_A17 = 1;
		_A18 = 1;
		_A1A = -1;
		_A1C = 50.0f;
		_A20 = 20.0f;
		_A24 = 1.0f;
		_A28 = 5.0f;
		_A2C = 1.0f;
		_A30 = 0.9f;
		_A34 = 0.6f;
		_A38 = 0.2f;
		_A3C = 0.08f;
		_A40 = 20.0f;
		_A44 = -10.0f;
		_A48 = 10.0f;
		_A4C = 1.25f;
		_A50 = 1100.0f;
		_A54 = 300.0f;
		_A58 = 1.0f;
	}

	virtual void read(Stream& stream) // _08 (weak)
	{
		CreatureParms::read(stream);
		mGeneral.read(stream);
		mProperParms.read(stream);
	}

	// _00-_7F8	= EnemyParmsBase
	ProperParms mProperParms; // _7F8
	u8 _A10;                  // _A10, unknown
	u8 _A11;                  // _A11, unknown
	u8 _A12;                  // _A12, unknown
	u8 _A13;                  // _A13, unknown
	u8 _A14;                  // _A14, unknown
	u8 _A15;                  // _A15, unknown
	u8 _A16;                  // _A16, unknown
	u8 _A17;                  // _A17, unknown
	u8 _A18;                  // _A18, unknown
	s16 _A1A;                 // _A1A, unknown
	f32 _A1C;                 // _A1C
	f32 _A20;                 // _A20
	f32 _A24;                 // _A24
	f32 _A28;                 // _A28
	f32 _A2C;                 // _A2C
	f32 _A30;                 // _A30
	f32 _A34;                 // _A34
	f32 _A38;                 // _A38
	f32 _A3C;                 // _A3C
	f32 _A40;                 // _A40
	f32 _A44;                 // _A44
	f32 _A48;                 // _A48
	f32 _A4C;                 // _A4C
	f32 _A50;                 // _A50
	f32 _A54;                 // _A54
	f32 _A58;                 // _A58
};

struct ProperAnimator : public EnemyAnimatorBase {
	virtual ~ProperAnimator() { }                                   // _08 (weak)
	virtual void setAnimMgr(SysShape::AnimMgr* mgr);                // _0C
	virtual SysShape::Animator& getAnimator() { return mAnimator; } // _10 (weak)
	virtual SysShape::Animator& getAnimator(int idx);               // _14

	SysShape::Animator mAnimator; // _10
};

/////////////////////////////////////////////////////////////////
// STATE MACHINE DEFINITIONS
enum StateID {
	WRAITH_Walk    = 0,
	WRAITH_Dead    = 1,
	WRAITH_Freeze  = 2,
	WRAITH_Bend    = 3,
	WRAITH_Escape  = 4,
	WRAITH_Fall    = 5,
	WRAITH_Flick   = 6,
	WRAITH_Recover = 7,
	WRAITH_Tired   = 8,
	WRAITH_Count   = 9,
};



struct State : public EnemyFSMState {
	inline State(int stateID)
	    : EnemyFSMState(stateID)
	{
	}

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateBend : public State {
	StateBend(int);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateDead : public State {
	StateDead(int);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
	u8 _10[0x4]; // _10, unknown
};

struct StateEscape : public State {
	StateEscape(int);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateFall : public State {
	StateFall(int);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateFlick : public State {
	StateFlick(int);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateFreeze : public State {
	StateFreeze(int);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateRecover : public State {
	StateRecover(int);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateTired : public State {
	StateTired(int);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
	int _10; // _10
};

struct StateWalk : public State {
	StateWalk(int);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};
/////////////////////////////////////////////////////////////////
} // namespace BlackMan
} // namespace Game

#endif
