#include "Player.h"

/*Az oszt�ly sz�veges reprezent�ci�ja*/

std::string Player::toString() {
    std::stringstream result;
    result << name << " - " << num;

    return result.str();
}
