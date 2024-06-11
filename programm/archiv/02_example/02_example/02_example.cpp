#include <iostream>
#include <fstream>
#include <istream>
#include <limits>
#include <string>

using namespace std;

bool checkC(const char* s);
bool checkCpp(const string& s);

int main()
{
    ifstream infile{ "strings-test.txt" };

    size_t len{};
    while (infile >> len) {
        cout << len << endl;

        infile.ignore(numeric_limits<streamsize>::max(), '\n');

        char* cstr = new char[len + 1];
        infile.getline(cstr, len + 1);
        cout << "[" << cstr << "]" << endl;
        cout << "check C: " << checkC(cstr) << endl;

        cout << "check cpp: " << checkCpp(string{ cstr }) << endl;

        // cout << cstr << endl;
        delete[] cstr;
    }


    cout << "Hello world!" << endl;
    return 0;
}

bool occursAgain(char ch, const char* s) {
    while (*s != 0) {
        if (ch == *s)
            return true;
        ++s;
    }
    return false;
}

bool checkC(const char* s) {

    const char* ptr{ s };
    while (*ptr != 0) {
        if (occursAgain(*ptr, ptr + 1))
            return true;
        ++ptr;
    }

    return false;
}


bool checkCpp(const string& s) {
    for (size_t i{ 0 }; i != s.size(); ++i) {
        for (size_t j{ i + 1 }; j != s.size(); ++j) {
            if (s[i] == s[j])
                return true;
        }
    }

    return false;
}
