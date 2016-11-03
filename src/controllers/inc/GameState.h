/*
 * StateControllerless.h
 *
 *  Created on: 3 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_GAMESTATE_H_
#define SRC_CONTROLLERS_INC_GAMESTATE_H_

#include <memory>

class GameState;
typedef std::shared_ptr<GameState> GameStatePtr;

class GameState {
public:
    virtual bool gameIsStarted() const = 0;
    virtual ~GameState() {}
};

#endif /* SRC_CONTROLLERS_INC_GAMESTATE_H_ */
