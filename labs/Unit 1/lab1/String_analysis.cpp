#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

void doSomething(string xyz)
{
    double upperCase = 0;
    double lowerCase = 0;
    double digits = 0;
    double specialChars = 0;

    // finding length of string
    int len = xyz.length();

    // running for loop
    for (int i = 0; i < len; i++)
    {
        if (xyz[i] >= 'A' && xyz[i] <= 'Z')
        {
            upperCase++;
        }
        else if (xyz[i] >= 'a' && xyz[i] <= 'z')
        {
            lowerCase++;
        }
        else if (xyz[i] >= '0' && xyz[i] <= '9')
        {
            digits++;
        }
        else
        {
            specialChars++;
        }
    }

    // finding percentage

    double uppercasePer = (upperCase * 100) / len;
    double lowercasePer = (lowerCase * 100) / len;
    double digitsPer = (digits * 100) / len;
    double specialcharsPer = (specialChars * 100) / len;

    cout << fixed << setprecision(3);
    cout << uppercasePer << "%" << endl;
    cout << lowercasePer << "%" << endl;
    cout << digitsPer << "%" << endl;
    cout << specialcharsPer << "%" << endl;
}

int main()
{
    string xyz = "Support1@litwork.in";
    doSomething(xyz);

    return 0;
}