//
// Created by Eitan Kats on 06/06/2022.
//

#include "League.hpp"
#include "memory"
#include "random"

namespace ex6 {

    League &ex6::League::addTeam(Team &team) {
        if (!this->teamNames.contains(team.getTeamName())) {
            this->teamNames.insert(team.getTeamName());
            this->Teams.push_back(std::make_shared<Team>(team));
        }
        return *this;
    }

    void League::fillTeams() {
        std::random_device rd;
        std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
        std::uniform_real_distribution<> dis(0.0, 1.0);
        while (this->teamNames.size() < 20) {
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

    League::League() {

    }

    League &League::addTeam(const std::shared_ptr<Team> &team) {
        if (!this->teamNames.contains(team->getTeamName())) {
            this->teamNames.insert(team->getTeamName());
            this->Teams.push_back(team);
        }
        return *this;
    }
}

