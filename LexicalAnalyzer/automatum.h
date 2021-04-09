#ifndef AUTOMATUM_H
#define AUTOMATUM_H

#include <list>
#include <cstring>

#include "analyzer.h"

class Automatum
{
public:
    Automatum();
    std::list<Analyzer> automata(std::string);
};

#endif // AUTOMATUM_H
