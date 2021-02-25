/*
** EPITECH PROJECT, 2021
** Hashcode_2021
** File description:
** Street
*/

#ifndef STREET_HPP_
#define STREET_HPP_

#include <iostream>

class Street {
    public:
        Street(int begin, int end, int last, std::string name);
        std::string getName() {return _name;}
        int getBegin() {return _begin;}
        int getEnd() {return _end;}
        int getLast() {return _last;}
        bool getTraficLight() {return _traficLight;}
        ~Street();

    protected:
        int _begin;
        int _end;
        int _last;
        bool _traficLight;
        std::string _name;
    private:
};

#endif /* !STREET_HPP_ */