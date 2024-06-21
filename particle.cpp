#include "particle.h"
#include <random>
#include <algorithm>
using namespace std;

Particle::Particle() : gen(random_device()()), distrib(0, 1) {}

void Particle::switchCells(Cell& c1, Cell& c2) {
    swap(c1.particleType, c2.particleType);
    c1.updated = true;
    c2.updated = true;
}

void SandParticle::update(vector<vector<Cell>>& cells, int i, int j) {
    int numR = cells.size();
    int numC = cells[0].size();

    if (i < numR - 1) {
        if (cells[i+1][j].particleType == EMPTY) {
            switchCells(cells[i][j], cells[i+1][j]);
        } else if (j < numC - 1 && cells[i+1][j+1].particleType == EMPTY) {
            switchCells(cells[i][j], cells[i+1][j+1]);
        } else if (j > 0 && cells[i+1][j-1].particleType == EMPTY) {
            switchCells(cells[i][j], cells[i+1][j-1]);
        } else if (cells[i+1][j].particleType == WATER) {
            switchCells(cells[i][j], cells[i+1][j]);
        }
    }
}

void WaterParticle::update(std::vector<std::vector<Cell>>& cells, int i, int j) {
    int numR = cells.size();
    int numC = cells[0].size();

    // Check if we can move down
    if (i < numR - 1 && cells[i+1][j].particleType == EMPTY) {
        switchCells(cells[i][j], cells[i+1][j]);
    } else {
        // Try to move horizontally with random direction
        bool moveLeft = distrib(gen) == 0;
        if (moveLeft && j > 0 && cells[i][j-1].particleType == EMPTY) {
            switchCells(cells[i][j], cells[i][j-1]);
        } else if (!moveLeft && j < numC - 1 && cells[i][j+1].particleType == EMPTY) {
            switchCells(cells[i][j], cells[i][j+1]);
        }
        // If we can't move in the randomly chosen direction, we don't try the other direction
        // This maintains the behavior from your original code
    }
}