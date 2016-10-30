/*
 * ShowActionView.h
 *
 *  Created on: 13 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_VIEWS_CONSOLE_SHOWACTIONVIEW_H_
#define SRC_VIEWS_CONSOLE_SHOWACTIONVIEW_H_

#include <ForwardGameAction.h>
#include <ForwardGameActionVisitor.h>

class ShowActionView : public ForwardGameActionVisitor {
private:
    ForwardGameActionPtr action;
public:
    ShowActionView(ForwardGameActionPtr action);
    void visit(StockAction* action);
    void visit(Move* action);
    void show();
};

#endif /* SRC_VIEWS_CONSOLE_SHOWACTIONVIEW_H_ */
