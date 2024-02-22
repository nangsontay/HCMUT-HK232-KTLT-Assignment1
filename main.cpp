/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2023
* Author: Vu Van Tien
* Date: 02.02.2023
*/

//The library here is concretely set, students are not allowed to include any other libraries.

#include "study_in_pink1.h"

using namespace std;

void sa_tc_01() {
    cout << "----- Sample Testcase 01 -----" << endl;
    string input_file("sa_tc_01_input");
    int HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3;
    if (!readFile(input_file, HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3)) {
        return;
    }

    cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", E1: " << E1 << endl;
    int result1 = firstMeet(EXP1, EXP2, E1);
    cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", result: " << result1 << endl;
    E2 = 39;
    HP1 = 333;
    EXP1 = 430;
    M1 = 890;
    cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", E1: " << E2 << endl;
    int result2 = traceLuggage(HP1, EXP1, M1, E2);
    cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", result: " << result2 << " HP1: " << HP1 << endl;
}

int main(int argc, const char *argv[]) {
    sa_tc_01();

    return 0;
}