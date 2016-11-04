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
#include <GameActionController.h>
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
    void start(std::shared_ptr<GameActionController> gameActionController);
public:
    Logic();
    ControllerPtr getNextController();
    void userGameStartRequested();
    void demoRequested();
    void gamePauseRequested();
    void gameResumeRequested();
    void gameCompleted();
    void exitRequested();
};

#endif /* SRC_CONTROLLERS_INC_LOGIC_H_ */
