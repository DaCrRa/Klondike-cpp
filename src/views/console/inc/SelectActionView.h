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

#include <map>

class SelectActionView : public GameActionVisitor {
private:
	std::map<char, GameActionPtr> availableActions;
	void completeActionInfo(GameActionPtr& action);
public:
	SelectActionView();
	GameActionPtr getAction();
	void visit(StockAction* stockAction);
	void visit(Move* move);
};

#endif /* SRC_INC_SELECTACTIONVIEW_H_ */
