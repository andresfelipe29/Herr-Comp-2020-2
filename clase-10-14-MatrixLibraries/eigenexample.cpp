#include <iostream>
#include <cstdlib>
#include <eigen3/Eigen/Dense>
#include <chrono>

double solvesystem(const int N);

int main(int argc, char **argv)
{
    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    /*Eigen::MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << m << "\n";*/
    
    /*Eigen::MatrixXd M = Eigen::MatrixXd::Random(3,3);
    std::cout << M << "\n";*/

    int N = std::atoi(argv[1]);
    int REPS = std::atoi(argv[2]);
    double t = 0;

    for(int i = 0; i < REPS; i++){
        t += solvesystem(N);
    }

    std::cout << t/REPS << "\n";
    /*Eigen::MatrixXd A(N,N);
    Eigen::VectorXd b(N);
    A = Eigen::MatrixXd::Random(N,N);
    b = Eigen::VectorXd::Random(N);*/
    //A << 1,2,3,  4,5,6,  7,8,10;
    //b << 3, 3, 4;
    //std::cout << "Here is the matrix A:\n" << A << "\n";
    //std::cout << "Here is the vector b:\n" << b << "\n";
    //std::cout << "The solution is:\n" << x << "\n";
    //std::cout << "Error= " << (A*x - b).norm() << "\n";
    
    return 0;
}

double solvesystem(const int N)
{
    srand(2); //controlar la semilla de los numeros aleatoreos
    Eigen::MatrixXd A(N,N);
    Eigen::VectorXd b(N);
    A = Eigen::MatrixXd::Random(N,N);
    b = Eigen::VectorXd::Random(N);
    //A << 1,2,3,  4,5,6,  7,8,10;
    //b << 3, 3, 4;
    //std::cout << "Here is the matrix A:\n" << A << "\n";
    //std::cout << "Here is the vector b:\n" << b << "\n";
    Eigen::VectorXd x(N);
    auto start = std::chrono::steady_clock::now();
    x = A.partialPivLu().solve(b);
    auto end = std::chrono::steady_clock::now();
    double time = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()*1.0e-9;

    return time;
}
