# 2D Sandbox Simulation

![Showcase](https://github.com/devanshsonii/particle-sim/assets/139559687/bb709795-3e6e-4f3d-b651-bd53a817d1f4)

## Project Overview

This project is a simple 2D sandbox simulation built using C++ and the Raylib library. It allows users to interact with a grid of particles and switch between sand and water particles to observe their behavior.

## Features

- **Grid-based Simulation**: The simulation runs on an 800x800 pixel grid divided into 5x5 pixel cells.
- **Particle Types**: The current implementation supports sand and water particles.
- **User Interaction**: Users can click on the grid to place particles and press `ENTER` to switch between sand and water particles.
- **Real-time Updates**: The simulation updates in real-time, showing how particles interact with each other.

## Dependencies

- **Raylib**: A simple and easy-to-use library to enjoy videogames programming. You can download it from [here](https://www.raylib.com/).
- **C++ Standard Library**: Includes vector, memory, and random libraries.

## Installation

1. **Clone the Repository**:
    ```sh
    git clone https://github.com/your-username/2d-sandbox-simulation.git
    cd 2d-sandbox-simulation
    ```

2. **Install Raylib**:
    Follow the instructions on the [Raylib website](https://www.raylib.com/).

3. **Compile the Project**:
    ```sh
    g++ -o sandbox main.cpp grid.cpp particle.cpp -lraylib -std=c++17 -lpthread -ldl -lrt -lX11
    ```

4. **Run the Simulation**:
    ```sh
    ./sandbox
    ```

## Usage

- **Run the Program**: Execute the compiled binary to start the simulation.
- **Place Particles**: Click on the grid to place the current particle type.
- **Switch Particle Type**: Press `ENTER` to switch between sand and water particles.

## Future Improvements

- **Additional Particles**: Add more types of particles such as fire, etc.
- **Better Interactions**: Improve the interaction logic between different types of particles.
- **Optimizations**: Optimize the simulation for better performance on larger grids.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request with your improvements.

## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.

---

Enjoy the sandbox simulation and have fun experimenting with different particles!
