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
    int id{};
    std::string company;
    std::string hour;
    std::string minute;
    std::string city;
};


RouteInfo* GetFromFile(const std::string& filename, int& numRoutes) {
    auto* routes = new RouteInfo[MAX_ROUTES]; // Array to store extracted data
    numRoutes = 0; // Initialize number of routes to 0
    std::string time;

    // Open the file
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return nullptr; // Return nullptr if file cannot be opened
    }

    // Read each line from the file
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        RouteInfo route;

        // Extract components from the line
        if (iss >> route.id >> route.company >> time >> route.city) {
            // Extract hour and minute from the time string
            int colonPos = time.find(':');
            if (colonPos != std::string::npos && colonPos >= 2 && colonPos < time.size() - 1) {
                route.hour = time.substr(0, colonPos);
                route.minute = time.substr(colonPos + 1, 2); // Extract 2 characters after the colon as minute
            } else {
                std::cerr << "Invalid time format: " << time << std::endl;
                continue; // Skip this line if time format is invalid
            }

            // Store the extracted route info in the routes array
            routes[numRoutes++] = route;

            // Check if the maximum number of routes has been reached
            if (numRoutes >= MAX_ROUTES) {
                std::cerr << "Maximum number of routes reached" << std::endl;
                break; // Break loop if maximum number of routes is reached
            }
        } else {
            std::cerr << "Failed to parse line: " << line << std::endl;
        }
    }

    // Close the file
    file.close();

    // Return the array containing extracted data
    return routes;
}

#endif //OOP_GETROUTESHELP_H
