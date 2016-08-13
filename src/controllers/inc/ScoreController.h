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

class DestScoreCalculator : public MoveDestVisitor {
private:
    int scoreDelta;
public:
    int getScoreDelta() const {
        return scoreDelta;
    }
    virtual ~DestScoreCalculator() {}
};

class FromStock : public DestScoreCalculator {
public:
    void visit(TableauPile* tableauPile) {
        std::cout << "...and dest is a tableau pile" << std::endl;
    }
    void visit(Foundation* foundation) {
        std::cout << "...and dest is is a foundation" << std::endl;
    }
};

class FromTableauPile : public DestScoreCalculator {
public:
    void visit(TableauPile* tableauPile) {
        std::cout << "...and dest is a tableau pile" << std::endl;
    }
    void visit(Foundation* foundation) {
        std::cout << "...and dest is is a foundation" << std::endl;
    }
};

class FromFoundation : public DestScoreCalculator {
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
    int scoreDelta;
public:
    MoveScoreCalculator(Move* m) : move(m), scoreDelta(0) {}
    void visit(Stock* stock) {
        std::cout << "calculate score for move, origin is waste (stock)";
        FromStock destVisitor;
        move->acceptDestVisitor(&destVisitor);
        scoreDelta = destVisitor.getScoreDelta();
    }
    void visit(TableauPile* tableauPile) {
        std::cout << "calculate score for move, origin is a tableau pile";
        FromTableauPile destVisitor;
        move->acceptDestVisitor(&destVisitor);
        scoreDelta = destVisitor.getScoreDelta();
    }
    void visit(Foundation* foundation) {
        std::cout << "calculate score for move, origin is a foundation";
        FromFoundation destVisitor;
        move->acceptDestVisitor(&destVisitor);
        scoreDelta = destVisitor.getScoreDelta();
    }
    int getScoreDelta() const {
        return scoreDelta;
    }
};

class GameActionScoreCalculator : public GameActionVisitor {
private:
    int scoreDelta;
public:
    void visit(StockAction* stockAction) {
        std::cout << "calculate score for stock action @@@@@@@@@@" << std::endl;
    }
    void visit(Move* move) {
        MoveScoreCalculator calculator(move);
        move->acceptOriginVisitor(&calculator);
        scoreDelta = calculator.getScoreDelta();
    }
    int getScoreDelta() const {
        return scoreDelta;
    }
};

class ScoreController {
private:
    std::shared_ptr<Klondike>& game;
    int calculateScoreDelta(GameActionPtr gameAction);
    int scoreDelta;
public:
    ScoreController(std::shared_ptr<Klondike>& game);
    void updateScore(GameActionPtr gameAction);
};

#endif /* SRC_CONTROLLERS_SCORECONTROLLER_H_ */
