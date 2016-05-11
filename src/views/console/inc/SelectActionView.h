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
#include <GameActionController.h>

#include <map>

class SelectActionView : public GameActionVisitor {
private:
	void completeActionInfo(GameActionPtr& action);
	GameActionController* actionController;
public:
	SelectActionView(GameActionController* c);
	void getAction(GameActionPtr& action);
	void visit(StockAction* stockAction);
	void visit(Move* move);
};

#endif /* SRC_INC_SELECTACTIONVIEW_H_ */
