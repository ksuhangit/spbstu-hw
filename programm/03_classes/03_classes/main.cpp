#include <iostream>
#include "geographic_point.h"
using namespace std;

// вспомогательная функция, выводящая полушария
void printSpheres(const GeographicPoint& gp) {
    if (gp.isEast()) {
        cout << "восточное полушарие, ";
    }
    else if (gp.isWest()) {
        cout << "западное полушарие, ";
    }
    else {
        cout << "нулевой меридиан, ";
    }
    if (gp.isNorth()) {
        cout << "северное полушарие" << endl;
    }
    else if (gp.isSouth()) {
        cout << "южное полушарие" << endl;
    }
    else {
        cout << "экватор" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    // демонстрация работы всех методов

    // задаем две точки (конструктор и методы set, используемые внутри конструктора)
    GeographicPoint eiffelTour(48.85837, 2.29448);
    GeographicPoint colosseo(41.89023, 12.49224);

    // выводим точки
    cout << "Координаты Эйфелевой башни: " << eiffelTour << endl;
    cout << "Координаты Колизея: " << colosseo << endl;

    // выводим точки с помощью методов доступа
    cout << "Широта Эйфелевой башни: " << eiffelTour.getLat() << endl;
    cout << "Долгота Колизея: " << colosseo.getLon() << endl;

    // получаем расстояние
    cout << "Расстояние от Эйфелевой башни до Колизея: " << eiffelTour.getDistance(colosseo) << endl;
    cout << "Расстояние от Колизея до Эйфелевой башни: " << colosseo.getDistance(eiffelTour) << endl;

    // проверяем полушария
    cout << "Эйфелева башня находитя: ";
    printSpheres(eiffelTour);
    cout << "Колизей находитя: ";
    printSpheres(colosseo);

    // выводим часовой пояс (смещение в минутах)
    cout << "Смещение в минутах относительно Гринвича (географический часовой пояс):" << endl;
    cout << "Эйфелева башня: " << eiffelTour.getTimeZoneMinutes() << endl;
    cout << "Колизей: " << colosseo.getTimeZoneMinutes() << endl;

    // попытка сделать объект с некорректным состоянием
    cout << "Создаем точку с широтой 100 градусов:" << endl;
    try {
        GeographicPoint wrongPoint(100, 0);
    }
    catch (...) {
        cout << "Не удалось" << endl;
    }
    cout << "Создаем точку с долготой 200 градусов:" << endl;
    try {
        GeographicPoint wrongPoint(0, 200);
    }
    catch (...) {
        cout << "Не удалось" << endl;
    }

    return 0;
}
