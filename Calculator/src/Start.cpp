#include <iostream>
#include "Start.h"
#include "Math.h"

void Start::Running()
{
    Math math;
    std::cout << "1. Addition\n" << "2. Subtraction\n" << "3. Multiplication\n" << "4. Division\n\n";
    std::cout << "Choose an option: "; std::cin >> choice;

    switch (choice)
    {
    case 1:
        math.Add();
        math.Run();
        std::cin >> choice2;
        system("cls");
        break;
    case 2:
        math.Subtract();
        math.Run();
        std::cin >> choice2;
        system("cls");
        break;
    case 3:
        math.Multiply();
        math.Run();
        std::cin >> choice2;
        system("cls");
        break;
    case 4:
        math.Division();
        math.Run();
        std::cin >> choice2;
        system("cls");
        break;
    default:
        std::cout << "Enter a valid option\n";
        break;
    }
}
