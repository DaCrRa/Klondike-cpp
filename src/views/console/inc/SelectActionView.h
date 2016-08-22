/*
 * SelectActionView.h
 *
 *  Created on: 2 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_INC_SELECTACTIONVIEW_H_
#define SRC_INC_SELECTACTIONVIEW_H_

#include <ForwardGameAction.h>
#include <ForwardGameActionVisitor.h>
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

class SelectActionView : public ForwardGameActionVisitor {
private:
    void completeActionInfo(ForwardGameActionPtr& action);
    UserGameActionController* actionController;
public:
    SelectActionView(UserGameActionController* c);
    void getAction(ForwardGameActionPtr& action);
    void visit(StockAction* stockAction);
    void visit(Move* move);
};

#endif /* SRC_INC_SELECTACTIONVIEW_H_ */
