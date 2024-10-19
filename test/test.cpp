#include <iostream>
#include <ctime>

int main() {
    // Lấy thời gian hiện tại
    std::time_t current_time = std::time(nullptr);

    // Chuyển thành struct tm để in ra dạng thời gian cụ thể
    std::tm* local_time = std::localtime(&current_time);

    // In ra thời gian
    std::cout << "Thời gian hệ thống hiện tại: "
              << local_time->tm_hour << ":"
              << local_time->tm_min << ":"
              << local_time->tm_sec << " "
              << local_time->tm_mday << "/"
              << local_time->tm_mon + 1 << "/"
              << local_time->tm_year + 1900 << std::endl;

    return 0;
}
