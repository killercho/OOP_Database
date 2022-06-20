#ifndef ENGINE_H
#define ENGINE_H

#include "Database.h"
#include "String.h"

class Engine {
private:
    Database db;
    bool hasChanged = false;

    void exit() const;
    void help() const;
    void open(const String& filename);
    void close() const;
    void save();

public:
    void run();
};

#endif
