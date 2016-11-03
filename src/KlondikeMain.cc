#include <ConsoleView.h>
#include <KlondikeApp.h>
#include <Logic.h>

int main(int argc, char* argv[]) {
    ConsoleView view;
    Logic logic;

    KlondikeApp(&view, &logic).run();
}
