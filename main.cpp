#include <iostream>
#include "raylib.h"
#include "grid.h"
#include "particle.h"
#include <vector>
using namespace std;

void Draw();
void Update();

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
        BeginDrawing();
        Update();
        ClearBackground(BLACK);
        Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void Draw() {
    for(auto &row : cells) {
        for(auto &cell : row) {
            cell.Draw();
        }
    }
}

void Update(){
    for(int i = numR - 1; i >= 0; i--){
        for(int j = numC - 1; j >= 0; j--){
            if(cells[i][j].isClicked()){
                cells[i][j].empty = false;
                cells[i][j].particleType = ParticleType::Water; 
            }
            cells[i][j].updated = !cells[i][j].updated;
            if(!cells[i][j].empty){
                unique_ptr<Particle> particle;
                switch(cells[i][j].particleType){
                    case ParticleType::Sand:
                        particle = make_unique<SandParticle>();
                        break;
                    case ParticleType::Water:
                        particle = make_unique<WaterParticle>();
                        break;
                    default:
                        continue; 
                }
                particle->Update(cells, i, j);
            }
        }
    }
}

