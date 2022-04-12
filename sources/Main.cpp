// /**
//  * Demo file for the exercise on numbers with units
//  *
//  * @author Erel Segal-Halevi
//  * @since 2019-02
//  *
//  * Edited by Dolev Dublon
//  * @since 2022-02
//  */

// #include <stdlib.h>
// #include <string>

// #include <vector>
// #include <cmath>

// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <stdexcept>
// using namespace std;

// #include "Matrix.hpp"
// using namespace zich;

// int main()
// {

//     // istringstream is1{"[1 1 1 1],[1 1 1 1], [1 1 1 1]\n"};
//     // CHECK_THROWS(is1 >> mat1);
//     // istringstream is2{"[1 1 1 1], [1 1 1 1] [1 1 1 1],\n"};
//     // CHECK_THROWS(is2 >> mat1);
//     // istringstream is3{"[1 11 1]  [1 1 1 1], [1 1 1 1]\n"};
//     // CHECK_THROWS(is3 >> mat1);
//     // istringstream is4{",[1 1 1 1], [1 1 1 1], [1 1 1 1]\n"};
//     // CHECK_THROWS(is4 >> mat1);
//     // istringstream is5{",,[1 1 1 1] [1 1 1 1] [1 1 1 1]\n"};
//     // CHECK_THROWS(is5 >> mat1);
//     // istringstream is6{"[ 1 1 1 1 ], [ 1 1 1 1 , [ 1 1 1 1 ]]\n"};
//     // CHECK_THROWS(is6 >> mat1);
// std::vector<double> unit_matrix = {1, 0, 0, 0, 1, 0, 0, 0, 1};
//     Matrix mat1{unit_matrix, 3, 3};
//     istringstream is7{"[1 1 1 1], [1 1 1 1], [1 1 1 1]\n"};
//     is7 >> mat1;

//     return 0;
// }