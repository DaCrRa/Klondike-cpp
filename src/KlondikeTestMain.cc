#include <ConsoleView.h>
#include <KlondikeApp.h>
#include <TestDeckFactory.h>
#include <KlondikePlainTextSerializer.h>
#include <KlondikePlainTextDeserializer.h>
#include <KlondikeToFileSaver.h>
#include <KlondikeFromFileLoader.h>
#include <LocalLogic.h>

int main(int argc, char* argv[]) {
    std::shared_ptr<AbstractDeckFactory> deckFactory(new TestDeckFactory());
    KlondikePlainTextSerializer serializer;
    KlondikePlainTextDeserializer deserializer;
    KlondikeToFileSaver toFileSaver(serializer);
    KlondikeFromFileLoader fromFileLoader(deserializer);

    LocalLogic logic(deckFactory, toFileSaver, fromFileLoader);
    ConsoleView view(*deckFactory, logic);

    KlondikeApp(&view, &logic).run();
}
