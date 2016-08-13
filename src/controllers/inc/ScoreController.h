/*
 * ScoreController.h
 *
 *  Created on: 6 de ago. de 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_SCORECONTROLLER_H_
#define SRC_CONTROLLERS_SCORECONTROLLER_H_

#include <Klondike.h>
#include <GameAction.h>
#include <GameActionVisitor.h>
#include <Move.h>

#include <iostream>

class FromStock : public MoveDestVisitor {
public:
    void visit(TableauPile* tableauPile) {
        std::cout << "...and dest is a tableau pile" << std::endl;
    }
    void visit(Foundation* foundation) {
        std::cout << "...and dest is is a foundation" << std::endl;
    }
};

class FromTableauPile : public MoveDestVisitor {
public:
    void visit(TableauPile* tableauPile) {
        std::cout << "...and dest is a tableau pile" << std::endl;
    }
    void visit(Foundation* foundation) {
        std::cout << "...and dest is is a foundation" << std::endl;
    }
};

class FromFoundation : public MoveDestVisitor {
public:
    void visit(TableauPile* tableauPile) {
        std::cout << "...and dest is a tableau pile" << std::endl;
    }
    void visit(Foundation* foundation) {
        std::cout << "...and dest is is a foundation" << std::endl;
    }
};

class MoveScoreCalculator : public MoveOriginVisitor {
private:
    Move* move;
public:
    MoveScoreCalculator(Move* m) : move(m) {}
    void visit(Stock* stock) {
        std::cout << "calculate score for move, origin is waste (stock)";
        FromStock destVisitor;
        move->acceptDestVisitor(&destVisitor);
    }
    void visit(TableauPile* tableauPile) {
        std::cout << "calculate score for move, origin is a tableau pile";
        FromTableauPile destVisitor;
        move->acceptDestVisitor(&destVisitor);
    }
    void visit(Foundation* foundation) {
        std::cout << "calculate score for move, origin is a foundation";
        FromFoundation destVisitor;
        move->acceptDestVisitor(&destVisitor);
    }
};

class ScoreController : public GameActionVisitor {
private:
    std::shared_ptr<Klondike>& game;
    int calculateScoreDelta(GameActionPtr gameAction);
public:
    ScoreController(std::shared_ptr<Klondike>& game);
    void updateScore(GameActionPtr gameAction);
    void visit(StockAction* stockAction);
    void visit(Move* move);
};

#endif /* SRC_CONTROLLERS_SCORECONTROLLER_H_ */
