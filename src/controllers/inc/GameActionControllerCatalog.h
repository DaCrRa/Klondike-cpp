/*
 * GameActionControllerCatalog.h
 *
 *  Created on: 24 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_GAMEACTIONCONTROLLERCATALOG_H_
#define SRC_CONTROLLERS_GAMEACTIONCONTROLLERCATALOG_H_

#include <ForwardGameActionController.h>
#include <Klondike.h>
#include <memory>
#include <vector>

class GameActionControllerCatalog {
private:
    const std::vector<std::shared_ptr<GameActionController> > availableControllers;
    size_t selected;
public:
    GameActionControllerCatalog(std::shared_ptr<Klondike>& game);
    const std::vector<std::shared_ptr<GameActionController> >& getAvailableGameActionControllers();
    void selectGameActionController(size_t selected);
    std::shared_ptr<GameActionController> getSelectedGameActionController();
};

#endif /* SRC_CONTROLLERS_GAMEACTIONCONTROLLERCATALOG_H_ */
