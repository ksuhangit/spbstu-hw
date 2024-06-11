#ifndef GEOGRAPHIC_POINT
#define GEOGRAPHIC_POINT

#include <iostream>

// Класс для работы с точками на поверхности земли

class GeographicPoint {
private:
    double lat, lon; // широта, долгота
public:
    // конструктор
    GeographicPoint(double lat = 0, double lon = 0);
    // методы доступа к полям
    double getLat() const {
        return lat;
    }
    double getLon() const {
        return lon;
    }
    void setLat(double lat);
    void setLon(double lon);
    // оператор вывода
    friend std::ostream& operator<<(std::ostream& out, const GeographicPoint& gp);
    // методы определения полушария
    bool isNorth() const {
        return lat > 0;
    }
    bool isSouth() const {
        return lat < 0;
    }
    bool isEast() const {
        return lon > 0;
    }
    bool isWest() const {
        return lon < 0;
    }
    // метод вычисления расстояния между точками
    double getDistance(const GeographicPoint& other);
    // метод, возвращающий смещение времени в минутах относительно Гринвича
    int getTimeZoneMinutes() const;
};

#endif
