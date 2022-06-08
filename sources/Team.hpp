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
        int winStreak = 0;
        int winCounter = 0;
        int loseStreak = 0;
        int loseCounter = 0;
        int totalPointsScored = 0;
        int totalOpponentScores = 0;
    public:
        const std::string &getTeamName() const;

        Team(double talent_level, std::string teamName);

        void increaseWinCounter();

        void increaseLoseCounter();

        void increaseTotalPointsScored(int scored);

        void increaseTotalOpponentScores(int opponentsPoints);

        double getTalentLevel() const;
    };
}


#endif //EX6_CPP_TEAM_HPP
