#include <iostream>

#include <fstream>
#include <sstream>

#include <vector>
#include "Player.h"

using namespace std;

enum FileExceptions {FileNotFoundException, NumberFormatException};
enum BadExceptin {Exception};

/* Megadjuk hogy a metódus csak a meghatározott kivételt dobhatja, ennek ellenõrzése futásidõben történik,
így futáshiba lehet belõle */

vector<Player> readFile(string fileName) throw (FileExceptions);
Player getPlayerFromLine(string line) throw (FileExceptions);

int main()
{
    try {
        vector<Player> players = readFile("input.txt");

        for (int i = 0; i < players.size(); ++i) {
            cout << players[i].toString() << endl;
        }
    } catch (FileExceptions e) {
        if (e == FileNotFoundException) {
            cerr << "File not found!\n";
        } else {
            cerr << "Invalid number!\n";
        }
    }

    return 0;
}

vector<Player> readFile(string fileName) throw (FileExceptions) {
    ifstream file;
    vector<Player> players;

    file.open(fileName.c_str());

    if (file.fail()) {
        throw FileNotFoundException;
    }

    string line;
    getline(file, line);
    while (!file.fail()) {
        try {
            players.push_back(getPlayerFromLine(line));
        } catch (FileExceptions e) {
            file.close();
            throw NumberFormatException;
        }
        getline(file, line);
    }
    file.close();

    //throw Exception;

    return players;
}

Player getPlayerFromLine(string line) throw (FileExceptions) {
    stringstream stream;
    stream << line;

    string name = "";
    int num;

    //a stream-bõl olvasunk a ;-ig
    getline(stream, name, ';');
    stream >> num;

    if (stream.fail()) {
        throw NumberFormatException;
    }

    return Player(name, num);
}
