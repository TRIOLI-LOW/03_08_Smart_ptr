﻿#include <iostream>
#include <vector>
#include <memory>

class tridiagonal_matrix
{
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;
    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) :
        m_down{ down }, m_upper{ upper }, m_middle{ middle }
    {};
    ~tridiagonal_matrix() { std::cout << "destructor called\n"; }

    std::unique_ptr <tridiagonal_matrix> clone() {
       std::unique_ptr <tridiagonal_matrix>  up1 =  std::make_unique <tridiagonal_matrix>(
            m_down,
            m_upper,
            m_middle
            );
       return up1;
    }
};

int main()
{
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.1 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };
    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
        );
    std::cout << "matrix : " << matrix << std::endl;
    auto matrix_clone = matrix->clone();
    std::cout << "matrix_clone : " << matrix_clone << std::endl;

    std::cout << "matrix -> middle[2] : " << matrix->m_middle.at(2) << std::endl;

    std::cout << "matrix_clone -> middle[2] : " << matrix_clone->m_middle.at(2) << std::endl;

    return 0;
}