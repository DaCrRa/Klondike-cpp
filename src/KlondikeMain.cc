#include <ConsoleView.h>
#include <KlondikeApp.h>
#include <KlondikePlainTextSerializer.h>
#include <KlondikeToFileSaver.h>
#include <Logic.h>

int main(int argc, char* argv[]) {
    KlondikePlainTextSerializer serializer;
    KlondikeToFileSaver toFileSaver(serializer);
    Logic logic(toFileSaver);
    ConsoleView view(logic);

    KlondikeApp(&view, &logic).run();
}
