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

void checkType(const std::map<std::string, Station>& stations);

void checkType(const std::unordered_set<MaintenanceTask, std::hash<MaintenanceTask>>& tasks);

#endif //OOP_RTTICHECK_H
