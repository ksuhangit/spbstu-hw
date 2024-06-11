// Ilia Shemiakin, 2023
// Пример абстрактного класса

#include <iostream>
#include <string>

// абстрактный класс, содержащий имя преподавателя и количество его статей
// объекты этого класса в явном виде не могут быть созданы
class Teacher
{
public:
  Teacher(const std::string& name) :   // конструктор вызовем в конструкторе потомка
    name_(name),
    publicationCount_(0)
  {}

  // классы, содержащие виртуальные методы, должны также иметь виртуальный деструктор
  // для корректного разрушения объектов производных классов через указатель базового класса
  virtual ~Teacher() = default;

  const std::string& getName() const
  {
    return name_;
  }

  int getPublicationCount() const
  {
    return publicationCount_;
  }

  void setPublicationCount(int count)
  {
    publicationCount_ = count;
  }

  // расчёт повышающего коэффициента к зарплате;
  // чистая виртуальная функция, именно она делает класс абстрактным
  virtual double getCoefficient() const = 0;

protected:
  std::string name_;
  int publicationCount_;               // количество статей
};

// Ассистент
class Assistant : public Teacher
{
public:
  Assistant(const std::string& name) :
    Teacher(name)                      // в конструкторе вызываем конструктор базового класса
  {}

  // на зарплатный коэффициент ассистента влияет только количество статей;
  // ключевое слово override (C++11) показывает, что метод переопределён
  // и не дает ошибиться, например, при изменении сигнатуры метода в базовом классе
  double getCoefficient() const override
  {
    const double NORMAL = 1.0;
    const double HIGH = 1.3;

    return publicationCount_ < PUBLICATION_BARRIER ?
      NORMAL :
      HIGH;
  }

private:
  static const int PUBLICATION_BARRIER = 3;
};

// Профессор
class Professor : public Teacher
{
public:
  Professor(const std::string& name) :
    Teacher(name),
    postgraduateCount_(0)
  {}

  int getPostgraduateCount() const
  {
    return postgraduateCount_;
  }

  void setPostgraduateCount(int count)
  {
    postgraduateCount_ = count;
  }

  // профессор может получить повышенный зарплатный коэффициент,
  // если у него достаточное количество аспирантов
  double getCoefficient() const override
  {
    const double NORMAL = 1.0;
    const double HIGH = 1.3;
    const double HIGHEST = 1.6;

    if (publicationCount_ < PUBLICATION_BARRIER)
    {
      return NORMAL;
    }
    else if (postgraduateCount_ < POSTGRADUATE_BARRIER)
    {
      return HIGH;
    }
    else
    {
      return HIGHEST;
    }
  }

private:
  // необходимое количество статей для профессора выше, чем для ассистента
  static const int PUBLICATION_BARRIER = 5;
  static const int POSTGRADUATE_BARRIER = 2;

  int postgraduateCount_;              // количество аспирантов
};

// функция выводит информацию о преподавателе,
// в качестве параметра принимается ссылка на объект базового(!) типа
void printInfo(std::ostream& stream, const Teacher& teacher)
{
  stream << teacher.getName() << " is ";
  // с помощью оператора dynamic_cast можно определить, кем на самом деле является преподаватель
  if (dynamic_cast<const Professor*>(&teacher) != nullptr)
  {
    stream << "a professor ";
  }
  else if (dynamic_cast<const Assistant*>(&teacher) != nullptr)
  {
    stream << "an assistant ";
  }
  stream << "with salary coefficient " << teacher.getCoefficient() << '\n';
}

int main()
{
  // попробуйте создать объект базового класса - возникнет ошибка, т.к. класс абстрактный

  Professor professor1("Boris Ivanov");
  professor1.setPublicationCount(6);

  Professor professor2("Alexander Stepanov");
  professor2.setPublicationCount(7);
  professor2.setPostgraduateCount(3);

  Assistant assistant1("Ivan Petrov");
  assistant1.setPublicationCount(2);

  printInfo(std::cout, professor1);
  printInfo(std::cout, professor2);
  printInfo(std::cout, assistant1);

  return 0;
}