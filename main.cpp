#include <iostream>
#include "raylib.h"
#include "grid.h"
#include "particle.h"
#include <vector>
#include <memory>
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


std::unique_ptr<Particle> getParticle(ParticleType type) {
    switch (type) {
        case SAND:
            return std::make_unique<SandParticle>();
        case WATER:
            return std::make_unique<WaterParticle>();
        default:
            return nullptr;
    }
}

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


void Update() {
    if (IsKeyPressed(KEY_ENTER)) {
        isSand = !isSand;
    }

    for (int i = numR - 1; i >= 0; i--) {
        for (int j = numC - 1; j >= 0; j--) {
            cells[i][j].updated = false;
            if (cells[i][j].isClicked()) {
                cells[i][j].particleType = isSand ? SAND : WATER;
            }
            
            auto particle = getParticle(cells[i][j].particleType);
            if (particle && !cells[i][j].updated) {
                particle->update(cells, i, j);
            }
        }
    }
}