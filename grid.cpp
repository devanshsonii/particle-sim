#include "grid.h"
#include <algorithm>

// Constructor definition
Cell::Cell(int x, int y, int width, int height, bool empty, bool updated)
    : x(x), y(y), width(width), height(height), empty(empty), updated(updated) {}

void Cell::Draw() {
    Color color = empty ? BLACK : WHITE;
    DrawRectangle(x, y, width, height, color);
}

void Cell::Update(Cell& below) {
    
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
