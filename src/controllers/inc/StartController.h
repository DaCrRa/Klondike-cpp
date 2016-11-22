/*
 * StartController.h
 *
 *  Created on: 16 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_STARTCONTROLLER_H_
#define SRC_CONTROLLERS_STARTCONTROLLER_H_

#include <AbstractDeckFactory.h>
#include <Controller.h>
#include <ControllerVisitor.h>
#include <EventObserver.h>
#include <GameSessionStarter.h>
#include <GameState.h>
#include <memory>
#include <vector>

class StartController : public Controller {
private:
    void start(std::shared_ptr<GameActionController> gameActionController);
protected:
    std::shared_ptr<AbstractDeckFactory> deckFactory;
    GameSessionStarter sessionStarter;
    GameStatePtr gameState;
    EventObserver& eventObserver;
    virtual std::shared_ptr<Klondike> instantiateKlondike() = 0;
public:
    StartController(std::shared_ptr<AbstractDeckFactory> factory,
                    GameSessionStarter& starter,
                    GameStatePtr state,
                    EventObserver& observer);
    void startGame();
    void startDemo();
    bool isGameInProgress();
    AbstractDeckFactory& getDeckFactory();
    void accept(ControllerVisitor* v);
    virtual ~StartController() {}
};

#endif /* SRC_CONTROLLERS_STARTCONTROLLER_H_ */
