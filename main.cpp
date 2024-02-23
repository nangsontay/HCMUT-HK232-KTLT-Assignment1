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
    cout << "----- Sample Testcase 08 -----" << endl;
    const char * arr_pwds[] = {"123xyz", "pink#pink", "pink123", "xxxx@xxxx", "pink#pink", "pink123", "pink123"};
    int num_pwds = 7;
    cout << "num_pwds: " << num_pwds << endl;
    int result = findCorrectPassword(arr_pwds, num_pwds);
    cout << "num_pwds: " << num_pwds << ", result: " << result << endl;
}

int main(int argc, const char *argv[]) {
    sa_tc_01();

    return 0;
}