// Программа читает последовательность чисел из файла "infile.txt" (должен находиться в дирректории проекта)
// и записывает в два раза большие числа в файл "outfile.txt" (будет создан автоматически).
// Во входном файле числа разделяются символами-разделителями (пробел, табуляция, перенос строки).

#include <iostream>
#include <fstream>

int main()
{
    std::ifstream in("infile.txt");
    std::ofstream out("outfile.txt");
    if (!in.is_open() || !out.is_open())
    {
        std::cerr << "File can not be opened\n";
        return 1;
    }
    int n = 0;
    // здесь считывание производится прямо в условии цикла,
    // затем поток in приводится к типу bool (false - если при считывании были ошибки)
    while (in >> n)
    {
        out << n * 2 << '\n';
    }
    in.close();
    out.close();

    return 0;
}
