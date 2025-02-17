#ifndef _GAME_ENTITIES_TYRE_H
#define _GAME_ENTITIES_TYRE_H

#include "Game/EnemyStateMachine.h"
#include "Game/EnemyAnimatorBase.h"
#include "Game/EnemyParmsBase.h"
#include "Game/EnemyMgrBase.h"
#include "Game/JointFuncs.h"
#include "Game/EnemyBase.h"
#include "Game/WalkSmokeEffect.h"
#include "SysShape/Joint.h"
#include "Collinfo.h"

/**
 * --Header for Waterwraith Rollers (Tyre)--
 */

namespace efx {
struct TKageTyresmoke;
struct TEnemyHamonChasePos;
} // namespace efx

namespace Game {
struct TyreTubeShadowNode : public JointShadowNode {
	inline TyreTubeShadowNode()
	    : JointShadowNode(2)
	{
	}

	virtual ~TyreTubeShadowNode() { } // _08 (weak)

	void makeShadowSRT(JointShadowParm&, Matrixf*);

	// _00		= VTBL
	// _00-_24	= JointShadowNode
};

namespace Tyre {
struct TyreShadowMgr;
struct FSM;

bool frontTyreCallBack(J3DJoint*, int);
bool rearTyreCallBack(J3DJoint*, int);

struct Obj : public EnemyBase {
	Obj();

	//////////////// VTABLE
	virtual void onInit(CreatureInitArg* settings);                                          // _30
	virtual void doSimulation(f32);                                                          // _4C
	virtual void doDirectDraw(Graphics& gfx);                                                // _50
	virtual void inWaterCallback(WaterBox* wb);                                              // _84
	virtual void outWaterCallback();                                                         // _88
	virtual void collisionCallback(CollEvent& event);                                        // _EC
	virtual void getShadowParam(ShadowParam& settings);                                      // _134
	virtual bool needShadow();                                                               // _138
	virtual ~Obj() { }                                                                       // _1BC (weak)
	virtual void birth(Vector3f&, f32);                                                      // _1C0
	virtual void doUpdate();                                                                 // _1CC
	virtual void doAnimationCullingOff();                                                    // _1DC
	virtual void doDebugDraw(Graphics& gfx);                                                 // _1EC
	virtual void setParameters();                                                            // _228
	virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID() { return EnemyTypeID::EnemyID_Tyre; } // _258 (weak)
	virtual void doGetLifeGaugeParam(LifeGaugeParam&);                                       // _260
	virtual bool damageCallBack(Creature* source, f32 damage, CollPart* part);               // _278
	virtual bool hipdropCallBack(Creature* source, f32 damage, CollPart* part);              // _284
	virtual bool earthquakeCallBack(Creature* source, f32 bounceFactor);                     // _28C
	virtual void doStartStoneState();                                                        // _2A4
	virtual void doFinishStoneState();                                                       // _2A8
	virtual void setFSM(FSM* fsm);                                                           // _2F8 (weak)
	virtual void setInitialSetting(EnemyInitialParamBase* params) { }                        // _1C4 (weak)
	virtual bool isUnderground() { return mIsUnderground; }                                  // _D0 (weak)
	virtual bool bombCallBack(Creature*, Vector3f&, f32) { return false; }                   // _294 (weak)
	//////////////// VTABLE END

	bool isFreeze();
	void frontRollMtxCalc();
	void rearRollMtxCalc();
	void moveStart();
	void collisionStOn();
	void collisionStOff();
	void flick();
	void deadEffect();
	void createSmokeEffect();
	void fadeSmokeEffect();
	void landEffect(Vector3f&);
	void scaleUpShadow();

	// _00 		= VTBL
	// _00-_2BC	= EnemyBase
	EnemyBase* mOwner;                   // _2BC Waterwraith object
	f32 _2C0;                            // _2C0
	f32 _2C4;                            // _2C4
	f32 _2C8;                            // _2C8
	f32 _2CC;                            // _2CC
	u8 _2D0;                             // _2D0, unknown
	bool mIsUnderground;                 // _2D1
	bool mIsShadowActive;                // _2D2, unknown
	Vector3f _2D4;                       // _2D4
	u8 _2E0[0xC];                        // _2E0, unknown
	Vector3f mTyrePositions[2];          // _2EC
	FSM* mFsm;                           // _304
	f32 mShadowScale;                    // _308
	f32 _30C;                            // _30C
	u16 mTyreFrontJointIndex;            // _310
	u16 mTyreRearJointIndex;             // _312
	f32 _314;                            // _314
	int mAnimCounter;                    // _318
	f32 mFallingYPosition;               // _31c
	u8 _320;                             // _320
	u8 _321;                             // _321
	u8 _322;                             // _322
	Vector3f mEfxPosition;               // _324
	efx::TKageTyresmoke* mEfxSmoke1;     // _330
	efx::TKageTyresmoke* mEfxSmoke2;     // _334
	TyreShadowMgr* mShadowMgr;           // _338
	efx::TEnemyHamonChasePos* mEfxHamon; // _33C
	WaterBox* _340;                      // _340
	                                     // _344 = PelletView
};

struct Mgr : public EnemyMgrBase {
	Mgr(int objLimit, u8 modelType);

