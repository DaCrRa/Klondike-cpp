/*
 * GameInProgress.h
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_GAMEINPROGRESSSTATE_H_
#define SRC_CONTROLLERS_INC_GAMEINPROGRESSSTATE_H_

#include <KlondikeAppState.h>

#include <UserGameActionController.h>

class GameInProgressState: public KlondikeAppState {
public:
    ControllerPtr getController(KlondikeAppStateContext& context) {
        return ControllerPtr(new UserGameActionController(context));
    }
};

#endif /* SRC_CONTROLLERS_INC_GAMEINPROGRESSSTATE_H_ */
