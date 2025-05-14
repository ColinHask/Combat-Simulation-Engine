

/* 
========================= CMAKE WORKFLOW REFERENCE =========================

 Folder Structure
- All source files go in:        /src/
- All headers go in:            /include/
- External headers (like JSON): /external/
- Build artifacts go in:        /build/

 CMake Basics
1. Configure (generate build files) (do this when new files):
   > Run this FROM the /build directory:
   cmake ..

2. Build project:
   > Still in /build:
   cmake --build .

3. Run binary (Windows):
    run simulator.exe from build\bin\Debug

 When to Re-run cmake .. :
- You add new .cpp or .hpp files
- You change the CMakeLists.txt
- You add a new external library
(Otherwise you can just run cmake --build . again)

 Common Fix: 
If you get weird linker or file-not-found issues after adding code, do:
> cd build
> cmake ..         ← reconfigure
> cmake --build .  ← rebuild

===========================================================================
*/

#include <iostream>
#include <fstream>
#include <json.hpp>  // from external/json.hpp
#include <chrono>
#include <thread>
#include "Unit.hpp"
#include "Grid.hpp"

using json = nlohmann::json;

int main() {
    // To DO:
    // add grid before units
    // make unit's constructor place it on grid Unit u1(grid, color, x, y)
    // have them generate their own ID uning static var
    // add game_controller, list of units, random order per tick, combat detection / resolution

    Grid grid(6, 6);

    std::vector<std::pair<int, int>> walls = {
        {1, 0}, {1, 1}, {1, 2},  // vertical wall
        {3, 2}, {3, 3}, {3, 4},  // another vertical wall
        {2, 2}                   // central block
    };

    grid.add_wall(walls); 

    grid.display(); //  visualize
    std::this_thread::sleep_for(std::chrono::seconds(1));

    Unit u1("red", &grid, 0,0);
    Unit u2("blue", &grid, 5,5);
    u1.print_info();
    u2.print_info();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    grid.display(); //  visualize with units

    std::this_thread::sleep_for(std::chrono::seconds(1));

    // B#....
    // .#....
    // .###..
    // ...#..
    // ...#..
    // .....R

    // 20 move demo
    for(int i = 0; i < 20; i++){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        u1.move();
        u2.move();
        grid.display();
    }

    return 0;
}
