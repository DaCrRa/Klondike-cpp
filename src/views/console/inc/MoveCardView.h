/*
 * MoveCardView.h
 *
 *  Created on: 7 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_VIEWS_CONSOLE_MOVECARDVIEW_H_
#define SRC_VIEWS_CONSOLE_MOVECARDVIEW_H_

#include <UserGameActionController.h>
#include <UserSelectedMove.h>

#include <map>

class MoveCardView : public MoveOriginVisitor {
private:
    UserGameActionController* controller;
    std::map<GameElement*, char> gameElementTag;

    MovePtr move;

    std::map<char, MoveOrigin*> tagPossibleOrigins();
    std::map<char, MoveDest*> tagPossibleDests(MoveOrigin* origin);
public:
    MoveCardView(UserGameActionController* c);
    void visit(Stock* s);
    void visit(Foundation* f);
    void visit(TableauPile* tp);
    void completeMove(UserSelectedMove* m);
};

#endif /* SRC_VIEWS_CONSOLE_MOVECARDVIEW_H_ */
