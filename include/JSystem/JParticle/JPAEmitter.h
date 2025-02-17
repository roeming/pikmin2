#ifndef _JSYSTEM_JPA_JPAEMITTER_H
#define _JSYSTEM_JPA_JPAEMITTER_H

#include "Dolphin/gx.h"
#include "Dolphin/mtx.h"
#include "JSystem/JGeometry.h"
#include "JSystem/JMath.h"
#include "JSystem/JParticle/JPANode.h"
#include "JSystem/JParticle/JPAResource.h"
#include "JSystem/JSupport/JSUList.h"
#include "JSystem/JUtility/TColor.h"
#include "types.h"
#include "Color4.h"
#include "Vector3.h"

struct JPABaseEmitter;
struct JPAEmitterWorkData;
struct JPAEmitterManager;
struct JPAEmitterCallBack;
struct JPAParticleCallBack;

struct JPADrawInfo {
	Mtx mtx1;
	Mtx mtx2;
};

enum JPAEmitterFlags {
	JPAEMIT_Unk1     = 0x1,
	JPAEMIT_Unk2     = 0x2,
	JPAEMIT_IsDemoOn = 0x4,
	JPAEMIT_Unk4     = 0x8,
	JPAEMIT_Unk5     = 0x10,
	JPAEMIT_Unk6     = 0x20,
	JPAEMIT_Unk7     = 0x40,
	JPAEMIT_Unk8     = 0x80,
	JPAEMIT_Unk9     = 0x100,
};

struct JPABaseParticle {
	void init_p(JPAEmitterWorkData*);
	void init_c(JPAEmitterWorkData*, JPABaseParticle*);
	void calc_p(JPAEmitterWorkData*);
	void calc_c(JPAEmitterWorkData*);
	bool canCreateChild(JPAEmitterWorkData*);
	f32 getCalcCurrentPositionX(const JPABaseEmitter*) const;
	f32 getCalcCurrentPositionY(const JPABaseEmitter*) const;
	f32 getCalcCurrentPositionZ(const JPABaseEmitter*) const;

	// unused/inlined:
	~JPABaseParticle();
	f32 getWidth(const JPABaseEmitter*) const;
	f32 getHeight(const JPABaseEmitter*) const;

	JGeometry::TVec3f _00;       // _00
	JGeometry::TVec3f mPosition; // _0C
	JGeometry::TVec3f _18;       // _18
	JGeometry::TVec3f _24;       // _24
	JGeometry::TVec3f _30;       // _30
	JGeometry::TVec3f _3C;       // _3C
	JGeometry::TVec3f _48;       // _48
	JGeometry::TVec3f _54;       // _54
	f32 _60;                     // _60
	f32 _64;                     // _64
	f32 _68;                     // _68
	f32 _6C;                     // _6C
	f32 _70;                     // _70
	f32 _74;                     // _74
	unknown _78;                 // _78
	uint _7C;                    // _7C
	s16 _80;                     // _80
	u16 _82;                     // _82
	f32 _84;                     // _84
	s16 _88;                     // _88
	s16 _8A;                     // _8A
	JUtility::TColor _8C;        // _8C
	JUtility::TColor _90;        // _90
	u8 _94;                      // _94
	u8 _95;                      // _95
	u8 _96;                      // _96
};

struct JPAParticleCallBack {
	virtual ~JPAParticleCallBack() = 0;                      // _08
	virtual void execute(JPABaseEmitter*, JPABaseParticle*); // _0C (weak)
	virtual void draw(JPABaseEmitter*, JPABaseParticle*);    // _10 (weak)
};

// TODO: Fill stuff in.
struct JPABaseEmitter {
	JPABaseEmitter();
	~JPABaseEmitter();
	void init(JPAEmitterManager*, struct JPAResource*);
	JPABaseParticle* createParticle();
	JPABaseParticle* createChild(JPABaseParticle*);
	void deleteAllParticle();
	bool processTillStartFrame();
	bool processTermination();
	void calcEmitterGlobalPosition(JGeometry::TVec3f*) const;
	int getCurrentCreateNumber() const;

	// unused/inlined:
	void getEmitterAxisX(JGeometry::TVec3f*) const;
	void getEmitterAxisY(JGeometry::TVec3f*) const;
	void getEmitterAxisZ(JGeometry::TVec3f*) const;
	int getDrawCount() const;
	void loadTexture(u8, _GXTexMapID);

