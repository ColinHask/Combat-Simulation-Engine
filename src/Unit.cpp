#include "Unit.hpp"
#include "Grid.hpp"
#include <iostream>

int Unit::next_id_ = 0;

//start with down default
std::pair<int, int> last_sucessful_move = {0, 1};



// Unit automaticly sets ID and adds to grid
// future improvments: modify add_unit to return bool, handle impossible unit placement more gracefully
Unit::Unit(std::string team,Grid* grid, int x, int y)
    : id_(next_id_++), team_(team), x_(x), y_(y), grid_(grid) {
        grid->add_unit(x,y,this);
    }

void Unit::print_info() const {
    std::cout << "Unit" << id_ << " (" << team_ << ") at (" << x_ << ", " << y_ << ")\n"; 
}
std::string Unit::get_team(){
    return team_;
}

// location helper
void Unit::update_location(){

    std::pair<int, int> location = grid_->find_unit_coords(this);

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
void Unit::move(){


    std::vector<std::pair<int, int>> moves = {
    {0, 1},  // down
    {1, 1},  // diag down-right
    {1, 0},  // right
    {1, -1}, // diag up-right
    {0, -1}, // up
    {-1, -1}, // diag up-left
    {-1, 0}, // left
    {-1, 1} // diag down-left
    };

    std::pair<int, int> location = grid_->find_unit_coords(this);

    // find location for future different unit behavior using this info
    update_location();
    
    // try last sucessful move before iterating
    bool moved = grid_->try_move(this, last_sucessful_move.first, last_sucessful_move.second);
    if (moved){
        std:: cout << "Unit Moved!\n";
        update_location();
        return;
    }

    // iterate through trying moves
    for (const std::pair<int, int>& move : moves){
        bool moved = grid_->try_move(this, move.first, move.second);
        if (moved){
            std:: cout << "Unit Moved!\n";
            update_location();
            last_sucessful_move = std::make_pair(move.first, move.second);
            return;
        }
    }
    std::cout << "Unit didnt move, all attempts failed\n";



}