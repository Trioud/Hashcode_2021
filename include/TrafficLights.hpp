/*
** EPITECH PROJECT, 2021
** src
** File description:
** TrafficLights
*/

#include <iostream>

class TrafficsInfos {
    public:
        TrafficsInfos() {
            T = 0;
            T_intersections = 0;
            T_streets = 0;
            T_cars = 0;
            Points = 0;
            filled = false;
        };
        ~TrafficsInfos() {};
        void dump () {
            std::cout << T << std::endl;
            std::cout << T_intersections << std::endl;
            std::cout << T_streets << std::endl;
            std::cout << T_cars << std::endl;
            std::cout << Points << std::endl;
            std::cout << filled << std::endl;
        };
    //6 -> nb de seconde de la simulation
    //4 -> Le nb d'intersections
    //5 -> le nb de street
    //2 -> Nombres de voitures
    //1000 -> Nombre de points que tu remportes avant le temps;
    int T;
    int T_intersections;
    int T_streets;
    int T_cars;
    int Points;
    bool filled;
    protected:
    private:
};
