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
#include <MoveOrigin.h>
#include <MoveCardController.h>

#include <map>

class SelectActionView : public GameActionVisitor {
private:
	std::map<char, GameActionPtr> availableActions;

	MoveCardController* controller;
	std::map<MoveOrigin*, char> origins;

	void completeActionInfo(GameActionPtr& action);
	std::map<char, MoveOrigin*> getPossibleOrigins();
public:
	SelectActionView(MoveCardController* c);
	GameActionPtr getAction();
	void visit(StockAction* stockAction);
	void visit(Move* move);
};

#endif /* SRC_INC_SELECTACTIONVIEW_H_ */
