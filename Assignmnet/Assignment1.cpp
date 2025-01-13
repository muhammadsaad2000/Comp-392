#include <iostream>
#include <string>

int main() {
    std::string name;
    double monthly_salary;

    // Prompt the user for their name
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    // Prompt the user for their monthly salary
    std::cout << "Enter your monthly salary: ";
    std::cin >> monthly_salary;

    // Calculate the annual salary
    double annual_salary = monthly_salary * 12;

    // Display the user's name and annual salary
    std::cout << "Hello, " << name << "! Your annual salary is $" << annual_salary << std::endl;

    return 0;
}