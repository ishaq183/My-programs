#include <iostream>

using namespace std;

// Make a function to check the leap year
bool isLeepYear(int year) {
    return (year % 4 == 0);
}

// Make a function to calculate the age
void ageCalculator(int birth_day, int birth_month, int birth_year, int current_day, int current_month, int current_year) {
    // Declare an array to store days in months
    int DaysInMonth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Calculate age
    int Years = current_year - birth_year;
    int Months = current_month - birth_month;
    int Days = current_day - birth_day;

    // Check the validation for calculated months
    if (Months < 0) {
        Years--;
        Months += 12;
    }

    // Check the validation for calculated days
    if (Days < 0) {
        Months--;
        Days += DaysInMonth[birth_month - 1];
    }

    // Check that the birth year is leap or not
    if (isLeepYear(birth_year)&&birth_month<2) {
        Days++;
    }

    // Check that the current year is leap or not
    if (isLeepYear(current_year)&& current_month>2) {
        Days++;
    }

    cout << "Your age is " << Years << " years " << Months << " months " << Days << " days." << endl;
}

int main() {
    // Declaration of variables
    int birth_day, birth_month, birth_year, current_day, current_month, current_year;

    cout << "AGE CALCULATOR\n" << endl;

    // Take Date of Birth from user
    cout << "Enter Date of birth (DD/MM/YYYY): " << endl;
    cin >> birth_day >> birth_month >> birth_year;
// Take current date as input from user
    cout << "Enter current date(DD/MM/YYYY)" << endl;
    cin >> current_day >> current_month >> current_year;

    // Check the Date validation
    if (birth_day < 1 || birth_day > 31 || birth_month < 1 || birth_month > 12||
            current_day < 1 || current_day > 31 || current_month < 1 || current_month > 12||current_year < birth_year) {
        cout << "You enter invalid date" << endl;
        return 1;
    }
    else {

        ageCalculator(birth_day, birth_month, birth_year, current_day, current_month, current_year);
    }

    return 0;
}