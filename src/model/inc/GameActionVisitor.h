/*
 * GameActionVisitor.h
 *
 *  Created on: 30 de ago. de 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_GAMEACTIONVISITOR_H_
#define SRC_MODEL_INC_GAMEACTIONVISITOR_H_

class ForwardGameAction;
class UndoGameAction;

class GameActionVisitor {
public:
    virtual void visit(ForwardGameAction* fwdGameAction);
    virtual void visit(UndoGameAction* undoGameAction);
    virtual ~GameActionVisitor() {}
};

#endif /* SRC_MODEL_INC_GAMEACTIONVISITOR_H_ */
