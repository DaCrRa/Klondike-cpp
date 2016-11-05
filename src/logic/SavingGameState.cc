/*
 * SavingGameState.cpp
 *
 *  Created on: 5 Nov 2016
 *      Author: dancre
 */

#include <SavingGameState.h>

#include <AppStatesBuilder.h>

SavingGameState::SavingGameState(AppStatesBuilder& sb, std::shared_ptr<SaveGameController>& sgc) :
    AppState(sb), saveGameController(sgc) {}

ControllerPtr SavingGameState::getController() {
    return saveGameController;
}

AppStatePtr SavingGameState::transitionToNoGameInProgress() {
    return statesBuilder.getPausedState();
}
