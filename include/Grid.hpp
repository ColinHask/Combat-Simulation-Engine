class Unit;
#include <vector>
#include <utility>  // for std::pair

class Grid {
public:
    Grid(int width, int height);

    void add_wall(int x, int y);
    void add_wall(const std::vector<std::pair<int, int>>& positions);
    bool try_move(Unit* unit, int x, int y);
    std::pair<int, int> find_unit_coords(Unit* unit);
    void add_unit(int x, int y, Unit* unit);
    void display();

private:
    int width_;
    int height_;
    std::vector<std::vector<Unit*>> unit_layer_;
    std::vector<std::vector<bool>> wall_layer_;
};