/*
* Author: Wesley Anastasi
* Assignment Title: MP1 Bank Problem
* Assignment Description: This program 
* Due Date: 2/3/2023
* Date Created: 2/3/2023
* Date Last Modified: 2/3/2023
*/

/*
* Data Abstraction:
* 
* Input:
* 
* Process:
* 
* Output:
*
* Assumptions:
* 
* Questions:
* 1: Total charge = 50545.47
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream inputFile;
    float sum, input;
    int chargesNum = 10000;
    float charges[chargesNum];

    sum = 0;
    inputFile.open("charges.txt");

    for (int i = 0; inputFile >> input; i++)
    {
        charges[i] = input;
    }

    for (int i = 0; i < chargesNum-1; i++)
    {
        if (charges[i] < charges[i+1])
        {
            swap(charges[i], charges[i+1]);
            i = 0;
        }
    }

    for (int i = 0; i < chargesNum; i++)
    {
        sum += charges[i];
    }

    cout << fixed << setprecision(2) << sum << endl;
    return 0;
}