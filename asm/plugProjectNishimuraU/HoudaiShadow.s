.include "macros.inc"
.section .rodata  # 0x804732E0 - 0x8049E220
.balign 0x8
.global lbl_8048B030
lbl_8048B030:
	.asciz "246-HoudaiShadow"
	.skip 3
	.asciz "rhand1jnt"
	.skip 2
	.asciz "rhand2jnt"
	.skip 2
	.asciz "rhand3jnt"
	.skip 2
	.asciz "lhand1jnt"
	.skip 2
	.asciz "lhand2jnt"
	.skip 2
	.asciz "lhand3jnt"
	.skip 2
	.asciz "rfoot1jnt"
	.skip 2
	.asciz "rfoot2jnt"
	.skip 2
	.asciz "rfoot3jnt"
	.skip 2
	.asciz "lfoot1jnt"
	.skip 2
	.asciz "lfoot2jnt"
	.skip 2
	.asciz "lfoot3jnt"
	.skip 2

.section .text, "ax"  # 0x800056C0 - 0x80472F00
.global __ct__Q34Game6Houdai15HoudaiShadowMgrFPQ34Game6Houdai3Obj
__ct__Q34Game6Houdai15HoudaiShadowMgrFPQ34Game6Houdai3Obj:
/* 802BF47C 002BC3BC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 802BF480 002BC3C0  7C 08 02 A6 */	mflr r0
/* 802BF484 002BC3C4  90 01 00 24 */	stw r0, 0x24(r1)
/* 802BF488 002BC3C8  BF 61 00 0C */	stmw r27, 0xc(r1)
/* 802BF48C 002BC3CC  7C 9B 23 78 */	mr r27, r4
/* 802BF490 002BC3D0  7C 7C 1B 78 */	mr r28, r3
/* 802BF494 002BC3D4  93 63 00 04 */	stw r27, 4(r3)
/* 802BF498 002BC3D8  38 60 00 20 */	li r3, 0x20
/* 802BF49C 002BC3DC  4B D6 4A 09 */	bl __nw__FUl
/* 802BF4A0 002BC3E0  7C 60 1B 79 */	or. r0, r3, r3
/* 802BF4A4 002BC3E4  41 82 00 10 */	beq lbl_802BF4B4
/* 802BF4A8 002BC3E8  7F 64 DB 78 */	mr r4, r27
/* 802BF4AC 002BC3EC  4B F8 1D D1 */	bl __ct__Q24Game19JointShadowRootNodeFPQ24Game8Creature
/* 802BF4B0 002BC3F0  7C 60 1B 78 */	mr r0, r3
lbl_802BF4B4:
/* 802BF4B4 002BC3F4  90 1C 00 48 */	stw r0, 0x48(r28)
/* 802BF4B8 002BC3F8  38 60 00 24 */	li r3, 0x24
/* 802BF4BC 002BC3FC  4B D6 49 E9 */	bl __nw__FUl
/* 802BF4C0 002BC400  7C 7B 1B 79 */	or. r27, r3, r3
/* 802BF4C4 002BC404  41 82 00 18 */	beq lbl_802BF4DC
/* 802BF4C8 002BC408  38 80 00 02 */	li r4, 2
/* 802BF4CC 002BC40C  4B F8 1E 11 */	bl __ct__Q24Game15JointShadowNodeFi
/* 802BF4D0 002BC410  3C 60 80 4D */	lis r3, __vt__Q24Game16SphereShadowNode@ha
/* 802BF4D4 002BC414  38 03 DE D8 */	addi r0, r3, __vt__Q24Game16SphereShadowNode@l
/* 802BF4D8 002BC418  90 1B 00 00 */	stw r0, 0(r27)
lbl_802BF4DC:
/* 802BF4DC 002BC41C  93 7C 00 8C */	stw r27, 0x8c(r28)
/* 802BF4E0 002BC420  80 7C 00 48 */	lwz r3, 0x48(r28)
/* 802BF4E4 002BC424  80 9C 00 8C */	lwz r4, 0x8c(r28)
/* 802BF4E8 002BC428  48 15 1F 21 */	bl add__5CNodeFP5CNode
/* 802BF4EC 002BC42C  38 60 00 24 */	li r3, 0x24
/* 802BF4F0 002BC430  4B D6 49 B5 */	bl __nw__FUl
/* 802BF4F4 002BC434  7C 7B 1B 79 */	or. r27, r3, r3
/* 802BF4F8 002BC438  41 82 00 18 */	beq lbl_802BF510
/* 802BF4FC 002BC43C  38 80 00 02 */	li r4, 2
/* 802BF500 002BC440  4B F8 1D DD */	bl __ct__Q24Game15JointShadowNodeFi
/* 802BF504 002BC444  3C 60 80 4D */	lis r3, __vt__Q24Game16SphereShadowNode@ha
/* 802BF508 002BC448  38 03 DE D8 */	addi r0, r3, __vt__Q24Game16SphereShadowNode@l
/* 802BF50C 002BC44C  90 1B 00 00 */	stw r0, 0(r27)
lbl_802BF510:
/* 802BF510 002BC450  93 7C 00 C0 */	stw r27, 0xc0(r28)
/* 802BF514 002BC454  80 7C 00 48 */	lwz r3, 0x48(r28)
/* 802BF518 002BC458  80 9C 00 C0 */	lwz r4, 0xc0(r28)
/* 802BF51C 002BC45C  48 15 1E ED */	bl add__5CNodeFP5CNode
/* 802BF520 002BC460  7F 9F E3 78 */	mr r31, r28
/* 802BF524 002BC464  7F 9E E3 78 */	mr r30, r28
/* 802BF528 002BC468  3B A0 00 00 */	li r29, 0
lbl_802BF52C:
/* 802BF52C 002BC46C  38 60 00 28 */	li r3, 0x28
/* 802BF530 002BC470  4B D6 49 75 */	bl __nw__FUl
/* 802BF534 002BC474  7C 7B 1B 79 */	or. r27, r3, r3
/* 802BF538 002BC478  41 82 00 20 */	beq lbl_802BF558
/* 802BF53C 002BC47C  38 80 00 02 */	li r4, 2
/* 802BF540 002BC480  4B F8 1D 9D */	bl __ct__Q24Game15JointShadowNodeFi
/* 802BF544 002BC484  3C 60 80 4D */	lis r3, __vt__Q24Game17TubeShadowSetNode@ha
/* 802BF548 002BC488  38 00 00 00 */	li r0, 0
/* 802BF54C 002BC48C  38 63 DE B8 */	addi r3, r3, __vt__Q24Game17TubeShadowSetNode@l
/* 802BF550 002BC490  90 7B 00 00 */	stw r3, 0(r27)
/* 802BF554 002BC494  90 1B 00 24 */	stw r0, 0x24(r27)
lbl_802BF558:
/* 802BF558 002BC498  93 7F 00 4C */	stw r27, 0x4c(r31)
/* 802BF55C 002BC49C  38 60 00 28 */	li r3, 0x28
/* 802BF560 002BC4A0  4B D6 49 45 */	bl __nw__FUl
/* 802BF564 002BC4A4  7C 7B 1B 79 */	or. r27, r3, r3
/* 802BF568 002BC4A8  41 82 00 20 */	beq lbl_802BF588
/* 802BF56C 002BC4AC  38 80 00 02 */	li r4, 2
/* 802BF570 002BC4B0  4B F8 1D 6D */	bl __ct__Q24Game15JointShadowNodeFi
/* 802BF574 002BC4B4  3C 60 80 4D */	lis r3, __vt__Q24Game17TubeShadowSetNode@ha
/* 802BF578 002BC4B8  38 00 00 00 */	li r0, 0
/* 802BF57C 002BC4BC  38 63 DE B8 */	addi r3, r3, __vt__Q24Game17TubeShadowSetNode@l
/* 802BF580 002BC4C0  90 7B 00 00 */	stw r3, 0(r27)
/* 802BF584 002BC4C4  90 1B 00 24 */	stw r0, 0x24(r27)
lbl_802BF588:
/* 802BF588 002BC4C8  93 7F 00 5C */	stw r27, 0x5c(r31)
/* 802BF58C 002BC4CC  38 60 00 28 */	li r3, 0x28
/* 802BF590 002BC4D0  4B D6 49 15 */	bl __nw__FUl
/* 802BF594 002BC4D4  7C 7B 1B 79 */	or. r27, r3, r3
/* 802BF598 002BC4D8  41 82 00 20 */	beq lbl_802BF5B8
/* 802BF59C 002BC4DC  38 80 00 02 */	li r4, 2
/* 802BF5A0 002BC4E0  4B F8 1D 3D */	bl __ct__Q24Game15JointShadowNodeFi
/* 802BF5A4 002BC4E4  3C 60 80 4D */	lis r3, __vt__Q24Game17TubeShadowSetNode@ha
/* 802BF5A8 002BC4E8  38 00 00 00 */	li r0, 0
/* 802BF5AC 002BC4EC  38 63 DE B8 */	addi r3, r3, __vt__Q24Game17TubeShadowSetNode@l
/* 802BF5B0 002BC4F0  90 7B 00 00 */	stw r3, 0(r27)
/* 802BF5B4 002BC4F4  90 1B 00 24 */	stw r0, 0x24(r27)
lbl_802BF5B8:
/* 802BF5B8 002BC4F8  93 7F 00 6C */	stw r27, 0x6c(r31)
/* 802BF5BC 002BC4FC  38 60 00 28 */	li r3, 0x28
/* 802BF5C0 002BC500  4B D6 48 E5 */	bl __nw__FUl
/* 802BF5C4 002BC504  7C 7B 1B 79 */	or. r27, r3, r3
/* 802BF5C8 002BC508  41 82 00 20 */	beq lbl_802BF5E8
/* 802BF5CC 002BC50C  38 80 00 02 */	li r4, 2
/* 802BF5D0 002BC510  4B F8 1D 0D */	bl __ct__Q24Game15JointShadowNodeFi
/* 802BF5D4 002BC514  3C 60 80 4D */	lis r3, __vt__Q24Game17TubeShadowSetNode@ha
/* 802BF5D8 002BC518  38 00 00 00 */	li r0, 0
/* 802BF5DC 002BC51C  38 63 DE B8 */	addi r3, r3, __vt__Q24Game17TubeShadowSetNode@l
/* 802BF5E0 002BC520  90 7B 00 00 */	stw r3, 0(r27)
/* 802BF5E4 002BC524  90 1B 00 24 */	stw r0, 0x24(r27)
lbl_802BF5E8:
/* 802BF5E8 002BC528  93 7F 00 7C */	stw r27, 0x7c(r31)
/* 802BF5EC 002BC52C  38 60 00 24 */	li r3, 0x24
/* 802BF5F0 002BC530  4B D6 48 B5 */	bl __nw__FUl
/* 802BF5F4 002BC534  7C 7B 1B 79 */	or. r27, r3, r3
/* 802BF5F8 002BC538  41 82 00 18 */	beq lbl_802BF610
/* 802BF5FC 002BC53C  38 80 00 02 */	li r4, 2
/* 802BF600 002BC540  4B F8 1C DD */	bl __ct__Q24Game15JointShadowNodeFi
/* 802BF604 002BC544  3C 60 80 4D */	lis r3, __vt__Q24Game16SphereShadowNode@ha
/* 802BF608 002BC548  38 03 DE D8 */	addi r0, r3, __vt__Q24Game16SphereShadowNode@l
/* 802BF60C 002BC54C  90 1B 00 00 */	stw r0, 0(r27)
lbl_802BF610:
/* 802BF610 002BC550  93 7F 00 90 */	stw r27, 0x90(r31)
/* 802BF614 002BC554  38 60 00 24 */	li r3, 0x24
/* 802BF618 002BC558  4B D6 48 8D */	bl __nw__FUl
/* 802BF61C 002BC55C  7C 7B 1B 79 */	or. r27, r3, r3
/* 802BF620 002BC560  41 82 00 18 */	beq lbl_802BF638
/* 802BF624 002BC564  38 80 00 02 */	li r4, 2
/* 802BF628 002BC568  4B F8 1C B5 */	bl __ct__Q24Game15JointShadowNodeFi
/* 802BF62C 002BC56C  3C 60 80 4D */	lis r3, __vt__Q24Game16SphereShadowNode@ha
/* 802BF630 002BC570  38 03 DE D8 */	addi r0, r3, __vt__Q24Game16SphereShadowNode@l
/* 802BF634 002BC574  90 1B 00 00 */	stw r0, 0(r27)
lbl_802BF638:
/* 802BF638 002BC578  93 7F 00 A0 */	stw r27, 0xa0(r31)
/* 802BF63C 002BC57C  38 60 00 24 */	li r3, 0x24
/* 802BF640 002BC580  4B D6 48 65 */	bl __nw__FUl
/* 802BF644 002BC584  7C 7B 1B 79 */	or. r27, r3, r3
/* 802BF648 002BC588  41 82 00 18 */	beq lbl_802BF660
/* 802BF64C 002BC58C  38 80 00 02 */	li r4, 2
/* 802BF650 002BC590  4B F8 1C 8D */	bl __ct__Q24Game15JointShadowNodeFi
/* 802BF654 002BC594  3C 60 80 4D */	lis r3, __vt__Q24Game16SphereShadowNode@ha
/* 802BF658 002BC598  38 03 DE D8 */	addi r0, r3, __vt__Q24Game16SphereShadowNode@l
/* 802BF65C 002BC59C  90 1B 00 00 */	stw r0, 0(r27)
lbl_802BF660:
/* 802BF660 002BC5A0  93 7F 00 B0 */	stw r27, 0xb0(r31)
/* 802BF664 002BC5A4  80 7C 00 48 */	lwz r3, 0x48(r28)
/* 802BF668 002BC5A8  80 9F 00 4C */	lwz r4, 0x4c(r31)
/* 802BF66C 002BC5AC  48 15 1D 9D */	bl add__5CNodeFP5CNode
/* 802BF670 002BC5B0  80 7C 00 48 */	lwz r3, 0x48(r28)
/* 802BF674 002BC5B4  80 9F 00 5C */	lwz r4, 0x5c(r31)
/* 802BF678 002BC5B8  48 15 1D 91 */	bl add__5CNodeFP5CNode
/* 802BF67C 002BC5BC  80 7C 00 48 */	lwz r3, 0x48(r28)
/* 802BF680 002BC5C0  80 9F 00 6C */	lwz r4, 0x6c(r31)
/* 802BF684 002BC5C4  48 15 1D 85 */	bl add__5CNodeFP5CNode
/* 802BF688 002BC5C8  80 7C 00 48 */	lwz r3, 0x48(r28)
/* 802BF68C 002BC5CC  80 9F 00 7C */	lwz r4, 0x7c(r31)
/* 802BF690 002BC5D0  48 15 1D 79 */	bl add__5CNodeFP5CNode
/* 802BF694 002BC5D4  80 7C 00 48 */	lwz r3, 0x48(r28)
/* 802BF698 002BC5D8  80 9F 00 90 */	lwz r4, 0x90(r31)
/* 802BF69C 002BC5DC  48 15 1D 6D */	bl add__5CNodeFP5CNode
/* 802BF6A0 002BC5E0  80 7C 00 48 */	lwz r3, 0x48(r28)
/* 802BF6A4 002BC5E4  80 9F 00 A0 */	lwz r4, 0xa0(r31)
/* 802BF6A8 002BC5E8  48 15 1D 61 */	bl add__5CNodeFP5CNode
/* 802BF6AC 002BC5EC  80 7C 00 48 */	lwz r3, 0x48(r28)
/* 802BF6B0 002BC5F0  80 9F 00 B0 */	lwz r4, 0xb0(r31)
/* 802BF6B4 002BC5F4  48 15 1D 55 */	bl add__5CNodeFP5CNode
/* 802BF6B8 002BC5F8  38 00 00 00 */	li r0, 0
/* 802BF6BC 002BC5FC  3B BD 00 01 */	addi r29, r29, 1
/* 802BF6C0 002BC600  90 1E 00 08 */	stw r0, 8(r30)
/* 802BF6C4 002BC604  2C 1D 00 04 */	cmpwi r29, 4
/* 802BF6C8 002BC608  3B FF 00 04 */	addi r31, r31, 4
/* 802BF6CC 002BC60C  90 1E 00 0C */	stw r0, 0xc(r30)
/* 802BF6D0 002BC610  90 1E 00 10 */	stw r0, 0x10(r30)
/* 802BF6D4 002BC614  90 1E 00 14 */	stw r0, 0x14(r30)
/* 802BF6D8 002BC618  3B DE 00 10 */	addi r30, r30, 0x10
/* 802BF6DC 002BC61C  41 80 FE 50 */	blt lbl_802BF52C
/* 802BF6E0 002BC620  7F 83 E3 78 */	mr r3, r28
/* 802BF6E4 002BC624  BB 61 00 0C */	lmw r27, 0xc(r1)
/* 802BF6E8 002BC628  80 01 00 24 */	lwz r0, 0x24(r1)
/* 802BF6EC 002BC62C  7C 08 03 A6 */	mtlr r0
/* 802BF6F0 002BC630  38 21 00 20 */	addi r1, r1, 0x20
/* 802BF6F4 002BC634  4E 80 00 20 */	blr 

