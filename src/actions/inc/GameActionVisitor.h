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
class RedoGameAction;
class UserSelectedMove;

class GameActionVisitor {
public:
    virtual void visit(ForwardGameAction* fwdGameAction) = 0;
    virtual void visit(UndoGameAction* undoGameAction) = 0;
    virtual void visit(RedoGameAction* undoGameAction) = 0;
    virtual void visit(UserSelectedMove* userSelectedMove) = 0;
    virtual ~GameActionVisitor() {}
};

#endif /* SRC_MODEL_INC_GAMEACTIONVISITOR_H_ */
