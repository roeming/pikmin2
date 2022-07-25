#ifndef _PSSYSTEM_STREAMBGM_H
#define _PSSYSTEM_STREAMBGM_H

/*
    __vt__Q28PSSystem9StreamBgm:
    .4byte 0
    .4byte 0
    .4byte __dt__Q28PSSystem9StreamBgmFv
    .4byte init__Q28PSSystem9StreamBgmFv
    .4byte scene1st__Q28PSSystem9StreamBgmFPQ28PSSystem11TaskChecker
    .4byte startSeq__Q28PSSystem9StreamBgmFv
    .4byte stopSeq__Q28PSSystem7SeqBaseFUl
    .4byte pauseOn__Q28PSSystem7SeqBaseFQ38PSSystem7SeqBase9PauseMode
    .4byte pauseOff__Q28PSSystem7SeqBaseFv
    .4byte getCastType__Q28PSSystem9StreamBgmFv
    .4byte getSeqType__Q28PSSystem9StreamBgmFv
    .4byte exec__Q28PSSystem7SeqBaseFv
    .4byte onPlayingFrame__Q28PSSystem7SeqBaseFv
    .4byte isPlaying__Q28PSSystem9StreamBgmFv
    .4byte seqLoadAfter__Q28PSSystem7SeqBaseFv
    .4byte getHandleP__Q28PSSystem9StreamBgmFv
    .4byte setConfigVolume__Q28PSSystem9StreamBgmFv
*/

namespace PSSystem {
struct SeqBase {
	virtual ~SeqBase();                  // _08
	virtual void init();                 // _0C
	virtual void scene1st(TaskChecker*); // _10 (inline)
	virtual void startSeq();             // _14
	virtual void stopSeq(unsigned long); // _18
	virtual void pauseOn(PauseMode);     // _1C
	virtual void pauseOff();             // _20
	virtual void getCastType();          // _24 (inline)
	virtual void getSeqType();           // _28 (inline)
	virtual void exec();                 // _2C
	virtual void onPlayingFrame();       // _30
	virtual void isPlaying();            // _34
	virtual void seqLoadAfter();         // _38 (inline)
};
} // namespace PSSystem

namespace PSSystem {
struct StreamBgm : public SeqBase {
	virtual ~StreamBgm();                // _08
	virtual void init();                 // _0C
	virtual void scene1st(TaskChecker*); // _10 (inline)
	virtual void startSeq();             // _14
	virtual void getCastType();          // _24 (inline)
	virtual void getSeqType();           // _28 (inline)
	virtual void isPlaying();            // _34
	virtual void getHandleP();           // _3C (inline)
	virtual void setConfigVolume();      // _40

	StreamBgm(unsigned long, const JAInter::SoundInfo&);
	void setId(unsigned long);
};
} // namespace PSSystem

#endif
