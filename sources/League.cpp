//
// Created by Eitan Kats on 06/06/2022.
//

#include "League.hpp"
#include "memory"
#include "random"
#include "Game.hpp"
#include "algorithm"
#include "iostream"
#include "cmath"

const int TOTAL_TEAMS = 20;

namespace ex6 {


    League::League(const std::vector<std::shared_ptr<Team>> &teams) : _teams(teams), _leagueSchedule(TOTAL_TEAMS) {
        for (auto &team: teams) {
            this->_teamNames.insert(team->getTeamName());
        }
        this->fillTeams();
    }

    League::League() : _leagueSchedule(TOTAL_TEAMS) {
        this->fillTeams();
    }


    League &ex6::League::addTeam(Team &team) {
        if (!this->_teamNames.contains(team.getTeamName())) {
            this->_teamNames.insert(team.getTeamName());
            this->_teams.push_back(std::make_shared<Team>(team));
        }
        return *this;
    }

    void League::fillTeams() {
        std::random_device rd;
        std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
        std::uniform_real_distribution<> dis(0.0, 1.0);
        while (this->_teamNames.size() < TOTAL_TEAMS) {
            double currentTalent = dis(gen);
            currentTalent = currentTalent < 0.1 ? currentTalent + 0.1 : currentTalent;
            std::shared_ptr<Team> teamPtr = std::make_shared<Team>(currentTalent, generateRandomTeamName());
            this->addTeam(teamPtr);
        }
    }

    std::string League::generateRandomTeamName() {
        std::string str("0123456789abcdefghijklmnopqrstuvwxyz");

        std::random_device rd;
        std::mt19937 generator(rd());

        std::shuffle(str.begin(), str.end(), generator);

        return str.substr(0, 10);
    }

    League &League::addTeam(const std::shared_ptr<Team> &team) {
        if (!this->_teamNames.contains(team->getTeamName())) {
            this->_teamNames.insert(team->getTeamName());
            this->_teams.push_back(team);
        }
        return *this;
    }

    const std::unordered_set<std::string> &League::getTeamNames() const {
        return _teamNames;
    }

    const Schedule &League::getLeagueSchedule() const {
        return _leagueSchedule;
    }

    void League::executeLeagueGames() {

        for (std::tuple<int, int> match: this->_leagueSchedule.getRounds()) {
            const auto [a, b] = match;
            auto homeIdx = (size_t) a;
            auto guestIdx = (size_t) b;
            Game currGame{this->_teams.at(homeIdx), this->_teams.at(guestIdx)};

        }
        sortResults();
    }

    void League::displayScores(size_t toDisplay) {
        std::cout << "Team name" << ",\t\t" << "Wins" << ",\t" << "Losses" << ",\t" << "Total points" << std::endl;
        size_t toPrint = std::min(this->_teams.size(), toDisplay);
        for (size_t i = this->_teams.size() - 1; i > this->_teams.size() - 1 - toPrint; --i) {
            std::cout << *(this->_teams.at(i)) << std::endl;
        }
    }

    void League::sortResults() {
        std::sort(this->_teams.begin(), this->_teams.end(),
                  [](const std::shared_ptr<Team> &a, const std::shared_ptr<Team> &b) {
                      double teamARatio = (double) a->getTotalWins() / a->getTotalLosses();
                      double teamBRatio = (double) b->getTotalWins() / b->getTotalLosses();
                      if (teamARatio != teamBRatio) {
                          return teamARatio < teamBRatio;
                      } else {
                          int teamAPointsDiff = a->getTotalWins() - a->getTotalLosses();
                          int teamBPointsDiff = b->getTotalWins() - b->getTotalLosses();
                          return teamAPointsDiff < teamBPointsDiff;
                      }
                  });
    }
}

