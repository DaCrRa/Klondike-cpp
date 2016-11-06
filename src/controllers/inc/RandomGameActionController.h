/*
 * RandomGameActionController.h
 *
 *  Created on: 11 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_RANDOMGAMEACTIONCONTROLLER_H_
#define SRC_CONTROLLERS_RANDOMGAMEACTIONCONTROLLER_H_

#include <Klondike.h>
#include <GameActionController.h>

class RandomGameActionController : public GameActionController {
public:
    RandomGameActionController(EventObserver& observer, std::shared_ptr<Klondike>& g) :
        GameActionController(observer, g) {};
    void acceptGameActionControllerVisitor(GameActionControllerVisitor* v);
    ForwardGameActionPtr getAction();
};

#endif /* SRC_CONTROLLERS_RANDOMGAMEACTIONCONTROLLER_H_ */
