#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

fstream text("example.txt", ios::in);

int main() {
    string line;
    getline(text, line);
    getline(text, line);
    cout << line;
}
