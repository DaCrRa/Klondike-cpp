/*
 * GameConsoleView.h
 *
 *  Created on: 8 Apr 2016
 *      Author: dancre
 */

#ifndef SRC_GAMECONSOLEVIEW_H_
#define SRC_GAMECONSOLEVIEW_H_

#include <ForwardGameActionController.h>
#include <GameActionControllerVisitor.h>
#include <KlondikeConsoleRenderer.h>
#include <Klondike.h>

class GameView : public GameActionControllerVisitor {
private:
    KlondikeConsoleRenderer renderer;
    ForwardGameActionPtr gameAction;

    void selectGameAction(GameActionController* controller);
public:
    GameView(std::shared_ptr<Klondike>& game) : renderer(game) {};
    void interact(GameActionController* c);
    void visit(UserGameActionController* c);
    void visit(RandomGameActionController* c);
};

#endif
