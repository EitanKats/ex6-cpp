//
// Created by Eitan Kats on 07/06/2022.
//

#include "./sources/League.hpp"
#include "./sources/Schedule.hpp"

using namespace ex6;

int main() {

    League elLeague;
    elLeague.executeLeagueGames();
    elLeague.displayScores(20);
    return 1;
}