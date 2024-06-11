// Ilia Shemiakin, 2023
// Класс комплексного числа, пример перегрузки операторов

#include <iostream>
#include <cmath>

// класс для работы с комплексными числами
class Complex
{
public:
  // если в классе определён конструктор с параметрами, то конструктор по умолчанию не создаётся,
  // это значит, что нельзя создать комплексное число без явной инициализации
  Complex(double re, double im = 0) :
    re_(re),
    im_(im)
  {}

  // методы для задания полей объекта отсутствуют,
  // т.е. после создания объект нельзя изменить

  double getRe() const
  {
    return re_;
  }

  double getIm() const
  {
    return im_;
  }

  // модуль комплексного числа
  double abs() const;

  // метод для сложения двух комплексных чисел;
  Complex add(const Complex& c) const;

  // объявления дружественных функций для перегрузки операторов

  // сложение (как и другие операции) может быть реализовано в виде перегруженного оператора +
  friend Complex operator+(const Complex& c1, const Complex& c2);

  // можно перегрузить оператор вывода << с помощью внешней дружественной функции
  friend std::ostream& operator<<(std::ostream& stream, const Complex& c);

private:
  // поля класса, помеченные словом const, можно инициализировать только в конструкторе
  const double re_;
  const double im_;
};

// нетривиальные методы класса определим вне его тела

double Complex::abs() const
{
  return std::sqrt(re_ * re_ + im_ * im_);
}

Complex Complex::add(const Complex& c) const
{
  // возвращаем созданный "на лету" анонимный объект,
  // для этого нужен конструктор с двумя параметрами
  return Complex(re_ + c.re_, im_ + c.im_);
}

// вывод комплексного числа в поток
void print(const Complex& c, std::ostream& stream)
{
  stream << c.getRe()
    << (c.getIm() < 0 ? "-i*" : "+i*")
    << std::abs(c.getIm());
}

// определения дружественных функций для перегрузки операторов

Complex operator+(const Complex& c1, const Complex& c2) {
  return Complex(c1.re_ + c2.re_, c1.im_ + c2.im_);
}

// дружественные функции могут обращаться к закрытым (private) членам класса
std::ostream& operator<<(std::ostream& stream, const Complex& c)
{
  return stream << c.re_
    << (c.im_ < 0 ? "-i*" : "+i*")
    << std::abs(c.im_);
}

int main()
{
  Complex c1(7, -2.5);
  Complex c2(9, 2.2);
  // обратите внимание, это не оператор присваивания, а конструктор копирования (создан по умолчанию)
  Complex c3 = c1.add(c2);
  print(c3, std::cout);
  std::cout << '\n';
  std::cout << c3.abs() << '\n';

  // использование перегруженных операторов
  Complex c4 = c1 + c2;
  Complex c5 = c1 + 5.8;
  Complex c6 = 5.0 + c2;
  std::cout << c4 << '\n';
  std::cout << c5 << '\n';
  std::cout << c6 << '\n';

  return 0;
}
