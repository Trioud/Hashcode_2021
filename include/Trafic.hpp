/*
** EPITECH PROJECT, 2021
** Hashcode_2021
** File description:
** Trafic
*/

#ifndef TRAFIC_HPP_
#define TRAFIC_HPP_

#include "TrafficLights.hpp"
#include "Street.hpp"
#include "Car.hpp"

typedef struct Trafic{
    std::vector<Car> _CarList;
    std::vector<Street> _StreetList;
    TrafficsInfos infos;
}Trafic;

void blablalgorithm(Trafic traficInfo);

#endif /* !TRAFIC_HPP_ */