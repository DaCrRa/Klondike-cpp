/*
 * MainMenuView.h
 *
 *  Created on: 15 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_VIEWS_CONSOLE_MAINMENUVIEW_H_
#define SRC_VIEWS_CONSOLE_MAINMENUVIEW_H_

#include <GameActionController.h>
#include <Klondike.h>

#include <memory>

class MainMenuView {
public:
	std::shared_ptr<GameActionController> getSelection(Klondike* k);
};

#endif /* SRC_VIEWS_CONSOLE_MAINMENUVIEW_H_ */
