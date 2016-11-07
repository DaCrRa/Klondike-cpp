/*
 * KlondikePlainTextSerializer.h
 *
 *  Created on: 6 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_KLONDIKEPLAINTEXTSERIALIZER_H_
#define SRC_MODEL_INC_KLONDIKEPLAINTEXTSERIALIZER_H_

#include <KlondikeSerializer.h>
#include <KlondikeVisitor.h>
#include <iostream>

class KlondikePlainTextSerializer: public KlondikeSerializer {
private:

    class StockPlainTextSerializer : public StockVisitor {
    private:
        std::ostream& outputStream;
    public:
        StockPlainTextSerializer(std::ostream& os) :
            outputStream(os) {}
        void visitCoveredCard(const Card* covered);
        void allCoveredCardsVisited();
        void visitWasteCard(const Card* wasteCard);
        void allWasteCardsVisited();
    };
    class TableauPilePlainTextSerializer : public TableauPileVisitor {
    private:
        std::ostream& outputStream;
    public:
        TableauPilePlainTextSerializer(std::ostream& os) :
            outputStream(os) {}
        void visitCoveredCard(const Card* covered);
        void allCoveredCardsVisited();
        void visitUncoveredCard(const Card* uncovered);
        void allUncoveredCardsVisited();
    };
    class KlondikePlainTextSerializerVisitor : public KlondikeVisitor {
    private:
        std::ostream& outputStream;
    public:
        KlondikePlainTextSerializerVisitor (std::ostream& os) :
            outputStream(os) {}
        void visitScore(int score);
        void visitStock(Stock* s);
        void visitFoundation(Foundation* f);
        void allFoundationsVisited();
        void visitTableauPile(TableauPile* tp);
        void allTableauPilesVisited();
    };
public:
    void serialize(std::shared_ptr<Klondike>& game, std::ostream& outputStream);
};

#endif /* SRC_MODEL_INC_KLONDIKEPLAINTEXTSERIALIZER_H_ */
