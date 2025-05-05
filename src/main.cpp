// run simulator.exe from build\bin\Debug

#include <iostream>
#include <fstream>
#include <json.hpp>  // from external/json.hpp
#include "Unit.hpp"
#include "Grid.hpp"

using json = nlohmann::json;

int main() {
    Unit u1(1, "red", 2, 3);
    u1.print_info();

    Unit u2(2, "blue", 1, 1);
    u2.print_info();

    Grid grid(6, 6);

    std::vector<std::pair<int, int>> walls = {
        {1, 0}, {1, 1}, {1, 2},  // vertical wall
        {3, 2}, {3, 3}, {3, 4},  // another vertical wall
        {0, 4}, {1, 4}, {2, 4},  // horizontal wall at the bottom
        {2, 2}                   // central block
    };

    grid.add_wall(walls);
    grid.add_unit(5, 5, &u1); // pass pointer using &
    grid.add_unit(0, 0, &u2); 

    grid.display(); //  visualize
    return 0;
}
