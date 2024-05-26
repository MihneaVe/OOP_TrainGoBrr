#ifndef MAINTENANCETASK_H
#define MAINTENANCETASK_H

#include <string>
#include <utility>
#include <iostream>

class MaintenanceTask {
private:
    std::string description;
    int duration; // in hours
    std::string trainID;
public:
    MaintenanceTask(std::string  description, int duration, std::string  trainID);

    [[nodiscard]] std::string getTrainID() const;

    [[nodiscard]] std::string getDescription() const;

    [[nodiscard]] int getDuration() const;

    friend bool operator==(const MaintenanceTask& other1, const MaintenanceTask& other2);

    ~MaintenanceTask();
};


//nu pot sa mut asta nici decum asa ca il las aici
namespace std {
    template <>
    struct hash<MaintenanceTask> {
        std::size_t operator()(const MaintenanceTask& task) const {
            return std::hash<std::string>()(task.getTrainID());
        }
    };
}

#endif // MAINTENANCETASK_H
