// /**
//  * Demo file for the exercise on numbers with units
//  *
//  * @author Erel Segal-Halevi
//  * @since 2019-02
//  *
//  * Edited by Dolev Dublon
//  * @since 2022-02
//  */
// #define DOCTEST_CONFIG_IMPLEMENT
// #include "../doctest.h"
// using namespace doctest;

// #include <iostream>
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

//     TEST_CASE("matrix multiplication")
//     {
//         vector<double> identity_3 = {1, 0, 0, 0, 1, 0, 0, 0, 1}; // 3x3
//         Matrix mat_identity_3(identity_3, 3, 3);
//         vector<double> vec1 = {1, 1, 1, 1, 1, 1, 1, 1, 1};                            // 3x3
//         vector<double> arr = {2, 1, 1, 1, 2, 1, 1, 1, 2};                             // 3x3   arr = identity_3 + vec1
//         vector<double> vec2 = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0};                   // 3x4
//         vector<double> identity_4 = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}; // 4x4
//         vector<double> _vec_ = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};                  // 4x3
//         Matrix _mat_(_vec_, 4, 3);
//         Matrix mat1(vec1, 3, 3);
//         Matrix mat_arr(arr, 3, 3);
//         Matrix mat2(vec2, 3, 4);
//         Matrix mat_identity_4(identity_4, 4, 4);

//         CHECK(((mat1 * mat_identity_3) == mat1));
//         CHECK(((mat_identity_3 * mat1) == mat1));
//         CHECK(((mat2 * mat_identity_4) == mat2));
//         CHECK(((mat1 + mat_identity_3) == mat_arr));
//         CHECK(((mat2 * _mat_) == mat1));

//         for (double i = 1; i < 500; i++)
//         {
//             int random = rand() % 1000;
//             vector<double> vec1 = {i * random, i * random, i * random, i * random, i * random, i * random, i * random, i * random, i * random};
//             Matrix matrix(vec1, 3, 3);
//             CHECK(((matrix * mat_identity_3) == matrix));

//             vector<double> arr1 = {i, i, i, i, i, i, i, i, i}; // 3x3

//             vector<double> arr = {pow(i, 2), pow(i, 2), pow(i, 2), pow(i, 2), pow(i, 2), pow(i, 2), pow(i, 2), pow(i, 2), pow(i, 2)}; // 3x3
//             Matrix mat1(arr1, 3, 3);
//             Matrix mat(arr, 3, 3);
//             CHECK(((mat1 * mat1) != mat));
//             CHECK(((mat_identity_3 * mat_identity_3) == mat_identity_3));
//         }
//     }

//     return 0;
// }