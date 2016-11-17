/*
 * KlondikePlainTextDeserializer.cpp
 *
 *  Created on: 9 Nov 2016
 *      Author: dancre
 */

#include <KlondikePlainTextDeserializer.h>
#include <KlondilePlainTextSerializerDeserializerConstants.h>
#include <KlondikeDeserializedInitParameters.h>
#include <KlondikeImpl.h>

#include <istream>

std::istream& operator>>(std::istream& is, DeckType& type) {
    int deckTypeAsInt;
    is >> deckTypeAsInt;
    type = static_cast<DeckType>(deckTypeAsInt);
    return is;
}

std::vector<int> KlondikePlainTextDeserializer::deserializePile(
    std::string& readString,
    std::istream& inputStream,
    const std::string& endMark) {

    std::vector<int> deckIndexes;
    while (readString != endMark) {
        deckIndexes.push_back(std::stoi(readString));
        inputStream >> readString;
    }
    inputStream >> readString;
    return deckIndexes;
}

void KlondikePlainTextDeserializer::deserialize(std::shared_ptr<Klondike>& g, std::istream& inputStream) {

    DeckType t;
    inputStream >> t;
    std::string readString;
    inputStream >> readString;
    if (readString != KlondikePlainTextSerializerDeserializer::DECKTYPE_END_MARK) {
        throw std::exception();
    }
    deckFactory->setSelectedDeck(t);

    KlondikeDeserializedInitParameters deserializedParameters;

    int score;
    inputStream >> score;
    deserializedParameters.setScore(score);

    inputStream >> readString;
    if (readString != KlondikePlainTextSerializerDeserializer::SCORE_END_MARK) {
        throw std::exception();
    }

    inputStream >> readString;
    deserializedParameters.setStockCardsIds(deserializePile(readString,
                                            inputStream,
                                            KlondikePlainTextSerializerDeserializer::STOCK_END_MARK));

    deserializedParameters.setWasteCardsIds(deserializePile(readString,
                                            inputStream,
                                            KlondikePlainTextSerializerDeserializer::WASTE_END_MARK));

    while (readString != KlondikePlainTextSerializerDeserializer::FOUNDATIONS_END_MARK) {
        deserializedParameters.addFoundation();
        deserializedParameters.setLastFoundationCardsIds(deserializePile(readString,
                inputStream,
                KlondikePlainTextSerializerDeserializer::FOUNDATION_END_MARK));
    }

    inputStream >> readString;
    while (readString != KlondikePlainTextSerializerDeserializer::TABLEAU_END_MARK) {
        deserializedParameters.addTableauPile();
        deserializedParameters.setLastTableauPileCoveredCardsIds(deserializePile(readString,
                inputStream,
                KlondikePlainTextSerializerDeserializer::TABLEAU_PILE_COVERED_END_MARK));

        deserializedParameters.setLastTableauPileUncoveredCardsIds(deserializePile(readString,
                inputStream,
                KlondikePlainTextSerializerDeserializer::TABLEAU_PILE_END_MARK));
    }

    g = std::shared_ptr<Klondike>(new KlondikeImpl(deckFactory->getDeck()));
    g->initialize(deserializedParameters);
}

