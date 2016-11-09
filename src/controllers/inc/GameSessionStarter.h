/*
 * GameSessionStarter.h
 *
 *  Created on: 8 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_GAMESESSIONSTARTER_H_
#define SRC_CONTROLLERS_INC_GAMESESSIONSTARTER_H_

#include <Klondike.h>
#include <GameActionControllerHolder.h>

class GameSessionStarter {
private:
    std::shared_ptr<Klondike>& game;
    GameActionControllerHolder& gameActionControllerHolder;
public:
    GameSessionStarter(std::shared_ptr<Klondike>& g,
                       GameActionControllerHolder& gach) :
        game(g),
        gameActionControllerHolder(gach) {}
    void startSession(std::shared_ptr<Klondike>& g,
                      std::shared_ptr<GameActionController> actionController);
};

#endif /* SRC_CONTROLLERS_INC_GAMESESSIONSTARTER_H_ */
