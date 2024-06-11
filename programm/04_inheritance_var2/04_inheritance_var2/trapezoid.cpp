#include "trapezoid.h"

// конструктор
Trapezoid::Trapezoid(const Point& leftBottom, double bottom, double top, double h) : leftBottom(leftBottom), bottom(bottom), top(top), h(h) { // 20.05.24 переписано через const ссылку
    // проверяем корректность
    if (bottom <= 0 || top <= 0 || h <= 0) {
        throw std::invalid_argument{ "Трапеция недействительна." };
    }
}

// вычисление площади
double Trapezoid::getArea() const {
    // площадь трапеции - полусумма оснований умноженная на высоту
    return (bottom + top) / 2 * h;
}

// изотропное масштабирование относительно центра
void Trapezoid::scale(double k) {
    if (k <= 0) {
        throw std::invalid_argument{ "Введенное значение k недопустимо." };
    }
    // координаты центра
    Point center = getCenter();
    // масштабируем относительно центра
    leftBottom.x = (leftBottom.x - center.x) * k + center.x;
    leftBottom.y = (leftBottom.y - center.y) * k + center.y;
    bottom *= k;
    top *= k;
    h *= k;
}

// получение точки центра
Point Trapezoid::getCenter() const {
    // центр - середина средней линии
    return Point{ leftBottom.x + bottom / 2, leftBottom.y + h / 2 };
}

// получение названия фигуры
std::string Trapezoid::getName() const {
    return "Трапеция";
}

