//
// Created by Eitan Kats on 06/06/2022.
//

#include "Game.hpp"
#include "cmath"
#include "random"

namespace ex6 {
    Game::Game(std::shared_ptr<Team> hostTeam, std::shared_ptr<Team> guestTeam) : _guestTeam(guestTeam),
                                                                                  _hostTeam(hostTeam) {
        generateGameResult();
    }

    void Game::generateGameResult() {
        std::random_device rd{};
        std::mt19937 gen{rd()};

        std::normal_distribution<> homeScoreDist{65, 5};
        std::normal_distribution<> guestScoreDist{60, 5};

        int homeScore = 0;
        int guestScore = 0;

        while (homeScore < 55 and guestScore < 55) {
            homeScore = std::round(homeScoreDist(gen));
            guestScore = std::round(guestScoreDist(gen));
        }
        std::uniform_int_distribution bonusDistribution(1, 100);
        double bonus = bonusDistribution(gen);

        guestScore += std::round(_guestTeam->getTalentLevel() * (bonus / 10));
        homeScore += std::round(_hostTeam->getTalentLevel() * (bonus / 10));
        handleGameResults(homeScore, guestScore);

    }

    void Game::handleGameResults(int homeScore, int guestScore) {
        if (homeScore > guestScore) {
            _guestTeam->increaseLoseCounter();
            _hostTeam->increaseWinCounter();
        } else {
            _guestTeam->increaseWinCounter();
            _hostTeam->increaseLoseCounter();
        }

        _guestTeam->increaseTotalPointsScored(guestScore);
        _guestTeam->increaseTotalOpponentScores(homeScore);

        _hostTeam->increaseTotalPointsScored(homeScore);
        _hostTeam->increaseTotalOpponentScores(guestScore);
    }
}
