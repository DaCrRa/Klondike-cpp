#include <ConsoleView.h>
#include <Logic.h>
#include <KlondikeApp.h>

int main(int argc, char* argv[]) {
    ConsoleView view;
    Logic logic;

    KlondikeApp(&view, &logic).run();
}
