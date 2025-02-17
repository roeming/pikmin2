#ifndef _PSM_ENVSE_PERSPECTIVE_AVOIDY_H
#define _PSM_ENVSE_PERSPECTIVE_AVOIDY_H

#include "JSystem/JAudio/JAI/JAISound.h"
#include "PSGame/EnvSe.h"
#include "JSystem/JAudio/JAI/JAISe.h"
#include "PSGame/SoundTable.h"

namespace PSM {
struct EnvSe_Perspective_AvoidY : public PSGame::EnvSe_Perspective {
	virtual JAISound* play();  // _0C
	virtual u32 getCastType(); // _10 (weak)

	// _10     = VTBL
	// _00-_48 = PSGame::EnvSe_Perspective
	f32 _48;   // _48
	f32 _4C;   // _4C
	u8 _50[4]; // _50
	f32 _54;   // _54
	f32 _58;   // _58
	f32 _5C;   // _5C
};

struct Env_Pollutin : public PSGame::EnvSe_AutoPan {
	virtual JAISound* play();  // _0C
	virtual u32 getCastType(); // _10 (weak)

	// _10     = VTBL
	// _00-_50 = PSGame::EnvSe_AutoPan
	f32 _50; // _50
};

/**
 * @size{0x14}
 */
struct PersEnvInfo {
	f32 _00; // _00
	f32 _04; // _04
	f32 _08; // _08
	f32 _0C; // _0C
	f32 _10; // _10
};

/**
 * @size{0x14}
 */
struct PersEnvManager {
	PersEnvManager(PSSystem::EnvSeMgr*);

	void playOk(EnvSe_Perspective_AvoidY*);
	void exec();

	PSSystem::EnvSeMgr* mEnvSeMgr; // _00
	u8 _04;                        // _04
	u8 _05[0x3];                   // _05, possibly padding
	void* _08;                     // _08, unknown ptr
	void* _0C;                     // _0C, unknown ptr
	f32 _10;                       // _10
};

struct EnvSeObjBuilder : public PSGame::Builder_EvnSe_Perspective {
	EnvSeObjBuilder(JGeometry::TBox3<float>);

	virtual ~EnvSeObjBuilder();                                 // _08
	virtual void onBuild(PSSystem::EnvSeBase*);                 // _0C
	virtual PSGame::EnvSe_Perspective* newSeObj(u32, f32, Vec); // _10

	void setInfo(PersEnvInfo);

	// _00     = VTBL
	// _00-_4C = PSGame::Builder_EvnSe_Perspective
	void* _4C;                // _4C, unknown ptr
	PersEnvInfo mPersEnvInfo; // _50
};

struct SeSound : public JAISe {
	inline SeSound()
	    : mPerspInfo()
	    , _49C(0)
	    , _4A0(1.0f)
	{
	}

	virtual f32 setDistanceVolumeCommon(f32, u8);                                          // _BC
	virtual void initParameter(void*, JAInter::Actor*, u32, u32, u8, JAInter::SoundInfo*); // _C8
	virtual void onGet();                                                                  // _CC
	virtual void onRelease();                                                              // _D0
	virtual void setSeDistancePan(u8);                                                     // _DC
	virtual void setSeDistanceDolby(u8);                                                   // _EC

	static SeSound* makeSeSound();
	void specializePerspCalc(const PSGame::SoundTable::SePerspInfo&);
	void calcVolumeSpecialized(f32);
	f32 calcVolume(f32, unsigned char, unsigned char);
	void calcPan(const Vec&, f32);
	void calcDolby(const Vec&, f32);

	// _00      = VTABLE
	// _00-_484 = JAISe
	PSGame::SoundTable::SePerspInfo mPerspInfo; // _484
	u8 _49C;                                    // _49C
	f32 _4A0;                                   // _4A0

	static float cDol_0Rad;
	static float cDol_HalfRad;
	static float cDol_FullRad;
	static float cPan_MaxAmp;
	static float cCenterRad;
};
} // namespace PSM

#endif
