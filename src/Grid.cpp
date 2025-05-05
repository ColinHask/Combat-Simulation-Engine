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