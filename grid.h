#ifndef GRID_H
#define GRID_H

#include "raylib.h"
#include <vector>

enum ParticleType {
    SAND,
    WATER,
    WALL,
    EMPTY
};

class Cell {
public:
    int x;
    int y;
    int width;
    int height;
    bool updated;
    ParticleType particleType;
    Color color;
    Cell() : x(0), y(0), width(0), height(0), color(BLACK), updated(false) {} // Default constructor

    Cell(int x, int y, int width, int height, bool updated, ParticleType particleType);
    void Draw();
    void Update(std::vector<std::vector<Cell>> &cells);
    bool isClicked();


};

#endif
