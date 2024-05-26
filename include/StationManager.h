
#ifndef OOP_STATIONMANAGER_H
#define OOP_STATIONMANAGER_H

#include <map>
#include <iostream>

template <typename T>
class StationManager {
private:
    std::map<std::string, T> stations;
public:
    void addStation(const std::string& name, const T& station);

    void displayStations() const;

    const std::map<std::string, T>& getStations() const;

    ~StationManager();
};

#endif //OOP_STATIONMANAGER_H
