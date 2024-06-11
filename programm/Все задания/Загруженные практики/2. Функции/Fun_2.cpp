#include <iostream>

bool isPrime(int number) {
    
    for (int i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

 
void printPrimes(int number) {
    if (number < 0) {
        std::cout << number << " is negative number" << std::endl;
    }
    else if (number == 0) {
        std::cout << number << " isn't prime number" << std::endl;
    }
    else if (!isPrime(number)) {
        std::cout << " Isn't a prime number. Please enter a prime number." << std::endl;
    }
    else {
        std::cout << " The prime number: " << number << std::endl;
        for (int i = 2; i < number; i++) {
            if (isPrime(i)) {
                std::cout << i << " ";
            }
        }
    }
}
int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    printPrimes(number);

    return 0;
}