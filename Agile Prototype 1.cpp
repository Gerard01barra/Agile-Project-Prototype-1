// Agile Prototype 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>
#include <cstring>
#include <string>
using namespace std;

// Check if input is a valid decimal number
bool isValidDecimal(string input) {
    bool hasDecimalPoint = false;
    int i = 0;

    // Sign Bit Checker 
    if (input[0] == '+' or input[0] == '-') {
        if (input.length() == 1) {
            return false;
        }
        i = 1;
    }

    while (i < input.length()) {
        if (input[i] == '.') {
            if (hasDecimalPoint == true) {
                return false;
            }
            hasDecimalPoint = true;
        }
        else {
            if (isdigit(input[i]) == false) {
                return false;
            }
        }
        i = i + 1;
    }

    return true;
}

// Converts float input to IEEE 754 binary 
string floatToBinary(float value) {
    unsigned int bits;
    memcpy(&bits, &value, sizeof(bits));
    return bitset<32>(bits).to_string();
}

// Arithmetic functions
float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

int main() {
    string input1;
    string input2;
    float num1;
    float num2;

    cout << "Enter first decimal number: ";
    cin >> input1;

    if (isValidDecimal(input1) == false) {
        cout << "Error: Invalid decimal input." << endl;
        return 1;
    }

    cout << "Enter second decimal number: ";
    cin >> input2;

    if (isValidDecimal(input2) == false) {
        cout << "Error: Invalid decimal input." << endl;
        return 1;
    }

    // Convert after validation
    num1 = stof(input1);
    num2 = stof(input2);

    float sum = add(num1, num2);
    float diff = subtract(num1, num2);
    float prod = multiply(num1, num2);

    cout << "\n--- Results ---" << endl;

    cout << "Addition: " << sum << endl;
    cout << "Binary:   " << floatToBinary(sum) << endl;

    cout << "\nSubtraction: " << diff << endl;
    cout << "Binary:      " << floatToBinary(diff) << endl;

    cout << "\nMultiplication: " << prod << endl;
    cout << "Binary:         " << floatToBinary(prod) << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
