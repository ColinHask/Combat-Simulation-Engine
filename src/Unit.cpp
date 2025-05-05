#include "Unit.hpp"
#include <iostream>

Unit::Unit(int id, std::string team, int x, int y)
    : id_(id), team_(team), x_(x), y_(y) {}

void Unit::print_info() const {
    std::cout << "Unit" << id_ << " (" << team_ << ") at (" << x_ << ", " << y_ << ")\n"; 
}