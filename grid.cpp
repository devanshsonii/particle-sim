#include "grid.h"
#include <algorithm>
#include <vector>

// Constructor definition
Cell::Cell(int x, int y, int width, int height, bool updated, ParticleType particleType)
    : x(x), y(y), width(width), height(height), updated(updated), particleType(particleType) {}

void Cell::Draw() {
    // Color color = empty ? BLACK : WHITE;
    Color color;
    switch (particleType) {
        case SAND:
            color = YELLOW;
            break;
        case WATER:
            color = BLUE;
            break;
        case WALL:
            color = GRAY;
            break;
        case EMPTY:
            color = BLACK;
            break;
    }
    DrawRectangle(x, y, width, height, color);
}

void Cell::Update(std::vector<std::vector<Cell>> &cells) {

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
