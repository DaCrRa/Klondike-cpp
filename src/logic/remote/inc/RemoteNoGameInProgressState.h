/*
 * RemoteNoGameInProgressState.h
 *
 *  Created on: 22 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_LOGIC_REMOTE_INC_REMOTENOGAMEINPROGRESSSTATE_H_
#define SRC_LOGIC_REMOTE_INC_REMOTENOGAMEINPROGRESSSTATE_H_

#include <NoGameInProgress.h>

class RemoteNoGameInProgressState : public NoGameInProgressState {
public:
    RemoteNoGameInProgressState(AppStatesBuilder& sb,
                                std::shared_ptr<AbstractDeckFactory> factory,
                                GameSessionStarter& starter,
                                EventObserver& eventObserver,
                                GameStatePtr gameState);
    ControllerPtr getController();
};

#endif /* SRC_LOGIC_REMOTE_INC_REMOTENOGAMEINPROGRESSSTATE_H_ */
