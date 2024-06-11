//Напишите функцию removeChar, формирующую новую строку путём
// удаления из исходной указанного символа.Указатель на новую строку
// необходимо передать, как параметр.

#include <iostream> 
#include <cstring>

void removeChar(const char* str, char c, char* result) {
    int index = 0;


    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != c) {
            result[index] = str[i];
            index++;
        }
    }

    result[index] = '\0';
}

int main() {
    const char* str = "hello"; 
    char c = 'l'; 
    char result[100];


    removeChar(str, c, result);

    std::cout << "Original string: " << str << std::endl;
    std::cout << "New string: " << result << std::endl;

    return 0;
}
