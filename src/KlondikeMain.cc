#include <iostream>

#include <Deck.h>
#include <Pile.h>

int main(int argc, char* argv[]) {
   Deck d;
   int takenCards = 0;
   while(d.hasMoreCards()) {
      Card& c = d.takeNext();
      std::cout << "took " << ++takenCards << std::endl;
   }

   Pile p;
}
