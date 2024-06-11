// Ilia Shemiakin, 2024
// Стек

#include <iostream>

// Стек - структура данных, работающая по принципу LIFO (Last In, First Out),
// т.е. элементы извлекаются из стека в порядке, обратном порядку их добавления.
// Ниже реализован стек целых чисел на базе связного списка
class StackInt
{
public:
    // конструктор
    StackInt() :
        head_(nullptr)	// nullptr - пустой указатель (не указывает ни на какой адрес)
        // устаревший аналог - NULL
    {}

    // деструктор освобождает память, выделенную под список (вызывается неявно при уничтожении объекта);
    // кода объект содержит в себе какой-либо внешний ресурс (например, динамически выделенную память),
    // необходимо(!) реализовать (или запретить) конструктор копирования, оператор присвивания и деструктор,
    // в C++11 желательно также определить конструктор перемещения и оператор перемещающего присваивания
    ~StackInt()
    {
        while (head_)	  // то же, что while (head_ != nullptr)
        {
            Node* temp = head_;
            head_ = head_->next;
            // обязательно освобождаем память, выделенную под каждый элемент
            delete temp;
        }
    }

    void push(int);	// добавление элемента в стек
    int pop();		  // извлечение элемента из стека

    // вывод всего стека на экран
    friend std::ostream& operator<<(std::ostream& stream, const StackInt& stack);

private:
    // структура, описывающая элемент стека
    struct Node
    {
        int data;		  // данные
        Node* next;	// указатель на следующий элемент
    };

    // указатель на вершину стека
    Node* head_;

    // для упрощения примера копирование и перемещение объектов запрещены
    StackInt(const StackInt&) = delete;
    StackInt(StackInt&&) = delete;
    StackInt& operator=(const StackInt&) = delete;
    StackInt& operator=(StackInt&&) = delete;
};

// метод, помещающий значение в стек
void StackInt::push(int val)
{
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = head_;
    head_ = newNode;
}

// метод, извлекающий значение из стека;
// извлекаемое значение возвращается функцией, элемент при этом удаляется из стека
int StackInt::pop()
{
    if (!head_)
    {
        throw std::logic_error("Stack is empty");
    }
    int res = head_->data;
    Node* temp = head_;
    head_ = head_->next;
    delete temp;
    return res;
}

// вывод всего стека на экран
std::ostream& operator<<(std::ostream& stream, const StackInt& stack)
{
    StackInt::Node* temp = stack.head_;
    while (temp)
    {
        stream << temp->data << "  ";
        temp = temp->next;
    }
    return stream;
}

int main()
{
    StackInt stack;

    // пытаемся извлечь значение из пустого стека
    try
    {
        stack.pop();	// будет сгенерировано исключение
    }
    catch (const std::logic_error& e)
    {
        std::cerr << e.what() << '\n';
    }

    // помещаем несколько значений в стек
    stack.push(5);
    stack.push(2);
    stack.push(57);
    stack.push(10);
    stack.push(7);
    stack.push(8);
    stack.push(22);

    // выведем стек на экран
    std::cout << "1: ";
    std::cout << stack;
    std::cout << '\n';

    // проверяем метод pop, должно вернуться число, помещённое в стек последним
    std::cout << "extract " << stack.pop() << '\n';
    std::cout << "2: ";
    std::cout << stack;
    std::cout << '\n';

    // и ещё раз
    std::cout << "extract " << stack.pop() << '\n';
    std::cout << "3: ";
    std::cout << stack;
    std::cout << '\n';

    // снова добавим в стек несколько чисел
    stack.push(89);
    stack.push(15);
    std::cout << "4: ";
    std::cout << stack;
    std::cout << '\n';

    return 0;
}
