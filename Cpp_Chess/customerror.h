#ifndef CUSTOMERROR_H
#define CUSTOMERROR_H
#include <vector>
#include <cstdint>

class help : public std::exception
{
public:
    help(){};
    const char * what () const throw () {return "help";}
    ~help(){};
};

class resign : public std::exception
{
public:
    resign(){};
    const char * what () const throw () {return "Resigned";}
    ~resign(){};
};

class canceld : public std::exception
{
public:
    canceld(){};
    const char * what () const throw () {return "Canceld move";}
    ~canceld(){};
};

class nopiece : public std::exception
{
public:
    nopiece(){};
    const char * what () const throw () {return "Selected invalid piece";}
    ~nopiece(){};
};

class invalidmove : public std::exception
{
public:
    invalidmove(){};
    const char * what () const throw () {return "invalid Move";}
    ~invalidmove(){};
};

class samepiece : public std::exception
{
public:
    samepiece(){};
    const char * what () const throw () {return "Selected Same coordiantes";}
    ~samepiece(){};
};

class check : public std::exception
{
public:
    check(){};
    const char * what () const throw () {return "standing check";}
    ~check(){};
};

class noking : public std::exception
{
public:
    noking(){};
    const char * what () const throw () {return "no king";}
    ~noking(){};
};
#endif // CUSTOMERROR_H
