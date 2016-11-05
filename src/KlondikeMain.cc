#include <ConsoleView.h>
#include <KlondikeApp.h>
#include <Logic.h>

int main(int argc, char* argv[]) {
    Logic logic;
    ConsoleView view(logic);

    KlondikeApp(&view, &logic).run();
}
