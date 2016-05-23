/*
 * MoveCardView.h
 *
 *  Created on: 7 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_VIEWS_CONSOLE_MOVECARDVIEW_H_
#define SRC_VIEWS_CONSOLE_MOVECARDVIEW_H_

#include <GameActionController.h>
#include <Move.h>

#include <map>

class MoveCardView {
private:
    GameActionController* controller;
    std::map<GameElement*, char> gameElementTag;

    std::map<char, MoveOrigin*> tagPossibleOrigins();
    std::map<char, MoveDest*> tagPossibleDests(MoveOrigin* origin);
public:
    MoveCardView(GameActionController* c);
    void completeMove(Move* m);
};

#endif /* SRC_VIEWS_CONSOLE_MOVECARDVIEW_H_ */
