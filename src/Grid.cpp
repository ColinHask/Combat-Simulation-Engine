#include "Unit.hpp"
#include "Grid.hpp"
#include <iostream>

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
    else {
        std::cout << "WALL SKIPPED, WALL OUT OF BOUNDS\n";
    }
}
void Grid::add_wall(const std::vector<std::pair<int, int>>& positions) {
    for (const std::pair<int, int>& pos : positions) {
        int x = pos.first;
        int y = pos.second;
        add_wall(x, y);  // call the other method 
    }
}
void Grid::add_unit(int x, int y, Unit* unit){

    if (x >= 0 && x < width_ && y >= 0 && y < height_) {
        if (wall_layer_[y][x]){
            std::cout << "UNIT SKIPPED, UNIT WALL CONFLICT\n";
        } 
        else {
            unit_layer_[y][x] = unit;
        } 
    }else{
        std::cout << "UNIT SKIPPED, UNIT OUT OF BOUNDS\n";
    }
}

std::pair<int, int> Grid::find_unit_coords(Unit* target){
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            if (unit_layer_[y][x] == target){
                return {x, y};
            }
          }
      }

      // invalid coords to signal not found
      return {-1,-1};
}
// attempts to move unit
// note: x and y are not Goal Locations, they are change in x and y
bool Grid::try_move(Unit* unit, int x, int y){
    std::pair<int, int> start_pos = find_unit_coords(unit);
    if (start_pos == std::make_pair(-1, -1)){
        std::cout << "Unit not found\n";
        return false;
    }
    else{
        // check bounds
        if (start_pos.first + x >= 0 && start_pos.first  + x < width_ && start_pos.second + y >= 0 && start_pos.second + y < height_){
            // check walls
            if (wall_layer_[start_pos.second + y][start_pos.first  + x]){
                std::cout << "Move not possible, WALL CONFLICT\n";
                return false;
            }
            //check units
            else if (unit_layer_[start_pos.second + y][start_pos.first  + x] != nullptr){
                std::cout << "Move not possible, UNIT CONFLICT\n";
                return false;
            }
            else{
            // SUCCESS! update unit layer
                unit_layer_[start_pos.second][start_pos.first] = nullptr;
                unit_layer_[start_pos.second + y][start_pos.first  + x] = unit;
                std::cout << "unit moved\n";
                return true;
            }

        }
        else{
            std::cout << "Move not possible\n";
            return false;

        }
    }
}

void Grid::display(){
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            if(wall_layer_[y][x]){
                std::cout << "#";
            }
            else if (!(unit_layer_[y][x] == nullptr)){
                Unit* u = unit_layer_[y][x];
                std::cout << (u->get_team() == "red" ? "R" : "B");
            }
            else{
                std::cout << ".";
            }
          }
        std::cout << "\n";
      }
    
}