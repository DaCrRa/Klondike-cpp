#include <ConsoleView.h>
#include <KlondikeApp.h>
#include <TestDeckFactory.h>
#include <KlondikePlainTextSerializer.h>
#include <KlondikePlainTextDeserializer.h>
#include <KlondikeToFileSaver.h>
#include <KlondikeFromFileLoader.h>
#include <Logic.h>

int main(int argc, char* argv[]) {
    std::shared_ptr<AbstractDeckFactory> deckFactory(new TestDeckFactory());
    KlondikePlainTextSerializer serializer;
    KlondikePlainTextDeserializer deserializer;
    KlondikeToFileSaver toFileSaver(serializer);
    KlondikeFromFileLoader fromFileLoader(deserializer);

    Logic logic(deckFactory, toFileSaver, fromFileLoader);
    ConsoleView view(logic);

    KlondikeApp(&view, &logic).run();
}
