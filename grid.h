#ifndef GRID_H
#define GRID_H
#include "raylib.h"

enum ParticleType {
    None,
    Sand,
    Water
};

class Cell {
public:
    int x;
    int y;
    int width;
    int height;
    ParticleType particleType;
    bool updated;
    bool empty;
    Color color;
    Cell() : x(0), y(0), width(0), height(0), color(BLACK), updated(false) {} // Default constructor

    Cell(int x, int y, int width, int height, bool empty, bool updated);
    void Draw();
    void Update(Cell& below);
    bool isClicked();

};

#endif
