/*
 * KlondikeInitParameters.h
 *
 *  Created on: 10 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_KLONDIKEINITPARAMETERS_H_
#define SRC_MODEL_KLONDIKEINITPARAMETERS_H_

#include <vector>

#include <memory>

class TableauPileInitParameters {
protected:
    std::vector<int> coveredCardsIds;
    std::vector<int> uncoveredCardsIds;
public:
    const std::vector<int> getCoveredCardsIds() const {
        return coveredCardsIds;
    }
    const std::vector<int> getUncoveredCardsIds() const {
        return uncoveredCardsIds;
    }
};

class KlondikeInitParameters {
protected:
    int score;
    std::vector<int> stockCardsIds;
    std::vector<int> wasteCardsIds;
    std::vector<std::vector<int> > foundationsCardsIds;
    std::vector<std::shared_ptr<TableauPileInitParameters> > tableauInitParams;
public:
    int getScore() const {
        return score;
    }
    const std::vector<int> getStockCardsIds() const {
        return stockCardsIds;
    }
    const std::vector<int> getWasteCardsIds() const {
        return wasteCardsIds;
    }
    const std::vector<std::vector<int> > getFoundationsCardsIds() const {
        return foundationsCardsIds;
    }
    std::vector<std::shared_ptr<TableauPileInitParameters> > getTableauInitParams() const {
        return tableauInitParams;
    }
    virtual ~KlondikeInitParameters() {}
};

#endif /* SRC_MODEL_KLONDIKEINITPARAMETERS_H_ */
