/*
 * KlondikeAppStateContext.h
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_LOGIC_H_
#define SRC_CONTROLLERS_INC_LOGIC_H_

#include <Klondike.h>
#include <EventObserver.h>
#include <GameActionHistoryController.h>
#include <BestScoresController.h>
#include <AppStatesBuilder.h>
#include <assert.h>

class Logic : public EventObserver {
private:
    std::shared_ptr<Klondike> game;
    std::shared_ptr<GameActionHistoryController> historyController;
    std::shared_ptr<BestScoresController> bestScoresController;
    AppStatesBuilder statesBuildr;
    AppStatePtr currentState;
public:
    Logic();
    ControllerPtr getNextController();
    void gameStarted();
    void gamePaused();
    void gameResumed();
    void gameCompleted();
    void exitRequested();
};

#endif /* SRC_CONTROLLERS_INC_LOGIC_H_ */
