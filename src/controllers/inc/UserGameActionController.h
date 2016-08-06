/*
 * UserGameActionController.h
 *
 *  Created on: 12 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_USERGAMEACTIONCONTROLLER_H_
#define SRC_CONTROLLERS_INC_USERGAMEACTIONCONTROLLER_H_

#include <GameActionController.h>

class UserGameActionController: public GameActionController {
public:
    UserGameActionController(std::shared_ptr<Klondike>& game) : GameActionController(game) {};
    void acceptGameActionControllerVisitor(GameActionControllerVisitor* visitor);
};

#endif /* SRC_CONTROLLERS_INC_USERGAMEACTIONCONTROLLER_H_ */
