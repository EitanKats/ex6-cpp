//
// Created by Eitan Kats on 06/06/2022.
//

#include "League.hpp"
#include "memory"
#include "random"

const int TOTAL_TEAMS = 20;

namespace ex6 {

    League::League(std::vector<std::shared_ptr<Team>> teams) : _teams(teams), _leagueSchedule(TOTAL_TEAMS) {
        for (size_t i = 0; i < teams.size(); ++i) {
            this->_teamNames.insert(teams[i]->getTeamName());
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
            std::shared_ptr<Team> teamPtr = std::make_shared<Team>(dis(gen), createTeamName());
            this->addTeam(teamPtr);
        }
    }

    std::string League::createTeamName() {
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
}