	void setFlag(u32 flag) { mFlags |= flag; }
	bool isFlag(u32 flag) { return mFlags & flag; }
	void resetFlag(u32 flag) { mFlags &= ~flag; }
	bool is100() { return mFlags & 0x100; }

	inline void setScale(f32 scale)
	{
		_98 = JGeometry::TVec3f(scale);
		_B0 = scale;
		_B4 = scale;
	}

	inline void setScale(f32 scaleXY, f32 scaleZ)
	{
		_98 = JGeometry::TVec3f(scaleXY, scaleXY, scaleZ);
		_B0 = scaleXY;
		_B4 = scaleXY;
	}

	inline void setScaleOnly(f32 scale) { _98 = JGeometry::TVec3f(scale); }

	inline void setGlobalScale(f32 x, f32 y)
	{
		_B0 = x;
		_B4 = y;
	}

	inline void setAngle(f32 x, f32 y, f32 z)
	{
		_18.x = x;
		_18.y = y;
		_18.z = z;
	}

	inline void setAngle(JGeometry::TVec3f* vec)
	{
		_18.x = vec->x;
		_18.y = vec->y;
		_18.z = vec->z;
	}

	inline void setScaleMain(JGeometry::TVec3f& vec)
	{
		mScale.x = vec.x;
		mScale.y = vec.y;
		mScale.z = vec.z;
	}

	inline void setScaleMain(Vector3f& vec)
	{
		mScale.x = vec.x;
		mScale.y = vec.y;
		mScale.z = vec.z;
	}

	inline void setScaleMain(f32 x, f32 y, f32 z)
	{
		mScale.x = x;
		mScale.y = y;
		mScale.z = z;
	}

	inline void setGlobalScale(f32 x)
	{
		_B0 = x;
		_B4 = x;
	}

	inline void setColor(Color4& color)
	{
		mColor1.r = color.r;
		mColor1.g = color.g;
		mColor1.b = color.b;
		mColor1.a = color.a;
	}

	inline void setColorRGB(Color4& color)
	{
		mColor1.r = color.r;
		mColor1.g = color.g;
		mColor1.b = color.b;
	}

	inline void setColorRGB(u8 r, u8 g, u8 b)
	{
		mColor1.r = r;
		mColor1.g = g;
		mColor1.b = b;
	}

	inline void setColorRGB(JUtility::TColor& color)
	{
		mColor2.r = color.r;
		mColor2.g = color.g;
		mColor2.b = color.b;
	}

	inline void setPrmColorRGB(JUtility::TColor& color)
	{
		mColor1.r = color.r;
		mColor1.g = color.g;
		mColor1.b = color.b;
	}

	inline void setPrmColorRGB(u8 r, u8 g, u8 b)
	{
		mColor1.r = r;
		mColor1.g = g;
		mColor1.b = b;
	}

	inline void setPrmColor(JUtility::TColor& color)
	{
		mColor1.setRGB(color);
		mColor1.a = color.a;
	}

	Vector3f mScale;             // _00
	JGeometry::TVec3f _0C;       // _0C
	JGeometry::TVec3f _18;       // _18
	s32 _24;                     // _24
	f32 _28;                     // _28
	f32 _2C;                     // _2C
	f32 _30;                     // _30
	f32 _34;                     // _34
	u8 _38[0x8];                 // _38
	f32 _40;                     // _40
	u8 _44[4];                   // _44
	f32 _48;                     // _48
	s16 _4C;                     // _4C
	s16 _4E;                     // _4E
	s16 _50;                     // _50
	u16 _52;                     // _52
	u16 _54;                     // _54
	JSUPtrLink _58;              // _58
	Mtx mMatrix;                 // _68
	JGeometry::TVec3f _98;       // _98
	JGeometry::TVec3f mPosition; // _A4
	f32 _B0;                     // _B0
	f32 _B4;                     // _B4
	JUtility::TColor mColor1;    // _B8
	JUtility::TColor mColor2;    // _BC
	s32 : 0;                     // reset alignment to _C0
	u8 _C0[4];                   // _C0
	JMath::TRandom_fast_ mRng;   // _C4
	void* _C8;                   // _C8
	void* _CC;                   // _CC
	// JPANode<JPABaseParticle>* _C8; // _C8
	// JPANode<JPABaseParticle>* _CC; // _CC
	s32 _D0;   // _D0
	void* _D4; // _D4
	// JPANode<JPABaseParticle>* _D4; // _D4
	u8 _D8[4];                              // _D8
	s32 _DC;                                // _DC
	void* _E0;                              // _E0
	JPAEmitterManager* mManager;            // _E4
	JPAResource* mResource;                 // _E8
	JPAEmitterCallBack* mEmitterCallback;   // _EC
	JPAParticleCallBack* mParticleCallback; // _F0
	u32 mFlags;                             // _F4
	f32 _F8;                                // _F8
	f32 _FC;                                // _FC
	u32 _100;                               // _100
	s16 _104;                               // _104
	s16 _106;                               // _106
	JUtility::TColor _108;                  // _108
	JUtility::TColor _10C;                  // _10C
	u8 _110;                                // _110
	u8 _111;                                // _111
	u8 _112;                                // _112
	u8 _113;                                // _113
};

