#include "StationManager.h"
#include "Station.h"

template<typename T>
void StationManager<T>::addStation(const std::string& name, const T& station) {
    stations.emplace(name, station);
}

template<typename T>
void StationManager<T>::displayStations() const {
    for (const auto& pair : stations) {
        std::cout << "Station: " << pair.second.getName()
                  << ", Platforms: " << pair.second.getPlatforms()
                  << ", Location: " << pair.second.getLocation() << std::endl;
    }
}

template<typename T>
const std::map<std::string, T>& StationManager<T>::getStations() const {
    return stations;
}

template<typename T>
StationManager<T>::~StationManager()=default;



template class StationManager<Station>;