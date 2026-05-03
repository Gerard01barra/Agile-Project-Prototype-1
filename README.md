IEEE 754 Floating Point Calculator - User Guide
This program is a command-line tool that allows you to perform arithmetic operations (addition, subtraction, multiplication) on numbers in Decimal, Binary, and Hexadecimal formats. It also converts results into IEEE 754 single-precision format, showing the sign, exponent, and mantissa.
Getting Started
1. Compile the program using: g++ main.cpp -o ieee_calculator
2. Run the program using: ./ieee_calculator
How to Use
Step 1: Choose between calculating 1 or 2 numbers 
Step 2: Choose a format (1 = Decimal, 2 = Binary, 3 = Hex)
Step 3: Enter one/two numbers in that format
Step 4: Decide whether to run the program again or to exit the program
Input Rules
Decimal: digits, optional sign, one decimal point
Binary: only 0 and 1, max 32 bits
Hex: digits 0–9, A–F, max 8 characters
Operations
The program performs addition, subtraction, and multiplication.
For each result, it shows decimal, binary, hex, and IEEE breakdown.
Special Cases
Detects NaN, Infinity, and Zero.
Example Output
Addition: 5.5
Binary: 01000000101100000000000000000000
Hex: 40b00000
Sign: 0
Exponent: 10000001
Mantissa: 01100000000000000000000
Repeat or Exit
After calculations, enter 'y' to run again or 'n' to exit.
