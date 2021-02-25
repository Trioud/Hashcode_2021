/*
** EPITECH PROJECT, 2021
** Hashcode_2021
** File description:
** Intersection
*/

#ifndef INTERSECTION_HPP_
#define INTERSECTION_HPP_

#include "Street.hpp"
#include <vector>

class Intersection {
    public:
        Intersection(std::vector<Street> _StreetList, int Inter);
        std::vector<Street> getStreetList() {return _StreetList;}
        int getNum() {return _NumInter;}
        ~Intersection();

    protected:
        std::vector<Street> _StreetList;
        int _NumInter;
};

#endif /* !INTERSECTION_HPP_ */
