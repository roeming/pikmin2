#include "types.h"
#include "Game/pelletMgr.h"
#include "Game/Entities/PelletFruit.h"
#include "Game/Entities/ItemPlant.h"
#include "Iterator.h"
#include "nans.h"

#define MAX_FRUIT_COUNT     64
#define MAX_FRUIT_COLLPARTS 128

namespace Game {

/*
 * --INFO--
 * Address:	801FD9B8
 * Size:	000070
 */
void PelletFruit::Object::do_onInit(CreatureInitArg* arg)
{
	if (gameSystem->mMode == GSM_STORY_MODE && gameSystem->mSection->getCurrentCourseInfo()) {
		mRottingTimer = ItemPlant::mgr->mParms->mPlantParms.mP005;
	} else {
		mRottingTimer = 100.0f;
	}
}

/*
 * --INFO--
 * Address:	801FDA28
 * Size:	000180
 */
void PelletFruit::Object::do_update()
{
	/*
	stwu     r1, -0x50(r1)
	mflr     r0
	stw      r0, 0x54(r1)
	stw      r31, 0x4c(r1)
	mr       r31, r3
	lwz      r0, 0xf0(r3)
	cmplwi   r0, 0
	bne      lbl_801FDB94
	lwz      r0, 0xb8(r31)
	cmplwi   r0, 0
	bne      lbl_801FDB94
	bl       getStateID__Q24Game6PelletFv
	cmpwi    r3, 1
	beq      lbl_801FDB94
	lwz      r3, sys@sda21(r13)
	lfs      f2, 0x458(r31)
	lfs      f1, 0x54(r3)
	lfs      f0, lbl_80519D0C@sda21(r2)
	fsubs    f1, f2, f1
	stfs     f1, 0x458(r31)
	lfs      f1, 0x458(r31)
	fcmpo    cr0, f1, f0
	cror     2, 0, 2
	bne      lbl_801FDB94
	mr       r4, r31
	addi     r3, r1, 8
	lwz      r12, 0(r31)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	lfs      f2, 8(r1)
	lis      r3, __vt__Q23efx3Arg@ha
	lfs      f1, 0xc(r1)
	addi     r0, r3, __vt__Q23efx3Arg@l
	lfs      f0, 0x10(r1)
	stw      r0, 0x34(r1)
	stfs     f2, 0x38(r1)
	stfs     f1, 0x3c(r1)
	stfs     f0, 0x40(r1)
	lhz      r0, 0x43e(r31)
	cmplwi   r0, 0
	bne      lbl_801FDB20
	lis      r3, __vt__Q23efx5TBase@ha
	li       r5, 0
	addi     r0, r3, __vt__Q23efx5TBase@l
	lis      r3, __vt__Q23efx8TSimple2@ha
	stw      r0, 0x24(r1)
	addi     r0, r3, __vt__Q23efx8TSimple2@l
	lis      r3, __vt__Q23efx12TFruitsDownR@ha
	li       r4, 0x65
	stw      r0, 0x24(r1)
	addi     r0, r3, __vt__Q23efx12TFruitsDownR@l
	li       r6, 0x66
	addi     r3, r1, 0x24
	sth      r4, 0x28(r1)
	addi     r4, r1, 0x34
	sth      r6, 0x2a(r1)
	stw      r5, 0x2c(r1)
	stw      r5, 0x30(r1)
	stw      r0, 0x24(r1)
	bl       create__Q23efx8TSimple2FPQ23efx3Arg
	b        lbl_801FDB6C

lbl_801FDB20:
	lis      r3, __vt__Q23efx5TBase@ha
	li       r5, 0
	addi     r0, r3, __vt__Q23efx5TBase@l
	lis      r3, __vt__Q23efx8TSimple2@ha
	stw      r0, 0x14(r1)
	addi     r0, r3, __vt__Q23efx8TSimple2@l
	lis      r3, __vt__Q23efx12TFruitsDownP@ha
	li       r4, 0x63
	stw      r0, 0x14(r1)
	addi     r0, r3, __vt__Q23efx12TFruitsDownP@l
	li       r6, 0x64
	addi     r3, r1, 0x14
	sth      r4, 0x18(r1)
	addi     r4, r1, 0x34
	sth      r6, 0x1a(r1)
	stw      r5, 0x1c(r1)
	stw      r5, 0x20(r1)
	stw      r0, 0x14(r1)
	bl       create__Q23efx8TSimple2FPQ23efx3Arg

lbl_801FDB6C:
	lwz      r3, 0x330(r31)
	li       r4, 0x3842
	li       r5, 0
	lwz      r12, 0x28(r3)
	lwz      r12, 0x7c(r12)
	mtctr    r12
	bctrl
	mr       r3, r31
	li       r4, 0
	bl       kill__Q24Game8CreatureFPQ24Game15CreatureKillArg

lbl_801FDB94:
	lwz      r0, 0x54(r1)
	lwz      r31, 0x4c(r1)
	mtlr     r0
	addi     r1, r1, 0x50
	blr
	*/
}

/*
 * --INFO--
 * Address:	801FDBA8
 * Size:	00011C
 */
void PelletFruit::Object::changeMaterial()
{
	/*
	stwu     r1, -0x40(r1)
	mflr     r0
	li       r8, 0
	li       r5, 0xc0
	stw      r0, 0x44(r1)
	li       r12, 0x5c
	li       r11, 0x74
	li       r10, 0x96
	stmw     r25, 0x24(r1)
	li       r30, 0xff
	li       r29, 0x44
	mr       r31, r3
	li       r9, 0x6e
	li       r7, 0x14
	li       r6, 0x28
	stb      r5, 0x10(r1)
	addi     r27, r1, 0x11
	addi     r26, r1, 0x12
	stb      r29, 0x11(r1)
	addi     r25, r1, 0x13
	addi     r5, r1, 8
	stb      r29, 0x12(r1)
	lwz      r3, 0x174(r3)
	lhz      r0, 0x43e(r31)
	lwz      r3, 8(r3)
	stb      r30, 0x13(r1)
	slwi     r0, r0, 2
	lwz      r3, 4(r3)
	stb      r12, 0x14(r1)
	lwz      r4, 0x60(r3)
	addi     r3, r1, 0x10
	stb      r29, 0x15(r1)
	lwz      r28, 0(r4)
	li       r4, 0
	stb      r11, 0x16(r1)
	stb      r30, 0x17(r1)
	stb      r10, 0x18(r1)
	stb      r9, 0x19(r1)
	stb      r8, 0x1a(r1)
	stb      r30, 0x1b(r1)
	stb      r7, 0x1c(r1)
	stb      r8, 0x1d(r1)
	stb      r6, 0x1e(r1)
	stb      r30, 0x1f(r1)
	lbzx     r6, r27, r0
	lbzx     r7, r26, r0
	lbzx     r8, r25, r0
	lbzx     r0, r3, r0
	sth      r6, 0xa(r1)
	sth      r0, 8(r1)
	sth      r7, 0xc(r1)
	sth      r8, 0xe(r1)
	lwz      r3, 0x2c(r28)
	lwz      r12, 0(r3)
	lwz      r12, 0x64(r12)
	mtctr    r12
	bctrl
	lwz      r3, 0x174(r31)
	lwz      r3, 8(r3)
	lwz      r12, 0(r3)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	lwz      r3, 0x174(r31)
	lwz      r3, 8(r3)
	bl       diff__8J3DModelFv
	lmw      r25, 0x24(r1)
	lwz      r0, 0x44(r1)
	mtlr     r0
	addi     r1, r1, 0x40
	blr
	*/
}

/*
 * --INFO--
 * Address:	801FDCC4
 * Size:	0000B0
 */
PelletFruit::Mgr::Mgr()
    : FixedSizePelletMgr<Game::PelletFruit::Object>(PelletList::FRUIT)
{
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	stw      r0, 0x14(r1)
	extsh.   r0, r4
	stw      r31, 0xc(r1)
	stw      r30, 8(r1)
	mr       r30, r3
	beq      lbl_801FDCEC
	addi     r0, r30, 0xa0
	stw      r0, 4(r30)

lbl_801FDCEC:
	mr       r3, r30
	li       r4, 0
	li       r5, 2
	bl       __ct__Q24Game13BasePelletMgrFQ34Game10PelletList5cKind
	addi     r31, r30, 0x54
	mr       r3, r31
	bl       __ct__5CNodeFv
	lis      r3, __vt__16GenericContainer@ha
	lis      r4, "__vt__38Container<Q34Game11PelletFruit6Object>"@ha
	addi     r0, r3, __vt__16GenericContainer@l
	lis      r3,
"__vt__Q24Game47FixedSizePelletMgr<Q34Game11PelletFruit6Object>"@ha stw      r0,
0(r31) addi     r0, r4, "__vt__38Container<Q34Game11PelletFruit6Object>"@l addi
r4, r3, "__vt__Q24Game47FixedSizePelletMgr<Q34Game11PelletFruit6Object>"@l li
r5, 0 stw      r0, 0(r31) addi     r0, r4, 0x98 addi     r3, r30, 0x70 stb r5,
0x18(r31) stw      r4, 0(r30) stw      r0, 0x54(r30) bl
"__ct__42MonoObjectMgr<Q34Game11PelletFruit6Object>Fv" lis      r4,
__vt__Q34Game11PelletFruit3Mgr@ha mr       r3, r30 addi     r4, r4,
__vt__Q34Game11PelletFruit3Mgr@l stw      r4, 0(r30) addi     r0, r4, 0x98 stw
r0, 0x54(r30) lwz      r31, 0xc(r1) lwz      r30, 8(r1) lwz      r0, 0x14(r1)
	mtlr     r0
	addi     r1, r1, 0x10
	blr
	*/
}

/*
 * --INFO--
 * Address:	801FE020
 * Size:	00008C
 */
void PelletFruit::Mgr::setupResources()
{
	sys->heapStatusStart("PelletFruit", nullptr);
	alloc(MAX_FRUIT_COUNT);
	load();
	mCollPartMgr.alloc(MAX_FRUIT_COLLPARTS);
	sys->heapStatusEnd("PelletFruit");
}

/*
 * --INFO--
 * Address:	801FE0AC
 * Size:	00006C
 */
void PelletFruit::Mgr::onCreateModel(SysShape::Model* model)
{
	model->mJ3dModel->newDifferedDisplayList(0x1000000);
	model->mJ3dModel->calc();
	model->mJ3dModel->calcMaterial();
	model->mJ3dModel->makeDL();
	model->mJ3dModel->lock();
}

} // namespace Game
