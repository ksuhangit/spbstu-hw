#include "rectangle.h"

// конструктор
Rectangle::Rectangle(Point leftBottom, Point rightUp) : leftBottom(leftBottom), rightUp(rightUp) {
    // проверяем корректность
    if (leftBottom.x >= rightUp.x || leftBottom.y >= rightUp.y) {
        throw std::invalid_argument{ "Rectangle is not valid" };
    }
}

// вычисление площади
double Rectangle::getArea() const {
    // площадь прямоугольника равна произведению длин сторон
    return (rightUp.x - leftBottom.x) * (rightUp.y - leftBottom.y);
}

// изотропное масштабирование относительно центра
void Rectangle::scale(double k) {
    if (k >= 0) { // Проверка на неотрицательность коэффициента
        // координаты центра
        Point center = getCenter();
        // масштабируем относительно центра
        leftBottom.x = (leftBottom.x - center.x) * k + center.x;
        leftBottom.y = (leftBottom.y - center.y) * k + center.y;
        rightUp.x = (rightUp.x - center.x) * k + center.x;
        rightUp.y = (rightUp.y - center.y) * k + center.y;
    }
    else {
        // Действия, если коэффициент масштабирования меньше 0
        // Например, можно вывести сообщение об ошибке или оставить текущие значения прямоугольника без изменений
        std::cout << "Ошибка: Коэффициент масштабирования должен быть неотрицательным." << std::endl;
    }
}

// получение точки центра
Point Rectangle::getCenter() const {
    // по x и y находим середины сторон
    return Point{ (rightUp.x + leftBottom.x) / 2, (rightUp.y + leftBottom.y) / 2 };
}

// получение названия фигуры
std::string Rectangle::getName() const {
    return "Rectangle";
}
