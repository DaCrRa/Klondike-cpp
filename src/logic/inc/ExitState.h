/*
 * ExitState.h
 *
 *  Created on: 1 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_EXITSTATE_H_
#define SRC_CONTROLLERS_INC_EXITSTATE_H_

#include <AppState.h>

class ExitState : public AppState {
public:
    ExitState(AppStatesBuilder& sb) :
        AppState(sb) {}
    ControllerPtr getController() {
        throw NoMoreControllersException();
    }
};

#endif /* SRC_CONTROLLERS_INC_EXITSTATE_H_ */
