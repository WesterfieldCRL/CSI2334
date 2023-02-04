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
    input file is opened
    floats sum and input are declared
    int chargesNum is initialized
    float array charges is created with size chargesNum
    boolean swap is initialized
* 
* Input:
    the program reads floats from the provided input file
    and stores them in charges
* 
* Process:
    charges is sorted in descending order, and then the sum is
    taken of all the nums in the array
* 
* Output:
    the sum is output
*
* Assumptions:
    the inputFile opens
    the input is correct
    the user wants the sum of the nums in the file
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
    //Data Abstraction
    ifstream inputFile;
    float sum, input;
    int chargesNum = 10000;
    float charges[chargesNum];
    bool swap;

    sum = 0;

    //Open input file
    inputFile.open("charges.txt");

    //Get input
    for (int i = 0; inputFile >> input; i++)
    {
        charges[i] = input;
    }

    //Data Processing and Output
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

    //Close file
    inputFile.close();
    return 0;
}