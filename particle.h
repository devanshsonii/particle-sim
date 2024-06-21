#ifndef PARTICLE_H
#define PARTICLE_H

#include "grid.h"
#include <vector>
#include <random>

class Particle {
public:
    Particle();
    virtual ~Particle() = default;
    virtual void update(std::vector<std::vector<Cell>>& cells, int i, int j) = 0;

protected:
    void switchCells(Cell& c1, Cell& c2);
    std::mt19937 gen;
    std::uniform_int_distribution<> distrib;
};

class SandParticle : public Particle {
public:
    void update(std::vector<std::vector<Cell>>& cells, int i, int j) override;
};

class WaterParticle : public Particle {
public:
    void update(std::vector<std::vector<Cell>>& cells, int i, int j) override;
};

#endif