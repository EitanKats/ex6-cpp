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

    public:

        void executeLeagueGames();

        League &addTeam(Team &team);

        League &addTeam(const std::shared_ptr<Team> &team);

        const Schedule &getLeagueSchedule() const;

        const std::unordered_set<std::string> &getTeamNames() const;

        League();

        League(std::vector<std::shared_ptr<Team>> teams);
    };
}


#endif //EX6_CPP_LEAGUE_HPP