.global init__Q34Game6Houdai15HoudaiShadowMgrFv
init__Q34Game6Houdai15HoudaiShadowMgrFv:
/* 802BF6F8 002BC638  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 802BF6FC 002BC63C  7C 08 02 A6 */	mflr r0
/* 802BF700 002BC640  3C 80 80 49 */	lis r4, lbl_8048B030@ha
/* 802BF704 002BC644  90 01 00 24 */	stw r0, 0x24(r1)
/* 802BF708 002BC648  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 802BF70C 002BC64C  3B E4 B0 30 */	addi r31, r4, lbl_8048B030@l
/* 802BF710 002BC650  38 82 E1 50 */	addi r4, r2, lbl_8051C4B0@sda21
/* 802BF714 002BC654  93 C1 00 18 */	stw r30, 0x18(r1)
/* 802BF718 002BC658  93 A1 00 14 */	stw r29, 0x14(r1)
/* 802BF71C 002BC65C  7C 7D 1B 78 */	mr r29, r3
/* 802BF720 002BC660  80 63 00 04 */	lwz r3, 4(r3)
/* 802BF724 002BC664  83 C3 01 74 */	lwz r30, 0x174(r3)
/* 802BF728 002BC668  7F C3 F3 78 */	mr r3, r30
/* 802BF72C 002BC66C  48 17 F8 B9 */	bl getJoint__Q28SysShape5ModelFPc
/* 802BF730 002BC670  48 16 A1 71 */	bl getWorldMatrix__Q28SysShape5JointFv
/* 802BF734 002BC674  90 7D 00 00 */	stw r3, 0(r29)
/* 802BF738 002BC678  7F C3 F3 78 */	mr r3, r30
/* 802BF73C 002BC67C  38 9F 00 14 */	addi r4, r31, 0x14
/* 802BF740 002BC680  48 17 F8 A5 */	bl getJoint__Q28SysShape5ModelFPc
/* 802BF744 002BC684  80 BD 00 4C */	lwz r5, 0x4c(r29)
/* 802BF748 002BC688  38 9F 00 14 */	addi r4, r31, 0x14
/* 802BF74C 002BC68C  90 65 00 24 */	stw r3, 0x24(r5)
/* 802BF750 002BC690  7F C3 F3 78 */	mr r3, r30
/* 802BF754 002BC694  48 17 F8 91 */	bl getJoint__Q28SysShape5ModelFPc
/* 802BF758 002BC698  80 BD 00 4C */	lwz r5, 0x4c(r29)
/* 802BF75C 002BC69C  38 9F 00 14 */	addi r4, r31, 0x14
/* 802BF760 002BC6A0  90 65 00 24 */	stw r3, 0x24(r5)
/* 802BF764 002BC6A4  7F C3 F3 78 */	mr r3, r30
/* 802BF768 002BC6A8  48 17 F8 7D */	bl getJoint__Q28SysShape5ModelFPc
/* 802BF76C 002BC6AC  80 BD 00 5C */	lwz r5, 0x5c(r29)
/* 802BF770 002BC6B0  38 9F 00 20 */	addi r4, r31, 0x20
/* 802BF774 002BC6B4  90 65 00 24 */	stw r3, 0x24(r5)
/* 802BF778 002BC6B8  7F C3 F3 78 */	mr r3, r30
/* 802BF77C 002BC6BC  48 17 F8 69 */	bl getJoint__Q28SysShape5ModelFPc
/* 802BF780 002BC6C0  80 BD 00 6C */	lwz r5, 0x6c(r29)
/* 802BF784 002BC6C4  38 9F 00 2C */	addi r4, r31, 0x2c
/* 802BF788 002BC6C8  90 65 00 24 */	stw r3, 0x24(r5)
/* 802BF78C 002BC6CC  7F C3 F3 78 */	mr r3, r30
/* 802BF790 002BC6D0  48 17 F8 55 */	bl getJoint__Q28SysShape5ModelFPc
/* 802BF794 002BC6D4  80 BD 00 7C */	lwz r5, 0x7c(r29)
/* 802BF798 002BC6D8  38 9F 00 38 */	addi r4, r31, 0x38
/* 802BF79C 002BC6DC  90 65 00 24 */	stw r3, 0x24(r5)
/* 802BF7A0 002BC6E0  7F C3 F3 78 */	mr r3, r30
/* 802BF7A4 002BC6E4  48 17 F8 41 */	bl getJoint__Q28SysShape5ModelFPc
/* 802BF7A8 002BC6E8  80 BD 00 50 */	lwz r5, 0x50(r29)
/* 802BF7AC 002BC6EC  38 9F 00 38 */	addi r4, r31, 0x38
/* 802BF7B0 002BC6F0  90 65 00 24 */	stw r3, 0x24(r5)
/* 802BF7B4 002BC6F4  7F C3 F3 78 */	mr r3, r30
/* 802BF7B8 002BC6F8  48 17 F8 2D */	bl getJoint__Q28SysShape5ModelFPc
/* 802BF7BC 002BC6FC  80 BD 00 60 */	lwz r5, 0x60(r29)
/* 802BF7C0 002BC700  38 9F 00 44 */	addi r4, r31, 0x44
/* 802BF7C4 002BC704  90 65 00 24 */	stw r3, 0x24(r5)
/* 802BF7C8 002BC708  7F C3 F3 78 */	mr r3, r30
/* 802BF7CC 002BC70C  48 17 F8 19 */	bl getJoint__Q28SysShape5ModelFPc
/* 802BF7D0 002BC710  80 BD 00 70 */	lwz r5, 0x70(r29)
/* 802BF7D4 002BC714  38 9F 00 50 */	addi r4, r31, 0x50
/* 802BF7D8 002BC718  90 65 00 24 */	stw r3, 0x24(r5)
/* 802BF7DC 002BC71C  7F C3 F3 78 */	mr r3, r30
/* 802BF7E0 002BC720  48 17 F8 05 */	bl getJoint__Q28SysShape5ModelFPc
/* 802BF7E4 002BC724  80 BD 00 80 */	lwz r5, 0x80(r29)
/* 802BF7E8 002BC728  38 9F 00 5C */	addi r4, r31, 0x5c
/* 802BF7EC 002BC72C  90 65 00 24 */	stw r3, 0x24(r5)
/* 802BF7F0 002BC730  7F C3 F3 78 */	mr r3, r30
/* 802BF7F4 002BC734  48 17 F7 F1 */	bl getJoint__Q28SysShape5ModelFPc
/* 802BF7F8 002BC738  80 BD 00 54 */	lwz r5, 0x54(r29)
/* 802BF7FC 002BC73C  38 9F 00 5C */	addi r4, r31, 0x5c
/* 802BF800 002BC740  90 65 00 24 */	stw r3, 0x24(r5)
/* 802BF804 002BC744  7F C3 F3 78 */	mr r3, r30
/* 802BF808 002BC748  48 17 F7 DD */	bl getJoint__Q28SysShape5ModelFPc
/* 802BF80C 002BC74C  80 BD 00 64 */	lwz r5, 0x64(r29)
/* 802BF810 002BC750  38 9F 00 68 */	addi r4, r31, 0x68
/* 802BF814 002BC754  90 65 00 24 */	stw r3, 0x24(r5)
/* 802BF818 002BC758  7F C3 F3 78 */	mr r3, r30
/* 802BF81C 002BC75C  48 17 F7 C9 */	bl getJoint__Q28SysShape5ModelFPc
/* 802BF820 002BC760  80 BD 00 74 */	lwz r5, 0x74(r29)
/* 802BF824 002BC764  38 9F 00 74 */	addi r4, r31, 0x74
/* 802BF828 002BC768  90 65 00 24 */	stw r3, 0x24(r5)
/* 802BF82C 002BC76C  7F C3 F3 78 */	mr r3, r30
/* 802BF830 002BC770  48 17 F7 B5 */	bl getJoint__Q28SysShape5ModelFPc
/* 802BF834 002BC774  80 BD 00 84 */	lwz r5, 0x84(r29)
/* 802BF838 002BC778  38 9F 00 80 */	addi r4, r31, 0x80
/* 802BF83C 002BC77C  90 65 00 24 */	stw r3, 0x24(r5)
/* 802BF840 002BC780  7F C3 F3 78 */	mr r3, r30
/* 802BF844 002BC784  48 17 F7 A1 */	bl getJoint__Q28SysShape5ModelFPc
/* 802BF848 002BC788  80 BD 00 58 */	lwz r5, 0x58(r29)
/* 802BF84C 002BC78C  38 9F 00 80 */	addi r4, r31, 0x80
/* 802BF850 002BC790  90 65 00 24 */	stw r3, 0x24(r5)
/* 802BF854 002BC794  7F C3 F3 78 */	mr r3, r30
/* 802BF858 002BC798  48 17 F7 8D */	bl getJoint__Q28SysShape5ModelFPc
/* 802BF85C 002BC79C  80 BD 00 68 */	lwz r5, 0x68(r29)
/* 802BF860 002BC7A0  38 9F 00 8C */	addi r4, r31, 0x8c
/* 802BF864 002BC7A4  90 65 00 24 */	stw r3, 0x24(r5)
/* 802BF868 002BC7A8  7F C3 F3 78 */	mr r3, r30
/* 802BF86C 002BC7AC  48 17 F7 79 */	bl getJoint__Q28SysShape5ModelFPc
/* 802BF870 002BC7B0  80 BD 00 78 */	lwz r5, 0x78(r29)
/* 802BF874 002BC7B4  38 9F 00 98 */	addi r4, r31, 0x98
/* 802BF878 002BC7B8  90 65 00 24 */	stw r3, 0x24(r5)
/* 802BF87C 002BC7BC  7F C3 F3 78 */	mr r3, r30
/* 802BF880 002BC7C0  48 17 F7 65 */	bl getJoint__Q28SysShape5ModelFPc
/* 802BF884 002BC7C4  80 9D 00 88 */	lwz r4, 0x88(r29)
/* 802BF888 002BC7C8  90 64 00 24 */	stw r3, 0x24(r4)
/* 802BF88C 002BC7CC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 802BF890 002BC7D0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 802BF894 002BC7D4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 802BF898 002BC7D8  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 802BF89C 002BC7DC  7C 08 03 A6 */	mtlr r0
/* 802BF8A0 002BC7E0  38 21 00 20 */	addi r1, r1, 0x20
/* 802BF8A4 002BC7E4  4E 80 00 20 */	blr 

