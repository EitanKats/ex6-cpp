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

        std::normal_distribution<> homeScoreDist{75, 5};
        std::normal_distribution<> guestScoreDist{70, 5};

        double homeScore = 0;
        double guestScore = 0;

        while (homeScore < 55 and guestScore < 50) {
            homeScore = std::round(homeScoreDist(gen));
            guestScore = std::round(guestScoreDist(gen));
        }
        std::uniform_int_distribution bonusDistribution(1, 10);
        double bonus = bonusDistribution(gen);

        guestScore += std::round(_guestTeam->getTalentLevel() * bonus);
        homeScore += std::round(_hostTeam->getTalentLevel() * bonus);
        handleGameResults((int) homeScore, (int) guestScore);

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
