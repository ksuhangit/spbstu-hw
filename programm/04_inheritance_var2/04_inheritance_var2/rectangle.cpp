#include "rectangle.h"

// конструктор
Rectangle::Rectangle(const Point& leftBottom, const Point& rightUp) : leftBottom(leftBottom), rightUp(rightUp) { // 20.05.24 переписано через const ссылку
    // проверяем корректность
    if (leftBottom.x >= rightUp.x || leftBottom.y >= rightUp.y) {
        throw std::invalid_argument{ "Прямоугольник недействителен." };
    }
}

// вычисление площади
double Rectangle::getArea() const {
    // площадь прямоугольника равна произведению длин сторон
    return (rightUp.x - leftBottom.x) * (rightUp.y - leftBottom.y);
}

// изотропное масштабирование относительно центра
void Rectangle::scale(double k) {
    if (k <= 0) {
        throw std::invalid_argument{ "Введенное значение k недопустимо." };
    }
    // координаты центра
    Point center = getCenter();
    // масштабируем относительно центра
    leftBottom.x = (leftBottom.x - center.x) * k + center.x;
    leftBottom.y = (leftBottom.y - center.y) * k + center.y;
    rightUp.x = (rightUp.x - center.x) * k + center.x;
    rightUp.y = (rightUp.y - center.y) * k + center.y;
}

// получение точки центра
Point Rectangle::getCenter() const {
    // по x и y находим середины сторон
    return Point{ (rightUp.x + leftBottom.x) / 2, (rightUp.y + leftBottom.y) / 2 };
}

// получение названия фигуры
std::string Rectangle::getName() const {
    return "Прямоугольник";
}
