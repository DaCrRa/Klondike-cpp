/*
 * GameActionControllerVisitor.h
 *
 *  Created on: 2 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_INC_GAMEACTIONCONTROLLERVISITOR_H_
#define SRC_INC_GAMEACTIONCONTROLLERVISITOR_H_

class UserGameActionController;
class RandomGameActionController;

class GameActionControllerVisitor {
public:
    virtual void visit(UserGameActionController* controller) = 0;
    virtual void visit(RandomGameActionController* controller) = 0;
    virtual ~GameActionControllerVisitor() {}
};

#endif /* SRC_INC_GAMEACTIONCONTROLLERVISITOR_H_ */
