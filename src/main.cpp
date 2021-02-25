/*
** EPITECH PROJECT, 2021
** src
** File description:
** main
*/

#include <exception>
#include <stdexcept>
#include <iostream> 
#include <fstream>
#include <string>
#include "../include/TrafficLights.hpp"
#include <vector>
#include <sstream>
#include "../include/Car.hpp"
#include "../include/Street.hpp"
#include "../include/Trafic.hpp"

static int x = 0;

void error_gestion(int ac, char **av)
{
    if (ac != 2)
        throw std::invalid_argument("Not enough arguments");
}

std::vector<std::string> split(std::string strToSplit, char delimeter)
{
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (getline(ss, item, delimeter))
    {
       splittedStrings.push_back(item);
    }
    return splittedStrings;
}

void dump(std::vector<std::string> path)
{
    for (std::vector<std::string>::const_iterator i = path.begin(); i != path.end(); ++i)
        std::cout << *i << std::endl;
    std::cout << std::endl;
}

bool is_digits(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

void first_line(TrafficsInfos &infos, std::string first_line)
{
    std::vector<std::string> vector;

    if (!infos.filled) {
        vector = split(first_line, ' ');
        // dump(vector);
        infos.T = atoi(vector[0].c_str());
        infos.T_intersections = atoi(vector[1].c_str());
        infos.T_streets = atoi(vector[2].c_str());
        infos.T_cars = atoi(vector[3].c_str());
        infos.Points = atoi(vector[4].c_str());
        infos.filled = true;
        x++;
    }
}

std::string get_roads(std::string line, bool filled)
{
    if (filled == true) {
        std::vector<std::string> vector;
        vector = split(line, ' ');
        if (vector.size() == 4 && is_digits(vector[1])) {
            return (line);
        }
    }
    return ("");
}

std::string get_cars(std::string line, bool filled)
{
    if (filled == true) {
        std::vector<std::string> vector;
        vector = split(line, ' ');
        if (!is_digits(vector[1])) {
            return (line);
        }
    }
    return ("");
}

void createStreetList(std::vector<std::string> roads, std::vector<Street> &StreetList)
{
    for (auto e : roads) {
        std::vector<std::string> tmp = split(e, ' ');
        int a = std::stoi(tmp[0]);
        int b = std::stoi(tmp[1]);
        int c = std::stoi(tmp[3]);
        Street ee(a, b, c, tmp[2]);
        StreetList.push_back(ee);
    }
}

void createCarList(std::vector<std::string> cars, std::vector<Car> &CarsList)
{
    for (auto e : cars) {
        std::vector<std::string> tmp = split(e, ' ');
        Car ee(tmp);
        CarsList.push_back(ee);
    }
}

Trafic lecture_file(std::ifstream &File)
{
    //6 -> nb de seconde de la simulation
    //4 -> Le nb d'intersections
    //5 -> le nb de street
    //2 -> Nombres de voitures
    //1000 -> Nombre de points que tu remportes avant le temps;
    int i = 0;
    Trafic traficInfos;
    std::string stock;
    std::string tmp;
    TrafficsInfos infos;
    std::vector<std::string> roads;
    std::vector<std::string> cars;
    std::vector<Street> StreetList;
    std::vector<Car> CarList;

    while (getline(File, stock)) {
        tmp = get_roads(stock, infos.filled);
        if (!tmp.empty()) {
            roads.push_back(tmp);
            continue;
        }
        tmp = get_cars(stock, infos.filled);
        if (!tmp.empty()) {
            cars.push_back(tmp);
            continue;
        }
        first_line(infos, stock);
    }
    createStreetList(roads, StreetList);
    createCarList(cars, CarList);
    traficInfos._CarList = CarList;
    traficInfos._StreetList = StreetList;
    traficInfos.infos = infos;
    return (traficInfos);
}

int blablacars(int ac, char **av)
{
    std::ifstream fichier(av[1]);

    if (fichier) {
        Trafic tmp = lecture_file(fichier);
        blablalgorithm(tmp);

    } else {
        throw std::invalid_argument("File can't be found");
    }
    return (0);
}

int main(int ac, char **av)
{
    try {
        error_gestion(ac, av);
    }
    catch (std::exception const &str) {
        std::cout << str.what() << std::endl;
        return (84);
    }
    return (blablacars(ac, av));
}