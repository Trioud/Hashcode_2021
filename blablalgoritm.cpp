/*
** EPITECH PROJECT, 2021
** Hashcode_2021
** File description:
** blablalgoritm
*/

#include "include/Trafic.hpp"
#include "include/Intersection.hpp"

void blablalgorithm(Trafic traficInfo)
{
    int i = 0;
    std::cout << "All Cars :" << std::endl;
    for (auto a : traficInfo._CarList) {
        i++;
        std::cout << "Car " << i << std::endl;
        std::vector<std::string> tmp = a.getPath();
        for (auto m : tmp)
            std::cout << "  " << m << std::endl;
    }

    std::cout << "\nAll Streets :" << std::endl;

    for (auto a : traficInfo._StreetList) {
        std::cout << "Street : " << a.getName() << std::endl;
        std::cout << "  begin at " << a.getBegin() << std::endl;
        std::cout << "  end at " << a.getEnd() << std::endl;
        std::cout << "  time : " << a.getLast() << " sec."<< std::endl;
        std::cout << "  traficLight : " << a.getTraficLight() << std::endl;
    }
    std::vector<Intersection> Inter;
    for (int i = 0; i != traficInfo.infos.T_intersections; i ++) {
        Inter.push_back(Intersection(traficInfo._StreetList, i));
    }
    std::cout << "\nAll Intersections :" << std::endl;
    for (auto a : Inter) {
        std::cout << "Inter " << a.getNum() << std::endl;
        std::vector<Street> tmp = a.getStreetList();
        for (auto r : tmp) {
            std::cout << "  " << r.getName() << std::endl;
        }
    }

}