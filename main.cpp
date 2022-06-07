//
// Created by Eitan Kats on 07/06/2022.
//

#include "./sources/League.hpp"
#include "./sources/Schedule.hpp"

using namespace ex6;

int main() {

    League elLeague;
    Team a{0.3, "PEDRO"};
    Team b{0.5, "PEDRO"};
    elLeague.addTeam(a);
    elLeague.addTeam(b);
    elLeague.fillTeams();

    return 1;
}