/*
 * GameActionVisitor.h
 *
 *  Created on: 2 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_INC_GAMEACTIONVISITOR_H_
#define SRC_INC_GAMEACTIONVISITOR_H_

class StockAction;
class Move;

class ForwardGameActionVisitor {
public:
    virtual void visit(StockAction* stockAction) = 0;
    virtual void visit(Move* move) = 0;
    virtual ~ForwardGameActionVisitor() {}
};

#endif /* SRC_INC_GAMEACTIONVISITOR_H_ */
