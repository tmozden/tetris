#include <stdio.h>
#include <stdlib.h>
#include <vector>

class Color{
    
    public: 
    int r, g, b;
    
    Color(int rin, int gin, int bin);
};

class Place{

    public:
    float x, y, z;
    
    Place(float xin, float yin, float zin); 

};

class Cube {
    
    public:
    
    Color myColor;
    Place myPlace;
    
    Cube(Color color, Place place);

};

class Piece {

    public:
    vector<Cube> cubes;
    
    Piece(vector<Cube> inCubes);
    void rotate();
    
    std::string serialize() {
        std::stringstream out;
        out << "{\"cubes\":[";
        for (Cube &c : cubes) {
            out << c.serialize();
        }
        out << "]}";
        
        return out.str();
        
        /*
        folly::dynamic out;
        out["cubes"] = folly::dynamic::object;
        for (Cube &c : cubes) {
            out["cubes"].push_back(c.serialize();
        }
        return folly::toJson(out).toStdString();
        */
    }

};

class Side{

    public:
    vector<Cube> placedCubes;
    Cube activeCube;
    

}
