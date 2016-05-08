/*
 * MoveCardView.h
 *
 *  Created on: 7 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_VIEWS_CONSOLE_MOVECARDVIEW_H_
#define SRC_VIEWS_CONSOLE_MOVECARDVIEW_H_

#include <MoveCardController.h>
#include <Move.h>

#include <map>

class MoveCardView {
private:
	MoveCardController* controller;
	std::map<GameElement*, char> origins;

	std::map<char, MoveOrigin*> getPossibleOrigins();
	std::map<char, MoveDest*> getPossibleDests(MoveOrigin* origin);
public:
	MoveCardView(MoveCardController* c);
	void completeMove(Move* m);
};

#endif /* SRC_VIEWS_CONSOLE_MOVECARDVIEW_H_ */
