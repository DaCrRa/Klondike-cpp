/*
 * GameActionVisitor.h
 *
 *  Created on: 2 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_INC_GAMEACTIONVISITOR_H_
#define SRC_INC_GAMEACTIONVISITOR_H_

class StockAction;

class GameActionVisitor {
public:
	virtual void visit(StockAction* stockAction) = 0;
	virtual ~GameActionVisitor() {}
};

#endif /* SRC_INC_GAMEACTIONVISITOR_H_ */
