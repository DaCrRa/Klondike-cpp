/*
 * GameStarted.h
 *
 *  Created on: 3 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_GAMESTARTEDSTATE_H_
#define SRC_CONTROLLERS_INC_GAMESTARTEDSTATE_H_

#include <GameState.h>

class GameStartedState: public GameState {
public:
    bool gameIsStarted() const {
        return true;
    }
};

#endif /* SRC_CONTROLLERS_INC_GAMESTARTEDSTATE_H_ */
