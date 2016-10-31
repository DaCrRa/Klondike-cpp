/*
 * DemoInProgressState.h
 *
 *  Created on: 1 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_DEMOINPROGRESSSTATE_H_
#define SRC_CONTROLLERS_INC_DEMOINPROGRESSSTATE_H_

#include <KlondikeAppState.h>
#include <RandomGameActionController.h>

class DemoInProgressState: public KlondikeAppState {
public:
    ControllerPtr getController(KlondikeAppStateContext& context) {
        return ControllerPtr(new RandomGameActionController(context));
    }
};

#endif /* SRC_CONTROLLERS_INC_DEMOINPROGRESSSTATE_H_ */
