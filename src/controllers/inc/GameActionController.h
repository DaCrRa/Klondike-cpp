/*
 * GameActionController.h
 *
 *  Created on: 24 de abr. de 2016
 *      Author: dancre
 */

#ifndef SRC_INC_GAMEACTIONCONTROLLER_H_
#define SRC_INC_GAMEACTIONCONTROLLER_H_

#include <Klondike.h>
#include <Controller.h>
#include <ControllerVisitor.h>
#include <ForwardGameAction.h>
#include <ForwardGameActionVisitor.h>
#include <GameActionControllerVisitor.h>
#include <EventObserver.h>

class GameActionController: public Controller {
protected:
    EventObserver& observer;
    std::shared_ptr<Klondike>& game;

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

    class MoveDestFinder : public KlondikeVisitor {
    private:
        MoveOrigin* origin;
        std::vector<MoveDest*> possibleDests;
    public:
        MoveDestFinder(MoveOrigin* orig) : origin(orig) {}
        void visitTableauPile(TableauPile* tp);
        void visitFoundation(Foundation* f);
        std::vector<MoveDest*> getPossibleDests() {
            return possibleDests;
        }
    };

public:
    GameActionController(EventObserver& observer, std::shared_ptr<Klondike>& g) :
        observer(observer),
        game(g) {};
    std::shared_ptr<Klondike>& getGame();
    void pauseGame();
    void doAction(GameActionPtr action);
    virtual void acceptGameActionControllerVisitor(GameActionControllerVisitor* visitor) = 0;
    void accept(ControllerVisitor* visitor);
    std::vector<MoveOrigin*> getPossibleMoveOrigins();
    std::vector<MoveDest*> getPossibleMoveDests(MoveOrigin* origin);
    ~GameActionController() {}
};

#endif /* SRC_INC_GAMEACTIONCONTROLLER_H_ */
