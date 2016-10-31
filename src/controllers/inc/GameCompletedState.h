/*
 * GameCompletedState.h
 *
 *  Created on: 1 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_GAMECOMPLETEDSTATE_H_
#define SRC_CONTROLLERS_INC_GAMECOMPLETEDSTATE_H_

#include <KlondikeAppState.h>
#include <GamePausedState.h>

class GameCompletedState : public KlondikeAppState {
public:
    ControllerPtr getController(KlondikeAppStateContext& context) {
        context.getBestScoresController()->registerScore();
        context.setState(KlondikeAppStatePtr(new GamePausedState()));
        //context.getGame().reset();
        return ControllerPtr(context.getBestScoresController());
    }
};

#endif /* SRC_CONTROLLERS_INC_GAMECOMPLETEDSTATE_H_ */
