/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:27:56 by marvin            #+#    #+#             */
/*   Updated: 2024/01/24 11:27:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8| b);
}
/*

int create_trgb(int t, int r, int g, int b) {
    return (t << 24 | r << 16 | g << 8 | b);
}
Bitwise Left Shift (<<) Operation:

t << 24: Shifts the bits of t 24 positions to the left. This effectively places the value of t in the most significant byte (alpha channel) of the resulting integer.

r << 16: Shifts the bits of r 16 positions to the left. This places the value of r in the second byte (red channel) of the resulting integer.

g << 8: Shifts the bits of g 8 positions to the left. This places the value of g in the third byte (green channel) of the resulting integer.

b: The value of b is placed directly in the least significant byte (blue channel) of the resulting integer.

Bitwise OR (|) Operation:

The results of the left shifts are combined using the bitwise OR operator (|). This operation effectively merges the values of the alpha, red, green, and blue channels into a single integer.
Shifting bits to the left (<<) is a bitwise operation that effectively multiplies an integer by a power of 2. Let's take a simple example to illustrate the concept:

Suppose you have a binary number b = 00101010 (42 in decimal). If you shift the bits of b to the left by 2 positions (b << 2), you get 10101000 in binary, which is 168 in decimal.

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Here's how the shifting works step by step:

Original binary number b = 00101010 (42 in decimal).
Shift left by 2 positions (b << 2):
sql
Copy code
00101010   (original binary)
<< 2       (shift left by 2 positions)
-----------
10101000   (resulting binary)
So, shifting to the left effectively multiplies the original number by 2 raised to the power of the number of positions shifted.

In the context of the create_trgb function:

t << 24: Shifts the bits of t 24 positions to the left.
r << 16: Shifts the bits of r 16 positions to the left.
g << 8: Shifts the bits of g 8 positions to the left.
These shifts are used to position the values of t, r, g, and b in specific bytes of a 32-bit integer, where each byte represents a color channel (alpha, red, green, blue) in the RGBA color model. The left shifts are a way of organizing and combining these color channels into a single integer.*/

int get_t(int t)
{
	return (t << 24 & 0xFF);
}

int get_r(int r)
{
	return (r << 16 & 0xFF);
}

int get_g(int g)
{
	return (g << 8 & 0xFF);
}

int get_b(int b)
{
	return (b & 0xFF);
}
/*
The get_t function extracts the alpha (transparency) component from a given color represented as a 32-bit integer in the RGBA format. Let's break down the function:

int get_t(int trgb) {
    return ((trgb >> 24) & 0xFF);
}
Bitwise Right Shift (>>) Operation:

(trgb >> 24): Shifts the bits of the input trgb 24 positions to the right. This operation isolates the most significant byte, which corresponds to the alpha channel.
Bitwise AND (&) Operation:

& 0xFF: Performs a bitwise AND operation with the result of the right shift. This operation is used to ensure that only the least significant 8 bits are retained, effectively masking out any other bits.
Return Statement:

The resulting value is returned by the function. This value represents the alpha channel (transparency) of the original color.
To put it simply, the function extracts the alpha channel value from a 32-bit integer that represents a color in the RGBA format. The extracted value is then returned.
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

If you replace the bitwise AND (&) with the bitwise OR (|) in the get_t function, the behavior would change. Let's take a look at the modified function:

int get_t(int trgb) {
    return ((trgb >> 24) | 0xFF);
}
In this case:

Bitwise Right Shift (>>) Operation:

(trgb >> 24): Shifts the bits of the input trgb 24 positions to the right. This operation isolates the most significant byte, which corresponds to the alpha channel.
Bitwise OR (|) Operation:

| 0xFF: Performs a bitwise OR operation with the result of the right shift. This operation effectively sets all bits to 1 in the least significant 8 bits, regardless of their original values.
Return Statement:

The resulting value is returned by the function.
However, using the bitwise OR (|) in this context doesn't make much sense for extracting the alpha channel. The purpose of using the bitwise AND (&) with 0xFF in the original function is to mask out all bits except the least significant 8 bits, ensuring that only the alpha channel value is retained.

If you use the bitwise OR (|) with 0xFF, you effectively set all the bits to 1 in the least significant 8 bits, which could result in a value that is not a valid alpha channel value (beyond the range of 0 to 255). The original use of bitwise AND (& 0xFF) is more appropriate for correctly extracting the alpha channel.
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

In the context of bitwise operations in programming, 0xFF is a hexadecimal constant representing the binary value 11111111. In decimal, this is equivalent to 255. The two hexadecimal digits "0x" are commonly used as a prefix to indicate that the following characters represent a hexadecimal number.

In bitwise operations, using 0xFF is often seen in combination with bitwise AND (&) to perform a bitwise mask operation. When you perform a bitwise AND operation between a value and 0xFF, it effectively keeps only the least significant 8 bits of that value and sets all other bits to 0.

For example:

int value = 0xABCD;  // Binary: 1010101111001101
int maskedValue = value & 0xFF;  // Binary: 0000000000001101
In this example, maskedValue will be 13 in decimal, which corresponds to the least significant 8 bits of the original value. This is a common technique used to extract or manipulate specific byte values in programming, particularly when dealing with color channels in graphics or network protocols where values are often represented using a byte (8 bits).

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Char/int conversion
Since each byte contains 2^8 = 256 values (1 byte = 8 bits), and RGB values range from 0 to 255, we can perfectly fit a unsigned char for each TRGB parameters {T, R, G, B} (char is 1 byte) and fit a int for the TRGB value (int is 4 bytes). In order to set the values programatically we use type converting.

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

unsigned char	get_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	get_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	get_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	get_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}
*/