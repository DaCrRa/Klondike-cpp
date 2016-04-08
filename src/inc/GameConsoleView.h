/*
 * GameConsoleView.h
 *
 *  Created on: 8 Apr 2016
 *      Author: dancre
 */

#ifndef SRC_GAMECONSOLEVIEW_H_
#define SRC_GAMECONSOLEVIEW_H_

#include <Controller.h>
#include <KlondikeConsoleRenderer.h>
#include <Klondike.h>

class GameConsoleView {
private:
	KlondikeConsoleRenderer renderer;
public:
	GameConsoleView(Klondike* k);
	void interact(Controller* c);
};

#endif
