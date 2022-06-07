//
// Created by Eitan Kats on 06/06/2022.
//

#ifndef EX6_CPP_TEAM_HPP
#define EX6_CPP_TEAM_HPP

#include "string"

namespace ex6 {

    class Team {
    private:
        double _talent_level;
        std::string _teamName;
    public:
        const std::string &getTeamName() const;

        Team(double talent_level, std::string teamName);

    };
}


#endif //EX6_CPP_TEAM_HPP
