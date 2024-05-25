#include <iostream>
#include "raylib.h"
#include "grid.h"
#include <vector>

using namespace std;

void Draw();
void Update();
void switchCells(Cell &c1, Cell &c2);

vector<vector<Cell>> cells;
const int screenHeight = 800;
const int screenWidth = 800;
const int recWidth = 5;
const int recHeight = 5;
int numR = screenHeight / recHeight;
int numC = screenWidth / recWidth;

int main() {
    cells.resize(numR, vector<Cell>(numC));
    for(int i = 0; i < numR; i++) {
        for(int j = 0; j < numC; j++) {
            cells[i][j] = Cell(j * recWidth, i * recHeight, recWidth, recHeight, true, false);
        }
    }

    InitWindow(screenWidth, screenHeight, "Sand Sim");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        Update();
        BeginDrawing();
        float fps = GetFPS();
        cout << fps << "\n";
        ClearBackground(BLACK);
        Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void Draw() {
    for(auto &row : cells) {
        for(Cell &cell : row) {
            cell.Draw();
        }
    }
}

void Update(){
    for(int i = numR - 1; i >= 0; i--){
        for(int j = numC - 1; j >= 0; j--){
            cells[i][j].empty = cells[i][j].isClicked() ? false : cells[i][j].empty;
            cells[i][j].updated = !cells[i][j].updated;
            if(i < numR - 1){
                if(!cells[i][j].empty && cells[i+1][j].empty){
                    switchCells(cells[i][j], cells[i+1][j]);
                } else if(j < numC - 1 && cells[i+1][j+1].empty){
                    switchCells(cells[i][j], cells[i+1][j+1]);
                } else if(j > 0 && cells[i+1][j-1].empty) {
                    switchCells(cells[i][j], cells[i+1][j-1]);
                }
            }
        }
    }
}

void switchCells(Cell &c1, Cell &c2){
    swap(c1.empty, c2.empty);
    c1.updated = true; c2.updated = true;
}