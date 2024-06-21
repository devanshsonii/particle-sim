#include "particle.h"
#include "grid.h" 
#include <iostream>


void switchCells(Cell &c1, Cell &c2){
    std::swap(c1.x, c2.x);
    std::swap(c1.y, c2.y);
    std::swap(c1.width, c2.width);
    std::swap(c1.height, c2.height);
    std::swap(c1.particleType, c2.particleType);
    std::swap(c1.updated, c2.updated);
    std::swap(c1.empty, c2.empty);
    std::swap(c1.color, c2.color);

    c1.updated = true;
    c2.updated = true;
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
    if (i < cells.size() - 1 && cells[i + 1][j].empty) {
        switchCells(cells[i][j], cells[i + 1][j]);
    } else {
        bool moved = false;
        if (j < cells[0].size() - 1 && cells[i][j + 1].empty) {
            switchCells(cells[i][j], cells[i][j + 1]);
            moved = true;
        }
        if (!moved && j > 0 && cells[i][j - 1].empty) {
            switchCells(cells[i][j], cells[i][j - 1]);
        }
    }
}


