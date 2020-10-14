#include <iostream>
#include <eigen3/Eigen/Dense>

int main(int argc, char **argv)
{
    Eigen::MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << m << "\n";

    srand(2); //controlar la semilla de los numeros aleatoreos
    
    Eigen::MatrixXd M = Eigen::MatrixXd::Random(3,3);
    std::cout << M << "\n";

    int N = std::atoi(argv[1]);
    Eigen::MatrixXd A(N,N);
    Eigen::VectorXd b(N);
    A = Eigen::MatrixXd::Random(N,N);
    b = Eigen::VectorXd::Random(N);
    //A << 1,2,3,  4,5,6,  7,8,10;
    //b << 3, 3, 4;
    //std::cout << "Here is the matrix A:\n" << A << "\n";
    //std::cout << "Here is the vector b:\n" << b << "\n";
    Eigen::VectorXd x(N);
    x = A.partialPivLu().solve(b);
    //std::cout << "The solution is:\n" << x << "\n";
    //std::cout << "Error= " << (A*x - b).norm() << "\n";
    
    return 0;
}
