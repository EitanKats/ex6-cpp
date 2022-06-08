//
// Created by Eitan Kats on 06/06/2022.
//

#include "Team.hpp"

#include "utility"
#include "iostream"

namespace ex6 {

    const std::string &Team::getTeamName() const {
        return _teamName;
    }

    Team::Team(double talent_level, std::string teamName) : _talent_level(talent_level),
                                                            _teamName(std::move(teamName)) {

    }

    void Team::increaseWinCounter() {
        winCounter++;
        loseCounter = 0;
        ++totalWins;
        if (this->winStreak < winCounter) {
            winStreak = winCounter;
        }

    }

    int Team::getTotalWins() const {
        return totalWins;
    }

    int Team::getTotalLosses() const {
        return totalLosses;
    }

    void Team::increaseLoseCounter() {
        loseCounter++;
        winCounter = 0;
        ++totalLosses;
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

    double Team::getTalentLevel() const {
        return _talent_level;
    }

    int Team::getTotalPointsScored() const {
        return totalPointsScored;
    }

    int Team::getTotalOpponentScores() const {
        return totalOpponentScores;
    }

    std::ostream &operator<<(std::ostream &os, const Team &currTeam) {
        const std::string separator = ",\t\t";
        os << currTeam.getTeamName() << separator << currTeam.getTotalWins() << separator
           << currTeam.getTotalLosses() << separator << currTeam.getTotalPointsScored();
        return os;
    }

}