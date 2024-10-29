#include <stdio.h>    // for printf function
#include <limits.h>   // for char, int family constants
#include <float.h>    // for float family constants

int main()
{
    // char family
    printf("\nRange of char: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("Range of signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Range of unsigned char: 0 to %d\n", UCHAR_MAX);

    // short int family
    printf("\nRange of short int: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Range of signed short int: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Range of unsigned short int: 0 to %u\n", USHRT_MAX);

    // int family
    printf("\nRange of int: %d to %d\n", INT_MIN, INT_MAX);
    printf("Range of signed int: %d to %d\n", INT_MIN, INT_MAX);
    printf("Range of unsigned int: 0 to %u\n", UINT_MAX);

    // long int family
    printf("\nRange of long int: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Range of signed long int: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Range of unsigned long int: 0 to %lu\n", ULONG_MAX);

    // long long int family
    printf("\nRange of long long int: %lld to %lld\n", LLONG_MIN, LLONG_MAX);
    printf("Range of signed long long int: %lld to %lld\n", LLONG_MIN, LLONG_MAX);
    printf("Range of unsigned long long int: 0 to %llu\n", ULLONG_MAX);

    // float family
    printf("\nRange of float: %e to %e\n", FLT_MIN, FLT_MAX);
    printf("Range of double: %e to %e\n", DBL_MIN, DBL_MAX);
    printf("Range of long double: %Le to %Le\n", LDBL_MIN, LDBL_MAX);

    return 0;
}
