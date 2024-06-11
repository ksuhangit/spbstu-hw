// Ilia Shemiakin, 2023
// Простой пример работы с виртуальными методами

#include <iostream>

// базовый класс животного
class Animal
{
public:
  // классы, содержащие виртуальные методы, должны также иметь виртуальный деструктор
  // для корректного разрушения объектов производных классов через указатель базового класса
  virtual ~Animal() = default;

  // метод, печатающий на экран звук, который издает животное
  // попробуйте убрать слово virtual и посмотрите, как изменится выолнение программы
  virtual void getSound() const
  {
    std::cout << "Unknown sound\n";
  }
};

class Bull : public Animal
{
public:
  // метод getSound переопределяется в производных классах
  void getSound() const
  {
    std::cout << "Mmooooo\n";
  }
};

class Dog : public Animal
{
public:
  void getSound() const
  {
    std::cout << "Haw-Haw\n";
  }
};

int main()
{
  // массив указателей на объекты базового(!) класса
  const int ANIMAL_COUNT = 3;
  Animal* animals[ANIMAL_COUNT]{ nullptr };

  try
  {
    // массив с динамически созданными объектами производных классов
    animals[0] = new Bull;
    animals[1] = new Dog;
    animals[2] = new Bull;

    for (int i = 0; i < ANIMAL_COUNT; ++i)
    {
      animals[i]->getSound();
    }
  }
  catch (const std::exception& e)
  {
    std::cout << "Exception: " << e.what() << '\n';
  }

  for (int i = 0; i < ANIMAL_COUNT; ++i)
  {
    delete animals[i];
  }

  return 0;
}
