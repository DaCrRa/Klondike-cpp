#include <ConsoleView.h>
#include <KlondikeApp.h>
#include <DeckFactory.h>
#include <KlondikePlainTextSerializer.h>
#include <KlondikePlainTextDeserializer.h>
#include <KlondikeToFileSaver.h>
#include <KlondikeFromFileLoader.h>
#include <Logic.h>

#include <iostream>
int main(int argc, char* argv[]) {
    std::shared_ptr<AbstractDeckFactory> deckFactory(new DeckFactory());
    std::cout << "available decks " << deckFactory->getNumberOfAvailableDecks() << std::endl;
    KlondikePlainTextSerializer serializer;
    KlondikePlainTextDeserializer deserializer;
    KlondikeToFileSaver toFileSaver(serializer);
    KlondikeFromFileLoader fromFileLoader(deserializer);

    Logic logic(deckFactory, toFileSaver, fromFileLoader);
    ConsoleView view(logic);

    KlondikeApp(&view, &logic).run();
}
