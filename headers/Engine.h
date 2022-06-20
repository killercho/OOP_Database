#ifndef ENGINE_H
#define ENGINE_H

#include "Database.h"
#include "String.h"

/**
 * Class Engine made to imitate the loop of the programme and execute all commands and desires that the user has.
 * */
class Engine {
private:
    Database db;
    bool hasChanged = false; //!< Bool variable that checks whether any changes have been made to the file.

    void help() const;                 //!< Help menu listing all the avaliable commands.
    void open(const String& filename); //!< Open command that opens a file. // Not ready yet...
    void close() const;                //!< Close command that closes the file without exeting the programme. // Not ready yet...
    void save();                       //!< Save command that saves all the loaded tables.

public:
    void run(); //!< Function that if called starts the programme.
};

#endif
