/*
 * GamePausedState.h
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_NOGAMEINPROGRESSSTATE_H_
#define SRC_CONTROLLERS_INC_NOGAMEINPROGRESSSTATE_H_

#include <AbstractDeckFactory.h>
#include <GameSessionStarter.h>
#include <GameState.h>
#include <AppState.h>

class NoGameInProgressState : public AppState,
    public std::enable_shared_from_this<NoGameInProgressState> {

protected:
    std::shared_ptr<AbstractDeckFactory> deckFactory;
    GameSessionStarter& gameSessionStarter;
    EventObserver& eventObserver;
    GameStatePtr gameState;
public:
    NoGameInProgressState(AppStatesBuilder& sb,
                          std::shared_ptr<AbstractDeckFactory> factory,
                          GameSessionStarter& starter,
                          EventObserver& eventObserver,
                          GameStatePtr gameState);
    virtual ControllerPtr getController() = 0;
    AppStatePtr transitionToExit();
    AppStatePtr transitionToGameInProgress();
    AppStatePtr transitionToSavingGame();
    AppStatePtr transitionToLoadingGame();
    virtual ~NoGameInProgressState() {}
};

#endif /* SRC_CONTROLLERS_INC_NOGAMEINPROGRESSSTATE_H_ */
