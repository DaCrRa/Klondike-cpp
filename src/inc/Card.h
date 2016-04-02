#ifndef CARD_H
#define CARD_H

class Card {

   private:
      int rank;

   public:
      Card(int r);

      int getRank();

      bool hasSameSuit(const Card* c);

      int compareRank(const Card* c);
};

#endif
