/*
 * KlondikeAppStateContext.h
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_LOGIC_H_
#define SRC_CONTROLLERS_INC_LOGIC_H_

#include <Klondike.h>
#include <KlondikeSaver.h>
#include <EventObserver.h>
#include <GameActionControllerHolder.h>
#include <GameActionHistoryController.h>
#include <BestScoresController.h>
#include <SaveGameController.h>
#include <AppStatesBuilder.h>
#include <assert.h>

class Logic : public EventObserver {
private:
    std::shared_ptr<Klondike> game;
    GameActionControllerHolder gameActionControllerHolder;
    std::shared_ptr<GameActionHistoryController> historyController;
    std::shared_ptr<BestScoresController> bestScoresController;
    std::shared_ptr<SaveGameController> saveGameController;
    KlondikeSaver& saver;
    AppStatesBuilder statesBuildr;
    AppStatePtr currentState;
public:
    Logic(KlondikeSaver& saver);
    ControllerPtr getNextController();
    void gameStarted();
    void saveGameRequested();
    void loadGameRequested();
    void gamePauseRequested();
    void gameResumeRequested();
    void gameCompleted();
    void exitRequested();
};

#endif /* SRC_CONTROLLERS_INC_LOGIC_H_ */
