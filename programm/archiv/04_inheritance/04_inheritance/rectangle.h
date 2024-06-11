#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

// класс Прямоугольник
class Rectangle : public Shape {
private:
    Point leftBottom; // левый нижний угол
    Point rightUp; // правый верхний угол
public:
    Rectangle(Point leftBottom, Point rightUp); // конструктор
    virtual double getArea() const override; // вычисление площади
    virtual void scale(double k) override; // изотропное масштабирование относительно центра
    virtual Point getCenter() const override; // получение точки центра
    virtual std::string getName() const override; // получение названия фигуры
};

#endif
