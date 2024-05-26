#ifndef MAINTENANCETASK_H
#define MAINTENANCETASK_H

#include <string>
#include <utility>

class MaintenanceTask {
private:
    std::string description;
    int duration; // in hours
    std::string trainID;
public:
    MaintenanceTask(std::string  description, int duration, std::string  trainID)
            : description(std::move(description)), duration(duration), trainID(std::move(trainID)) {}

    [[nodiscard]] std::string getTrainID() const {
        return trainID;
    }

    [[nodiscard]] std::string getDescription() const {
        return description;
    }
    [[nodiscard]] int getDuration() const {
        return duration;
    }

    bool operator==(const MaintenanceTask& other) const {
        return trainID == other.trainID;
    }
};

namespace std {
    template <>
    struct hash<MaintenanceTask> {
        std::size_t operator()(const MaintenanceTask& task) const {
            return std::hash<std::string>()(task.getTrainID());
        }
    };
}

#endif // MAINTENANCETASK_H
