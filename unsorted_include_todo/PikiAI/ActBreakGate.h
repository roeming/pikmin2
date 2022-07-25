#ifndef _PIKIAI_ACTBREAKGATE_H
#define _PIKIAI_ACTBREAKGATE_H

/*
        __vt__Q26PikiAI12ActBreakGate:
        .4byte 0
        .4byte 0
        .4byte init__Q26PikiAI12ActBreakGateFPQ26PikiAI9ActionArg
        .4byte exec__Q26PikiAI12ActBreakGateFv
        .4byte cleanup__Q26PikiAI12ActBreakGateFv
        .4byte emotion_success__Q26PikiAI12ActBreakGateFv
        .4byte emotion_fail__Q26PikiAI6ActionFv
        .4byte applicable__Q26PikiAI6ActionFv
        .4byte getNextAIType__Q26PikiAI6ActionFv
        .4byte
   bounceCallback__Q26PikiAI12ActBreakGateFPQ24Game4PikiPQ23Sys8Triangle .4byte
   collisionCallback__Q26PikiAI12ActBreakGateFPQ24Game4PikiRQ24Game9CollEvent
        .4byte
   platCallback__Q26PikiAI12ActBreakGateFPQ24Game4PikiRQ24Game9PlatEvent .4byte
   doDirectDraw__Q26PikiAI6ActionFR8Graphics .4byte
   "wallCallback__Q26PikiAI6ActionFR10Vector3<f>" .4byte
   getInfo__Q26PikiAI6ActionFPc .4byte
   onKeyEvent__Q26PikiAI12ActBreakGateFRCQ28SysShape8KeyEvent .4byte 0 .4byte 0
        .4byte
   "@52@4@onKeyEvent__Q26PikiAI12ActBreakGateFRCQ28SysShape8KeyEvent"
*/

namespace PikiAI {
struct Action {
    virtual void init(ActionArg*);                            // _08
    virtual void exec();                                      // _0C
    virtual void cleanup();                                   // _10
    virtual void emotion_success();                           // _14
    virtual void emotion_fail();                              // _18 (inline)
    virtual void applicable();                                // _1C (inline)
    virtual void getNextAIType();                             // _20 (inline)
    virtual void bounceCallback(Game::Piki*, Sys::Triangle*); // _24
    virtual void collisionCallback(Game::Piki*, Game::CollEvent&); // _28
    virtual void platCallback(Game::Piki*, Game::PlatEvent&);      // _2C
    virtual void doDirectDraw(Graphics&);       // _30 (inline)
    virtual void wallCallback(Vector3<float>&); // _34 (inline)
    virtual void getInfo(char*);                // _38
};
} // namespace PikiAI

namespace PikiAI {
struct ActBreakGate : public Action {
    virtual void init(ActionArg*);                                 // _08
    virtual void exec();                                           // _0C
    virtual void cleanup();                                        // _10
    virtual void emotion_success();                                // _14
    virtual void bounceCallback(Game::Piki*, Sys::Triangle*);      // _24
    virtual void collisionCallback(Game::Piki*, Game::CollEvent&); // _28
    virtual void platCallback(Game::Piki*, Game::PlatEvent&);      // _2C
    virtual void onKeyEvent(const SysShape::KeyEvent&);         // _3C (inline)
    virtual void _40() = 0;                                     // _40
    virtual void _44() = 0;                                     // _44
    virtual void @52 @4 @onKeyEvent(const SysShape::KeyEvent&); // _48 (inline)

    ActBreakGate(Game::Piki*);
    void initFollow();
};
} // namespace PikiAI

#endif
