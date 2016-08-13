/*
 * MoveScoreCalculator.cc
 *
 *  Created on: 13 de ago. de 2016
 *      Author: dancre
 */

#include <MoveScoreCalculator.h>

int MoveScoreCalculator::DestScoreCalculator::getScoreDelta() const {
    return scoreDelta;
}

void MoveScoreCalculator::FromStock::visit(TableauPile* tableauPile) {

}

void MoveScoreCalculator::FromStock::visit(Foundation* foundation) {

}

void MoveScoreCalculator::FromTableauPile::visit(TableauPile* tableauPile) {

}

void MoveScoreCalculator::FromTableauPile::visit(Foundation* foundation) {

}

void MoveScoreCalculator::FromFoundation::visit(TableauPile* tableauPile) {

}

void MoveScoreCalculator::FromFoundation::visit(Foundation* foundation) {

}

void MoveScoreCalculator::visit(Stock* stock) {
    FromStock destVisitor;
    move->acceptDestVisitor(&destVisitor);
    scoreDelta = destVisitor.getScoreDelta();
}
void MoveScoreCalculator::visit(TableauPile* tableauPile) {
    FromTableauPile destVisitor;
    move->acceptDestVisitor(&destVisitor);
    scoreDelta = destVisitor.getScoreDelta();
}
void MoveScoreCalculator::visit(Foundation* foundation) {
    FromFoundation destVisitor;
    move->acceptDestVisitor(&destVisitor);
    scoreDelta = destVisitor.getScoreDelta();
}
int MoveScoreCalculator::getScoreDelta() const {
    return scoreDelta;
}
