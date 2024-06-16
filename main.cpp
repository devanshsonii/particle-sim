#include <iostream>
#include "raylib.h"
#include "grid.h"
#include <vector>
#include <random>

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
bool isSand = true;

int main() {
    cells.resize(numR, vector<Cell>(numC));
    for(int i = 0; i < numR; i++) {
        for(int j = 0; j < numC; j++) {
            cells[i][j] = Cell(j * recWidth, i * recHeight, recWidth, recHeight, false, EMPTY);
        }
    }

    InitWindow(screenWidth, screenHeight, "Sand Sim");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        Update();
        BeginDrawing();
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
    std::random_device rd; // Non-deterministic generator
    std::mt19937 gen(rd()); // To seed mersenne twister.
    std::uniform_int_distribution<> distrib(0, 1); // Define range


    if(IsKeyPressed(KEY_ENTER)){
        isSand = !isSand;
    }

    for(int i = numR - 1; i >= 0; i--){
        for(int j = numC - 1; j >= 0; j--){
            cells[i][j].updated = false;
            if(cells[i][j].isClicked()){
                if(isSand){
                    cells[i][j].particleType = SAND;
                } else {
                    cells[i][j].particleType = WATER;
                }
            }
            if(cells[i][j].particleType == SAND){
                if(i < cells.size() - 1){
                    if(cells[i+1][j].particleType == EMPTY){
                        switchCells(cells[i][j], cells[i+1][j]);
                    } else if(j < cells[0].size() - 1 && cells[i+1][j+1].particleType == EMPTY){
                        switchCells(cells[i][j], cells[i+1][j+1]);
                    } else if(j > 0 && cells[i+1][j-1].particleType == EMPTY){
                        switchCells(cells[i][j], cells[i+1][j-1]);
                    }
                }
            } 
            if(cells[i][j].particleType == WATER && cells[i][j].updated == false){
                if(i < cells.size() - 1 && cells[i+1][j].particleType == EMPTY){
                    switchCells(cells[i][j], cells[i+1][j]);
                } else {
                    bool moveLeft = distrib(gen) == 0; // Randomly choose left or right
                    if(moveLeft && j > 0 && cells[i][j-1].particleType == EMPTY){
                        switchCells(cells[i][j], cells[i][j-1]);
                    } else if(!moveLeft && j < cells[0].size() - 1 && cells[i][j+1].particleType == EMPTY){
                        switchCells(cells[i][j], cells[i][j+1]);
                    }
                }
                cells[i][j].updated = true;
            }
        }
    }
}

void switchCells(Cell &c1, Cell &c2){
    swap(c1.particleType, c2.particleType);
    c1.updated = true; c2.updated = true;
}