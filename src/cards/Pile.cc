#include <Pile.h>

#include <assert.h>

void Pile::add(const Card* c) {
    cards.push_back(c);
}

void Pile::add(const std::vector<const Card*>& cards) {
    this->cards.insert(this->cards.end(), cards.begin(), cards.end());
}

bool Pile::hasCards() const {
    return !cards.empty();
}

const Card* Pile::showTopCard() const {
    assert(hasCards());
    return cards.back();
}

int Pile::getNumberOfCards() const {
    return cards.size();
}

const Card* Pile::removeTopCard() {
    const Card* top = this->showTopCard();
    cards.pop_back();
    return top;
}

PileIterator Pile::begin() const {
    return cards.begin();
}

PileIterator Pile::end() const {
    return cards.end();
}
