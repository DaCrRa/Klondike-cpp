/*
 * RandomGameActionController.cpp
 *
 *  Created on: 11 de may. de 2016
 *      Author: dancre
 */

#include <RandomGameActionController.h>
#include <StockAction.h>
#include <Move.h>

#include <vector>

RandomGameActionController::RandomGameActionController(Klondike* g) :
	game(g)
{

}

GameActionPtr RandomGameActionController::getAction() {
	std::vector<GameActionPtr> actions;
	if(game->getStock()->hasCards()) {
		actions.push_back(GameActionPtr(new StockAction()));
	}
	for (std::vector<MoveOrigin*>::iterator it = game->getPossibleMoveOrigins().begin(); it != game->getPossibleMoveOrigins().begin(); ++it) {
		std::vector<MoveDest*> moveDests = game->getPossibleMoveDests(*it);
		for (std::vector<MoveDest*>::iterator destIt = moveDests.begin(); destIt != moveDests.begin(); ++destIt) {
			Move m;
			m.setOrigin(*it);
			m.setDest(*destIt);
			actions.push_back(GameActionPtr(&m));
		}
	}
	return actions[0];
}

