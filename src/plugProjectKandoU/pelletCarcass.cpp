#include "Game/pelletMgr.h"
#include "Game/Entities/PelletCarcass.h"
#include "Iterator.h"

#define MAX_CARCASS_COUNT     64
#define MAX_CARCASS_COLLPARTS 128

namespace Game {

/*
 * --INFO--
 * Address:	801FB8CC
 * Size:	0000B0
 */
PelletCarcass::Mgr::Mgr()
    : FixedSizePelletMgr<Game::PelletCarcass::Object>(PelletList::CARCASS)
{
}

/*
 * --INFO--
 * Address:	801FBC28
 * Size:	000064
 */
void PelletCarcass::Mgr::setupResources()
{
	sys->heapStatusStart("Carcass", nullptr);
	alloc(MAX_CARCASS_COUNT);
	load();
	mCollPartMgr.alloc(MAX_CARCASS_COLLPARTS);
	sys->heapStatusEnd("Carcass");
}
} // namespace Game
