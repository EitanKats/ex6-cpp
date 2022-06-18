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
#include "vector"

using namespace ex6;

void badTeam() {
    Team a{1.1, "asdf"};
}

void badTeamNegativeTalent() {
    Team a{-1, "asdf"};
}

void badTeamName() {
    Team a{-1, "asd\x01"};
}

TEST_CASE ("Check team creation") {
            CHECK_THROWS(badTeam());
            CHECK_THROWS(badTeamNegativeTalent());
            CHECK_THROWS(badTeamName());
}

TEST_CASE ("Check league creation") {

            SUBCASE("two teams with the same name") {


        std::vector<std::shared_ptr<Team>> _teams;
        std::shared_ptr<Team> team1 = std::make_shared<Team>(0.9, "Golden State Warriors");
        std::shared_ptr<Team> team2 = std::make_shared<Team>(0.4, "Boston Celtics");
        std::shared_ptr<Team> team3 = std::make_shared<Team>(0.5, "Brooklyn Nets");
        std::shared_ptr<Team> team4 = std::make_shared<Team>(0.3, "Denver Nuggets");
        std::shared_ptr<Team> team5 = std::make_shared<Team>(0.4, "Philadelphia 76ers");
        std::shared_ptr<Team> team6 = std::make_shared<Team>(0.5, "Minnesota Timberwolves");
        std::shared_ptr<Team> team7 = std::make_shared<Team>(0.3, "Chicago Bulls");
        std::shared_ptr<Team> team8 = std::make_shared<Team>(0.2, "Portland Trail Blazers");
        std::shared_ptr<Team> team9 = std::make_shared<Team>(0.5, "LA Clippers");
        std::shared_ptr<Team> team10 = std::make_shared<Team>(0.9, "Los Angeles Lakers");
        std::shared_ptr<Team> team11 = std::make_shared<Team>(0.7, "Milwaukee Bucks");
        std::shared_ptr<Team> team12 = std::make_shared<Team>(0.3, "Atlanta Hawks");
        std::shared_ptr<Team> team13 = std::make_shared<Team>(0.2, "Charlotte Hornets");
        std::shared_ptr<Team> team14 = std::make_shared<Team>(0.6, "Miami Heat");
        std::shared_ptr<Team> team15 = std::make_shared<Team>(0.8, "Phoenix Suns");
        std::shared_ptr<Team> team16 = std::make_shared<Team>(0.6, "Dallas Mavericks");
        std::shared_ptr<Team> team17 = std::make_shared<Team>(0.5, "Memphis Grizzlies");
        std::shared_ptr<Team> team18 = std::make_shared<Team>(0.3, "Utah Jazz");
        std::shared_ptr<Team> team19 = std::make_shared<Team>(0.1, "Washington Wizards");
        std::shared_ptr<Team> team20 = std::make_shared<Team>(0.1, "Oklahoma City Thunder");
        _teams.push_back(team1);
        _teams.push_back(team2);
        _teams.push_back(team3);
        _teams.push_back(team4);
        _teams.push_back(team5);
        _teams.push_back(team6);
        _teams.push_back(team7);
        _teams.push_back(team8);
        _teams.push_back(team9);
        _teams.push_back(team10);
        _teams.push_back(team11);
        _teams.push_back(team12);
        _teams.push_back(team13);
        _teams.push_back(team14);
        _teams.push_back(team15);
        _teams.push_back(team16);
        _teams.push_back(team17);
        _teams.push_back(team18);
        _teams.push_back(team19);
        _teams.push_back(team20);
        League league2{_teams};

                CHECK_NOTHROW(league2.displayScores(10));
                CHECK(1 == 1);

                CHECK(league2.getTeamNames().size() == 20);

    }
            SUBCASE("check fill works") {
        League elLeague;
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

    Schedule testSche{6};
    //should be 6(6-1) = 30
            CHECK(testSche.getRounds().size() == 30);

}

TEST_CASE ("league execution test") {
    League testLeague;
            CHECK_NOTHROW(testLeague.getTeamNames());
            CHECK_NOTHROW(testLeague.displayScores(1));
            CHECK_NOTHROW(testLeague.getLeagueSchedule().getRounds());
            CHECK_NOTHROW(testLeague.executeLeagueGames());
            CHECK_NOTHROW(testLeague.displayScores(1));
            CHECK_NOTHROW(testLeague.displayScores(4));
}
