#include "grid.h"
#include <algorithm>

// Constructor definition
Cell::Cell(int x, int y, int width, int height, bool empty, bool updated)
    : x(x), y(y), width(width), height(height), updated(updated), empty(empty) {}

void Cell::Draw() {
    Color drawColor = this->empty ? BLACK : this->color; // Default to black if empty, otherwise use the cell's color
    switch(particleType){
        case ParticleType::None:
            drawColor = BLACK; // Or any color representing an empty cell
            break;
        case ParticleType::Sand:
            drawColor = BROWN;
            break;
        case ParticleType::Water:
            drawColor = BLUE;
            break;
    }
    DrawRectangle(x, y, width, height, drawColor);
}


bool Cell::isClicked(){
    Vector2 mousePos = GetMousePosition();
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        if (mousePos.x >= x && mousePos.x <= x + width && mousePos.y >= y && mousePos.y <= y + height) {
            return true;
        }
    }
    return false;
}
