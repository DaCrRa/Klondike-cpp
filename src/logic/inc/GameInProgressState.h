/*
 * GameInProgress.h
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_GAMEINPROGRESSSTATE_H_
#define SRC_CONTROLLERS_INC_GAMEINPROGRESSSTATE_H_

#include <UserGameActionController.h>
#include <State.h>

class GameInProgressState: public State {
private:
    EventObserver& eventObserver;
    std::shared_ptr<Klondike>& game;
    std::shared_ptr<GameActionHistoryController>& historyController;
public:
    GameInProgressState(StatesBuilder& sb,
                        EventObserver& observer,
                        std::shared_ptr<Klondike>& g,
                        std::shared_ptr<GameActionHistoryController>& h);
    ControllerPtr getController();
    StatePtr transitionToGamePaused();
    StatePtr transitionToGameCompleted();
};

#endif /* SRC_CONTROLLERS_INC_GAMEINPROGRESSSTATE_H_ */
