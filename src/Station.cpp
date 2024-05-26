#include "Station.h"

Station::Station(std::string  name, int platforms, std::string  location)
: name(std::move(name)), platforms(platforms), location(std::move(location)) {}

[[nodiscard]] std::string Station::getName() const { return name; }
[[nodiscard]] int Station::getPlatforms() const { return platforms; }
[[nodiscard]] std::string Station::getLocation() const { return location; }

Station::~Station() = default;