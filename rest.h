struct Vector2D {
    int x;
    int y;

    void operator = (const Vector2D& scih) {
        x = scih.x;
        y = scih.y;
    }

    Vector2D(int _x, int _y){
        x = _x;
        y = _y;
    }
};

//-------------------------- Classes --------------------------------

class Player : public Entity {
    public:
        Player() {
            gfx = '+';
        }
};

class Entity {
    private:
        Vector2D _pos;
        char _gfx;
    public:
        Entity(Vector2D spawn, char gfx) {
            _pos = spawn;
            _gfx = gfx;
        }

        Vector2D getPos() {
            return _pos;
        }

        void setPos(Vector2D pos) {
            _pos = pos;
        }
}

//-------------------------- Functions --------------------------------

void drawLevel() {

}
