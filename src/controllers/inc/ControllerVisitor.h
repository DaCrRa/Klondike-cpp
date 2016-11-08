/*
 * ControllerVisitor.h
 *
 *  Created on: 23 de abr. de 2016
 *      Author: dancre
 */

#ifndef SRC_INC_CONTROLLERVISITOR_H_
#define SRC_INC_CONTROLLERVISITOR_H_

class GameActionController;
class StartController;
class BestScoresController;
class SaveGameController;
class LoadGameController;

class ControllerVisitor {
public:
    virtual void visit(GameActionController* sc) = 0;
    virtual void visit(StartController* sc) = 0;
    virtual void visit(BestScoresController* sc) = 0;
    virtual void visit(SaveGameController* sc) = 0;
    virtual void visit(LoadGameController* sc) = 0;
    virtual ~ControllerVisitor() {}
};

#endif /* SRC_INC_CONTROLLERVISITOR_H_ */
