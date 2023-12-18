#ifndef CUSTOMERROR_H
#define CUSTOMERROR_H
#include <vector>
#include <cstdint>

class help : public std::exception
{
public:
    const char * what () const throw () {return "help";}
};

class resign : public std::exception
{
public:
    const char * what () const throw () {return "Resigned";}
};

class canceld : public std::exception
{
public:
    const char * what () const throw () {return "Canceld move";}
};

class nopiece : public std::exception
{
public:
    const char * what () const throw () {return "Selected invalid piece";}
};

class invalidmove : public std::exception
{
public:
    const char * what () const throw () {return "invalid Move";}
};

class samepiece : public std::exception
{
public:
    const char * what () const throw () {return "Selected Same coordiantes";}
};

class check : public std::exception
{
public:
    const char * what () const throw () {return "standing check";}
};

class noking : public std::exception
{
public:
    const char * what () const throw () {return "no king";}
};
#endif // CUSTOMERROR_H
