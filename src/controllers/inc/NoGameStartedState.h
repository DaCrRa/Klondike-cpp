/*
 * NoGameStartedState.h
 *
 *  Created on: 3 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_NOGAMESTARTEDSTATE_H_
#define SRC_CONTROLLERS_INC_NOGAMESTARTEDSTATE_H_

#include <GameState.h>

class NoGameStartedState: public GameState {
public:
    bool gameIsStarted() const {
        return false;
    }
};

#endif /* SRC_CONTROLLERS_INC_NOGAMESTARTEDSTATE_H_ */
