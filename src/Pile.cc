#include <Pile.h>

void Pile::add(const Card* c) {
   cards.push_back(c);
}

void Pile::add(const std::vector<const Card*>& cards) {
   this->cards.insert(this->cards.end(), cards.begin(), cards.end());
}

bool Pile::hasCards() {
	return !cards.empty();
}

const Card* Pile::top() {
	return cards.back();
}
