// run simulator.exe from build\bin\Debug

#include <iostream>
#include <fstream>
#include <json.hpp>  // from external/json.hpp
#include "Unit.hpp"

using json = nlohmann::json;

int main() {
    std::cout << "Combat Simulation Engine - Test Run\n";

    Unit a1(1, "red", 2, 3);
    a1.print_info();

    return 0;
}