	//////////////// VTABLE
	// virtual ~Mgr();                                  // _58 (weak)
	virtual EnemyBase* birth(EnemyBirthArg&);          // _70
	virtual void doAlloc();                            // _A8
	virtual void loadModelData();                      // _C8
	virtual J3DModelData* doLoadBmd(void*);            // _D4
	virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID() // _AC (weak)
	{
		return EnemyTypeID::EnemyID_Tyre;
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
	Obj* mObj; // _44, array of Objs
};

extern Obj* curT;

struct Parms : public EnemyParmsBase {
	struct ProperParms : public Parameters {
		inline ProperParms()
		    : Parameters(nullptr, "EnemyParmsBase")
		    , mTyreRotationSpeed(this, 'fp01', "回転スピード", 0.5f, 0.0f, 100.0f) // rotation speed
		{
		}

		Parm<f32> mTyreRotationSpeed; // _804
	};

	Parms()
	{
		_830                 = 0;
		_831                 = 0;
		mDoUseGlobalJointMgr = true;
		_833                 = 10;
		_834                 = 0.0f;
		_838                 = 0.75f;
		_83C                 = 0.05f;
		_840                 = 0.025f;
		_844                 = 0.5f;
		_848                 = 1.2f;
	}

	virtual void read(Stream& stream) // _08 (weak)
	{
		CreatureParms::read(stream);
		mGeneral.read(stream);
		mProperParms.read(stream);
	}

	// _00-_7F8	= EnemyParmsBase
	ProperParms mProperParms; // _7F8
	u8 _830;                  // _830, unknown
	u8 _831;                  // _831, unknown
	u8 mDoUseGlobalJointMgr;  // _832, unknown
	u8 _833;                  // _833, unknown
	f32 _834;                 // _834
	f32 _838;                 // _838
	f32 _83C;                 // _83C
	f32 _840;                 // _840
	f32 _844;                 // _844
	f32 _848;                 // _848
};

struct ProperAnimator : public EnemyAnimatorBase {
	virtual ~ProperAnimator() { }                                    // _08 (weak)
	virtual void setAnimMgr(SysShape::AnimMgr* mgr);                 // _0C
	virtual SysShape::Animator& getAnimator() { return mAnimator; }; // _10 (weak)
	virtual SysShape::Animator& getAnimator(int idx);                // _14

	// _00 		= VTBL
	// _00-_10	= EnemyAnimatorBase
	SysShape::Animator mAnimator; // _10
};

struct TyreShadowMgr {
	TyreShadowMgr(Obj*);

	void init();
	void update();

	f32 mGlobalScale;                 // _00
	Matrixf* mFrontMatrix;            // _04
	Matrixf* mBackMatrix;             // _08
	Obj* mObj;                        // _0C
	JointShadowRootNode* mRootNode;   // _10
	TyreTubeShadowNode* mFrontShadow; // _14
	TyreTubeShadowNode* mBackShadow;  // _18
};

/////////////////////////////////////////////////////////////////
// STATE MACHINE DEFINITIONS
enum StateID {
	TYRE_Move   = 0,
	TYRE_Land   = 1,
	TYRE_Freeze = 2,
	TYRE_Dead   = 3,
};

struct FSM : public EnemyStateMachine {
	virtual void init(EnemyBase*); // _08

	// _00		= VTBL
	// _00-_1C	= EnemyStateMachine
};

struct State : public EnemyFSMState {
	inline State(int stateID)
	    : EnemyFSMState(stateID)
	{
	}

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateDead : public State {
	StateDead(int stateID);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateFreeze : public State {
	StateFreeze(int stateID);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
	u32 _10; // _10
};

struct StateLand : public State {
	StateLand(int stateID);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateMove : public State {
	StateMove(int stateID);

	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};
/////////////////////////////////////////////////////////////////
} // namespace Tyre
} // namespace Game

#endif
