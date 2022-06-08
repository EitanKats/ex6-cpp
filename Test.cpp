//
// Created by Eitan Kats on 06/06/2022.
//
#include "doctest.h"
#include "./sources/Team.hpp"
#include "./sources/League.hpp"
#include "./sources/Schedule.hpp"
#include "unordered_set"
#include "string"
#include "iostream"

using namespace ex6;

TEST_CASE ("Check league creation") {
    League elLeague;
            SUBCASE("two teams with the same name") {

        Team a{0.3, "PEDRO"};
        Team b{0.5, "PEDRO"};
        elLeague.addTeam(a);
        elLeague.addTeam(b);
    }
            SUBCASE("check fill works") {
                CHECK(elLeague.getTeamNames().size() == 20);
    }
}

TEST_CASE ("test schedule") {
    League leagueSample;

    auto rounds = leagueSample.getLeagueSchedule().getRounds();
    std::unordered_set<std::string> seti;

    for (size_t i = 0; i < rounds.size(); ++i) {
        const auto [a, b] = rounds.at(i);
        std::string shpring = "H" + std::to_string(a) + "G" + std::to_string(b);
        if (seti.contains(shpring)) {
                    CHECK(1 == 0);
        } else {
            seti.insert(shpring);
        }
    }
    std::cout << rounds.size() << std::endl;
            CHECK(rounds.size() == 380);

    leagueSample.executeLeagueGames();
}
