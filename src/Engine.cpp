#include "../headers/Engine.h"
#include "../headers/String.h"
#include <iostream>

using namespace std;

void Engine::run()
{
    char buffer[1024];
    cin.getline(buffer, 1024, ' ');
    String command = buffer;
    String option;
    String optionTwo;
    while (true) {
        if (command == "exit") {
            if (hasChanged)
                throw "There are unsaved changes present!";
            break;
        } else if (command == "help")
            help();
        else if (command == "open") {
            cin.getline(buffer, 1024);
            option = buffer;
            open(option);
        } else if (command == "close") {
            close();
            hasChanged = false;
        } else if (command == "save")
            save();
        else if (command == "rename") {
            cin.getline(buffer, 1024, ' ');
            option = buffer;
            cin.getline(buffer, 1024);
            optionTwo = buffer;
            db.rename(option, optionTwo);
        }
    }
}

void Engine::open(const String& filename) { }

void Engine::close() const { }

void Engine::save()
{
    db.saveTables();
    hasChanged = false;
}

void Engine::help() const
{
    cout << "To leave type 'exit'.\n";
    cout << "to save the tables type 'save'\n";
    cout << "To rename a file type 'rename' followed by it's old name and the desired new name.\n";
}
