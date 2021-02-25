/*
** EPITECH PROJECT, 2021
** Hashcode_2021
** File description:
** Street
*/

#include "../include/Street.hpp"

Street::Street(int begin, int end, int last, std::string name)
{
    _begin = begin;
    _end = end;
    _last = last;
    _name = name;
    _traficLight = false;
}

Street::~Street()
{
}