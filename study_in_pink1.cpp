#include "study_in_pink1.h"

bool readFile(
        const string &filename,
        int &HP1,
        int &HP2,
        int &EXP1,
        int &EXP2,
        int &M1,
        int &M2,
        int &E1,
        int &E2,
        int &E3
) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    } else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
//Recheck and reset the data for each task
void checkData(int &HP, int &M) {
    if (HP > 666) HP = 666;
    if (HP < 0) HP = 0;
    if (M > 3000) M = 3000;
    if (M < 0) M = 0;
}

bool checkTask(int e) {
    return ((e >= 0) && (e <= 99));
}

void checkexp(int &exp) {
    if (exp < 0) exp = 0;
    if (exp > 600) exp = 600;
}

// Task 1: CLEARED
int firstMeet(int &exp1, int &exp2, int e1) {
    if (!checkTask(e1)) return -99;
    if (e1 <= 4) {
        switch (e1) {
            case 0:
                exp2 += 29;
                break;
            case 1:
                exp2 += 45;
                break;
            case 2:
                exp2 += 75;
                break;
            case 3:
                exp2 += (29 + 45 + 75);
                break;
        }
        int d = e1 * 3 + exp1 * 7;
        if (d % 2 == 0) exp1 += ceil((double) d / 200);
        else exp1 -= floor((double) d / 100);
    } else {
        if (e1 <= 19) exp2 += (e1 / 4 + 19);
        else if (e1 <= 49) exp2 += (e1 / 9 + 21);
        else if (e1 <= 65) exp2 += (e1 / 16 + 17);
        else if (e1 <= 79) {
            exp2 += (e1 / 4 + 19);
            if (exp2 > 200) exp2 += (e1 / 9 + 21);
        } else {
            exp2 += (e1 / 4 + 19);
            exp2 += (e1 / 9 + 21);
            if (exp2 > 400) {
                exp2 += (e1 / 16 + 17);
                exp2 *= (15 / 100);
            }
        }
        exp1 -= e1;
    }
    checkexp(exp1);
    checkexp(exp2);
    return exp1 + exp2;
}

// Task 2: CLEARED
int nearestsquarenum(double n) {
    int t1 = ceil(sqrt(n));
    int t2 = floor(sqrt(n));
    t1 *= t1;
    t2 *= t2;
    if (abs(n - t1) < abs(n - t2)) return t1;
    else return t2;
}

bool halfspentcheck(double M1, double spent) {
    if (spent > (M1 / 2)) return true;
    else return false;
}

double calculateP(int EXP1) {
    int sqnum = nearestsquarenum(EXP1);
    double p;
    if (EXP1 >= sqnum) p = 100;
    else p = ceil(((EXP1 / sqnum + 80.0) / 123.0) * 100);

    return p;
}

