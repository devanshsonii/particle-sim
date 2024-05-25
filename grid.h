#ifndef GRID_H
#define GRID_H

#include "raylib.h"

class Cell {
public:
    int x;
    int y;
    int width;
    int height;
    bool empty;
    bool updated;
    Color color;
    Cell() : x(0), y(0), width(0), height(0), empty(true), color(BLACK), updated(false) {} // Default constructor

    Cell(int x, int y, int width, int height, bool empty, bool updated);
    void Draw();
    void Update(Cell& below);
    bool isClicked();


};

#endif
