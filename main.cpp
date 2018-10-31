#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <ncurses.h>
#include <list>
#include <iterator>
#include "rest.h"

using namespace std;

list <Entity> lEntities;
Entity* pplayer;

void setup();
void getInput();

int main() {
    //system("clear");
    system("clear");
    setup();
    drawLevel(lEntities);

    while(true) {
        //Loop
        getInput();
        drawLevel(lEntities);
    }

    return 0;
}

void setup() {
    fstream fs;
    fs.open("level.txt", fstream::in);

    int x = 0;
    int y = 0;
    char c;

    while (fs.get(c)) {

        if (c == '@') {
            //code player
            Player player;
            Vector2D temp(x, y);
            player.setPos(temp);
            lEntities.push_front(player);
            pplayer = &lEntities.front();
        } else if (c == '#') {
            //code wall
            Vector2D wallPos(x, y);
            Entity ent(wallPos, '#');
            lEntities.push_front(ent);
        }
        if (x == 10) {
            x = 0;
            y++;
        } else {
            x++;
        }
    }

    fs.close();
}

void getInput() {
    char d;
    d = getch();

    if (d == 'a') {
        if ((pplayer->getPos()).x > 0)
            pplayer->move(Vector2D(
                -1,
                0
            ));
    } else if (d == 'w') {
        if ((pplayer->getPos()).y > 0)
            pplayer->move(Vector2D(
                0,
                -1
            ));
    } else if (d == 'd') {
        if ((pplayer->getPos()).x < 11)
            pplayer->move(Vector2D(
                1,
                0
            ));
    } else if (d == 's') {
        if ((pplayer->getPos()).y < 11)
            pplayer->move(Vector2D(
                0,
                1
            ));
    }
}
