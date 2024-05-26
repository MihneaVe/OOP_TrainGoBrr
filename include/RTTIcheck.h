#ifndef OOP_RTTICHECK_H
#define OOP_RTTICHECK_H

#include "Station.h"
#include "MaintenanceTask.h"
#include <map>
#include <unordered_set>
#include <typeinfo>
#include <iostream>
#include <cxxabi.h>
#include <memory>

void checkType(const std::map<std::string, Station>& stations) {
    for (const auto& pair : stations) {
        int status = 0;
        std::unique_ptr<char[], void(*)(void*)> realname(
                abi::__cxa_demangle(typeid(pair.second).name(), nullptr, nullptr, &status), std::free);

        std::cout << "Type: " << (status == 0 ? realname.get() : typeid(pair.second).name())
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
