//
// Created by Eitan Kats on 06/06/2022.
//

#include "Schedule.hpp"
#include "algorithm"
#include "exception"

namespace ex6 {


    void Schedule::createRounds() {

        std::vector<int> topVect(_totalTeams / 2);
        std::vector<int> botVect(_totalTeams / 2);

        for (size_t i = 0; i < _totalTeams; ++i) {
            if (i > (this->_totalTeams / 2) - 1) {
                botVect[i - this->_totalTeams / 2] = (int) i;
            } else {
                topVect[i] = (int) i;
            }
        }

        int k = 0;
        while (k < _totalTeams - 1) {

            registerRound(topVect, botVect);
            int botRowShift = botVect[0];
            int topRowShift = topVect[topVect.size() - 1];

            for (size_t i = topVect.size() - 1; i > 0; --i) {
                size_t prev = i - 1;
                topVect[i] = topVect[prev];
            }
            for (size_t i = 0; i < (_totalTeams / 2) - 1; i++) {
                botVect[i] = botVect[i + 1];
            }
            topVect[1] = botRowShift;
            botVect[_totalTeams / 2 - 1] = topRowShift;
            ++k;
        }
    }

    void Schedule::registerRound(const std::vector<int>& topTeams, const std::vector<int>& botTeams) {
        size_t total_teams = std::min(topTeams.size(), botTeams.size());
        for (size_t i = 0; i < total_teams; ++i) {
            this->rounds.emplace_back(topTeams[i], botTeams[i]);
            this->rounds.emplace_back(botTeams[i], topTeams[i]);

        }
    }

    const std::vector<std::tuple<int, int>> &Schedule::getRounds() const {
        return rounds;
    }

    Schedule::Schedule(size_t totalTeams) : _totalTeams(totalTeams) {
        createRounds();
    }
}

