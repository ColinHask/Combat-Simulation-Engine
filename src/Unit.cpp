#include "Unit.hpp"
#include "Grid.hpp"
#include <algorithm>
#include <iostream>
#include <random>


std::mt19937 Unit::RNG{ std::random_device{}() };   // definition + seed

int Unit::next_id_ = 0;


// Unit automaticly sets ID and adds to grid
// future improvments: modify add_unit to return bool, handle impossible unit placement more gracefully
Unit::Unit(std::string team,Grid* grid, int x, int y)
    : id_(next_id_++), team_(team), x_(x), y_(y), grid_(grid) {

       

        // 50% chance unit is right leaning or left leaning
        // right leaning units move in counterclockwise leaning patterns
        std::bernoulli_distribution dist(0.5);
        right_leaning_ = dist(RNG);

        //determine moves
        if (right_leaning_){
            moves_ = {
            {1, 0},  // right
            {1, -1}, // diag up-right
            {0, -1}, // up
            {-1, -1}, // diag up-left
            {-1, 0}, // left
            {-1, 1}, // diag down-left
            {0, 1},  // down
            {1, 1}  // diag down-right
            };
        } else {
            moves_ = {
            {-1, 0}, // left
            {-1, -1}, // diag up-left
            {0, -1}, // up
            {1, -1}, // diag up-right
            {1, 0},  // right
            {1, 1},  // diag down-right
            {0, 1},  // down
            {-1, 1} // diag down-left
            };
        }
        

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


    // for checking moves / debugging move list
    // std::cout << "Unit " << id_ << " checking moves: ";
    // for (const auto& [dx, dy] : moves) {
    //     std::cout << "(" << dx << "," << dy << ") ";
    // }
    // std::cout << "\n";

    std::pair<int, int> location = grid_->find_unit_coords(this);

    // find location for future different unit behavior using this info
    update_location();

    for (int i = 0; i < 9; i++){
        bool moved = grid_->try_move(this, moves_[0].first, moves_[0].second);
        if (moved){
            std:: cout << "Unit Moved!\n";
            update_location();
            return;
        } else {

            std::uniform_int_distribution<int> dist_chance(0, 2);   
            std::uniform_int_distribution<int> dist_rotation(0, 7); 

            int rand_chance   = dist_chance(RNG);
            int rand_rotation = dist_rotation(RNG);

            // 1/3 chance of random moveset rotation
            if (rand_chance == 1){
                std:: cout << "RANDOM ROTATION ================================================\n";
                std::rotate(moves_.begin(), moves_.begin() + rand_rotation, moves_.end());


            } else {
                // // Rotate left by 1 → [2, 3, 4, 1]
                std::rotate(moves_.begin(), moves_.begin() + 1, moves_.end());
            }


        }
    }
    std::cout << "Unit didnt move, all attempts failed\n";



}