/*
 * GameConsoleView.h
 *
 *  Created on: 8 Apr 2016
 *      Author: dancre
 */

#ifndef SRC_GAMECONSOLEVIEW_H_
#define SRC_GAMECONSOLEVIEW_H_

#include <Controller.h>
#include <ControllerVisitor.h>
#include <GameActionController.h>
#include <KlondikeConsoleRenderer.h>
#include <Klondike.h>

class GameConsoleView : public ControllerVisitor {
private:
	KlondikeConsoleRenderer renderer;
public:
	GameConsoleView(Klondike* k);
	void interact(Controller* c);
	void visit(GameActionController* c);
};

#endif
