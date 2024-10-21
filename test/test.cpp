#include <iostream>
#include <ctime>

int main() {
    // Create two tm structs for the two dates
    std::tm start_date = {};
    start_date.tm_year = 2024 - 1900; // Years since 1900
    start_date.tm_mon = 10 - 1;       // Months are 0-based (0 = January)
    start_date.tm_mday = 24;

    std::tm end_date = {};
    end_date.tm_year = 2012 - 1900;
    end_date.tm_mon = 3 - 1;
    end_date.tm_mday = 12;

    // Convert to time_t (timestamp in seconds)
    std::time_t start_time = std::mktime(&start_date);
    std::time_t end_time = std::mktime(&end_date);

    // Calculate the difference in seconds and convert to days
    double difference = std::difftime(start_time, end_time) / (60 * 60 * 24); // Convert to days
    
    std::cout << "Number of days between the two dates: " << difference << " days\n";
    
    return 0;
}