int road2(int &HP1, int &EXP1, int &M1, int cases) //Use variables ref from traceLuggage
{
    int spent = 0;
    switch (cases) {
        case 1: {
            //Mua do an
            if (HP1 < 200) {
                HP1 += ceil((double) HP1 * 30 / 100);
                M1 -= 150;
                spent += 150;
            } else {
                HP1 += ceil((double) HP1 * 10 / 100);
                M1 -= 70;
                spent += 70;
            }
            break;
        }
        case 2: {
            //Thue xe
            if (EXP1 < 400) {
                M1 -= 200;
                spent += 200;
            } else {
                M1 -= 120;
                spent += 120;
            }
            EXP1 += ceil((double) EXP1 * 13 / 100);
            break;
        }
        case 3: {
            //Vo gia cu
            if (EXP1 < 300) {
                M1 -= 100;
                spent += 100;
            } else {
                M1 -= 120;
                spent += 120;
            }
            EXP1 -= floor((double) EXP1 * 10 / 100);
            break;
        }
    }
    checkData(HP1, M1);
    checkexp(EXP1);
    return spent;
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {
    //Road1
    double p1 = calculateP(EXP1);
    //Road2
    //check E2: Odd
    if (E2 % 2 != 0) {
        int spent = 0;
        int temp = M1;
        for (int i = 1; i <= 3; i++) {
            spent += road2(HP1, EXP1, M1, i);
            if (halfspentcheck(temp, spent)) break;
            if (i + 1 > 3) i = 0;
        }
        HP1 -= floor((double) HP1 * 17 / 100);
        EXP1 += ceil((double) EXP1 * 17 / 100);
    } else {
        //Check E2: Even
        for (int i = 1; i <= 3; i++) {
            road2(HP1, EXP1, M1, i);
            if (M1 <= 0) break;
        }
        if (M1 < 0) M1 = 0;
        HP1 -= floor((double) HP1 * 17 / 100);
        EXP1 += ceil((double) EXP1 * 17 / 100);
    }
    checkData(HP1, M1);
    checkexp(EXP1);
    double p2 = calculateP(EXP1);
    //Road3
    const int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double p3;
    if (E2 % 10 == 0) p3 = P[E2];
    else {
        int i = 0;
        while (E2 > 0) {
            int tmp = E2 % 10;
            i += tmp;
            E2 /= 10;
        }
        p3 = P[i % 10];
    }
    checkData(HP1, M1);
    checkexp(EXP1);
    if ((p1 == 100) && (p2 == 100) && (p3 == 100)) EXP1 -= floor((double) EXP1 * 25 / 100);
    else {
        double pall = (p1 + p2 + p3) / 3.0;
        if (pall < 50.0) {
            HP1 -= floor((double) HP1 * 15 / 100);
            EXP1 += ceil((double) EXP1 * 15 / 100);
        } else {
            HP1 -= floor((double) HP1 * 10 / 100);
            EXP1 += ceil((double) EXP1 * 20 / 100);
        }
    }
    checkexp(EXP1);
    checkData(HP1, M1);
    return HP1 + EXP1 + M1;
}

// Task 3: CLEARED
int simplifyNum(int a) {
    int b = a % 10;
    while (b != a) {
        a = a / 10 + a % 10;
        b = a % 10;
    }
    return a;
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
    int taxi[10][10], sherlock[10][10];
    int meetx = 0, meety = 0;
    //Taxi point:
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int temp = ((E3 * j) + (i * 2)) * (i - j);
            taxi[i][j] = temp;
        }
    }
    //Finding the meeting point:
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (taxi[i][j] > (E3 * 2)) ++meetx;
            if (taxi[i][j] < (E3 * -1)) ++meety;
        }
    }
    meetx = simplifyNum(meetx);
    meety = simplifyNum(meety);
    //Dirty trick: Only checking Sherlock point on the meeting point
    int max = taxi[meetx][meety];
    int x = meetx;
    int y = meety;
    //Duyet nua cheo trai tren
    while ((x != -1) && (y != -1)) {
        if (taxi[x][y] > max) max = taxi[x][y];
        --x;
        --y;
    }
    //Duyet nua cheo phai duoi
    x = meetx;
    y = meety;
    while ((x != 9) && (y != -1)) {
        if (taxi[x][y] > max) max = taxi[x][y];
        ++x;
        --y;
    }
    x = meetx;
    y = meety;
    while ((x != -1) && (y != 9)) {
        if (taxi[x][y] > max) max = taxi[x][y];
        --x;
        ++y;
    }
    x = meetx;
    y = meety;
    while ((x != 9) && (y != 9)) {
        if (taxi[x][y] > max) max = taxi[x][y];
        ++x;
        ++y;
    }
    //Check if they can meet at meeting point
    if (abs(taxi[meetx][meety]) > abs(max)) {
        EXP1 -= floor((double) EXP1 * 12 / 100);
        HP1 -= floor((double) HP1 * 10 / 100);
        EXP2 -= floor((double) EXP2 * 12 / 100);
        HP2 -= floor((double) HP2 * 10 / 100);
        return taxi[meetx][meety];
    } else {
        EXP1 += ceil((double) EXP1 * 12 / 100);
        HP1 += ceil((double) HP1 * 10 / 100);
        EXP2 += ceil((double) EXP2 * 12 / 100);
        HP2 += ceil((double) HP2 * 10 / 100);
        return max;
    }
}

// Task 4
int checkPassword(const char *s, const char *email) {
    // TODO: Complete this function
    string pass = s, temp_email = email;
    if (pass.length() < 8) return -1;
    if (pass.length() > 20) return -2;
    string se;
    for (int i = 0; i < temp_email.length(); ++i) {
        if (temp_email[i] == '@') break;
        se += temp_email[i];
    }
    for (int i = 0; i < pass.length(); ++i) {
        if (pass[i] == se[0]) {
            //Check if the password contains the "se" string
            bool check = true;
            //first element is already checked
            for (int j = i + 1; j < se.length(); ++j) {
                if (pass[j] != se[j]) {
                    check = false;
                    break;
                }
            }
            if (check) return (-1 * (300 + i));
        }
    }
    //check duplicate characters
    for (int i = 0; i < pass.length(); ++i)
        if ((pass[i] == pass[i + 1]) && (pass[i] == pass[i + 2])) return (-1 * (400 + i));
    //check special characters
    const char specialchar[5] = {'!', '@', '#', '$', '%'};
    bool check = false;
    for (int i = 0; i < pass.length(); ++i) {
        for (int j = 0; j < 5; ++j)
            if (pass[i] == specialchar[j]) {
                check = true;
                break;
            }
        if (check) break;
    }
    if (!check) return -5;

    return -99;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    return -1;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
