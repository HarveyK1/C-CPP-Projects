#include <iostream>
#include "Math.h"


double Math::Add()
{
    std::cout << "Enter two numbers\n";
    std::cout << "Number 1: "; std::cin >> m_a;
    std::cout << "Number 2: "; std::cin >> m_b;
    std::cout << m_a << " + " << m_b << " = " << m_a + m_b;
    return 0;
}
double Math::Subtract()
{
    std::cout << "Enter two numbers\n";
    std::cout << "Number 1: "; std::cin >> m_a;
    std::cout << "Number 2: "; std::cin >> m_b;
    std::cout << m_a << " - " << m_b << " = " << m_a - m_b;
    return 0;
}
double Math::Multiply()
{
    std::cout << "Enter two numbers\n";
    std::cout << "Number 1: "; std::cin >> m_a;
    std::cout << "Number 2: "; std::cin >> m_b;
    std::cout << m_a << " * " << m_b << " = " << m_a * m_b;
    return 0;
}
double Math::Division()
{
    std::cout << "Enter two numbers\n";
    std::cout << "Number 1: "; std::cin >> m_a;
    std::cout << "Number 2: "; std::cin >> m_b;
    std::cout << m_a << " / " << m_b << " = " << m_a / m_b;
    return 0;
}
void Math::Run()
{
    std::cout << "\n\n1. Continue\n" << "2. Exit App\n";
}
