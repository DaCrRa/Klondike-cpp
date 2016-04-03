#include <iostream>

#include <Deck.h>
#include <Pile.h>
#include <Foundation.h>
#include <TableauPile.h>

int main(int argc, char* argv[]) {
   Deck d;
   int takenCards = 0;
   while(d.hasCards()) {
      const Card* c = d.removeTop();
      std::cout << "took " << ++takenCards << std::endl;
   }

   Foundation f;
   TableauPile t;
}
