#ifndef OOP_RTTICHECK_H
#define OOP_RTTICHECK_H

#include "Station.h"
#include "MaintenanceTask.h"
#include <map>
#include <unordered_set>
#include <typeinfo>
#include <iostream>
#include <regex>
#include <memory>

void checkType(const std::map<std::string, Station>& stations) {
    std::regex typePattern("\\d+(.*)");  // Regular expression to match leading numbers

    for (const auto& pair : stations) {
        std::string mangledName = typeid(pair.second).name();
        std::smatch match;
        std::string demangledName = mangledName;

        if (std::regex_match(mangledName, match, typePattern) && match.size() > 1) {
            demangledName = match.str(1);  // Extract the demangled type name
        }

        std::cout << "Type: " << demangledName
                  << ", Section: " << pair.second.getName() << std::endl;
    }
}

void checkType(const std::unordered_set<MaintenanceTask, std::hash<MaintenanceTask>>& tasks) {
    for (const auto& task : tasks) {
        std::cout << "Task ID: " << task.getTrainID()
                  << ", Task: " << task.getDescription() << std::endl;
    }
}

#endif //OOP_RTTICHECK_H
