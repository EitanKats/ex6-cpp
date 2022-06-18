//
// Created by Eitan Kats on 06/06/2022.
//

#ifndef EX6_CPP_SCHEDULE_HPP
#define EX6_CPP_SCHEDULE_HPP


#include "tuple"
#include "vector"

namespace ex6 {

    class Schedule {
    private:

        size_t _totalTeams;
        std::vector<std::tuple<int, int>> rounds;

        //total number of games should be n/2(n-1)
        void registerRound(const std::vector<int>& topTeams, const std::vector<int>& botTeams);

        void createRounds();

    public:
        const std::vector<std::tuple<int, int>> &getRounds() const;

        Schedule(size_t _totalTeams);


    };
}


#endif //EX6_CPP_SCHEDULE_HPP
