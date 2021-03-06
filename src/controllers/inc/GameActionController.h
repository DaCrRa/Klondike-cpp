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
    std::shared_ptr<Klondike> game;

    class MoveDestFinder : public KlondikeVisitor {
    private:
        MoveOrigin* origin;
        int numberOfCards;
        std::vector<MoveDest*> possibleDests;
        void checkIfIsPossibleDestAndAddIt(MoveDest* dest);
    public:
        MoveDestFinder(MoveOrigin* orig, int n) :
            origin(orig),
            numberOfCards(n) {}
        void visitTableauPile(TableauPile* tp);
        void visitFoundation(Foundation* f);
        std::vector<MoveDest*> getPossibleDests() {
            return possibleDests;
        }
    };

public:
    GameActionController(EventObserver& observer) :
        observer(observer) {};
    void setGame(std::shared_ptr<Klondike>& g) {
        game = g;
    }
    std::shared_ptr<Klondike>& getGame();
    void pauseGame();
    void doAction(GameActionPtr action);
    virtual void acceptGameActionControllerVisitor(GameActionControllerVisitor* visitor) = 0;
    void accept(ControllerVisitor* visitor);
    std::vector<MoveDest*> getPossibleMoveDests(MoveOrigin* origin, int numberOfCards = 1);
    ~GameActionController() {}
};

#endif /* SRC_INC_GAMEACTIONCONTROLLER_H_ */
