/*
 * UserGameActionController.h
 *
 *  Created on: 12 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_USERGAMEACTIONCONTROLLER_H_
#define SRC_CONTROLLERS_INC_USERGAMEACTIONCONTROLLER_H_

#include <GameActionController.h>
#include <GameActionHistoryController.h>

#include <memory>

class UserGameActionController: public GameActionController {
private:
    std::shared_ptr<GameActionHistoryController>& historyController;
    class MoveOrigFinder : public KlondikeVisitor {
    private:
        std::vector<MoveOrigin*> possibleOrigins;
    public:
        void visitStock(Stock* stock);
        void visitTableauPile(TableauPile* tp);
        void visitFoundation(Foundation* f);
        std::vector<MoveOrigin*> getPossibleOrigins() {
            return possibleOrigins;
        }
    };
public:
    UserGameActionController(EventObserver& observer,
                             std::shared_ptr<Klondike>& g,
                             std::shared_ptr<GameActionHistoryController>& historyController) :
        GameActionController(observer, g),
        historyController(historyController) {};
    std::vector<MoveOrigin*> getPossibleMoveOrigins();
    void acceptGameActionControllerVisitor(GameActionControllerVisitor* visitor);
    std::shared_ptr<GameActionHistoryController> getGameActionHistoryController();
};

#endif /* SRC_CONTROLLERS_INC_USERGAMEACTIONCONTROLLER_H_ */
