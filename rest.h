using namespace std;

struct Vector2D {
    int x;
    int y;

    void operator = (const Vector2D& scih) {
        x = scih.x;
        y = scih.y;
    }

    bool operator == (const Vector2D& scih) {
        return ((this->x == scih.x) && (this->y == scih.y));
    }

    Vector2D(int _x, int _y) {
        x = _x;
        y = _y;
    }

    Vector2D() {
        x = 0;
        y = 0;
    }
};

//-------------------------- Classes --------------------------------

class Entity {
    protected:
        Vector2D _pos;
        char _gfx;
    public:
        Entity() {
            _pos = Vector2D(0, 0);
            _gfx = 'k';
        }

        Entity(Vector2D spawn, char gfx) {
            _pos = spawn;
            _gfx = gfx;
        }

        Entity(char gfx) {
            _gfx = gfx;
        }

        Vector2D getPos() {
            return _pos;
        }

        void setPos(Vector2D pos) {
            _pos = pos;
        }

        void move(Vector2D dir) {
            _pos.x += dir.x;
            _pos.y += dir.y;
        }

        void moveCollisions(Vector2D dir, list <Entity> lEnt) {
            // newx = _pos.x + dir.x;
            // newy = _pos.y + dir.y;
            Vector2D newPos(_pos.x + dir.x, _pos.y + dir.y);
            bool colliding = false;

            list <Entity> :: iterator it;
            for (it = lEnt.begin(); it != lEnt.end(); ++it) {
                if (it->getPos() == newPos) {
                    colliding = true;
                }
            }

            if (!colliding) {
                _pos.x = newPos.x;
                _pos.y = newPos.y;
            }
        }

        char getGfx() {
            return _gfx;
        }
};

class Player : public Entity {
    public:
        Player() {
            _gfx = '+';
        }
};

//-------------------------- Functions --------------------------------

void drawLevel(list <Entity> lEnt) {
    system("clear");
    system("/bin/stty cooked");
    list <Entity> :: iterator it;
    for (int height = 0; height <= 10; height++) {
        for (int width = 0; width <= 10; width++) {
            //Render screen
            bool rendered = false;
            for (it = lEnt.begin(); it != lEnt.end() && !rendered; ++it) {
                if ((it->getPos()).x == width && (it->getPos()).y == height) {
                    cout << it->getGfx();
                    rendered = true;
                }
            }
            if (!rendered) {
                cout << " ";
            }
        }
        cout << "|" << endl;
    }
    cout << "----------\n";
    cout << "wasd = move | l = quit\n";
    system("/bin/stty raw");
}
