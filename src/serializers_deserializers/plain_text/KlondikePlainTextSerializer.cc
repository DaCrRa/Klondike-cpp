/*
 * KlondikePlainTextSerializer.cpp
 *
 *  Created on: 6 Nov 2016
 *      Author: dancre
 */

#include <KlondikePlainTextSerializer.h>

void KlondikePlainTextSerializer::serialize(std::ostream& os) {
    KlondikePlainTextSerializerVisitor visitor(os);
    game->accept(&visitor);
}

void KlondikePlainTextSerializer::KlondikePlainTextSerializerVisitor::visitScore(int score) {
    outputStream << score << std::endl;
    outputStream << "END_OF_SCORE" << std::endl;
}

void KlondikePlainTextSerializer::KlondikePlainTextSerializerVisitor::visitStock(Stock* s) {
    StockPlainTextSerializer stockSerializer(outputStream);
    s->acceptStockVisitor(&stockSerializer);
}

void KlondikePlainTextSerializer::KlondikePlainTextSerializerVisitor::visitFoundation(Foundation* f) {
    outputStream << "END_OF_FOUNDATION" << std::endl;
}

void KlondikePlainTextSerializer::KlondikePlainTextSerializerVisitor::allFoundationsVisited() {
    outputStream << "END_OF_FOUNDATIONS" << std::endl;
}

void KlondikePlainTextSerializer::KlondikePlainTextSerializerVisitor::visitTableauPile(TableauPile* tp) {
    TableauPilePlainTextSerializer serializer(outputStream);
    tp->acceptTableauPileVisitor(&serializer);
}

void KlondikePlainTextSerializer::KlondikePlainTextSerializerVisitor::allTableauPilesVisited() {
    outputStream << "END_OF_TABLEAU" << std::endl;
}

void KlondikePlainTextSerializer::StockPlainTextSerializer::visitCoveredCard(const Card* covered) {
    outputStream << covered->getRank() << std::endl;
}

void KlondikePlainTextSerializer::StockPlainTextSerializer::allCoveredCardsVisited() {
    outputStream << "END_OF_STOCK" << std::endl;
}

void KlondikePlainTextSerializer::StockPlainTextSerializer::visitWasteCard(const Card* wasteCard) {
    outputStream << wasteCard->getRank() << std::endl;
}
void KlondikePlainTextSerializer::StockPlainTextSerializer::allWasteCardsVisited() {
    outputStream << "END_OF_WASTE" << std::endl;
}

void KlondikePlainTextSerializer::TableauPilePlainTextSerializer::visitCoveredCard(const Card* covered) {
    outputStream << covered->getRank() << std::endl;
}

void KlondikePlainTextSerializer::TableauPilePlainTextSerializer::allCoveredCardsVisited() {
    outputStream << "END_OF_TABLEAU_COVERED" << std::endl;
}

void KlondikePlainTextSerializer::TableauPilePlainTextSerializer::visitUncoveredCard(const Card* uncovered) {
    outputStream << uncovered->getRank() << std::endl;
}

void KlondikePlainTextSerializer::TableauPilePlainTextSerializer::allUncoveredCardsVisited() {
    outputStream << "END_OF_TABLEAU_PILE" << std::endl;
}
