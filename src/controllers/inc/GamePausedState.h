/*
 * GamePausedState.h
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_GAMEPAUSEDSTATE_H_
#define SRC_CONTROLLERS_INC_GAMEPAUSEDSTATE_H_

#include <KlondikeAppState.h>

#include <StartController.h>

class GamePausedState : public KlondikeAppState {
public:
    GamePausedState()  {}
    ControllerPtr getController(KlondikeAppStateContext& context) {
        return ControllerPtr(new StartController(context));
    }
};

#endif /* SRC_CONTROLLERS_INC_GAMEPAUSEDSTATE_H_ */
