#include <iostream>
#include "shape.h"
#include "rectangle.h"
#include "trapezoid.h"
using namespace std;

// вывод точки в поток
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

// функция, сортирующая массив указателей на фигуры в порядке неубывания площадей
void sortShapes(Shape** shapes, int n) {
    // сортировка пузырьком
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*shapes[j + 1] < *shapes[j]) {
                Shape* tmp = shapes[j];
                shapes[j] = shapes[j + 1];
                shapes[j + 1] = tmp;
            }
        }
    }
}

// вывод данных фигур на экран
void print(Shape** shapes, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "Фигура: " << shapes[i]->getName() << endl;
        std::cout << "\tКоординаты центра: " << shapes[i]->getCenter() << endl;
        std::cout << "\tПлощадь: " << shapes[i]->getArea() << endl;
    }
}

int main() {

    // создать массив указателей на фигуры
    int n;
    std::cout << "Введите количество фигур: ";
    std::cin >> n;
    Shape** shapes = new Shape * [n] {}; //20.05.2024 замечание - должно быть обнуление
    
    std::cout << "Введите данные фигур:" << endl;
    for (int i = 0; i < n; i++) {
        std::cout << "1 - Прямоугольник, 2 - Равнобедренная трапеция: ";
        int t;
        std::cin >> t;
        try {
            if (t == 1) {
                Point lb, tr;
                std::cout << "Введите координаты левого нижнего угла: ";
                std::cin >> lb.x >> lb.y;
                std::cout << "Введите координаты правого верхнего угла: ";
                std::cin >> tr.x >> tr.y;
                shapes[i] = new Rectangle(lb, tr);
            }
            else if (t == 2) {
                Point lb;
                std::cout << "Введите координаты левого нижнего угла: ";
                std::cin >> lb.x >> lb.y;
                std::cout << "Введите длины нижнего основания, верхнего основания и высоту: ";
                double bottom, top, h;
                std::cin >> bottom >> top >> h;
                shapes[i] = new Trapezoid(lb, bottom, top, h);
            }
            else {
                
                std::cout << "Некорректный выбор, завершено" << std::endl;
                
                // освобождение памяти
                for (int i = 0; i < n; i++) {
                    delete shapes[i];
                }
                delete[] shapes;
                return 0;

            }

        }
        catch (...) {
            // исключения в конструкторе фигуры или некорректный выбор фигуры
            std::cout << "Некорректная фигура, введите другие данные" << std::endl;
            --i;
            // освобождение памяти
            for (int i = 0; i < n; i++) {
                delete shapes[i];
            }
            delete[] shapes;
            return 0; 
        }


    }

   
    // отсортировать фигуры по неубыванию площадей
    sortShapes(shapes, n);
     
    // вывести информацию о фигурах
    std::cout << "После сортировки:" << endl;
    print(shapes, n);

    // выполнить масштабирование на заданный коэффициент
    double k;
    std::cout << "Введите коэффициент масштабирования: ";
    std::cin >> k;
    for (int i = 0; i < n; i++) {
        try {
            shapes[i]->scale(k);
        }
        catch (invalid_argument ex) {
            std::cout << "Ошибка при масштабировании: " << ex.what() << endl;
        }
    }

    // вывести информацию еще раз
    std::cout << "После масштабирования:" << endl;
    print(shapes, n);

    // освобождение памяти
    for (int i = 0; i < n; i++) {
        delete shapes[i];
    }
    delete[] shapes;

    return 0;
}
