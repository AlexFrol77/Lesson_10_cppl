#include <iostream>
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

    void printMatrix() {
        std::cout << "\n" << "down: ";
        for (const auto& it : m_down) {
            std::cout << it << " ";
        }
        std::cout << "\n" << "upper: ";
        for (const auto& it : m_upper) {
            std::cout << it << " ";
        }
        std::cout << "\n" << "middle: ";
        for (const auto& it : m_middle) {
            std::cout << it << " ";
        }
        std::cout << std::endl;
    }

    std::unique_ptr<tridiagonal_matrix> clone() {
        return std::unique_ptr <tridiagonal_matrix>(new tridiagonal_matrix(m_down, m_upper, m_middle));
    }
};

int main() {

    setlocale(LC_ALL, "rus");

    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };
    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
    );

    auto matrix_clone = matrix->clone();

    std::cout << "Адрес matrix: " << matrix << " " << "Адрес matrix_clone: " << matrix_clone << "\n" << std::endl;

    std::cout << "matrix :";
    matrix->printMatrix();

    std::cout << "\n" << "/////////////////////" << "\n" << std::endl;

    std::cout << "matrix_clone :";
    matrix_clone->printMatrix();

    std::cout << std::endl;

    return 0;
}