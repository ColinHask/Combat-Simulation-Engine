class Unit;
#include <vector>
#include <utility>  // for std::pair

class Grid {
public:
    Grid(int width, int height);

    void add_wall(int x, int y);
    void add_wall(const std::vector<std::pair<int, int>>& positions);

    void add_unit(int x, int y);

private:
    int width_;
    int height_;
    std::vector<std::vector<Unit*>> unit_layer_;
    std::vector<std::vector<bool>> wall_layer_;
};