.global "setJointPosPtr__Q34Game6Houdai15HoudaiShadowMgrFiiP10Vector3<f>"
"setJointPosPtr__Q34Game6Houdai15HoudaiShadowMgrFiiP10Vector3<f>":
/* 802BF8A8 002BC7E8  54 84 20 36 */	slwi r4, r4, 4
/* 802BF8AC 002BC7EC  54 A0 10 3A */	slwi r0, r5, 2
/* 802BF8B0 002BC7F0  7C 63 22 14 */	add r3, r3, r4
/* 802BF8B4 002BC7F4  7C 63 02 14 */	add r3, r3, r0
/* 802BF8B8 002BC7F8  90 C3 00 08 */	stw r6, 8(r3)
/* 802BF8BC 002BC7FC  4E 80 00 20 */	blr 

.global update__Q34Game6Houdai15HoudaiShadowMgrFv
update__Q34Game6Houdai15HoudaiShadowMgrFv:
/* 802BF8C0 002BC800  94 21 FF 00 */	stwu r1, -0x100(r1)
/* 802BF8C4 002BC804  7C 08 02 A6 */	mflr r0
/* 802BF8C8 002BC808  90 01 01 04 */	stw r0, 0x104(r1)
/* 802BF8CC 002BC80C  DB E1 00 F0 */	stfd f31, 0xf0(r1)
/* 802BF8D0 002BC810  F3 E1 00 F8 */	psq_st f31, 248(r1), 0, qr0
/* 802BF8D4 002BC814  DB C1 00 E0 */	stfd f30, 0xe0(r1)
/* 802BF8D8 002BC818  F3 C1 00 E8 */	psq_st f30, 232(r1), 0, qr0
/* 802BF8DC 002BC81C  DB A1 00 D0 */	stfd f29, 0xd0(r1)
/* 802BF8E0 002BC820  F3 A1 00 D8 */	psq_st f29, 216(r1), 0, qr0
/* 802BF8E4 002BC824  DB 81 00 C0 */	stfd f28, 0xc0(r1)
/* 802BF8E8 002BC828  F3 81 00 C8 */	psq_st f28, 200(r1), 0, qr0
/* 802BF8EC 002BC82C  DB 61 00 B0 */	stfd f27, 0xb0(r1)
/* 802BF8F0 002BC830  F3 61 00 B8 */	psq_st f27, 184(r1), 0, qr0
/* 802BF8F4 002BC834  DB 41 00 A0 */	stfd f26, 0xa0(r1)
/* 802BF8F8 002BC838  F3 41 00 A8 */	psq_st f26, 168(r1), 0, qr0
/* 802BF8FC 002BC83C  BF 21 00 84 */	stmw r25, 0x84(r1)
/* 802BF900 002BC840  7C 79 1B 78 */	mr r25, r3
/* 802BF904 002BC844  38 61 00 08 */	addi r3, r1, 8
/* 802BF908 002BC848  80 99 00 04 */	lwz r4, 4(r25)
/* 802BF90C 002BC84C  48 00 16 31 */	bl getTraceCentrePosition__Q34Game6Houdai3ObjFv
/* 802BF910 002BC850  C0 62 E1 58 */	lfs f3, lbl_8051C4B8@sda21(r2)
/* 802BF914 002BC854  C0 42 E1 5C */	lfs f2, lbl_8051C4BC@sda21(r2)
/* 802BF918 002BC858  ED 03 00 F2 */	fmuls f8, f3, f3
/* 802BF91C 002BC85C  C0 C1 00 08 */	lfs f6, 8(r1)
/* 802BF920 002BC860  EC E2 00 B2 */	fmuls f7, f2, f2
/* 802BF924 002BC864  C0 A1 00 0C */	lfs f5, 0xc(r1)
/* 802BF928 002BC868  C0 81 00 10 */	lfs f4, 0x10(r1)
/* 802BF92C 002BC86C  C0 22 E1 60 */	lfs f1, lbl_8051C4C0@sda21(r2)
/* 802BF930 002BC870  EC 08 38 2A */	fadds f0, f8, f7
/* 802BF934 002BC874  D0 C1 00 50 */	stfs f6, 0x50(r1)
/* 802BF938 002BC878  D0 A1 00 54 */	stfs f5, 0x54(r1)
/* 802BF93C 002BC87C  EC 08 00 2A */	fadds f0, f8, f0
/* 802BF940 002BC880  D0 81 00 58 */	stfs f4, 0x58(r1)
/* 802BF944 002BC884  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 802BF948 002BC888  D0 61 00 5C */	stfs f3, 0x5c(r1)
/* 802BF94C 002BC88C  D0 41 00 60 */	stfs f2, 0x60(r1)
/* 802BF950 002BC890  D0 61 00 64 */	stfs f3, 0x64(r1)
/* 802BF954 002BC894  40 81 00 20 */	ble lbl_802BF974
/* 802BF958 002BC898  EC 03 38 FA */	fmadds f0, f3, f3, f7
/* 802BF95C 002BC89C  EC 68 00 2A */	fadds f3, f8, f0
/* 802BF960 002BC8A0  FC 03 08 40 */	fcmpo cr0, f3, f1
/* 802BF964 002BC8A4  40 81 00 14 */	ble lbl_802BF978
/* 802BF968 002BC8A8  FC 00 18 34 */	frsqrte f0, f3
/* 802BF96C 002BC8AC  EC 60 00 F2 */	fmuls f3, f0, f3
/* 802BF970 002BC8B0  48 00 00 08 */	b lbl_802BF978
lbl_802BF974:
/* 802BF974 002BC8B4  FC 60 08 90 */	fmr f3, f1
lbl_802BF978:
/* 802BF978 002BC8B8  C0 02 E1 60 */	lfs f0, lbl_8051C4C0@sda21(r2)
/* 802BF97C 002BC8BC  FC 03 00 40 */	fcmpo cr0, f3, f0
/* 802BF980 002BC8C0  40 81 00 30 */	ble lbl_802BF9B0
/* 802BF984 002BC8C4  C0 02 E1 64 */	lfs f0, lbl_8051C4C4@sda21(r2)
/* 802BF988 002BC8C8  C0 41 00 5C */	lfs f2, 0x5c(r1)
/* 802BF98C 002BC8CC  EC 60 18 24 */	fdivs f3, f0, f3
/* 802BF990 002BC8D0  C0 21 00 60 */	lfs f1, 0x60(r1)
/* 802BF994 002BC8D4  C0 01 00 64 */	lfs f0, 0x64(r1)
/* 802BF998 002BC8D8  EC 42 00 F2 */	fmuls f2, f2, f3
/* 802BF99C 002BC8DC  EC 21 00 F2 */	fmuls f1, f1, f3
/* 802BF9A0 002BC8E0  EC 00 00 F2 */	fmuls f0, f0, f3
/* 802BF9A4 002BC8E4  D0 41 00 5C */	stfs f2, 0x5c(r1)
/* 802BF9A8 002BC8E8  D0 21 00 60 */	stfs f1, 0x60(r1)
/* 802BF9AC 002BC8EC  D0 01 00 64 */	stfs f0, 0x64(r1)
lbl_802BF9B0:
/* 802BF9B0 002BC8F0  80 79 00 00 */	lwz r3, 0(r25)
/* 802BF9B4 002BC8F4  38 81 00 50 */	addi r4, r1, 0x50
/* 802BF9B8 002BC8F8  C0 02 E1 68 */	lfs f0, lbl_8051C4C8@sda21(r2)
/* 802BF9BC 002BC8FC  38 A1 00 14 */	addi r5, r1, 0x14
/* 802BF9C0 002BC900  C0 23 00 1C */	lfs f1, 0x1c(r3)
/* 802BF9C4 002BC904  C0 A3 00 2C */	lfs f5, 0x2c(r3)
/* 802BF9C8 002BC908  C0 83 00 0C */	lfs f4, 0xc(r3)
/* 802BF9CC 002BC90C  EC 61 00 2A */	fadds f3, f1, f0
/* 802BF9D0 002BC910  C0 42 E1 60 */	lfs f2, lbl_8051C4C0@sda21(r2)
/* 802BF9D4 002BC914  D0 21 00 18 */	stfs f1, 0x18(r1)
/* 802BF9D8 002BC918  C0 22 E1 6C */	lfs f1, lbl_8051C4CC@sda21(r2)
/* 802BF9DC 002BC91C  C0 02 E1 70 */	lfs f0, lbl_8051C4D0@sda21(r2)
/* 802BF9E0 002BC920  D0 81 00 14 */	stfs f4, 0x14(r1)
/* 802BF9E4 002BC924  D0 A1 00 1C */	stfs f5, 0x1c(r1)
/* 802BF9E8 002BC928  D0 61 00 18 */	stfs f3, 0x18(r1)
/* 802BF9EC 002BC92C  D0 41 00 68 */	stfs f2, 0x68(r1)
/* 802BF9F0 002BC930  D0 41 00 6C */	stfs f2, 0x6c(r1)
/* 802BF9F4 002BC934  D0 21 00 70 */	stfs f1, 0x70(r1)
/* 802BF9F8 002BC938  D0 01 00 74 */	stfs f0, 0x74(r1)
/* 802BF9FC 002BC93C  80 79 00 8C */	lwz r3, 0x8c(r25)
/* 802BFA00 002BC940  48 03 2C DD */	bl "makeShadowSRT__Q24Game16SphereShadowNodeFRQ24Game15JointShadowParmR10Vector3<f>"
/* 802BFA04 002BC944  C3 42 E1 60 */	lfs f26, lbl_8051C4C0@sda21(r2)
/* 802BFA08 002BC948  7F 3F CB 78 */	mr r31, r25
/* 802BFA0C 002BC94C  C3 62 E1 74 */	lfs f27, lbl_8051C4D4@sda21(r2)
/* 802BFA10 002BC950  7F 3E CB 78 */	mr r30, r25
/* 802BFA14 002BC954  C3 82 E1 78 */	lfs f28, lbl_8051C4D8@sda21(r2)
/* 802BFA18 002BC958  3B A1 00 2C */	addi r29, r1, 0x2c
/* 802BFA1C 002BC95C  C3 A2 E1 7C */	lfs f29, lbl_8051C4DC@sda21(r2)
/* 802BFA20 002BC960  3B 81 00 38 */	addi r28, r1, 0x38
/* 802BFA24 002BC964  C3 C2 E1 80 */	lfs f30, lbl_8051C4E0@sda21(r2)
/* 802BFA28 002BC968  3B 61 00 44 */	addi r27, r1, 0x44
/* 802BFA2C 002BC96C  C3 E2 E1 84 */	lfs f31, lbl_8051C4E4@sda21(r2)
/* 802BFA30 002BC970  3B 40 00 00 */	li r26, 0
lbl_802BFA34:
/* 802BFA34 002BC974  D3 41 00 68 */	stfs f26, 0x68(r1)
/* 802BFA38 002BC978  38 81 00 50 */	addi r4, r1, 0x50
/* 802BFA3C 002BC97C  38 A1 00 14 */	addi r5, r1, 0x14
/* 802BFA40 002BC980  38 C1 00 20 */	addi r6, r1, 0x20
/* 802BFA44 002BC984  D3 41 00 6C */	stfs f26, 0x6c(r1)
/* 802BFA48 002BC988  D3 61 00 70 */	stfs f27, 0x70(r1)
/* 802BFA4C 002BC98C  D3 81 00 74 */	stfs f28, 0x74(r1)
/* 802BFA50 002BC990  80 7F 00 4C */	lwz r3, 0x4c(r31)
/* 802BFA54 002BC994  48 03 28 65 */	bl "makeShadowSRT__Q24Game17TubeShadowSetNodeFRQ24Game15JointShadowParmR10Vector3<f>R10Vector3<f>"
/* 802BFA58 002BC998  D3 A1 00 68 */	stfs f29, 0x68(r1)
/* 802BFA5C 002BC99C  7F A6 EB 78 */	mr r6, r29
/* 802BFA60 002BC9A0  38 81 00 50 */	addi r4, r1, 0x50
/* 802BFA64 002BC9A4  38 A1 00 20 */	addi r5, r1, 0x20
/* 802BFA68 002BC9A8  D3 C1 00 6C */	stfs f30, 0x6c(r1)
/* 802BFA6C 002BC9AC  D3 61 00 70 */	stfs f27, 0x70(r1)
/* 802BFA70 002BC9B0  D3 81 00 74 */	stfs f28, 0x74(r1)
/* 802BFA74 002BC9B4  80 7F 00 5C */	lwz r3, 0x5c(r31)
/* 802BFA78 002BC9B8  48 03 28 41 */	bl "makeShadowSRT__Q24Game17TubeShadowSetNodeFRQ24Game15JointShadowParmR10Vector3<f>R10Vector3<f>"
/* 802BFA7C 002BC9BC  D3 E1 00 68 */	stfs f31, 0x68(r1)
/* 802BFA80 002BC9C0  7F A5 EB 78 */	mr r5, r29
/* 802BFA84 002BC9C4  7F 86 E3 78 */	mr r6, r28
/* 802BFA88 002BC9C8  38 81 00 50 */	addi r4, r1, 0x50
/* 802BFA8C 002BC9CC  D3 E1 00 6C */	stfs f31, 0x6c(r1)
/* 802BFA90 002BC9D0  D3 61 00 70 */	stfs f27, 0x70(r1)
/* 802BFA94 002BC9D4  D3 81 00 74 */	stfs f28, 0x74(r1)
/* 802BFA98 002BC9D8  80 7F 00 6C */	lwz r3, 0x6c(r31)
/* 802BFA9C 002BC9DC  48 03 28 1D */	bl "makeShadowSRT__Q24Game17TubeShadowSetNodeFRQ24Game15JointShadowParmR10Vector3<f>R10Vector3<f>"
/* 802BFAA0 002BC9E0  D3 41 00 68 */	stfs f26, 0x68(r1)
/* 802BFAA4 002BC9E4  7F 85 E3 78 */	mr r5, r28
/* 802BFAA8 002BC9E8  7F 66 DB 78 */	mr r6, r27
/* 802BFAAC 002BC9EC  38 81 00 50 */	addi r4, r1, 0x50
/* 802BFAB0 002BC9F0  D3 41 00 6C */	stfs f26, 0x6c(r1)
/* 802BFAB4 002BC9F4  D3 61 00 70 */	stfs f27, 0x70(r1)
/* 802BFAB8 002BC9F8  D3 81 00 74 */	stfs f28, 0x74(r1)
/* 802BFABC 002BC9FC  80 7F 00 7C */	lwz r3, 0x7c(r31)
/* 802BFAC0 002BCA00  48 03 27 F9 */	bl "makeShadowSRT__Q24Game17TubeShadowSetNodeFRQ24Game15JointShadowParmR10Vector3<f>R10Vector3<f>"
/* 802BFAC4 002BCA04  2C 1A 00 00 */	cmpwi r26, 0
/* 802BFAC8 002BCA08  40 82 00 84 */	bne lbl_802BFB4C
/* 802BFACC 002BCA0C  C0 42 E1 60 */	lfs f2, lbl_8051C4C0@sda21(r2)
/* 802BFAD0 002BCA10  38 81 00 50 */	addi r4, r1, 0x50
/* 802BFAD4 002BCA14  C0 22 E1 88 */	lfs f1, lbl_8051C4E8@sda21(r2)
/* 802BFAD8 002BCA18  38 A1 00 20 */	addi r5, r1, 0x20
/* 802BFADC 002BCA1C  C0 02 E1 84 */	lfs f0, lbl_8051C4E4@sda21(r2)
/* 802BFAE0 002BCA20  D0 41 00 68 */	stfs f2, 0x68(r1)
/* 802BFAE4 002BCA24  D0 41 00 6C */	stfs f2, 0x6c(r1)
/* 802BFAE8 002BCA28  D0 21 00 70 */	stfs f1, 0x70(r1)
/* 802BFAEC 002BCA2C  D0 01 00 74 */	stfs f0, 0x74(r1)
/* 802BFAF0 002BCA30  80 7F 00 90 */	lwz r3, 0x90(r31)
/* 802BFAF4 002BCA34  48 03 2B E9 */	bl "makeShadowSRT__Q24Game16SphereShadowNodeFRQ24Game15JointShadowParmR10Vector3<f>"
/* 802BFAF8 002BCA38  C0 02 E1 84 */	lfs f0, lbl_8051C4E4@sda21(r2)
/* 802BFAFC 002BCA3C  7F A5 EB 78 */	mr r5, r29
/* 802BFB00 002BCA40  38 81 00 50 */	addi r4, r1, 0x50
/* 802BFB04 002BCA44  D0 01 00 74 */	stfs f0, 0x74(r1)
/* 802BFB08 002BCA48  80 7F 00 A0 */	lwz r3, 0xa0(r31)
/* 802BFB0C 002BCA4C  48 03 2B D1 */	bl "makeShadowSRT__Q24Game16SphereShadowNodeFRQ24Game15JointShadowParmR10Vector3<f>"
/* 802BFB10 002BCA50  C0 02 E1 84 */	lfs f0, lbl_8051C4E4@sda21(r2)
/* 802BFB14 002BCA54  7F 85 E3 78 */	mr r5, r28
/* 802BFB18 002BCA58  38 81 00 50 */	addi r4, r1, 0x50
/* 802BFB1C 002BCA5C  D0 01 00 74 */	stfs f0, 0x74(r1)
/* 802BFB20 002BCA60  80 7F 00 B0 */	lwz r3, 0xb0(r31)
/* 802BFB24 002BCA64  48 03 2B B9 */	bl "makeShadowSRT__Q24Game16SphereShadowNodeFRQ24Game15JointShadowParmR10Vector3<f>"
/* 802BFB28 002BCA68  C0 22 E1 8C */	lfs f1, lbl_8051C4EC@sda21(r2)
/* 802BFB2C 002BCA6C  7F 65 DB 78 */	mr r5, r27
/* 802BFB30 002BCA70  C0 02 E1 90 */	lfs f0, lbl_8051C4F0@sda21(r2)
/* 802BFB34 002BCA74  38 81 00 50 */	addi r4, r1, 0x50
/* 802BFB38 002BCA78  D0 21 00 70 */	stfs f1, 0x70(r1)
/* 802BFB3C 002BCA7C  D0 01 00 74 */	stfs f0, 0x74(r1)
/* 802BFB40 002BCA80  80 79 00 C0 */	lwz r3, 0xc0(r25)
/* 802BFB44 002BCA84  48 03 2B 99 */	bl "makeShadowSRT__Q24Game16SphereShadowNodeFRQ24Game15JointShadowParmR10Vector3<f>"
/* 802BFB48 002BCA88  48 00 00 60 */	b lbl_802BFBA8
lbl_802BFB4C:
/* 802BFB4C 002BCA8C  C0 42 E1 60 */	lfs f2, lbl_8051C4C0@sda21(r2)
/* 802BFB50 002BCA90  38 81 00 50 */	addi r4, r1, 0x50
/* 802BFB54 002BCA94  C0 22 E1 94 */	lfs f1, lbl_8051C4F4@sda21(r2)
/* 802BFB58 002BCA98  38 A1 00 20 */	addi r5, r1, 0x20
/* 802BFB5C 002BCA9C  C0 02 E1 84 */	lfs f0, lbl_8051C4E4@sda21(r2)
/* 802BFB60 002BCAA0  D0 41 00 68 */	stfs f2, 0x68(r1)
/* 802BFB64 002BCAA4  D0 41 00 6C */	stfs f2, 0x6c(r1)
/* 802BFB68 002BCAA8  D0 21 00 70 */	stfs f1, 0x70(r1)
/* 802BFB6C 002BCAAC  D0 01 00 74 */	stfs f0, 0x74(r1)
/* 802BFB70 002BCAB0  80 7F 00 90 */	lwz r3, 0x90(r31)
/* 802BFB74 002BCAB4  48 03 2B 69 */	bl "makeShadowSRT__Q24Game16SphereShadowNodeFRQ24Game15JointShadowParmR10Vector3<f>"
/* 802BFB78 002BCAB8  C0 02 E1 84 */	lfs f0, lbl_8051C4E4@sda21(r2)
/* 802BFB7C 002BCABC  7F A5 EB 78 */	mr r5, r29
/* 802BFB80 002BCAC0  38 81 00 50 */	addi r4, r1, 0x50
/* 802BFB84 002BCAC4  D0 01 00 74 */	stfs f0, 0x74(r1)
/* 802BFB88 002BCAC8  80 7F 00 A0 */	lwz r3, 0xa0(r31)
/* 802BFB8C 002BCACC  48 03 2B 51 */	bl "makeShadowSRT__Q24Game16SphereShadowNodeFRQ24Game15JointShadowParmR10Vector3<f>"
/* 802BFB90 002BCAD0  C0 02 E1 84 */	lfs f0, lbl_8051C4E4@sda21(r2)
/* 802BFB94 002BCAD4  7F 85 E3 78 */	mr r5, r28
/* 802BFB98 002BCAD8  38 81 00 50 */	addi r4, r1, 0x50
/* 802BFB9C 002BCADC  D0 01 00 74 */	stfs f0, 0x74(r1)
/* 802BFBA0 002BCAE0  80 7F 00 B0 */	lwz r3, 0xb0(r31)
/* 802BFBA4 002BCAE4  48 03 2B 39 */	bl "makeShadowSRT__Q24Game16SphereShadowNodeFRQ24Game15JointShadowParmR10Vector3<f>"
lbl_802BFBA8:
/* 802BFBA8 002BCAE8  80 7E 00 08 */	lwz r3, 8(r30)
/* 802BFBAC 002BCAEC  28 03 00 00 */	cmplwi r3, 0
/* 802BFBB0 002BCAF0  41 82 00 24 */	beq lbl_802BFBD4
/* 802BFBB4 002BCAF4  C0 01 00 20 */	lfs f0, 0x20(r1)
/* 802BFBB8 002BCAF8  D0 03 00 00 */	stfs f0, 0(r3)
/* 802BFBBC 002BCAFC  C0 01 00 24 */	lfs f0, 0x24(r1)
/* 802BFBC0 002BCB00  80 7E 00 08 */	lwz r3, 8(r30)
/* 802BFBC4 002BCB04  D0 03 00 04 */	stfs f0, 4(r3)
/* 802BFBC8 002BCB08  C0 01 00 28 */	lfs f0, 0x28(r1)
/* 802BFBCC 002BCB0C  80 7E 00 08 */	lwz r3, 8(r30)
/* 802BFBD0 002BCB10  D0 03 00 08 */	stfs f0, 8(r3)
lbl_802BFBD4:
/* 802BFBD4 002BCB14  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 802BFBD8 002BCB18  28 03 00 00 */	cmplwi r3, 0
/* 802BFBDC 002BCB1C  41 82 00 24 */	beq lbl_802BFC00
/* 802BFBE0 002BCB20  C0 01 00 2C */	lfs f0, 0x2c(r1)
/* 802BFBE4 002BCB24  D0 03 00 00 */	stfs f0, 0(r3)
/* 802BFBE8 002BCB28  C0 01 00 30 */	lfs f0, 0x30(r1)
/* 802BFBEC 002BCB2C  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 802BFBF0 002BCB30  D0 03 00 04 */	stfs f0, 4(r3)
/* 802BFBF4 002BCB34  C0 01 00 34 */	lfs f0, 0x34(r1)
/* 802BFBF8 002BCB38  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 802BFBFC 002BCB3C  D0 03 00 08 */	stfs f0, 8(r3)
lbl_802BFC00:
/* 802BFC00 002BCB40  80 7E 00 10 */	lwz r3, 0x10(r30)
/* 802BFC04 002BCB44  28 03 00 00 */	cmplwi r3, 0
/* 802BFC08 002BCB48  41 82 00 24 */	beq lbl_802BFC2C
/* 802BFC0C 002BCB4C  C0 01 00 38 */	lfs f0, 0x38(r1)
/* 802BFC10 002BCB50  D0 03 00 00 */	stfs f0, 0(r3)
/* 802BFC14 002BCB54  C0 01 00 3C */	lfs f0, 0x3c(r1)
/* 802BFC18 002BCB58  80 7E 00 10 */	lwz r3, 0x10(r30)
/* 802BFC1C 002BCB5C  D0 03 00 04 */	stfs f0, 4(r3)
/* 802BFC20 002BCB60  C0 01 00 40 */	lfs f0, 0x40(r1)
/* 802BFC24 002BCB64  80 7E 00 10 */	lwz r3, 0x10(r30)
/* 802BFC28 002BCB68  D0 03 00 08 */	stfs f0, 8(r3)
lbl_802BFC2C:
/* 802BFC2C 002BCB6C  80 7E 00 14 */	lwz r3, 0x14(r30)
/* 802BFC30 002BCB70  28 03 00 00 */	cmplwi r3, 0
/* 802BFC34 002BCB74  41 82 00 24 */	beq lbl_802BFC58
/* 802BFC38 002BCB78  C0 01 00 44 */	lfs f0, 0x44(r1)
/* 802BFC3C 002BCB7C  D0 03 00 00 */	stfs f0, 0(r3)
/* 802BFC40 002BCB80  C0 01 00 48 */	lfs f0, 0x48(r1)
/* 802BFC44 002BCB84  80 7E 00 14 */	lwz r3, 0x14(r30)
/* 802BFC48 002BCB88  D0 03 00 04 */	stfs f0, 4(r3)
/* 802BFC4C 002BCB8C  C0 01 00 4C */	lfs f0, 0x4c(r1)
/* 802BFC50 002BCB90  80 7E 00 14 */	lwz r3, 0x14(r30)
/* 802BFC54 002BCB94  D0 03 00 08 */	stfs f0, 8(r3)
lbl_802BFC58:
/* 802BFC58 002BCB98  3B 5A 00 01 */	addi r26, r26, 1
/* 802BFC5C 002BCB9C  3B DE 00 10 */	addi r30, r30, 0x10
/* 802BFC60 002BCBA0  2C 1A 00 04 */	cmpwi r26, 4
/* 802BFC64 002BCBA4  3B FF 00 04 */	addi r31, r31, 4
/* 802BFC68 002BCBA8  41 80 FD CC */	blt lbl_802BFA34
/* 802BFC6C 002BCBAC  E3 E1 00 F8 */	psq_l f31, 248(r1), 0, qr0
/* 802BFC70 002BCBB0  CB E1 00 F0 */	lfd f31, 0xf0(r1)
/* 802BFC74 002BCBB4  E3 C1 00 E8 */	psq_l f30, 232(r1), 0, qr0
/* 802BFC78 002BCBB8  CB C1 00 E0 */	lfd f30, 0xe0(r1)
/* 802BFC7C 002BCBBC  E3 A1 00 D8 */	psq_l f29, 216(r1), 0, qr0
/* 802BFC80 002BCBC0  CB A1 00 D0 */	lfd f29, 0xd0(r1)
/* 802BFC84 002BCBC4  E3 81 00 C8 */	psq_l f28, 200(r1), 0, qr0
/* 802BFC88 002BCBC8  CB 81 00 C0 */	lfd f28, 0xc0(r1)
/* 802BFC8C 002BCBCC  E3 61 00 B8 */	psq_l f27, 184(r1), 0, qr0
/* 802BFC90 002BCBD0  CB 61 00 B0 */	lfd f27, 0xb0(r1)
/* 802BFC94 002BCBD4  E3 41 00 A8 */	psq_l f26, 168(r1), 0, qr0
/* 802BFC98 002BCBD8  CB 41 00 A0 */	lfd f26, 0xa0(r1)
/* 802BFC9C 002BCBDC  BB 21 00 84 */	lmw r25, 0x84(r1)
/* 802BFCA0 002BCBE0  80 01 01 04 */	lwz r0, 0x104(r1)
/* 802BFCA4 002BCBE4  7C 08 03 A6 */	mtlr r0
/* 802BFCA8 002BCBE8  38 21 01 00 */	addi r1, r1, 0x100
/* 802BFCAC 002BCBEC  4E 80 00 20 */	blr 
