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
#include <GameState.h>

#include <memory>
#include <vector>

class StartController : public Controller {
private:
    GameStatePtr gameState;
    EventObserver& eventObserver;
public:
    StartController(GameStatePtr state, EventObserver& observer);
    void startGame();
    void startDemo();
    void resumeGame();
    void terminateApp();
    bool isGameInProgress();
    void accept(ControllerVisitor* v);
};

#endif /* SRC_CONTROLLERS_STARTCONTROLLER_H_ */
