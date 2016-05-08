/*
 * MoveCardView.cpp
 *
 *  Created on: 7 de may. de 2016
 *      Author: dancre
 */

#include <MoveCardView.h>

#include <ItemSelectionDialog.h>

MoveCardView::MoveCardView(MoveCardController* c) :
	controller(c)
{
	Klondike* game = controller->getGame();
	origins.insert(std::pair<GameElement*, char>(game->getStock(), 's'));
	char foundationTag = 'A';
	for (std::vector<Foundation>::iterator it = game->getFoundations().begin() ; it != game->getFoundations().end() ; ++it) {
		origins.insert(std::pair<GameElement*, char>(it.base(), foundationTag++));
	}
}

void MoveCardView::completeMove(Move* move) {
	std::map<char, MoveOrigin*> possibleOrigins = getPossibleOrigins();
	ItemSelectionDialog<MoveOrigin*> dialogFrom("Move from: ", possibleOrigins, 'c');
	MoveOrigin* origin = dialogFrom.getSelectedItem();
	std::map<char, MoveDest*> possibleDests = getPossibleDests(origin);
	ItemSelectionDialog<MoveDest*> dialogTo("Move to: ", possibleDests, 'c');
	MoveDest* dest = dialogTo.getSelectedItem();
	move->setOrigin(origin);
	move->setDest(dest);
}

std::map<char, MoveOrigin*> MoveCardView::getPossibleOrigins() {
	std::map<char, MoveOrigin*> possibleOrigins;
	std::vector<MoveOrigin*> availableOrigins = controller->getAvailableOrigins();
	for (std::vector<MoveOrigin*>::iterator it = availableOrigins.begin(); it != availableOrigins.end(); ++it) {
		possibleOrigins[origins[*it]] = *it;
	}
	return possibleOrigins;
}

std::map<char, MoveDest*> MoveCardView::getPossibleDests(MoveOrigin* origin) {
	std::map<char, MoveDest*> possibleDests;
	std::vector<MoveDest*> availableDests = controller->getAvailableDests(origin);
	for (std::vector<MoveDest*>::iterator it = availableDests.begin(); it != availableDests.end(); ++it) {
		possibleDests[origins[*it]] = *it;
	}
	return possibleDests;
}
