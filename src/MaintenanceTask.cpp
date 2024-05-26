#include "MaintenanceTask.h"


MaintenanceTask::MaintenanceTask(std::string  description, int duration, std::string  trainID)
: description(std::move(description)), duration(duration), trainID(std::move(trainID)) {}

[[nodiscard]] std::string MaintenanceTask::getTrainID() const {
    return trainID;
}

[[nodiscard]] std::string MaintenanceTask::getDescription() const {
    return description;
}
[[nodiscard]] int MaintenanceTask::getDuration() const {
    return duration;
}

bool operator==(const MaintenanceTask& other1, const MaintenanceTask& other2){
    return other2.trainID == other1.trainID;
}

MaintenanceTask::~MaintenanceTask() = default;