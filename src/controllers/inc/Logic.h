/*
 * Logic.h
 *
 *  Created on: 22 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_LOGIC_H_
#define SRC_CONTROLLERS_LOGIC_H_

#include <StartController.h>
#include <Klondike.h>
#include <GameActionControllerCatalog.h>
#include <BestScoresController.h>

#include <memory>

class NoMoreControllersException : public std::exception {
public:
    const char* what() const throw() {
        return "No more controllers!";
    }
};

class Logic {
private:
    std::shared_ptr<Klondike> game;
    GameActionControllerCatalog actionControllerCatalog;
    StartController startController;
    BestScoresController bestScoresController;
public:
    Logic();
    Controller* getNextController();
};

#endif /* SRC_CONTROLLERS_LOGIC_H_ */
