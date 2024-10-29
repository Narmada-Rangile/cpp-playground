//
// Created by devesh on 29/10/24.
//

#include <stdio.h>

int main() {
    char var1;                    // size: 1 byte, range: -128 to 127
    unsigned char var2;           // size: 1 byte, range: 0 to 255
    signed char var3;             // size: 1 byte, range: -128 to 127

    int var4;                     // size: 4 bytes, range: -2,147,483,648 to 2,147,483,647
    unsigned int var5;            // size: 4 bytes, range: 0 to 4,294,967,295
    signed int var6;              // size: 4 bytes, range: -2,147,483,648 to 2,147,483,647

    short int var7;               // size: 2 bytes, range: -32,768 to 32,767
    unsigned short int var8;      // size: 2 bytes, range: 0 to 65,535
    signed short int var9;        // size: 2 bytes, range: -32,768 to 32,767

    long int var10;               // size: 4 bytes, range: -2,147,483,648 to 2,147,483,647
    unsigned long int var11;      // size: 4 bytes, range: 0 to 4,294,967,295
    signed long int var12;        // size: 4 bytes, range: -2,147,483,648 to 2,147,483,647

    long long int var13;          // size: 8 bytes, range: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
    unsigned long long int var14; // size: 8 bytes, range: 0 to 18,446,744,073,709,551,615
    signed long long int var15;   // size: 8 bytes, range: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807

    float var16;                  // size: 4 bytes,  range: 1.2E-38 to 3.4E+38
    double var17;                 // size: 8 bytes,  range: 2.3E-308 to 1.7E+308
    long double var18;            // size: 10 bytes, range: 3.4E-4932 to 1.1E+4932
}