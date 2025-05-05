# Combat Simulation Engine

A modular, grid-based combat simulation engine written in C++17. This project serves as both a learning tool and a foundation for more complex battlefield simulations such as autonomous agent behavior, team tactics, and spatial reasoning.

---

##  Features

- Grid-based world representation with adjustable width and height
- Walls and obstacles that prevent unit placement
- Basic unit system with team identification (e.g., red vs. blue)
- JSON output for simulation state logging
- Terminal display visualization of grid state
- Expandable structure using modular C++ classes

---

##  Project Structure

```
combat-simulation-engine/
├── build/              # CMake build directory
├── config/             # (Reserved) Simulation configuration files
├── external/           # External dependencies (e.g., nlohmann/json)
├── include/            # Header files (Unit.hpp, Grid.hpp, etc.)
├── outputs/            # JSON output logs from simulation runs
├── scripts/            # Placeholder for run/test automation scripts
├── src/                # C++ implementation files
├── CMakeLists.txt      # Root CMake build configuration
└── README.md           # You're here
```

---

##  Getting Started

### 1. Prerequisites

- CMake (v3.10+)
- A C++17-compatible compiler (e.g., MSVC, GCC, or Clang)

### 2. Build Instructions

```bash
# From project root
mkdir build
cd build
cmake ..
cmake --build .
```

### 3. Run the Simulator

```bash
bin/Debug/simulator.exe    # Windows
./bin/simulator            # Linux/Mac
```

---

##  Sample Output

Terminal grid display:
```
.#..
..U.
.#..
....
```

JSON state log:
```json
{
  "grid_size": [4, 4],
  "units": [
    { "id": 1, "team": "red", "x": 2, "y": 1 }
  ],
  "walls": [
    [1, 0], [1, 2]
  ],
  "status": "ok",
  "version": 1.0
}
```

---

##  Dependencies

- [nlohmann/json](https://github.com/nlohmann/json) — single-header JSON parser (`external/json.hpp`)

---

##  Planned Features

- Turn-based movement system (`tick()` loop)
- Basic AI behavior trees
- Combat resolution mechanics (e.g., facing direction, vision cone)
- CSV or live visual output (Python tool)
- Logging and replay support

---

##  Author

Built and maintained by Colin Haskins as a warm-up for low-level simulation tooling in C++.

---

## License

MIT License — see [`LICENSE`](./LICENSE) for details.
