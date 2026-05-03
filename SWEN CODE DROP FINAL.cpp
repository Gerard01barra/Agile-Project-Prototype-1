// SWEN CODE DROP FINAL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

// Sign Extension Process
string signExtend(string bin) {
    // make sure binary is max 32 bits
    if (bin.length() > 32) {
        throw "Binary too long";
    }

    char sign = bin[0]; // take first bit (sign bit)

    // add extra sign bits in front
    string extra(32 - bin.length(), sign);
    return extra + bin;
}

// Decimal User Input Validation 
bool isValidDecimal(string s) {
    if (s.empty()) return false;

    bool dot = false;
    bool digitFound = false;

    int i = 0;

    // ignore sign
    if (s[0] == '-' || s[0] == '+') {
        i = 1;
    }

    for (; i < s.length(); i++) {
        if (s[i] == '.') {
            if (dot) return false;
            dot = true;
        }
        else if (isdigit(s[i])) {
            digitFound = true;
        }
        else {
            return false;
        }
    }

    return digitFound;
}

// Binary User Input Validation 
bool isValidBinary(string s) {
    if (s.empty() || s.length() > 32) return false;

    for (char c : s) {
        if (c != '0' && c != '1') return false;
    }
    return true;
}

// HEX User Input Validation 
bool isValidHex(string s) {
    if (s.empty() || s.length() > 8) return false;

    for (char c : s) {
        if (!isxdigit(c)) return false;
    }
    return true;
}

// Float to Binary Conversion 
string floatToBinary(float num) {
    unsigned int bits;
    memcpy(&bits, &num, sizeof(bits));

    return bitset<32>(bits).to_string();
}

// Binary to Float Conversion 
float binaryToFloat(string s) {
    unsigned int bits = bitset<32>(s).to_ulong();

    float num;
    memcpy(&num, &bits, sizeof(num));

    return num;
}

// Float to HEX Conversion 
string floatToHex(float num) {
    unsigned int bits;
    memcpy(&bits, &num, sizeof(bits));

    stringstream ss;
    ss << hex << setw(8) << setfill('0') << bits;

    return ss.str();
}

// HEX to Binary Conversion
string hexToBinary(string hexStr) {
    unsigned int value;
    stringstream ss;

    ss << hex << hexStr;
    ss >> value;

    string bin = bitset<32>(value).to_string();

    // Shorten input to fit in HEX format
    int size = hexStr.length() * 4;
    bin = bin.substr(32 - size);

    return signExtend(bin);
}

// Output Using the IEEE format
void printIEEE(string b) {
    cout << "Sign: " << b.substr(0, 1) << endl;
    cout << "Exponent: " << b.substr(1, 8) << endl;
    cout << "Mantissa: " << b.substr(9, 23) << endl;
}

// Special Cases For NaN, Ifinite Cases, and Zero Case
void printSpecialCases(float num) {
    if (isnan(num)) {
        cout << "Special Case: NaN" << endl;
    }
    else if (isinf(num)) {
        cout << "Special Case: Infinity" << endl;
    }
    else if (num == 0.0f) {
        cout << "Special Case: Zero" << endl;
    }
}

// Input Validation IF INVALID
float getValue(string s, int format) {
    if (format == 1) {
        if (!isValidDecimal(s)) throw "Invalid decimal input";
        return stof(s);
    }
    else if (format == 2) {
        if (!isValidBinary(s)) throw "Invalid binary input";

        string full = signExtend(s);
        return binaryToFloat(full);
    }
    else if (format == 3) {
        if (!isValidHex(s)) throw "Invalid hex input";

        string bin = hexToBinary(s);
        return binaryToFloat(bin);
    }

    throw "Unknown format";
}

// Main UI Process
int main() {
    char again = 'y';

    while (again == 'y' || again == 'Y') {

        // NEW: Mode selection (Conversion or Arithmetic)
        int mode;
        cout << "\nChoose mode:\n";
        cout << "1. Single Number Conversion\n";
        cout << "2. Arithmetic Operations\n";
        cout << "Enter choice: ";
        cin >> mode;

        // NEW: Single number conversion mode
        if (mode == 1) {
            int format;
            string input;
            float value;

            cout << "\nChoose format:\n";
            cout << "1. Decimal\n";
            cout << "2. Binary\n";
            cout << "3. Hex\n";
            cout << "Enter choice: ";
            cin >> format;

            while (true) {
                cout << "Enter value: ";
                cin >> input;

                try {
                    value = getValue(input, format);
                    break;
                }
                catch (const char* msg) {
                    cout << "Error: " << msg << endl;
                }
            }

            cout << "\n=== Conversion Results ===\n";
            cout << "Decimal: " << value << endl;

            string bin = floatToBinary(value);
            cout << "Binary: " << bin << endl;
            cout << "Hex: " << floatToHex(value) << endl;

            printIEEE(bin);
            printSpecialCases(value);
        }

        // Arithmetic mode (original functionality)
        else if (mode == 2) {

            int format;
            string a, b;
            float x, y;

            cout << "\nChoose format:\n";
            cout << "1. Decimal\n";
            cout << "2. Binary\n";
            cout << "3. Hex\n";
            cout << "Enter choice: ";
            cin >> format;

            // First User Input
            while (true) {
                cout << "Enter first number: ";
                cin >> a;

                try {
                    x = getValue(a, format);
                    break;
                }
                catch (const char* msg) {
                    cout << "Error: " << msg << endl;
                }
            }

            // Second User Input
            while (true) {
                cout << "Enter second number: ";
                cin >> b;

                try {
                    y = getValue(b, format);
                    break;
                }
                catch (const char* msg) {
                    cout << "Error: " << msg << endl;
                }
            }

            // Adding Process
            float sum = x + y;
            cout << "\nAddition: " << sum << endl;
            printSpecialCases(sum);

            string sumBin = floatToBinary(sum);
            cout << "Binary: " << sumBin << endl;
            cout << "Hex: " << floatToHex(sum) << endl;
            printIEEE(sumBin);

            // Subtraction Process
            float diff = x - y;
            cout << "\nSubtraction: " << diff << endl;
            printSpecialCases(diff);

            string diffBin = floatToBinary(diff);
            cout << "Binary: " << diffBin << endl;
            cout << "Hex: " << floatToHex(diff) << endl;
            printIEEE(diffBin);

            // Multiplication Process
            float mul = x * y;
            cout << "\nMultiplication: " << mul << endl;
            printSpecialCases(mul);

            string mulBin = floatToBinary(mul);
            cout << "Binary: " << mulBin << endl;
            cout << "Hex: " << floatToHex(mul) << endl;
            printIEEE(mulBin);
        }

        else {
            cout << "Invalid mode selected.\n";
        }

        // Repeating Process
        while (true) {
            cout << "\nTry Again? (y/n): ";
            cin >> again;

            // Forcing User to follow the prompts so the loop doesn't run forever
            if (again == 'y' || again == 'Y' || again == 'n' || again == 'N') {
                break;
            }
            else {
                cout << "Error: Please enter 'y' or 'n' only." << endl;
            }
        }
    }

    cout << "Program End" << endl;
    return 0;
}