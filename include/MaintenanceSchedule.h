#ifndef OOP_MAINTENANCESCHEDULE_H
#define OOP_MAINTENANCESCHEDULE_H

#include <unordered_set>
#include <functional>

template <typename T>
class MaintenanceSchedule {
private:
    std::unordered_set<T, std::hash<T>> tasks;
public:
    void addTask(const T& task) {
        tasks.insert(task);
    }

    void displayTasks() const {
        for (const auto& task : tasks) {
            std::cout << "Task: " << task.getDescription()
                      << ", Duration: " << task.getDuration()
                      << " hours, Train ID: " << task.getTrainID() << std::endl;
        }
    }

    const std::unordered_set<T, std::hash<T>>& getTasks() const {
        return tasks;
    }
};


#endif //OOP_MAINTENANCESCHEDULE_H
