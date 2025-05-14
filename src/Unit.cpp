#include "Unit.hpp"
#include "Grid.hpp"
#include <iostream>
#include <random>

// TO DO:
// modify moves to be declaired in constructer and a local var
// rotate moves using below code snippet as reference
// remove last sucessful move from existance
//===========================================================
// #include <algorithm>
// #include <vector>

// std::vector<int> v = {1, 2, 3, 4};

// // Rotate left by 1 → [2, 3, 4, 1]
// std::rotate(v.begin(), v.begin() + 1, v.end());
// =========================================================
// v.begin() = start of vector

// v.begin() + 1 = new start (element that will move to the front)

// v.end() = end of vector



    const std::vector<std::pair<int, int>> Unit::right_leaning_moves = {
    {0, 1},  // down
    {1, 1},  // diag down-right
    {1, 0},  // right
    {1, -1}, // diag up-right
    {0, -1}, // up
    {-1, -1}, // diag up-left
    {-1, 0}, // left
    {-1, 1} // diag down-left
    };

    const std::vector<std::pair<int, int>> Unit::left_leaning_moves = {
    {0, 1},  // down
    {-1, 1}, // diag down-left
    {-1, 0}, // left
    {-1, -1}, // diag up-left
    {0, -1}, // up
    {1, -1}, // diag up-right
    {1, 0},  // right
    {1, 1}  // diag down-right
    };

int Unit::next_id_ = 0;

//start with down default
std::pair<int, int> last_successful_move = {0, 1};



// Unit automaticly sets ID and adds to grid
// future improvments: modify add_unit to return bool, handle impossible unit placement more gracefully
Unit::Unit(std::string team,Grid* grid, int x, int y)
    : id_(next_id_++), team_(team), x_(x), y_(y), grid_(grid) {

        std::random_device rd;
        std::mt19937 gen(rd());
        std::bernoulli_distribution dist(0.5);  // 50% chance

        // 50% chance unit is right leaning or left leaning
        // right leaning units move in counterclockwise leaning patterns
        right_leaning_ = dist(gen);

        grid->add_unit(x,y,this);
    }

void Unit::print_info() const {
    std::cout << "Unit" << id_ << " (" << team_ << ") at (" << x_ << ", " << y_ << ") right_leaning: " << right_leaning_ <<"\n"; 
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


    // 50% chance unit is right leaning or left leaning
    // right leaning units move in counterclockwise patterns

    std::vector<std::pair<int, int>> moves;

    if (right_leaning_){
        moves = right_leaning_moves;
    }
    else {
        moves = left_leaning_moves;
    }

    // for checking moves / debugging move list
    // std::cout << "Unit " << id_ << " checking moves: ";
    // for (const auto& [dx, dy] : moves) {
    //     std::cout << "(" << dx << "," << dy << ") ";
    // }
    // std::cout << "\n";

    std::pair<int, int> location = grid_->find_unit_coords(this);

    // find location for future different unit behavior using this info
    update_location();
    
    // try last successful move before iterating
    bool moved = grid_->try_move(this, last_successful_move.first, last_successful_move.second);
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
            last_successful_move = std::make_pair(move.first, move.second);
            return;
        }
    }
    std::cout << "Unit didnt move, all attempts failed\n";



}