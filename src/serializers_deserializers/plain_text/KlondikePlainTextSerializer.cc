/*
 * KlondikePlainTextSerializer.cpp
 *
 *  Created on: 6 Nov 2016
 *      Author: dancre
 */

#include <KlondikePlainTextSerializer.h>
#include <KlondilePlainTextSerializerDeserializerConstants.h>

void KlondikePlainTextSerializer::serialize(std::shared_ptr<Klondike>& g, std::ostream& os) {
    KlondikePlainTextSerializerVisitor visitor(os);
    g->accept(&visitor);
}

void KlondikePlainTextSerializer::KlondikePlainTextSerializerVisitor::visitScore(int score) {
    outputStream << score << std::endl;
    outputStream << KlondikePlainTextSerializerDeserializer::SCORE_END_MARK << std::endl;
}

void KlondikePlainTextSerializer::KlondikePlainTextSerializerVisitor::visitStock(Stock* s) {
    StockPlainTextSerializer stockSerializer(outputStream);
    s->acceptStockVisitor(&stockSerializer);
}

void KlondikePlainTextSerializer::KlondikePlainTextSerializerVisitor::visitFoundation(Foundation* f) {
    outputStream << KlondikePlainTextSerializerDeserializer::FOUNDATION_END_MARK << std::endl;
}

void KlondikePlainTextSerializer::KlondikePlainTextSerializerVisitor::allFoundationsVisited() {
    outputStream << KlondikePlainTextSerializerDeserializer::FOUNDATIONS_END_MARK << std::endl;
}

void KlondikePlainTextSerializer::KlondikePlainTextSerializerVisitor::visitTableauPile(TableauPile* tp) {
    TableauPilePlainTextSerializer serializer(outputStream);
    tp->acceptTableauPileVisitor(&serializer);
}

void KlondikePlainTextSerializer::KlondikePlainTextSerializerVisitor::allTableauPilesVisited() {
    outputStream << KlondikePlainTextSerializerDeserializer::TABLEAU_END_MARK << std::endl;
}

void KlondikePlainTextSerializer::StockPlainTextSerializer::visitCoveredCard(const Card* covered) {
    outputStream << covered->getCardId() << std::endl;
}

void KlondikePlainTextSerializer::StockPlainTextSerializer::allCoveredCardsVisited() {
    outputStream << KlondikePlainTextSerializerDeserializer::STOCK_END_MARK << std::endl;
}

void KlondikePlainTextSerializer::StockPlainTextSerializer::visitWasteCard(const Card* wasteCard) {
    outputStream << wasteCard->getCardId() << std::endl;
}
void KlondikePlainTextSerializer::StockPlainTextSerializer::allWasteCardsVisited() {
    outputStream << KlondikePlainTextSerializerDeserializer::WASTE_END_MARK << std::endl;
}

void KlondikePlainTextSerializer::TableauPilePlainTextSerializer::visitCoveredCard(const Card* covered) {
    outputStream << covered->getCardId() << std::endl;
}

void KlondikePlainTextSerializer::TableauPilePlainTextSerializer::allCoveredCardsVisited() {
    outputStream << KlondikePlainTextSerializerDeserializer::TABLEAU_PILE_COVERED_END_MARK << std::endl;
}

void KlondikePlainTextSerializer::TableauPilePlainTextSerializer::visitUncoveredCard(const Card* uncovered) {
    outputStream << uncovered->getCardId() << std::endl;
}

void KlondikePlainTextSerializer::TableauPilePlainTextSerializer::allUncoveredCardsVisited() {
    outputStream << KlondikePlainTextSerializerDeserializer::TABLEAU_PILE_END_MARK << std::endl;
}
