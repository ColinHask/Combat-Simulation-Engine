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

}