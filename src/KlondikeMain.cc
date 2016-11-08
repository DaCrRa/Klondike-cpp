#include <ConsoleView.h>
#include <KlondikeApp.h>
#include <KlondikePlainTextSerializer.h>
#include <KlondikeToFileSaver.h>
#include <KlondikeFromFileLoader.h>
#include <Logic.h>

int main(int argc, char* argv[]) {
    KlondikePlainTextSerializer serializer;
    KlondikeToFileSaver toFileSaver(serializer);
    KlondikeFromFileLoader fromFileLoader;
    Logic logic(toFileSaver, fromFileLoader);
    ConsoleView view(logic);

    KlondikeApp(&view, &logic).run();
}
