#ifndef HWFINAL_SPACESHIP_H
#define HWFINAL_SPACESHIP_H

#include "string"

#define STOPPED 0
#define DOCKED 1
#define DEAD (-1)
#define MOVING 2
#define NOTEXIST (-2)

using namespace std;

class Spaceship {

public:
    Spaceship(string name, string pilot, float x, float y) : name(std::move(name)), pilot(std::move(pilot)), x(x),
                                                             y(y) {}
    const string &getName() const;

    int getStatus() const;

    float getX() const;

    float getY() const;

    void setStatus(int status_);


protected:
    string name;
    string pilot;
    float x;
    float y;
    int status = STOPPED;

};


#endif //HWFINAL_SPACESHIP_H
