#include<bits/stdc++.h>
using namespace std;

int main(){
    time_t current_time = time(0);
tm* time_now = localtime(&current_time);  
time_t conv_time_now = mktime(time_now);
cout<<current_time;
    return 0;
}