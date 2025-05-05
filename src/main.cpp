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

    Grid grid(4, 4);

    grid.add_wall(3,0);
    grid.add_wall(0,3);

    grid.add_unit(3, 3, &u1); // pass pointer using &
    grid.add_unit(0, 0, &u2); 

    grid.display(); //  visualize
    return 0;
}
