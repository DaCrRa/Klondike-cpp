/*
 * RemoteStartController.h
 *
 *  Created on: 22 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_REMOTE_INC_REMOTESTARTCONTROLLER_H_
#define SRC_CONTROLLERS_REMOTE_INC_REMOTESTARTCONTROLLER_H_

#include <StartController.h>

class RemoteStartController : public StartController {
private:
    std::shared_ptr<Klondike> instantiateKlondike();
public:
    RemoteStartController(std::shared_ptr<AbstractDeckFactory> factory,
                          GameSessionStarter& starter,
                          GameStatePtr state,
                          EventObserver& observer);
};

#endif /* SRC_CONTROLLERS_REMOTE_INC_REMOTESTARTCONTROLLER_H_ */
