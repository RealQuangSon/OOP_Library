#include <iostream>
#include <ctime>
using namespace std;

int main() {
    time_t current_time = time(0);
tm* time_now = localtime(&current_time); 
cout<<&time_now;

    return 0;
}
