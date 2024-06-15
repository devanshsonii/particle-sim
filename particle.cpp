#include "particle.h"
#include "grid.h" // Assuming this includes the definition of switchCells
#include <iostream>


void switchCells(Cell &c1, Cell &c2){
    std::swap(c1.empty, c2.empty);
    c1.updated = true; c2.updated = true;
}

void SandParticle::Update(std::vector<std::vector<Cell>>& cells, int i, int j) {
    if(i < cells.size() - 1){
        if(!cells[i][j].empty && cells[i+1][j].empty){
            switchCells(cells[i][j], cells[i+1][j]);
        } else if(j < cells[0].size() - 1 && cells[i+1][j+1].empty){
            switchCells(cells[i][j], cells[i+1][j+1]);
        } else if(j > 0 && cells[i+1][j-1].empty) {
            switchCells(cells[i][j], cells[i+1][j-1]);
        }
    }
}

void WaterParticle::Update(std::vector<std::vector<Cell>>& cells, int i, int j) {
    // Check if the particle can move down
    if (i < cells.size() - 1 && cells[i + 1][j].empty) {
        switchCells(cells[i][j], cells[i + 1][j]);
    }
    // If it cannot move down, check for sideways movement
    else {
        bool moved = false;
        // Check right
        if (j < cells[0].size() - 1 && cells[i][j + 1].empty) {
            switchCells(cells[i][j], cells[i][j + 1]);
            moved = true;
        }
        // If it couldn't move right, check left
        if (!moved && j > 0 && cells[i][j - 1].empty) {
            switchCells(cells[i][j], cells[i][j - 1]);
        }
    }
}
