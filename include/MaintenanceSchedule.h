#ifndef OOP_MAINTENANCESCHEDULE_H
#define OOP_MAINTENANCESCHEDULE_H

#include <unordered_set>
#include <functional>
#include <iostream>

template <typename T>
class MaintenanceSchedule {
private:
    std::unordered_set<T, std::hash<T>> tasks;
public:

    void addTask(const T& task);

    void displayTasks() const;

    const std::unordered_set<T, std::hash<T>>& getTasks() const;

};


#endif //OOP_MAINTENANCESCHEDULE_H
