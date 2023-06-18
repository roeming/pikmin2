#ifndef _PSSYSTEM_PSGAME_H
#define _PSSYSTEM_PSGAME_H

#include "JSystem/JUtility/JUTException.h"
#include "PSSystem/PSScene.h"
#include "PSSystem/SingletonBase.h"
#include "PSSystem/Seq.h"
#include "PSGame/SeMgr.h"

// idk what else goes in this file (if anything? maybe this is in the PSGame folder??)
// but these use the file name in the exception check so :shrug:
namespace PSSystem {
inline SceneMgr* getSceneMgr()
{

	P2ASSERTLINE(467, spSceneMgr);

	return spSceneMgr;
}

inline void checkSceneMgr(SceneMgr* mgr) { P2ASSERTLINE(476, mgr); }

inline PSGame::SeMgr* getSeMgrInstance()
{
	P2ASSERTLINE(567, SingletonBase<PSGame::SeMgr>::sInstance);
	return SingletonBase<PSGame::SeMgr>::sInstance;
}

inline SeqBase* getSeqFromScene(Scene* scene, u32 id) {
	SeqBase* seq = scene->_10.getSeq(id);
	P2ASSERTLINE(487, seq);
	return seq;
}

}; // namespace PSSystem



#endif