struct JPAEmitterCallBack {
	virtual ~JPAEmitterCallBack() = 0;          // _08
	virtual void execute(JPABaseEmitter*);      // _0C (weak)
	virtual void executeAfter(JPABaseEmitter*); // _10 (weak)
	virtual void draw(JPABaseEmitter*);         // _14 (weak)
	virtual void drawAfter(JPABaseEmitter*);    // _18 (weak)

	// not sure how this works with the pure virtual dtor
	// ~JPAEmitterCallBack();

	// _00 = VTBL
};

/**
 * @size{0x218}
 */
struct JPAEmitterWorkData {
	JPABaseEmitter* mEmitter;         // _00
	JPAResource* mResource;           // _04
	JPAResourceManager* mResourceMgr; // _08
	u32 _0C;                          // _0C
	JGeometry::TVec3f _10;            // _10
	JGeometry::TVec3f _1C;            // _1C
	JGeometry::TVec3f _28;            // _28
	f32 _34;                          // _34
	f32 _38;                          // _38
	f32 _3C;                          // _3C
	int mCreateNumber;                // _40;
	u32 _44;                          // _44
	Mtx _48;                          // _48
	Mtx _78;                          // _78
	Mtx _A8;                          // _A8
	Mtx _D8;                          // _D8
	JGeometry::TVec3f _108;           // _108
	f32 _114;                         // _114
	f32 _118;                         // _118
	f32 _11C;                         // _11C
	JGeometry::TVec3f _120;           // _120
	JGeometry::TVec3f _12C;           // _120
	JGeometry::TVec3f _138;           // _138
	f32 _144;                         // _144
	f32 _148;                         // _148
	f32 _14C;                         // _14C
	f32 _150;                         // _150
	Mtx _154;                         // _154
	Mtx _184;                         // _184
	Mtx _1B4;                         // _1B4
	JPANode<JPABaseParticle>* _1E4;   // _1E4
	JPANode<JPABaseParticle>* _1E8;   // _1E8
	int _1EC;                         // _1EC
	int _1F0;                         // _1F0
	int _1F4;                         // _1F4
	int _1F8;                         // _1F8
	f32 _1FC;                         // _1FC
	int _200;                         // _200
	int _204;                         // _204
	int _208;                         // _208
	int _20C;                         // _20C
	int _210;                         // _210
	short _214;                       // _214
	u8 _216;                          // _216
};

/**
 * @size{0x30}
 */
struct JPAEmitterManager {
	JPAEmitterManager(u32, u32, JKRHeap*, u8, u8);

	JPABaseEmitter* createSimpleEmitterID(const JGeometry::TVec3f&, u16, u8, u8, JPAEmitterCallBack*, JPAParticleCallBack*);
	void calc();
	void draw(const JPADrawInfo*, u8);
	void forceDeleteAllEmitter();
	void forceDeleteGroupEmitter(u8);
	void forceDeleteEmitter(JPABaseEmitter*);
	void entryResourceManager(JPAResourceManager*, u8);
	void clearResourceManager(u8);
	void calcYBBCam();

	// unused/inlined:
	void createSimpleEmitter(const JGeometry::TVec3f&, u16, JPAEmitterCallBack*, JPAParticleCallBack*);
	void calc(u8);
	void draw(f32 (*)[4], u8);
	void draw(const JPADrawInfo*);
	void draw(f32 (*)[4]);

	JSUList<JPABaseEmitter>* _00; // _00
	JSUPtrList _04;               // _04
	void* _10;
	void* _14;
	// JPANode<JPABaseParticle>* _10; // _10
	// JPANode<JPABaseParticle>* _14; // _14
	int _18;                         // _18
	struct JPAResourceManager** _1C; // _1C
	JPAEmitterWorkData* _20;         // _20
	uint _24;                        // _24
	uint _28;                        // _28
	u8 _2C;                          // _2C
	u8 _2D;                          // _2D
};

#endif
