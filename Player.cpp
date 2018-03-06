#include "Player.h"

/*Az osztály szöveges reprezentációja*/

std::string Player::toString() {
    std::stringstream result;
    result << name << " - " << num;

    return result.str();
}
