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
        cout << "Фигура: " << shapes[i]->getName() << endl;
        cout << "\tКоординаты центра: " << shapes[i]->getCenter() << endl;
        cout << "\tПлощадь: " << shapes[i]->getArea() << endl;
    }
}

int main() {

    // создать массив указателей на фигуры
    int n;
    cout << "Введите количество фигур: ";
    cin >> n;
    Shape** shapes = new Shape * [n]; // где-то тут хочет обнуление 
    for (int i = 0; i < n; i++) { //В функции main при создании массива указателей shapes вы забыли его обнулить. Вам нужно добавить инициализацию элементов массива указателей на nullptr:
        shapes[i] = nullptr;
    }
    cout << "Введите данные фигур:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "1 - Прямоугольник, 2 - Равнобедренная трапеция: ";
        int t;
        cin >> t;
        try {
            if (t == 1) {
                Point lb, tr;
                cout << "Введите координаты левого нижнего угла: ";
                cin >> lb.x >> lb.y;
                cout << "Введите координаты правого верхнего угла: ";
                cin >> tr.x >> tr.y;
                shapes[i] = new Rectangle(lb, tr);
            }
            else if (t == 2) {
                Point lb;
                cout << "Введите координаты левого нижнего угла: ";
                cin >> lb.x >> lb.y;
                cout << "Введите длины нижнего основания, верхнего основания и высоту: ";
                double bottom, top, h;
                cin >> bottom >> top >> h;
                shapes[i] = new Trapezoid(lb, bottom, top, h);
            }
            else {
                throw invalid_argument("");
            }
        }
        catch (...) {
            // исключения в конструкторе фигуры или некорректный выбор фигуры
            cout << "Некорректная фигура, введите другие данные" << endl;
            --i;
        }
    }

    // отсортировать фигуры по неубыванию площадей
    sortShapes(shapes, n);

    // вывести информацию о фигурах
    cout << "После сортировки:" << endl;
    print(shapes, n);

    // выполнить масштабирование на заданный коэффициент
    double k;
    cout << "Введите коэффициент масштабирования: ";
    cin >> k;
    for (int i = 0; i < n; i++) {
        shapes[i]->scale(k);
    }

    // вывести информацию еще раз
    cout << "После масштабирования:" << endl;
    print(shapes, n);

    // освобождение памяти
    for (int i = 0; i < n; i++) {
        delete shapes[i];
    }
    delete[] shapes;

    return 0;
}
