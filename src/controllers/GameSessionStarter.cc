/*
 * GameSessionStarter.cpp
 *
 *  Created on: 8 Nov 2016
 *      Author: dancre
 */

#include <GameSessionStarter.h>

void GameSessionStarter::startSession(std::shared_ptr<GameActionController> actionController) {
    game = std::shared_ptr<Klondike>(new Klondike());
    actionController->setGame(game);
    game->initialize();
    gameActionControllerHolder.setGameActionController(actionController);
}

