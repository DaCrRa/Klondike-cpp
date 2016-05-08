#ifndef CARD_H
#define CARD_H

class Card {

   private:
      int rank;

   public:
      Card(int r);

      int getRank() const;

      bool hasSameSuit(const Card* c) const;

      bool hasSameColor(const Card* c) const;

      int compareRank(const Card* c) const;
};

#endif
