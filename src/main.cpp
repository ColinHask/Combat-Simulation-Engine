#include <iostream>
#include <fstream>
#include <json.hpp>  // from external/json.hpp

using json = nlohmann::json;

int main() {
    std::cout << "Combat Simulation Engine - Test Run\n";

    // Create a simple test JSON object
    json test_data = {
        {"status", "ok"},
        {"version", 1.0},
        {"grid_size", {10, 10}},
        {"units", {
            {{"id", 1}, {"team", "red"}, {"x", 2}, {"y", 3}},
            {{"id", 2}, {"team", "blue"}, {"x", 7}, {"y", 6}}
        }}
    };

    // Output to console
    std::cout << test_data.dump(4) << "\n";

    // Save to outputs folder relative to executable
    std::ofstream out("../../../outputs/test_output.json");
    if (!out.is_open()) {
        std::cerr << "Failed to open file: ../../outputs/test_output.json\n";
        return 1;
    }

    out << test_data.dump(4);
    out.close();
    std::cout << "JSON written to ../../outputs/test_output.json\n";

    return 0;
}
