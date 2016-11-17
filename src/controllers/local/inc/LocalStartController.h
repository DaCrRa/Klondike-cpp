/*
 * LocalStartController.h
 *
 *  Created on: 17 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_LOCAL_INC_LOCALSTARTCONTROLLER_H_
#define SRC_CONTROLLERS_LOCAL_INC_LOCALSTARTCONTROLLER_H_

#include <StartController.h>

class LocalStartController : public StartController {
private:
    void start(std::shared_ptr<GameActionController> gameActionController);
public:
    LocalStartController(std::shared_ptr<AbstractDeckFactory> factory,
                         GameSessionStarter& starter,
                         GameStatePtr state,
                         EventObserver& observer);
};

#endif /* SRC_CONTROLLERS_LOCAL_INC_LOCALSTARTCONTROLLER_H_ */
