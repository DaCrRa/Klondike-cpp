/*
 * StartController.h
 *
 *  Created on: 16 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_STARTCONTROLLER_H_
#define SRC_CONTROLLERS_STARTCONTROLLER_H_

#include <Controller.h>
#include <ControllerVisitor.h>
#include <Klondike.h>
#include <EventObserver.h>
#include <GameActionControllerHolder.h>
#include <GameState.h>

#include <memory>
#include <vector>

class StartController : public Controller {
private:
    std::shared_ptr<Klondike>& game;
    GameActionControllerHolder& gameActionControllerHolder;
    GameStatePtr gameState;
    EventObserver& eventObserver;
    void start(std::shared_ptr<GameActionController> gameActionController);
public:
    StartController(std::shared_ptr<Klondike>& g,
                    GameActionControllerHolder& holder,
                    GameStatePtr state,
                    EventObserver& observer);
    void startGame();
    void startDemo();
    bool isGameInProgress();
    void accept(ControllerVisitor* v);
};

#endif /* SRC_CONTROLLERS_STARTCONTROLLER_H_ */
