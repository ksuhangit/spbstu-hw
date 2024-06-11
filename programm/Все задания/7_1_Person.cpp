// Ilia Shemiakin, 2023
// Класс Person

// В VisualStudio стандартная функция std::localtime считается небезопасной,
// можно использовать вместо неё localtime_s или объявить идентификатор _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <ctime>

// класс, содержащий базовую информацию о человеке
class Person
{
public:
  // конструктор - особый метод класса, использующийся для инициализации свойств при создании объекта
  Person();                               // конструктор без параметров
  Person(const std::string&, short);      // конструктор с двумя параметрами

  void setName(const std::string&);       // задать имя
  std::string getName() const;            // получить имя
  void setYear(short);                    // задать год рождения
  short getYear() const;                  // получить год рождения
  short getAge() const;                   // возвращает возраст человека в текущем году

private:
  std::string name_;	// имя человека
  short birthYear_;   // год рождения
};

// функция сортировки массива указателей на объекты Person
void sortPerson(Person**, int);

// функция для вывода информации о человеке в указанный поток
void printInfo(const Person& person, std::ostream& stream);

int main()
{
  const int SIZE = 5;
  Person* persons[SIZE]{ nullptr };  // массив указателей на объекты Person
  try
  {
    persons[0] = new Person("Ilya", 1989);
    persons[1] = new Person("Daniil", 1990);
    persons[2] = new Person("Mikhail", 1985);
    persons[3] = new Person("Olga", 1995);
    persons[4] = new Person("Anastasiya", 1983);

    for (int i = 0; i < SIZE; ++i)
    {
      printInfo(*persons[i], std::cout);
    }

    sortPerson(persons, SIZE);

    std::cout << std::endl;

    for (int i = 0; i < SIZE; ++i)
    {
      printInfo(*persons[i], std::cout);
    }
  }
  catch (...)
  {
    std::cout << "Error!\n";
  }

  for (int i = 0; i < SIZE; ++i)
  {
    delete persons[i];
  }

  return 0;
}

// методы класса должны быть объявлены внутри класса, но определены могут быть вне его;
// для этого применяется такой синтаксис <тип_возвр_значения> <имя_класса>::<имя_метода>(<параметры>)
Person::Person() :
  name_(""),
  birthYear_(0)
{}

Person::Person(const std::string& name, short birthYear) :
  name_(name),
  birthYear_(birthYear)
{}

// обратите внимание, что передаётся ссылка на объект, это позволяет избежать копирования строки
void Person::setName(const std::string& name)
{
  name_ = name;
}

// методы, отмеченные ключевым словом const не могут изменять значений свойств объекта
std::string Person::getName() const
{
  return name_;
}

void Person::setYear(short birthYear)
{
  birthYear_ = birthYear;
}

short Person::getYear() const
{
  return birthYear_;
}

// получение текущего года - не такое уж простое действие, используются типы time_t и tm
short Person::getAge() const
{
  std::time_t ctime;
  std::time(&ctime);
  std::tm* parsedTime = std::localtime(&ctime);
  // в поле tm_year структуры tm хранится количество лет после 1900 года
  return (parsedTime->tm_year + 1900) - birthYear_;
}

// сортировка людей по возрасту
// persons - указатель на массив указателей на объекты Person
// обратите внимание, что переставляются только указатели, а не сами объекты
void sortPerson(Person** persons, int size)
{
  for (int i = 0; i < size - 1; ++i)
  {
    for (int j = 0; j < size - i - 1; ++j)
    {
      if (persons[j]->getYear() > persons[j + 1]->getYear())
      {
        Person* temp = persons[j];
        persons[j] = persons[j + 1];
        persons[j + 1] = temp;
      }
    }
  }
}

void printInfo(const Person& person, std::ostream& stream)
{
  stream << person.getName() << " is " << person.getAge() << " years old\n";
}