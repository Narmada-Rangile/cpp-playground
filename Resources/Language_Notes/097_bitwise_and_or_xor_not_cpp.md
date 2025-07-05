## Bitwise Operators in C++ (Part 2)

This video continues the discussion on bitwise operators in C++, focusing on the **AND, OR, XOR, and NOT** operators.

-----

### Key Concepts

  * **Bitwise AND (`&`)** \[[03:36](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=216)\]

      * This operator compares two bits and returns `1` only if both bits are `1`; otherwise, it returns `0` \[[04:09](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=249)\].
      * **Truth Table:**
          * `0 & 0 = 0` \[[05:28](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=328)\]
          * `0 & 1 = 0` \[[05:34](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=334)\]
          * `1 & 0 = 0` \[[05:38](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=338)\]
          * `1 & 1 = 1` \[[05:44](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=344)\]
      * **Use Case: Bit Masking** \[[06:20](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=380)\]
          * Bit masking is used to check the state of a specific bit or a group of bits \[[06:46](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=406)\]. You can create a "mask" with a `1` at the desired bit position to isolate and check its value \[[07:09](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=429)\]. It can also be used to clear a group of bits by ANDing them with `0`s \[[09:20](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=560)\].

  * **Bitwise OR (`|`)** \[[10:05](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=605)\]

      * This operator compares two bits and returns `1` if at least one of the bits is `1`; otherwise, it returns `0` \[[10:15](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=615)\].
      * **Truth Table:**
          * `0 | 0 = 0` \[[10:20](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=620)\]
          * `0 | 1 = 1` \[[10:27](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=627)\]
          * `1 | 0 = 1` \[[10:29](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=629)\]
          * `1 | 1 = 1` \[[10:31](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=631)\]
      * **Use Case: Adding Bits** \[[11:21](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=681)\]
          * You can use the OR operator to set specific bits to `1` \[[11:32](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=692)\].

  * **Bitwise NOT (`~`)** \[[15:08](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=908)\]

      * This is a unary operator that inverts all the bits of a number, changing `0`s to `1`s and `1`s to `0`s \[[16:23](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=983)\].
      * **Use Case: Toggling Bits Off** \[[15:27](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=927)\]
          * It can be combined with the AND operator to set a specific bit to `0` \[[15:27](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=927)\].

  * **Bitwise XOR (`^`)** \[[17:08](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=1028)\]

      * The XOR (exclusive OR) operator returns `1` only if the two bits being compared are different; otherwise, it returns `0` \[[17:14](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=1034)\].
      * **Truth Table:**
          * `0 ^ 0 = 0` \[[18:04](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=1084)\]
          * `0 ^ 1 = 1` \[[18:07](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=1087)\]
          * `1 ^ 0 = 1` \[[18:10](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=1090)\]
          * `1 ^ 1 = 0` \[[18:13](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=1093)\]
      * **Use Case: Flipping Bits / Setting to Zero** \[[18:29](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=1109)\]
          * XORing a value with itself will always result in `0` \[[18:40](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=1120)\].

-----

### Code Examples

Here are some of the code examples from the video:

  * **Bitwise OR for "adding back" bits:**

    ```cpp
    int a = 0b00000101; 
    int b = 0b01011000; 
    b = b << 4; 
    int c = a | b; 
    ```

  * **Bitwise XOR for setting a variable to zero:**

    ```cpp
    int a = 0b1101;
    int b = a ^ a; // b will be 0
    ```

The video concludes by mentioning that the next episode will cover real-world applications of these operators \[[00:53](http://www.youtube.com/watch?v=HoQhw6_1NAA&t=53)\].
