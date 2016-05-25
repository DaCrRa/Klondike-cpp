/*
 * GameStatusController.h
 *
 *  Created on: 24 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_GAMESTATUSCONTROLLER_H_
#define SRC_CONTROLLERS_GAMESTATUSCONTROLLER_H_

#include <Klondike.h>

#include <memory>

class GameStatusController {
private:
    std::shared_ptr<Klondike>& game;
public:
    GameStatusController(std::shared_ptr<Klondike>& game);
    bool isGameInProgress();
    void startNewGame();
    void pauseGame();
    void resumeGame();
};

#endif /* SRC_CONTROLLERS_GAMESTATUSCONTROLLER_H_ */
