#include "MaintenanceSchedule.h"
#include "MaintenanceTask.h"

template<typename T>
void MaintenanceSchedule<T>::addTask(const T& task) {
    tasks.insert(task);
}

template<typename T>
void MaintenanceSchedule<T>::displayTasks() const {
    for (const auto& task : tasks) {
        std::cout << "Task: " << task.getDescription()
                  << ", Duration: " << task.getDuration()
                  << " hours, Train ID: " << task.getTrainID() << std::endl;
    }
}

template<typename T>
const std::unordered_set<T, std::hash<T>>& MaintenanceSchedule<T>::getTasks() const {
    return tasks;
}

template class MaintenanceSchedule<MaintenanceTask>;