#include <utility>


#ifndef OOP_STATION_H
#define OOP_STATION_H


class Station {
private:
    std::string name;
    int platforms;
    std::string location;
public:
    Station(std::string  name, int platforms, std::string  location)
            : name(std::move(name)), platforms(platforms), location(std::move(location)) {}

    [[nodiscard]] std::string getName() const { return name; }
    [[nodiscard]] int getPlatforms() const { return platforms; }
    [[nodiscard]] std::string getLocation() const { return location; }
};
#endif //OOP_STATION_H
