#pragma once
#include <vector> // Ensure vector is included
#include "grid.h" // Assuming grid.h has the definition of Cell

class Particle {
public:
    virtual ~Particle() = default;
    virtual void Update(std::vector<std::vector<Cell>>& cells, int i, int j) = 0;
};

class SandParticle : public Particle {
public:
    void Update(std::vector<std::vector<Cell>>& cells, int i, int j) override;
};

class WaterParticle : public Particle {
public:
    void Update(std::vector<std::vector<Cell>> &cells, int i, int j) override;
};