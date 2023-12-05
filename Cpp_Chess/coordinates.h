#ifndef COORDINATES_H
#define COORDINATES_H
#include <iostream>
template <typename T1, typename T2>
class Coordinates
{
public:
    Coordinates(const T1& X = 0, const T2& Y = 0) : Xcoordinate(X), Ycoordinate(Y) {}

    T1 GetX(void) const {return Xcoordinate;}
    T2 GetY(void) const {return Ycoordinate;}

    void setX(const T1& X) {Xcoordinate = X;}
    void setY(const T2& Y) {Ycoordinate = Y;}

    ~Coordinates(void) {}
private:
    T1 Xcoordinate;
    T2 Ycoordinate;
};

#endif // COORDINATES_H
