
#ifndef OOP_STATIONMANAGER_H
#define OOP_STATIONMANAGER_H

#include <map>

template <typename T>
class StationManager {
public:
    void addStation(const std::string& name, const T& station) {
        stations.emplace(name, station);
    }

    void displayStations() const {
        for (const auto& pair : stations) {
            std::cout << "Station: " << pair.second.getName()
                      << ", Platforms: " << pair.second.getPlatforms()
                      << ", Location: " << pair.second.getLocation() << std::endl;
        }
    }

    const std::map<std::string, T>& getStations() const {
        return stations;
    }

private:
    std::map<std::string, T> stations;
};

#endif //OOP_STATIONMANAGER_H
