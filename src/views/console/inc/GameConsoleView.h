/*
 * GameConsoleView.h
 *
 *  Created on: 8 Apr 2016
 *      Author: dancre
 */

#ifndef SRC_GAMECONSOLEVIEW_H_
#define SRC_GAMECONSOLEVIEW_H_

#include <GameActionController.h>
#include <GameActionControllerVisitor.h>
#include <KlondikeConsoleRenderer.h>
#include <Klondike.h>

class GameConsoleView : public GameActionControllerVisitor {
private:
    KlondikeConsoleRenderer renderer;
    GameActionPtr gameAction;

    void selectGameAction(GameActionController* controller);
public:
    GameConsoleView(std::shared_ptr<Klondike>& game) : renderer(game) {};
    void interact(GameActionController* c);
    void visit(UserGameActionController* c);
    void visit(RandomGameActionController* c);
};

#endif
