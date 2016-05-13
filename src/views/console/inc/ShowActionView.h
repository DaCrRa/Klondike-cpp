/*
 * ShowActionView.h
 *
 *  Created on: 13 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_VIEWS_CONSOLE_SHOWACTIONVIEW_H_
#define SRC_VIEWS_CONSOLE_SHOWACTIONVIEW_H_

#include <GameActionVisitor.h>
#include <GameAction.h>

class ShowActionView : public GameActionVisitor {
private:
	GameActionPtr action;
public:
	ShowActionView(GameActionPtr action);
	void visit(StockAction* action);
	void visit(Move* action);
	void show();
};

#endif /* SRC_VIEWS_CONSOLE_SHOWACTIONVIEW_H_ */
