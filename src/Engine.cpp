#include "../headers/Engine.h"
#include "../headers/String.h"
#include <iostream>

using namespace std;

void Engine::run()
{
    char buffer[1024];
    String command;
    cout << "Welcome to the DATABASE. It's still not ready for the naked eye, but you can taka a special look at it.\n";
    cout << "Enter your commands bellow.\n";
    cout << "If you don't know any commands type 'help'.\n";
    while (true) {
        cin.getline(buffer, 1024);
        String command = buffer;
        Vector<String> separatedCommand = command.splitStringBy(' ');
        if (separatedCommand[0] == "exit") {
            if (hasChanged)
                throw "There are unsaved changes present!";
            break;
        } else if (separatedCommand[0] == "help")
            help();
        else if (separatedCommand[0] == "open ") {
            cin.getline(buffer, 1024);
            open(separatedCommand[1]);
        } else if (separatedCommand[0] == "close") {
            close();
            hasChanged = false;
        } else if (separatedCommand[0] == "save")
            save();
        else if (separatedCommand[0] == "rename ") {
            db.rename(separatedCommand[1], separatedCommand[2]);
        }
    }
}

void Engine::open(const String& filename)
{
    std::cout << "Command not ready yet...";
}

void Engine::close() const
{
    std::cout << "Command not ready yet...";
}

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
