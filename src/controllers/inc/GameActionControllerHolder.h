/*
 * GameActionControllerHolder.h
 *
 *  Created on: 5 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_GAMEACTIONCONTROLLERHOLDER_H_
#define SRC_CONTROLLERS_INC_GAMEACTIONCONTROLLERHOLDER_H_

#include <GameActionController.h>

#include <memory>
#include <assert.h>

class GameActionControllerHolder {
private:
    std::shared_ptr<GameActionController> gameActionController;
public:
    void setGameActionController(std::shared_ptr<GameActionController> controller) {
        gameActionController = controller;
    }
    std::shared_ptr<GameActionController> getGameActionController() {
        assert(gameActionController);
        return gameActionController;
    }
};



#endif /* SRC_CONTROLLERS_INC_GAMEACTIONCONTROLLERHOLDER_H_ */
