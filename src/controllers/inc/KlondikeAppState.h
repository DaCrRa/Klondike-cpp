/*
 * KlondikeAppState.h
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_KLONDIKEAPPSTATE_H_
#define SRC_CONTROLLERS_INC_KLONDIKEAPPSTATE_H_

#include <memory>

#include <Controller.h>

class KlondikeAppStateContext;

class KlondikeAppState;
typedef std::shared_ptr<KlondikeAppState> KlondikeAppStatePtr;

class KlondikeAppState {

public:
    virtual ControllerPtr getController(KlondikeAppStateContext& context) = 0;
    virtual ~KlondikeAppState() {}
};

#endif /* SRC_CONTROLLERS_INC_KLONDIKEAPPSTATE_H_ */
