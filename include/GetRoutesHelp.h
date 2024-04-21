//
// Created by Mihnea on 4/21/2024.
//
#ifndef OOP_GETROUTESHELP_H
#define OOP_GETROUTESHELP_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

const int MAX_ROUTES = 150;

struct RouteInfo {
    int id[MAX_ROUTES]{};
    std::string company[MAX_ROUTES][4]{};
    std::string time[MAX_ROUTES][3]{};
    std::string city[MAX_ROUTES][16]{};
};

RouteInfo GetFromFile(const std::string& filename, int& numRoutes) {
    RouteInfo routes;
    numRoutes = 0;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return routes;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);

        // Extract components from the line
        if (numRoutes < MAX_ROUTES) {
            // Read ID
            if (!(iss >> routes.id[numRoutes])) {
                std::cerr << "Failed to read ID from line: " << line << std::endl;
                continue;
            }

            // Read Company
            if (!(iss >> routes.company[numRoutes][0])) {
                std::cerr << "Failed to read Company from line: " << line << std::endl;
                continue;
            }

            // Read Time
            if (!(iss >> routes.time[numRoutes][0])) {
                std::cerr << "Failed to read Time from line: " << line << std::endl;
                continue;
            }

            // Read City
            if (!(iss >> routes.city[numRoutes][0])) {
                std::cerr << "Failed to read City from line: " << line << std::endl;
                continue;
            }

            ++numRoutes;
        } else {
            std::cerr << "Maximum number of routes reached" << std::endl;
            break;
        }
    }

    file.close();

    return routes;
}


#endif //OOP_GETROUTESHELP_H
