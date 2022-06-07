//
// Created by Eitan Kats on 06/06/2022.
//

#include "Team.hpp"

namespace ex6 {

    const std::string &Team::getTeamName() const {
        return _teamName;
    }

    Team::Team(double talent_level, std::string teamName) : _talent_level(talent_level), _teamName(teamName) {

    }

    void Team::increaseWinCounter() {
        winCounter++;
        loseCounter = 0;
        if (this->winStreak < winCounter) {
            winStreak = winCounter;
        }

    }

    void Team::increaseLoseCounter() {
        loseCounter++;
        winCounter = 0;
        if (loseCounter > loseStreak) {
            loseStreak = loseCounter;
        }

    }

    void Team::increaseTotalPointsScored(int scored) {
        this->totalPointsScored += scored;
    }

    void Team::increaseTotalOpponentScores(int opponentsPoints) {
        this->totalOpponentScores += opponentsPoints;
    }
}