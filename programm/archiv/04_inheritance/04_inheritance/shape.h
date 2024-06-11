#ifndef SHAPE_H
#define SHAPE_H

#include "point.h"
#include <string>

// абстрактный класс Shape
class Shape {
public:
    virtual ~Shape() = default; // виртуальный деструктор
    virtual double getArea() const = 0; // вычисление площади
    virtual void scale(double k) = 0; // изотропное масштабирование относительно центра
    virtual Point getCenter() const = 0; // получение точки центра
    virtual std::string getName() const = 0; // получение названия фигуры
    bool operator<(const Shape& other) const { // оператор сравнения (по площади)
        return getArea() < other.getArea();
    }
};

#endif
