#include <iostream>

#include <Deck.h>
#include <Pile.h>
#include <Foundation.h>

int main(int argc, char* argv[]) {
   Deck d;
   int takenCards = 0;
   while(d.hasCards()) {
      Card& c = d.takeNext();
      std::cout << "took " << ++takenCards << std::endl;
   }

   Foundation f;
}
