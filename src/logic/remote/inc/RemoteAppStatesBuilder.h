/*
 * RemoteAppStatesBuilder.h
 *
 *  Created on: 22 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_LOGIC_REMOTE_INC_REMOTEAPPSTATESBUILDER_H_
#define SRC_LOGIC_REMOTE_INC_REMOTEAPPSTATESBUILDER_H_

#include <AppStatesBuilder.h>
#include <RemoteNoGameInProgressState.h>

class RemoteAppStatesBuilder : public AppStatesBuilder {
public:
    RemoteAppStatesBuilder(EventObserver& observer,
                           std::shared_ptr<AbstractDeckFactory> factory,
                           GameActionControllerHolder& gameActionControllerHolder,
                           GameSessionStarter& starter,
                           std::shared_ptr<BestScoresController>& bestScoresController,
                           std::shared_ptr<SaveGameController>& saveGameController,
                           std::shared_ptr<LoadGameController>& loadGameController) :
        AppStatesBuilder(observer,
                         factory,
                         gameActionControllerHolder,
                         starter,
                         bestScoresController,
                         saveGameController,
                         loadGameController) {

        initialState = AppStatePtr(new RemoteNoGameInProgressState(*this,
                                   factory,
                                   starter,
                                   observer,
                                   GameStatePtr(new NoGameStartedState())));
        gamePaused = AppStatePtr(new RemoteNoGameInProgressState(*this,
                                 factory,
                                 starter,
                                 observer,
                                 GameStatePtr(new GameStartedState())));

    }
};

#endif /* SRC_LOGIC_REMOTE_INC_REMOTEAPPSTATESBUILDER_H_ */
