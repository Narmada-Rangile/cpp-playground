# Fundamental Data Types in C

| Data Type       | Keyword Used  |
|-----------------|---------------|
| Character       | `char`        |
| Integer         | `int`         |
| Floating Point  | `float`       |
| Double          | `double`      |
| Valueless       | `void`        |

These data types can vary in their:

1. Notation (signed and unsigned notation)
2. Size (short, long and long long sizes)

> Note:
>
> - Sizes are only defined on `int` and `long double` is also defined in c-program.
> - Notations are only defined on `char` and `int` families.

## Unsigned Notation

This is defined only on `char` and `int`. Unsigned int/char keeps the sign bit free and makes the entire string of bits available for the storage of non-negative numbers.

## Signed Notation

This is defined only on `char` and `int`. It is the default one, means `signed int` and `int` are one and same thing. It uses the twos complement notation to store the numbers. Thus negative numbers are also allowed. Sign bit is the leftmost bit of the string of bits which is used to determine the sign of number stored. 0 means value is positive and 1 means value is negative.
