/*
 * LocalAppStatesBuilder.h
 *
 *  Created on: 17 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_LOGIC_LOCAL_INC_LOCALAPPSTATESBUILDER_H_
#define SRC_LOGIC_LOCAL_INC_LOCALAPPSTATESBUILDER_H_

#include <AppStatesBuilder.h>
#include <LocalNoGameInProgressState.h>

class LocalAppStatesBuilder : public AppStatesBuilder {
public:
    LocalAppStatesBuilder(EventObserver& observer,
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

        initialState = AppStatePtr(new LocalNoGameInProgressState(*this,
                                   factory,
                                   starter,
                                   observer,
                                   GameStatePtr(new NoGameStartedState())));
        gamePaused = AppStatePtr(new LocalNoGameInProgressState(*this,
                                 factory,
                                 starter,
                                 observer,
                                 GameStatePtr(new GameStartedState())));

    }

};

#endif /* SRC_LOGIC_LOCAL_INC_LOCALAPPSTATESBUILDER_H_ */
