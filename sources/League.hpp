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

namespace ex6 {
    class League {
    private:
        std::unordered_set<std::string> teamNames;
        std::vector<std::shared_ptr<Team>> Teams;

        std::string createTeamName();

    public:
        void fillTeams();

        League &addTeam(Team &team);

        League &addTeam(const std::shared_ptr<Team> &team);

        League();

        League(std::vector<std::shared_ptr<Team>> teams);
    };
}


#endif //EX6_CPP_LEAGUE_HPP
