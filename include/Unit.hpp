class Grid;
#pragma once
#include <vector>
#include <string>
#include <random>

class Unit {
    
    public:
        Unit(std::string team, Grid* grid, int x, int y);
        void print_info() const;
        void update_location();
        void move();
        std::string get_team();

        // other methods later

    private:
        int id_;
        static int next_id_;
        std::string team_;
        int x_;
        int y_;
        bool right_leaning_;
        std::vector<std::pair<int, int>> moves_;
        Grid* grid_;
        static std::mt19937 RNG;

};