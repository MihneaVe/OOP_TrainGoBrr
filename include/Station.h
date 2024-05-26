#include <utility>
#include <iostream>

#ifndef OOP_STATION_H
#define OOP_STATION_H


class Station {
private:
    std::string name;
    int platforms;
    std::string location;
public:
    Station(std::string  name, int platforms, std::string  location);

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] int getPlatforms() const;
    [[nodiscard]] std::string getLocation() const;

    ~Station();
};
#endif //OOP_STATION_H
