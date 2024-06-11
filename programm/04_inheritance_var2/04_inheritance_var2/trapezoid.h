#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "shape.h"

// класс Равнобедренная трапеция
class Trapezoid : public Shape {
private:
    Point leftBottom; // левый нижний угол
    double bottom; // длина нижнего основания
    double top; // длина верхнего основания
    double h; // высота
public:
    Trapezoid(const Point& leftBottom, double bottom, double top, double h); // конструктор
    virtual double getArea() const override; // вычисление площади
    virtual void scale(double k) override; // изотропное масштабирование относительно центра
    virtual Point getCenter() const override; // получение точки центра
    virtual std::string getName() const override; // получение названия фигуры
};

#endif
