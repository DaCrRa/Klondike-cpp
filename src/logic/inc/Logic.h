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
#include <KlondikeLoader.h>
#include <EventObserver.h>
#include <GameActionControllerHolder.h>
#include <BestScoresController.h>
#include <SaveGameController.h>
#include <LoadGameController.h>
#include <AppStatesBuilder.h>
#include <assert.h>
#include <AbstractDeckFactory.h>

class Logic : public EventObserver {
private:
    std::shared_ptr<Klondike> game;
    GameActionControllerHolder gameActionControllerHolder;
    GameSessionStarter gameSessionStarter;
    std::shared_ptr<BestScoresController> bestScoresController;
    std::shared_ptr<SaveGameController> saveGameController;
    std::shared_ptr<LoadGameController> loadGameController;
    KlondikeSaver& saver;
    AppStatesBuilder statesBuildr;
    AppStatePtr currentState;
public:
    Logic(std::shared_ptr<AbstractDeckFactory> factory, KlondikeSaver& saver, KlondikeLoader& loader);
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
