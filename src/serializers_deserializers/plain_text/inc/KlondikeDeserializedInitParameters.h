/*
 * KlondikeDeserializedInitParameters.h
 *
 *  Created on: 10 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_SERIALIZERS_DESERIALIZERS_PLAIN_TEXT_INC_KLONDIKEDESERIALIZEDINITPARAMETERS_H_
#define SRC_SERIALIZERS_DESERIALIZERS_PLAIN_TEXT_INC_KLONDIKEDESERIALIZEDINITPARAMETERS_H_

#include <KlondikeInitParameters.h>

class TableauPileDeserializedInitParameters : public TableauPileInitParameters {
public:
    void setCoveredCardsIds(std::vector<int>&& indexes);
    void setUncoveredCardsIds(std::vector<int>&& indexes);
};

class KlondikeDeserializedInitParameters: public KlondikeInitParameters {
private:
    std::shared_ptr<TableauPileDeserializedInitParameters> lastTableauPileParams;
public:
    void setStockCardsIds(std::vector<int>&& indexes);
    void setWasteCardsIds(std::vector<int>&& indexes);
    void addFoundation();
    void addTableauPile();
    void setLastFoundationCardsIds(std::vector<int>&& indexes);
    void setLastTableauPileCoveredCardsIds(std::vector<int>&& indexes);
    void setLastTableauPileUncoveredCardsIds(std::vector<int>&& indexes);
    void setScore(int score);
};

#endif /* SRC_SERIALIZERS_DESERIALIZERS_PLAIN_TEXT_INC_KLONDIKEDESERIALIZEDINITPARAMETERS_H_ */
