/*
 * MainMenuView.h
 *
 *  Created on: 15 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_VIEWS_CONSOLE_MAINMENUVIEW_H_
#define SRC_VIEWS_CONSOLE_MAINMENUVIEW_H_

#include <StartController.h>
#include <GameActionControllerVisitor.h>
#include <EventObserver.h>

#include <memory>

class MainMenuView {
private:
    EventObserver& eventObserver;
public:
    MainMenuView(EventObserver& observer) :
        eventObserver(observer) {}
    void interact(StartController* controller);
};

#endif /* SRC_VIEWS_CONSOLE_MAINMENUVIEW_H_ */
