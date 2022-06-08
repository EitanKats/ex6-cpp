//
// Created by Eitan Kats on 06/06/2022.
//

#ifndef EX6_CPP_LEAGUE_HPP
#define EX6_CPP_LEAGUE_HPP

#include "unordered_set"
#include "memory"
#include "Team.hpp"
#include "string"
#include "vector"
#include "Schedule.hpp"

namespace ex6 {
    class League {
    private:
        std::unordered_set<std::string> _teamNames;
        std::vector<std::shared_ptr<Team>> _teams;
        Schedule _leagueSchedule;

    private:
        std::string generateRandomTeamName();

        void fillTeams();

        void sortResults();

        void displayLongestWinStreak();

        void displayLongestLoseStreak();

        //more points scored the taken
        void displayAmountOfTeamsWithGoodScoreRatio();

        League &addTeam(Team &team);

        League &addTeam(const std::shared_ptr<Team> &team);

    public:

        void displayScores(size_t toDisplay);

        void executeLeagueGames();

        const Schedule &getLeagueSchedule() const;

        const std::unordered_set<std::string> &getTeamNames() const;

        League();

        League(const std::vector<std::shared_ptr<Team>> &teams);
    };
}


#endif //EX6_CPP_LEAGUE_HPP
