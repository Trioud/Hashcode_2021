/*
** EPITECH PROJECT, 2021
** Hashcode_2021
** File description:
** Intersection
*/

#include "../include/Intersection.hpp"

Intersection::Intersection(std::vector<Street> StreetList, int Inter)
{
    _NumInter = Inter;
    for (auto a : StreetList) {
        if (a.getEnd() == _NumInter) {
            _StreetList.push_back(a);
        }
    }
}

Intersection::~Intersection()
{
}