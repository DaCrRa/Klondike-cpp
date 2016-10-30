/*
 * MoveScoreCalculator.cc
 *
 *  Created on: 13 de ago. de 2016
 *      Author: dancre
 */

#include <MoveScoreCalculator.h>

#include <MoveFromTableauPile.h>
#include <MoveFromStock.h>
#include <MoveFromFoundation.h>

int MoveScoreCalculator::DestScoreCalculator::getScoreDelta() const {
    return scoreDelta;
}

void MoveScoreCalculator::FromStock::visit(TableauPile* tableauPile) {
    scoreDelta = MoveScoreCalculator::WASTE_TO_TABLEAU;
}

void MoveScoreCalculator::FromStock::visit(Foundation* foundation) {
    scoreDelta = MoveScoreCalculator::WASTE_TO_FOUNDATION;
}

void MoveScoreCalculator::FromTableauPile::visit(TableauPile* tableauPile) {
    scoreDelta = 0;
}

void MoveScoreCalculator::FromTableauPile::visit(Foundation* foundation) {
    scoreDelta = MoveScoreCalculator::TABLEAU_TO_FOUNDATION;
}

void MoveScoreCalculator::FromFoundation::visit(TableauPile* tableauPile) {
    scoreDelta = MoveScoreCalculator::FOUNDATION_TO_TABLEAU;
}

void MoveScoreCalculator::FromFoundation::visit(Foundation* foundation) {
    scoreDelta = 0;
}

void MoveScoreCalculator::visit(MoveFromStock* move) {
    FromStock destVisitor;
    move->acceptDestVisitor(&destVisitor);
    scoreDelta = destVisitor.getScoreDelta();
}
void MoveScoreCalculator::visit(MoveFromTableauPile* move) {
    FromTableauPile destVisitor;
    move->acceptDestVisitor(&destVisitor);
    scoreDelta = destVisitor.getScoreDelta();
    if (move->cardWasTurnUp()) {
        scoreDelta += TURN_UP_TABLEAU_CARD;
    }
}

void MoveScoreCalculator::visit(MoveFromFoundation* move) {
    FromFoundation destVisitor;
    move->acceptDestVisitor(&destVisitor);
    scoreDelta = destVisitor.getScoreDelta();
}
