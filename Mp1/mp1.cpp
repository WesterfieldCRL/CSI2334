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
* 2: Total charge ascending = 50545.19
* 3: Total charge descending = 50545.37
* 4: Because of the way rounding works, numbers get truncated when they get to big.
* Because of this, adding together numbers in different orders can lead to different
* parts being truncated which results in slightly different answers. The most
* accurate version of this program is to sort eveything in descending order first,
* and then sum all of them. This is larger numbers add up quickly, and soon
* the smaller numbers will not contribute to the sum. However, if you add the smaller
* numbers first, they will add up and contribute more to the overall answer.
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
    bool swap;

    sum = 0;
    inputFile.open("charges.txt");

    for (int i = 0; inputFile >> input; i++)
    {
        charges[i] = input;
    }

    do
    {
        swap = false;
        for (int i = 0; i < chargesNum-1; i++)
        {
            if (charges[i] > charges[i+1])
            {
                float temp = charges[i];
                charges[i] = charges[i+1];
                charges[i+1] = temp;
                swap = true;
            }
        }
    }while(swap);

    for (int i = 0; i < chargesNum; i++)
    {
        sum += charges[i];
    }

    cout << fixed << setprecision(2) << sum << endl;
    return 0;
}