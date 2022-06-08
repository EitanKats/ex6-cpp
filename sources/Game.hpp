//
// Created by Eitan Kats on 06/06/2022.
//

#ifndef EX6_CPP_GAME_HPP
#define EX6_CPP_GAME_HPP

#include "Team.hpp"
#include "memory"

namespace ex6 {

    class Game {
    private:
        std::shared_ptr<Team> _hostTeam;
        std::shared_ptr<Team> _guestTeam;

        void handleGameResults(int homeScore, int guestScore);

        void generateGameResult();

    public:
        Game(std::shared_ptr<Team> hostTeam, std::shared_ptr<Team> guestTeam);
    };
}


#endif //EX6_CPP_GAME_HPP
