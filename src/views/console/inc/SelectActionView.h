/*
 * SelectActionView.h
 *
 *  Created on: 2 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_INC_SELECTACTIONVIEW_H_
#define SRC_INC_SELECTACTIONVIEW_H_

#include <GameAction.h>
#include <GameActionVisitor.h>
#include <UserGameActionController.h>

#include <map>

class NoActionException : public std::exception {
public:
	const char* what() const throw() {
		return "No action selected!";
	}
};

class IncompleteMoveException : public std::exception {
public:
	const char* what() const throw() {
		return "Movement cancelled!";
	}
};

class SelectActionView : public GameActionVisitor {
private:
	void completeActionInfo(GameActionPtr& action);
	UserGameActionController* actionController;
public:
	SelectActionView(UserGameActionController* c);
	void getAction(GameActionPtr& action);
	void visit(StockAction* stockAction);
	void visit(Move* move);
};

#endif /* SRC_INC_SELECTACTIONVIEW_H_ */
