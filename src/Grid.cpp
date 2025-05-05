#include "Unit.hpp"
#include "Grid.hpp"

Grid::Grid(int width, int height)
    : width_(width), height_(height),
      //Create height number of rows, and each row is a vector of width number of false values
      wall_layer_(height, std::vector<bool>(width, false)),
      //Create a height x width grid of pointers to Unit, all initialized to nullptr
      unit_layer_(height, std::vector<Unit*>(width, nullptr)) {}

void Grid::add_wall(int x, int y){
    if (x >= 0 && x < width_ && y >= 0 && y < height_) {
        wall_layer_[y][x] = true;
    }
}
void Grid::add_wall(const std::vector<std::pair<int, int>>& positions){
    

}