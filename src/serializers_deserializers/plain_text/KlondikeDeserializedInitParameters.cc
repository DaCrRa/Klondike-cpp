/*
 * KlondikeDeserializedInitParameters.cc
 *
 *  Created on: 10 Nov 2016
 *      Author: dancre
 */

#include <KlondikeDeserializedInitParameters.h>

void TableauPileDeserializedInitParameters::setCoveredCardsIds(std::vector<int>&& indexes) {
    coveredCardsIds = indexes;
}

void TableauPileDeserializedInitParameters::setUncoveredCardsIds(std::vector<int>&& indexes) {
    uncoveredCardsIds = indexes;
}

void KlondikeDeserializedInitParameters::setStockCardsIds(std::vector<int>&& indexes) {
    stockCardsIds = indexes;
}

void KlondikeDeserializedInitParameters::setWasteCardsIds(std::vector<int>&& indexes) {
    wasteCardsIds = indexes;
}

void KlondikeDeserializedInitParameters::addFoundation() {
    foundationsCardsIds.push_back(std::vector<int>());
}

void KlondikeDeserializedInitParameters::setLastFoundationCardsIds(std::vector<int>&& indexes) {
    foundationsCardsIds.back() = indexes;
}

void KlondikeDeserializedInitParameters::setScore(int score) {
    this->score = score;
}

void KlondikeDeserializedInitParameters::addTableauPile() {
    lastTableauPileParams = std::shared_ptr<TableauPileDeserializedInitParameters>(new TableauPileDeserializedInitParameters());
    tableauInitParams.push_back(std::shared_ptr<TableauPileInitParameters>(lastTableauPileParams));
}

void KlondikeDeserializedInitParameters::setLastTableauPileCoveredCardsIds(std::vector<int>&& indexes) {
    lastTableauPileParams->setCoveredCardsIds(std::move(indexes));
}

void KlondikeDeserializedInitParameters::setLastTableauPileUncoveredCardsIds(std::vector<int>&& indexes) {
    lastTableauPileParams->setUncoveredCardsIds(std::move(indexes));
}
