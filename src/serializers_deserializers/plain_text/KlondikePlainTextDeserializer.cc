/*
 * KlondikePlainTextDeserializer.cpp
 *
 *  Created on: 9 Nov 2016
 *      Author: dancre
 */

#include <KlondikePlainTextDeserializer.h>
#include <KlondilePlainTextSerializerDeserializerConstants.h>

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

#include <iostream>
void KlondikePlainTextDeserializer::deserialize(std::shared_ptr<Klondike>& g, std::istream& inputStream) {
    int score;
    inputStream >> score;
    std::cout << "Score is " << score << std::endl;
    std::string mark;
    inputStream >> mark;
    std::cout << "mark: " << mark << std::endl;
    if (mark != KlondikePlainTextSerializerDeserializer::SCORE_END_MARK) {

    } else {
        std::cout << "score ok" << std::endl;
    }

    std::string readString;
    inputStream >> readString;
    std::vector<int> stockIndexes = deserializePile(readString,
                                    inputStream,
                                    KlondikePlainTextSerializerDeserializer::STOCK_END_MARK);
    std::cout << "stock ok!" << std::endl;
    std::cout << stockIndexes.size() << std::endl;

    std::vector<int> wasteIndexes = deserializePile(readString,
                                    inputStream,
                                    KlondikePlainTextSerializerDeserializer::WASTE_END_MARK);
    std::cout << "waste ok!" << std::endl;
    std::cout << wasteIndexes.size() << std::endl;

    while (readString != KlondikePlainTextSerializerDeserializer::FOUNDATIONS_END_MARK) {
        std::vector<int> foundationIndexes = deserializePile(readString,
                                             inputStream,
                                             KlondikePlainTextSerializerDeserializer::FOUNDATION_END_MARK);
        std::cout << "foundation ok!" << std::endl;
        std::cout << foundationIndexes.size() << std::endl;
    }
    std::cout << "foundations ok!" << std::endl;

    inputStream >> readString;
    while (readString != KlondikePlainTextSerializerDeserializer::TABLEAU_END_MARK) {
        std::vector<int> tableauCoveredIndexes = deserializePile(readString,
                inputStream,
                KlondikePlainTextSerializerDeserializer::TABLEAU_PILE_COVERED_END_MARK);
        std::cout << "tableau pile covered ok!" << std::endl;
        std::cout << tableauCoveredIndexes.size() << std::endl;

        std::vector<int> tableauUncoveredIndexes = deserializePile(readString,
                inputStream,
                KlondikePlainTextSerializerDeserializer::TABLEAU_PILE_END_MARK);
        std::cout << "tableau pile ok!" << std::endl;
        std::cout << tableauUncoveredIndexes.size() << std::endl;
    }
    std::cout << "tableau ok!" << std::endl;

    g = std::shared_ptr<Klondike>(new Klondike());
}

