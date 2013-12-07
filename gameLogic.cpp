
#include "gameLogic.h"

Color::Color(int rin, int gin, int bin){
    r = rin;
    g = gin;
    b = bin;
};

Place::Place(float xin, float yin, float zin){
    x = xin;
    y = yin;
    z = zin;
};

Cube::Cube(Color color, Place place){
    myColor = color;
    myPlace = place;

};

Piece::Piece(vector<Cube> inCubes){
    cubes = inCubes;

};
