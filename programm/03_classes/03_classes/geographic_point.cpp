#include "geographic_point.h"
#include <cmath>

// конструктор
GeographicPoint::GeographicPoint(double lat, double lon) {
    setLat(lat);
    setLon(lon);
}

// установка широты (от -90 до 90)
void GeographicPoint::setLat(double lat) {
    if (lat < -90 || lat > 90) {
        throw std::invalid_argument("Широта должна быть от -90 до 90");
    }
    this->lat = lat;
}

// установка долготы (от -180 до 180)
void GeographicPoint::setLon(double lon) {
    if (lon < -180 || lon > 180) {
        throw std::invalid_argument("Долгота должна быть от -180 до 180");
    }
    this->lon = lon;
}

// оператор вывода
std::ostream& operator<<(std::ostream& out, const GeographicPoint& gp) {
    out << gp.lat << ", " << gp.lon;
    return out;
}

// метод вычисления расстояния между точками
double GeographicPoint::getDistance(const GeographicPoint& other) {
    // переводим координаты из градусов в радианы
    double phi1 = lat * M_PI / 180;
    double phi2 = other.lat * M_PI / 180;
    double lambda1 = lon * M_PI / 180;
    double lambda2 = other.lon * M_PI / 180;
    // угловая длина ортодромии
    double delta = acos(sin(phi1) * sin(phi2) + cos(phi1) * cos(phi2) * cos(lambda2 - lambda1));
    // длина ортодромии
    // 6371 - средний радиус земли
    return 6371 * delta;
}

// метод, возвращающий смещение времени в минутах относительно Гринвича
int GeographicPoint::getTimeZoneMinutes() const {
    // географический часовой пояс составляет 15 градусов
    // при этом нулевым является пояс от -7.5 до 7.5
    // поэтому пересчитаваем отрицательные координаты со смещением на -7.5
    // положительные на +7.5
    // и берем результат деления на 15
    // для получения минут умножаем на 60
    return 60 * (lon < 0 ? (int)((lon - 7.5) / 15) : (int)((lon + 7.5) / 15));
}
