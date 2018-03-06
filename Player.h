#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
#include <cstdlib>
#include <sstream>

class Player {

    private:
        std::string name;
        int num;
        bool active;

    public:
        Player(std::string name, int num): name(name), num(num) {}

        void setName(std::string name) { this->name = name; }
        void setNum(int num) { this->num = num;}
        void setActive(bool active) { this->active = active; }

        std::string getName() { return name; }
        int getNum() { return num; }
        bool isActive() { return active; }

        std::string toString();
};


#endif // PLAYER_H_INCLUDED
