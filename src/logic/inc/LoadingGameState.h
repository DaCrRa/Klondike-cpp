/*
 * LoadingGameState.h
 *
 *  Created on: 8 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_LOGIC_INC_LOADINGGAME_H_
#define SRC_LOGIC_INC_LOADINGGAME_H_

#include <AppState.h>
#include <LoadGameController.h>

#include <memory>

class LoadingGameState: public AppState {
private:
    AppStatePtr previousState;
    std::shared_ptr<LoadGameController>& loadGameController;
public:
    LoadingGameState(AppStatesBuilder& sb, std::shared_ptr<LoadGameController>& lgc);
    void setPreviousState(AppStatePtr prev) {
        previousState = prev;
    }
    ControllerPtr getController();
    AppStatePtr transitionToGameInProgress();
    AppStatePtr transitionToNoGameInProgress();
};

#endif /* SRC_LOGIC_INC_LOADINGGAME_H_ */
