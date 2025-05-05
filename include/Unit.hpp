#pragma once
#include <string>

class Unit {
    
    public:
        Unit(int id, std::string team, int x, int y);
        void print_info() const;
        std::string get_team();
        // other methods later

    private:
        int id_;
        std::string team_;
        int x_;
        int y_;

};