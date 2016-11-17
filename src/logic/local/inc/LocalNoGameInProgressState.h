/*
 * LocalNoGameInProgressState.h
 *
 *  Created on: 17 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_LOGIC_LOCAL_INC_LOCALNOGAMEINPROGRESSSTATE_H_
#define SRC_LOGIC_LOCAL_INC_LOCALNOGAMEINPROGRESSSTATE_H_

#include <NoGameInProgress.h>

class LocalNoGameInProgressState : public NoGameInProgressState {
public:
    LocalNoGameInProgressState(AppStatesBuilder& sb,
                               std::shared_ptr<AbstractDeckFactory> factory,
                               GameSessionStarter& starter,
                               EventObserver& eventObserver,
                               GameStatePtr gameState);
    ControllerPtr getController();
};

#endif /* SRC_LOGIC_LOCAL_INC_LOCALNOGAMEINPROGRESSSTATE_H_ */
