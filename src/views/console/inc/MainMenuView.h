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

#include <memory>

class MainMenuView : public GameActionControllerVisitor {
private:
    size_t userControllerIndex;
    size_t randomControllerIndex;

    void startGame(StartController* startController, size_t gameActionControllerIndex);

    std::function<void(size_t&)> assignGameActionControllerIndex;
public:
    void interact(StartController* controller);
    void visit(UserGameActionController* userController);
    void visit(RandomGameActionController* randomController);
};

#endif /* SRC_VIEWS_CONSOLE_MAINMENUVIEW_H_ */
