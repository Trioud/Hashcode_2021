/*
** EPITECH PROJECT, 2021
** Hashcode_2021
** File description:
** Car
*/

#ifndef CAR_HPP_
#define CAR_HPP_

#include <iostream>
#include "Street.hpp"
#include <vector>

class Car {
    public:
        Car(std::vector<std::string> StreetList);
        std::vector<std::string> getPath() {return _Path;}
        ~Car();

    protected:
        std::string _begin;
        std::string _end;
        int timeToEnd;
        std::vector<std::string> _Path;

    private:
};

#endif /* !CAR_HPP_ */