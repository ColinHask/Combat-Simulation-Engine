#include "Unit.hpp"
#include "Grid.hpp"
#include <iostream>

Unit::Unit(int id, std::string team, int x, int y)
    : id_(id), team_(team), x_(x), y_(y) {}

void Unit::print_info() const {
    std::cout << "Unit" << id_ << " (" << team_ << ") at (" << x_ << ", " << y_ << ")\n"; 
}
std::string Unit::get_team(){
    return team_;
}

// location helper
void Unit::update_location(Grid* grid){

    std::pair<int, int> location = grid->find_unit_coords(this);

    if (location == std::make_pair(-1, -1)){
        std::cout << "Unit does not exist (BAD) (this shouldnt happen) ==============================\n";
        return;
    } else {
        x_ = location.first;
        y_ = location.second;
    }

}

// moves unit by continuously attempting to move via grid::try_move
// note: x and y are not Goal Locations, they are change in x and y
void Unit::move(Grid* grid){

    // find self coords using grid method (and update internal location)
    // determine goal coords
    // loop:
    //  if (try move):
    //    find self coords again (validation)
    //    set internal location vars
    //    break
    //  else:
    //   iterate goal coords (rotate around current location)
    //   count++ (if > 8 break and say move doesnt happen)
    std::vector<std::pair<int, int>> moves = {
    {0, 1},  // down
    {1, 0},  // right
    {0, -1}, // up
    {-1, 0}, // left
    {1, 1},  // diag down-right
    {-1, 1}, // diag down-left
    {1, -1}, // diag up-right
    {-1, -1} // diag up-left
    };

    std::pair<int, int> location = grid->find_unit_coords(this);

    // find location for future different unit behavior using this info
    update_location(grid);
    

    for (const std::pair<int, int>& move : moves){
        bool moved = grid->try_move(this, move.first, move.second);
        if (moved){
            std:: cout << "Unit Moved!\n";
            update_location(grid);
            return;
        }
    }
    std::cout << "Unit didnt move, all attempts failed\n";



}