/*
 * SavingGameState.h
 *
 *  Created on: 5 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_LOGIC_INC_SAVINGGAMESTATE_H_
#define SRC_LOGIC_INC_SAVINGGAMESTATE_H_

#include <AppState.h>
#include <SaveGameController.h>

class SavingGameState: public AppState {
private:
    std::shared_ptr<SaveGameController>& saveGameController;
public:
    SavingGameState(AppStatesBuilder& sb, std::shared_ptr<SaveGameController>& sgc);
    ControllerPtr getController();
    AppStatePtr transitionToNoGameInProgress();
};

#endif /* SRC_LOGIC_INC_SAVINGGAMESTATE_H_ */
