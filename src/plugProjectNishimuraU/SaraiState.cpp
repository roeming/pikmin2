#include "Game/Entities/Sarai.h"
#include "Game/EnemyAnimKeyEvent.h"
#include "Game/EnemyFunc.h"
#include "Game/MapMgr.h"
#include "Game/rumble.h"
#include "Dolphin/rand.h"

namespace Game {
namespace Sarai {

/*
 * --INFO--
 * Address:	802708A0
 * Size:	0003D0
 */
void FSM::init(EnemyBase* enemy)
{
	create(SARAI_StateCount);
	registerState(new StateDead);
	registerState(new StateFall);
	registerState(new StateDamage);
	registerState(new StateTakeOff);
	registerState(new StateFlick);
	registerState(new StateWait);
	registerState(new StateMove);
	registerState(new StateAttack);
	registerState(new StateFail);
	registerState(new StateCatchFly);
	registerState(new StateFallMeck);
}

/*
 * --INFO--
 * Address:	80270C70
 * Size:	000070
 */
void StateDead::init(EnemyBase* enemy, StateArg* stateArg)
{
	Obj* sarai = OBJ(enemy);
	sarai->deathProcedure();
	sarai->disableEvent(0, EB_Cullable);
	sarai->mTargetVelocity = Vector3f(0.0f);
	sarai->disableEvent(0, EB_Untargetable);
	sarai->flickStickTarget();
	sarai->startMotion(10, nullptr);
}

/*
 * --INFO--
 * Address:	80270CE0
 * Size:	000044
 */
void StateDead::exec(EnemyBase* enemy)
{
	if (enemy->mCurAnim->mIsPlaying && enemy->mCurAnim->mType == KEYEVENT_END) {
		enemy->kill(nullptr);
	}
}

/*
 * --INFO--
 * Address:	80270D24
 * Size:	000004
 */
void StateDead::cleanup(EnemyBase* enemy) { }

/*
 * --INFO--
 * Address:	80270D28
 * Size:	000068
 */
void StateFall::init(EnemyBase* enemy, StateArg* stateArg)
{
	Obj* sarai             = OBJ(enemy);
	sarai->_2C0            = 0.0f;
	sarai->mTargetVelocity = Vector3f(0.0f);
	sarai->disableEvent(0, EB_Untargetable);
	sarai->setEmotionExcitement();
	sarai->startMotion(6, nullptr);
	sarai->flickStickTarget();
}

/*
 * --INFO--
 * Address:	80270D90
 * Size:	0001B8
 */
void StateFall::exec(EnemyBase* enemy)
{
	Obj* sarai   = OBJ(enemy);
	Vector3f pos = sarai->getPosition();

	f32 minY = mapMgr->getMinY(pos);

	if (pos.y - minY < 10.0f || sarai->_2C0 > 1.0f) {
		sarai->finishMotion();
	}

	if (!sarai->isFinishMotion()) {
		f32 faceDir = sarai->getFaceDir() - 0.275f;

		if (faceDir < 0.0f) {
			faceDir = faceDir + TAU;
		} else if (faceDir >= TAU) {
			faceDir -= TAU;
		}

		sarai->mFaceDir    = faceDir;
		sarai->mRotation.y = sarai->mFaceDir;
	}

	sarai->_2C0 += sys->mDeltaTime;

	if (sarai->mCurAnim->mIsPlaying) {
		if (sarai->mCurAnim->mType == KEYEVENT_2) {
			sarai->createDownEffect();
			rumbleMgr->startRumble(11, pos, 2);
		} else if (sarai->mCurAnim->mType == KEYEVENT_END) {
			if (sarai->mHealth <= 0.0f) {
				transit(sarai, SARAI_Dead, nullptr);
			} else {
				transit(sarai, SARAI_Damage, nullptr);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	80270F48
 * Size:	000024
 */
void StateFall::cleanup(EnemyBase* enemy) { enemy->setEmotionCaution(); }

/*
 * --INFO--
 * Address:	80270F6C
 * Size:	000068
 */
void StateDamage::init(EnemyBase* enemy, StateArg* stateArg)
{
	Obj* sarai             = OBJ(enemy);
	sarai->_2C0            = 0.0f;
	sarai->mTargetVelocity = Vector3f(0.0f);
	sarai->disableEvent(0, EB_Untargetable);
	sarai->setEmotionExcitement();
	sarai->startMotion(7, nullptr);
	sarai->flickStickTarget();
}

/*
 * --INFO--
 * Address:	80270FD4
 * Size:	000108
 */
void StateDamage::exec(EnemyBase* enemy)
{
	Obj* sarai = OBJ(enemy);
	if (sarai->mHealth <= 0.0f || sarai->_2C0 > CG_PROPERPARMS(sarai).mFp23.mValue || sarai->getStickPikminNum() == 0) {
		sarai->finishMotion();
	}

	sarai->_2C0 += sys->mDeltaTime;

	if (sarai->mCurAnim->mIsPlaying && sarai->mCurAnim->mType == KEYEVENT_END) {
		if (sarai->mHealth <= 0.0f) {
			transit(sarai, SARAI_Dead, nullptr);
		} else {
			transit(sarai, SARAI_TakeOff, nullptr);
		}
	}
}

/*
 * --INFO--
 * Address:	802710DC
 * Size:	000024
 */
void StateDamage::cleanup(EnemyBase* enemy) { enemy->setEmotionCaution(); }

/*
 * --INFO--
 * Address:	80271100
 * Size:	00004C
 */
void StateTakeOff::init(EnemyBase* enemy, StateArg* stateArg)
{
	enemy->enableEvent(0, EB_Untargetable);
	enemy->setEmotionExcitement();
	enemy->startMotion(8, nullptr);
}

/*
 * --INFO--
 * Address:	8027114C
 * Size:	000108
 */
void StateTakeOff::exec(EnemyBase* enemy)
{
	Obj* sarai = OBJ(enemy);
	f32 val    = sarai->setHeightVelocity();

	if (sarai->mHealth <= 0.0f || val > CG_PROPERPARMS(sarai).mFp03.mValue) {
		sarai->finishMotion();
	}

	if (sarai->mCurAnim->mIsPlaying && sarai->mCurAnim->mType == KEYEVENT_END) {
		int nextState = sarai->getNextStateOnHeight();
		if (nextState >= 0) {
			transit(sarai, nextState, nullptr);
			return;
		}

		if (sarai->getCatchTargetNum()) {
			transit(sarai, SARAI_CatchFly, nullptr);
			return;
		}

		transit(sarai, SARAI_Move, nullptr);
	}
}

/*
 * --INFO--
 * Address:	80271254
 * Size:	000024
 */
void StateTakeOff::cleanup(EnemyBase* enemy) { enemy->setEmotionCaution(); }

/*
 * --INFO--
 * Address:	80271278
 * Size:	000058
 */
void StateFlick::init(EnemyBase* enemy, StateArg* stateArg)
{
	enemy->enableEvent(0, EB_Untargetable);
	enemy->enableEvent(0, EB_NoInterrupt);
	enemy->setEmotionExcitement();
	enemy->startMotion(5, nullptr);
}

/*
 * --INFO--
 * Address:	802712D0
 * Size:	000118
 */
void StateFlick::exec(EnemyBase* enemy)
{
	Obj* sarai = OBJ(enemy);
	sarai->setHeightVelocity();

	if (sarai->mCurAnim->mIsPlaying) {
		if (sarai->mCurAnim->mType == KEYEVENT_2) {
			EnemyFunc::flickStickPikmin(sarai, CG_PARMS(sarai)->mGeneral.mShakeRateMaybe.mValue,
			                            CG_PARMS(sarai)->mGeneral.mShakeKnockback.mValue, CG_PARMS(sarai)->mGeneral.mShakeDamage.mValue,
			                            -1000.0f, nullptr);
			sarai->mToFlick = 0.0f;

		} else if (sarai->mCurAnim->mType == KEYEVENT_END) {
			if (sarai->mHealth <= 0.0f) {
				transit(sarai, SARAI_Fall, nullptr);
				return;
			}

			if (sarai->getCatchTargetNum()) {
				transit(sarai, SARAI_CatchFly, nullptr);
				return;
			}

			transit(sarai, SARAI_Move, nullptr);
		}
	}
}

/*
 * --INFO--
 * Address:	802713E8
 * Size:	000030
 */
void StateFlick::cleanup(EnemyBase* enemy)
{
	enemy->disableEvent(0, EB_NoInterrupt);
	enemy->setEmotionCaution();
}

/*
 * --INFO--
 * Address:	80271418
 * Size:	0000B0
 */
void StateWait::init(EnemyBase* enemy, StateArg* stateArg)
{
	Obj* sarai             = OBJ(enemy);
	sarai->_2C0            = 0.0f;
	sarai->mTargetVelocity = Vector3f(0.0f);
	sarai->mTargetCreature = nullptr;
	sarai->enableEvent(0, EB_Untargetable);

	if (randWeightFloat(1.0f) < 0.5f) {
		sarai->startMotion(0, nullptr);
	} else {
		sarai->startMotion(1, nullptr);
	}
}

/*
 * --INFO--
 * Address:	802714C8
 * Size:	000160
 */
void StateWait::exec(EnemyBase* enemy)
{
	Obj* sarai = OBJ(enemy);
	f32 val    = sarai->setHeightVelocity();

	FakePiki* target = sarai->getAttackableTarget();
	if (target || sarai->_2C0 > CG_PROPERPARMS(sarai).mFp06.mValue) {
		sarai->finishMotion();
	}

	if (val > CG_PROPERPARMS(sarai).mFp03.mValue || sarai->_2C0 > 3.0f) {
		int nextState = sarai->getNextStateOnHeight();
		if (nextState >= 0) {
			transit(sarai, nextState, nullptr);
			return;
		}
	}

	sarai->_2C0 += sys->mDeltaTime;

	if (sarai->mCurAnim->mIsPlaying && sarai->mCurAnim->mType == KEYEVENT_END) {
		if (target) {
			sarai->mTargetCreature = target;
			transit(sarai, SARAI_Attack, nullptr);
			return;
		}

		transit(sarai, SARAI_Move, nullptr);
	}
}

/*
 * --INFO--
 * Address:	80271628
 * Size:	000004
 */
void StateWait::cleanup(EnemyBase* enemy) { }

/*
 * --INFO--
 * Address:	8027162C
 * Size:	00005C
 */
void StateMove::init(EnemyBase* enemy, StateArg* stateArg)
{
	Obj* sarai  = OBJ(enemy);
	sarai->_2C0 = 0.0f;
	sarai->setRandTarget();
	sarai->mTargetCreature = nullptr;
	sarai->enableEvent(0, EB_Untargetable);
	sarai->startMotion(1, nullptr);
}

/*
 * --INFO--
 * Address:	80271688
 * Size:	000208
 */
void StateMove::exec(EnemyBase* enemy)
{
	Obj* sarai = OBJ(enemy);

	f32 height         = sarai->setHeightVelocity();
	Vector3f pos       = sarai->getPosition();
	Vector3f targetPos = Vector3f(sarai->mTargetPos);

	FakePiki* target = sarai->getAttackableTarget();

	if (target || sarai->_2C0 > 10.0f || sqrDistanceXZ(pos, targetPos) < 625.0f) {
		sarai->mTargetVelocity = Vector3f(0.0f);
		sarai->finishMotion();
	} else {
		EnemyFunc::walkToTarget(sarai, targetPos, CG_PROPERPARMS(sarai).mFp04.mValue, CG_PARMS(sarai)->mGeneral.mRotationalAccel.mValue,
		                        CG_PARMS(sarai)->mGeneral.mRotationalSpeed.mValue);
	}

	if (height > CG_PROPERPARMS(sarai).mFp03.mValue || sarai->_2C0 > 3.0f) {
		int nextState = sarai->getNextStateOnHeight();
		if (nextState >= 0) {
			transit(sarai, nextState, nullptr);
			return;
		}
	}

	sarai->_2C0 += sys->mDeltaTime;

	if (sarai->mCurAnim->mIsPlaying && sarai->mCurAnim->mType == KEYEVENT_END) {
		if (target) {
			sarai->mTargetCreature = target;
			transit(sarai, SARAI_Attack, nullptr);
			return;
		}

		transit(sarai, SARAI_Wait, nullptr);
	}
}

/*
 * --INFO--
 * Address:	80271890
 * Size:	000004
 */
void StateMove::cleanup(EnemyBase* enemy) { }

/*
 * --INFO--
 * Address:	80271894
 * Size:	000078
 */
void StateAttack::init(EnemyBase* enemy, StateArg* stateArg)
{
	Obj* sarai  = OBJ(enemy);
	sarai->_2C0 = 0.0f;
	sarai->disableEvent(0, EB_Cullable);
	sarai->mTargetVelocity = Vector3f(0.0f);
	sarai->enableEvent(0, EB_NoInterrupt);
	sarai->enableEvent(0, EB_Untargetable);
	sarai->setEmotionExcitement();
	sarai->startMotion(2, nullptr);
}

/*
 * --INFO--
 * Address:	8027190C
 * Size:	000614
 */
void StateAttack::exec(EnemyBase* enemy)
{
	Obj* sarai       = OBJ(enemy);
	Creature* target = sarai->mTargetCreature;
	if (target) {
		f32 frame = sarai->getMotionFrame();
		if (frame <= 10.0f) {
			sarai->setHeightVelocity();
			Vector3f pos = sarai->getPosition();

			// atan2 nonsense.
		}
	}
	/*
	stwu     r1, -0xe0(r1)
	mflr     r0
	stw      r0, 0xe4(r1)
	stfd     f31, 0xd0(r1)
	psq_st   f31, 216(r1), 0, qr0
	stfd     f30, 0xc0(r1)
	psq_st   f30, 200(r1), 0, qr0
	stfd     f29, 0xb0(r1)
	psq_st   f29, 184(r1), 0, qr0
	stfd     f28, 0xa0(r1)
	psq_st   f28, 168(r1), 0, qr0
	stw      r31, 0x9c(r1)
	stw      r30, 0x98(r1)
	stw      r29, 0x94(r1)
	lwz      r30, 0x230(r4)
	mr       r29, r3
	mr       r31, r4
	cmplwi   r30, 0
	beq      lbl_80271CB0
	mr       r3, r31
	bl       getMotionFrame__Q24Game9EnemyBaseFv
	fmr      f31, f1
	lfs      f0, lbl_8051B15C@sda21(r2)
	fcmpo    cr0, f31, f0
	cror     2, 0, 2
	bne      lbl_80271A6C
	mr       r3, r31
	bl       setHeightVelocity__Q34Game5Sarai3ObjFv
	mr       r4, r30
	lwz      r5, 0xc0(r31)
	lwz      r12, 0(r30)
	addi     r3, r1, 0x20
	lfs      f30, 0x334(r5)
	lwz      r12, 8(r12)
	lfs      f31, 0x30c(r5)
	mtctr    r12
	bctrl
	mr       r4, r31
	addi     r3, r1, 0x2c
	lwz      r12, 0(r31)
	lfs      f29, 0x20(r1)
	lwz      r12, 8(r12)
	lfs      f28, 0x28(r1)
	mtctr    r12
	bctrl
	lfs      f1, 0x2c(r1)
	lis      r3, atanTable___5JMath@ha
	lfs      f0, 0x34(r1)
	addi     r3, r3, atanTable___5JMath@l
	fsubs    f1, f29, f1
	fsubs    f2, f28, f0
	bl       "atan2___Q25JMath18TAtanTable<1024,f>CFff"
	bl       roundAng__Ff
	lwz      r12, 0(r31)
	fmr      f29, f1
	mr       r3, r31
	lwz      r12, 0x64(r12)
	mtctr    r12
	bctrl
	fmr      f2, f1
	fmr      f1, f29
	bl       angDist__Fff
	fmuls    f31, f1, f31
	lfs      f0, lbl_8051B18C@sda21(r2)
	lfs      f1, lbl_8051B188@sda21(r2)
	fmuls    f0, f0, f30
	fabs     f2, f31
	fmuls    f1, f1, f0
	frsp     f0, f2
	fcmpo    cr0, f0, f1
	ble      lbl_80271A40
	lfs      f0, lbl_8051B158@sda21(r2)
	fcmpo    cr0, f31, f0
	ble      lbl_80271A3C
	fmr      f31, f1
	b        lbl_80271A40

lbl_80271A3C:
	fneg     f31, f1

lbl_80271A40:
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x64(r12)
	mtctr    r12
	bctrl
	fadds    f1, f31, f1
	bl       roundAng__Ff
	stfs     f1, 0x1fc(r31)
	lfs      f0, 0x1fc(r31)
	stfs     f0, 0x1a8(r31)
	b        lbl_80271CC8

lbl_80271A6C:
	lfs      f0, lbl_8051B190@sda21(r2)
	fcmpo    cr0, f31, f0
	cror     2, 0, 2
	bne      lbl_80271C78
	lwz      r0, 0xc8(r31)
	cmplwi   r0, 0
	beq      lbl_80271A8C
	stfs     f0, 0x2c0(r31)

lbl_80271A8C:
	lfs      f1, 0x2c0(r31)
	lfs      f0, lbl_8051B190@sda21(r2)
	fcmpo    cr0, f1, f0
	bge      lbl_80271CC8
	mr       r4, r30
	addi     r3, r1, 0x68
	lwz      r12, 0(r30)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r31
	lfs      f28, 0x6c(r1)
	lwz      r12, 0(r31)
	addi     r3, r1, 0x5c
	lfs      f0, lbl_8051B194@sda21(r2)
	lwz      r12, 8(r12)
	fadds    f28, f28, f0
	mtctr    r12
	bctrl
	mr       r4, r31
	addi     r3, r1, 0x50
	lwz      r12, 0(r31)
	lfs      f29, 0x60(r1)
	lwz      r12, 0x6c(r12)
	mtctr    r12
	bctrl
	lfs      f3, 0x50(r1)
	fsubs    f2, f28, f29
	lfs      f0, 0x54(r1)
	lfs      f1, 0x58(r1)
	stfs     f3, 0x80(r1)
	lwz      r3, sys@sda21(r13)
	stfs     f0, 0x84(r1)
	lfs      f0, lbl_8051B198@sda21(r2)
	stfs     f1, 0x88(r1)
	lfs      f1, 0x54(r3)
	lwz      r3, 0xc0(r31)
	fdivs    f2, f2, f1
	lfs      f1, 0x9d4(r3)
	fmuls    f1, f2, f1
	fcmpo    cr0, f1, f0
	bge      lbl_80271B38
	b        lbl_80271B4C

lbl_80271B38:
	lfs      f0, lbl_8051B19C@sda21(r2)
	fcmpo    cr0, f1, f0
	ble      lbl_80271B48
	b        lbl_80271B4C

lbl_80271B48:
	fmr      f0, f1

lbl_80271B4C:
	stfs     f0, 0x84(r1)
	mr       r3, r31
	addi     r4, r1, 0x80
	lwz      r12, 0(r31)
	lwz      r12, 0x68(r12)
	mtctr    r12
	bctrl
	lfs      f0, lbl_8051B1A0@sda21(r2)
	fcmpo    cr0, f31, f0
	ble      lbl_80271B88
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x304(r12)
	mtctr    r12
	bctrl

lbl_80271B88:
	mr       r4, r30
	lwz      r5, 0xc0(r31)
	lwz      r12, 0(r30)
	addi     r3, r1, 8
	lfs      f31, 0x334(r5)
	lwz      r12, 8(r12)
	lfs      f30, 0x30c(r5)
	mtctr    r12
	bctrl
	mr       r4, r31
	addi     r3, r1, 0x14
	lwz      r12, 0(r31)
	lfs      f28, 8(r1)
	lwz      r12, 8(r12)
	lfs      f29, 0x10(r1)
	mtctr    r12
	bctrl
	lfs      f1, 0x14(r1)
	lis      r3, atanTable___5JMath@ha
	lfs      f0, 0x1c(r1)
	addi     r3, r3, atanTable___5JMath@l
	fsubs    f1, f28, f1
	fsubs    f2, f29, f0
	bl       "atan2___Q25JMath18TAtanTable<1024,f>CFff"
	bl       roundAng__Ff
	lwz      r12, 0(r31)
	fmr      f29, f1
	mr       r3, r31
	lwz      r12, 0x64(r12)
	mtctr    r12
	bctrl
	fmr      f2, f1
	fmr      f1, f29
	bl       angDist__Fff
	fmuls    f30, f1, f30
	lfs      f0, lbl_8051B18C@sda21(r2)
	lfs      f1, lbl_8051B188@sda21(r2)
	fmuls    f0, f0, f31
	fabs     f2, f30
	fmuls    f1, f1, f0
	frsp     f0, f2
	fcmpo    cr0, f0, f1
	ble      lbl_80271C4C
	lfs      f0, lbl_8051B158@sda21(r2)
	fcmpo    cr0, f30, f0
	ble      lbl_80271C48
	fmr      f30, f1
	b        lbl_80271C4C

lbl_80271C48:
	fneg     f30, f1

lbl_80271C4C:
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x64(r12)
	mtctr    r12
	bctrl
	fadds    f1, f30, f1
	bl       roundAng__Ff
	stfs     f1, 0x1fc(r31)
	lfs      f0, 0x1fc(r31)
	stfs     f0, 0x1a8(r31)
	b        lbl_80271CC8

lbl_80271C78:
	mr       r3, r31
	bl       setHeightVelocity__Q34Game5Sarai3ObjFv
	lwz      r3, 0xc0(r31)
	lfs      f1, 0x1d4(r31)
	lfs      f0, 0x9fc(r3)
	lfs      f2, 0x1d8(r31)
	fmuls    f1, f1, f0
	lfs      f3, 0x1dc(r31)
	fmuls    f2, f2, f0
	fmuls    f3, f3, f0
	stfs     f1, 0x1d4(r31)
	stfs     f2, 0x1d8(r31)
	stfs     f3, 0x1dc(r31)
	b        lbl_80271CC8

lbl_80271CB0:
	lwz      r12, 0(r3)
	li       r5, 6
	li       r6, 0
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl

lbl_80271CC8:
	lwz      r3, 0x188(r31)
	lbz      r0, 0x24(r3)
	cmplwi   r0, 0
	beq      lbl_80271EE4
	lwz      r0, 0x1c(r3)
	cmplwi   r0, 2
	bne      lbl_80271E34
	lwz      r4, 0x230(r31)
	cmplwi   r4, 0
	beq      lbl_80271EE4
	lwz      r12, 0(r4)
	addi     r3, r1, 0x44
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r31
	addi     r3, r1, 0x38
	lwz      r12, 0(r31)
	lfs      f28, 0x44(r1)
	lwz      r12, 8(r12)
	lfs      f29, 0x48(r1)
	lfs      f30, 0x4c(r1)
	mtctr    r12
	bctrl
	lfs      f0, 0x3c(r1)
	lfs      f2, 0x40(r1)
	fsubs    f6, f29, f0
	lfs      f1, 0x38(r1)
	fsubs    f7, f30, f2
	lfs      f0, lbl_8051B158@sda21(r2)
	fsubs    f5, f28, f1
	fmuls    f1, f6, f6
	fmuls    f2, f7, f7
	stfs     f6, 0x78(r1)
	fmadds   f1, f5, f5, f1
	stfs     f5, 0x74(r1)
	stfs     f7, 0x7c(r1)
	fadds    f1, f2, f1
	fcmpo    cr0, f1, f0
	ble      lbl_80271D78
	ble      lbl_80271D7C
	frsqrte  f0, f1
	fmuls    f1, f0, f1
	b        lbl_80271D7C

lbl_80271D78:
	fmr      f1, f0

lbl_80271D7C:
	lfs      f0, lbl_8051B158@sda21(r2)
	fcmpo    cr0, f1, f0
	ble      lbl_80271D9C
	lfs      f0, lbl_8051B160@sda21(r2)
	fdivs    f0, f0, f1
	fmuls    f5, f5, f0
	fmuls    f6, f6, f0
	fmuls    f7, f7, f0

lbl_80271D9C:
	lfs      f2, lbl_8051B1A4@sda21(r2)
	mr       r3, r31
	lfs      f1, 0x78(r1)
	addi     r4, r1, 0x74
	fmuls    f6, f6, f2
	lfs      f4, 0x74(r1)
	fmuls    f5, f5, f2
	lfs      f0, 0x7c(r1)
	fmuls    f7, f7, f2
	lfs      f3, lbl_8051B158@sda21(r2)
	fsubs    f2, f1, f6
	lwz      r5, sys@sda21(r13)
	fsubs    f5, f4, f5
	lfs      f1, lbl_8051B1A8@sda21(r2)
	fsubs    f4, f0, f7
	stfs     f2, 0x78(r1)
	stfs     f5, 0x74(r1)
	stfs     f4, 0x7c(r1)
	stfs     f3, 0x78(r1)
	lfs      f0, 0x54(r5)
	fdivs    f0, f1, f0
	fmuls    f2, f5, f0
	fmuls    f1, f3, f0
	fmuls    f0, f4, f0
	stfs     f2, 0x74(r1)
	stfs     f1, 0x78(r1)
	stfs     f0, 0x7c(r1)
	lwz      r12, 0(r31)
	lwz      r12, 0x68(r12)
	mtctr    r12
	bctrl
	lfs      f0, 0x74(r1)
	stfs     f0, 0x1d4(r31)
	lfs      f0, 0x78(r1)
	stfs     f0, 0x1d8(r31)
	lfs      f0, 0x7c(r1)
	stfs     f0, 0x1dc(r31)
	b        lbl_80271EE4

lbl_80271E34:
	cmplwi   r0, 3
	bne      lbl_80271E4C
	lwz      r0, 0x1e0(r31)
	rlwinm   r0, r0, 0, 0xb, 9
	stw      r0, 0x1e0(r31)
	b        lbl_80271EE4

lbl_80271E4C:
	cmplwi   r0, 4
	bne      lbl_80271E88
	mr       r3, r31
	bl       getCatchTargetNum__Q34Game5Sarai3ObjFv
	cmpwi    r3, 0
	bne      lbl_80271EE4
	mr       r3, r29
	mr       r4, r31
	lwz      r12, 0(r29)
	li       r5, 8
	li       r6, 0
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	b        lbl_80271EE4

lbl_80271E88:
	cmplwi   r0, 0x3e8
	bne      lbl_80271EE4
	mr       r3, r31
	bl       getCatchTargetNum__Q34Game5Sarai3ObjFv
	cmpwi    r3, 0
	beq      lbl_80271EC4
	mr       r3, r29
	mr       r4, r31
	lwz      r12, 0(r29)
	li       r5, 9
	li       r6, 0
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	b        lbl_80271EE4

lbl_80271EC4:
	mr       r3, r29
	mr       r4, r31
	lwz      r12, 0(r29)
	li       r5, 6
	li       r6, 0
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl

lbl_80271EE4:
	psq_l    f31, 216(r1), 0, qr0
	lfd      f31, 0xd0(r1)
	psq_l    f30, 200(r1), 0, qr0
	lfd      f30, 0xc0(r1)
	psq_l    f29, 184(r1), 0, qr0
	lfd      f29, 0xb0(r1)
	psq_l    f28, 168(r1), 0, qr0
	lfd      f28, 0xa0(r1)
	lwz      r31, 0x9c(r1)
	lwz      r30, 0x98(r1)
	lwz      r0, 0xe4(r1)
	lwz      r29, 0x94(r1)
	mtlr     r0
	addi     r1, r1, 0xe0
	blr
	*/
}

/*
 * --INFO--
 * Address:	80271F20
 * Size:	000044
 */
void StateAttack::cleanup(EnemyBase* enemy)
{
	enemy->enableEvent(0, EB_Cullable);
	enemy->disableEvent(0, EB_NoInterrupt);
	enemy->mTargetCreature = nullptr;
	enemy->setEmotionCaution();
}

/*
 * --INFO--
 * Address:	80271F64
 * Size:	000058
 */
void StateFail::init(EnemyBase* enemy, StateArg* stateArg)
{
	enemy->enableEvent(0, EB_Untargetable);
	enemy->disableEvent(0, EB_Cullable);
	enemy->setEmotionExcitement();
	enemy->startMotion(9, nullptr);
}

/*
 * --INFO--
 * Address:	80271FBC
 * Size:	0000D8
 */
void StateFail::exec(EnemyBase* enemy)
{
	Obj* sarai = OBJ(enemy);
	sarai->setHeightVelocity();

	// regswaps here
	f32 decayRate          = CG_PROPERPARMS(sarai).mFp32.mValue;
	Vector3f vel           = sarai->mTargetVelocity;
	sarai->mTargetVelocity = vel * decayRate;

	if (sarai->mCurAnim->mIsPlaying && sarai->mCurAnim->mType == KEYEVENT_END) {
		if (sarai->getCatchTargetNum()) {
			transit(sarai, SARAI_CatchFly, nullptr);
			return;
		}

		transit(sarai, SARAI_Move, nullptr);
	}
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	stw      r0, 0x14(r1)
	stw      r31, 0xc(r1)
	mr       r31, r4
	stw      r30, 8(r1)
	mr       r30, r3
	mr       r3, r31
	bl       setHeightVelocity__Q34Game5Sarai3ObjFv
	lwz      r3, 0xc0(r31)
	lfs      f1, 0x1d4(r31)
	lfs      f0, 0x9fc(r3)
	lfs      f2, 0x1d8(r31)
	fmuls    f1, f1, f0
	lfs      f3, 0x1dc(r31)
	fmuls    f2, f2, f0
	fmuls    f3, f3, f0
	stfs     f1, 0x1d4(r31)
	stfs     f2, 0x1d8(r31)
	stfs     f3, 0x1dc(r31)
	lwz      r3, 0x188(r31)
	lbz      r0, 0x24(r3)
	cmplwi   r0, 0
	beq      lbl_8027207C
	lwz      r0, 0x1c(r3)
	cmplwi   r0, 0x3e8
	bne      lbl_8027207C
	mr       r3, r31
	bl       getCatchTargetNum__Q34Game5Sarai3ObjFv
	cmpwi    r3, 0
	beq      lbl_8027205C
	mr       r3, r30
	mr       r4, r31
	lwz      r12, 0(r30)
	li       r5, 9
	li       r6, 0
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	b        lbl_8027207C

lbl_8027205C:
	mr       r3, r30
	mr       r4, r31
	lwz      r12, 0(r30)
	li       r5, 6
	li       r6, 0
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl

lbl_8027207C:
	lwz      r0, 0x14(r1)
	lwz      r31, 0xc(r1)
	lwz      r30, 8(r1)
	mtlr     r0
	addi     r1, r1, 0x10
	blr
	*/
}

/*
 * --INFO--
 * Address:	80272094
 * Size:	000030
 */
void StateFail::cleanup(EnemyBase* enemy)
{
	enemy->enableEvent(0, EB_Cullable);
	enemy->setEmotionCaution();
}

/*
 * --INFO--
 * Address:	802720C4
 * Size:	000064
 */
void StateCatchFly::init(EnemyBase* enemy, StateArg* stateArg)
{
	Obj* sarai  = OBJ(enemy);
	sarai->_2C0 = 0.0f;
	sarai->setRandTarget();
	sarai->mTargetCreature = nullptr;
	sarai->enableEvent(0, EB_Untargetable);
	sarai->setEmotionExcitement();
	sarai->startMotion(3, nullptr);
}

/*
 * --INFO--
 * Address:	80272128
 * Size:	0001C0
 */
void StateCatchFly::exec(EnemyBase* enemy)
{
	Obj* sarai = OBJ(enemy);

	f32 height         = sarai->setHeightVelocity();
	Vector3f pos       = sarai->getPosition();
	Vector3f targetPos = Vector3f(sarai->mTargetPos);

	if (sarai->_2C0 > 10.0f || sqrDistanceXZ(pos, targetPos) < 625.0f) {
		sarai->mTargetVelocity = Vector3f(0.0f);
		sarai->finishMotion();
	} else {
		EnemyFunc::walkToTarget(sarai, targetPos, CG_PROPERPARMS(sarai).mFp05.mValue, CG_PARMS(sarai)->mGeneral.mRotationalAccel.mValue,
		                        CG_PARMS(sarai)->mGeneral.mRotationalSpeed.mValue);
	}

	if (!sarai->getCatchTargetNum()) {
		transit(sarai, SARAI_Move, nullptr);
		return;
	}

	if (height > CG_PROPERPARMS(sarai).mFp03.mValue || sarai->_2C0 > 3.0f) {
		int nextState = sarai->getNextStateOnHeight();
		if (nextState >= 0) {
			transit(sarai, nextState, nullptr);
			return;
		}
	}

	sarai->_2C0 += sys->mDeltaTime;

	if (sarai->mCurAnim->mIsPlaying && sarai->mCurAnim->mType == KEYEVENT_END) {
		transit(sarai, SARAI_FallMeck, nullptr);
	}
}

/*
 * --INFO--
 * Address:	802722E8
 * Size:	000024
 */
void StateCatchFly::cleanup(EnemyBase* enemy) { enemy->setEmotionCaution(); }

/*
 * --INFO--
 * Address:	8027230C
 * Size:	000070
 */
void StateFallMeck::init(EnemyBase* enemy, StateArg* stateArg)
{
	enemy->disableEvent(0, EB_NoInterrupt);
	enemy->enableEvent(0, EB_Untargetable);
	enemy->mTargetCreature = nullptr;
	enemy->mTargetVelocity = Vector3f(0.0f);
	enemy->setEmotionExcitement();
	enemy->startMotion(4, nullptr);
}

/*
 * --INFO--
 * Address:	8027237C
 * Size:	0000BC
 */
void StateFallMeck::exec(EnemyBase* enemy)
{
	Obj* sarai = OBJ(enemy);
	sarai->setHeightVelocity();

	if (sarai->mCurAnim->mIsPlaying) {
		if (sarai->mCurAnim->mType == KEYEVENT_2) {
			sarai->enableEvent(0, EB_NoInterrupt);

		} else if (sarai->mCurAnim->mType == KEYEVENT_3) {
			sarai->fallMeckGround();

		} else if (sarai->mCurAnim->mType == KEYEVENT_4) {
			sarai->disableEvent(0, EB_NoInterrupt);

		} else if (sarai->mCurAnim->mType == KEYEVENT_END) {
			transit(sarai, SARAI_Move, nullptr);
		}
	}
}

/*
 * --INFO--
 * Address:	80272438
 * Size:	000054
 */
void StateFallMeck::cleanup(EnemyBase* enemy)
{
	Obj* sarai = OBJ(enemy);
	sarai->disableEvent(0, EB_NoInterrupt);
	sarai->resetAttackableTimer(0.0f);
	sarai->setEmotionCaution();
}

} // namespace Sarai
} // namespace Game
