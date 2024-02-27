#include "multiplication.h"
#include "fileInputOutput.h"

#include <iostream>
#include <fstream>
#include <vector>

// default ctor
Multiplication::Multiplication()
{
    manMcand = 0;
    manMplier = 0;
    multiplicand = 0;
    multiplier = 0;
    bits = 0;
    result = 0;
}

// parameterized ctor
Multiplication::Multiplication(int mc, int ml, int b)
{
    multiplicand = mc;
    multiplier = ml;
    bits = b;
    result = 0;
}

// setter function that sets manMcand to passed in parameter
void Multiplication::setMultiplicand(int mcand)
{
    manMcand = mcand;
}

// setter function that sets manMplier to passed in parameter
void Multiplication::setMultiplier(int mplier)
{
    manMplier = mplier;
}

// returns multiplicand
int Multiplication::getMultiplicand() const
{
    return manMcand;
}

// returns multiplier
int Multiplication::getMultiplier() const
{
    return manMplier;
}

void Multiplication::decimalToBinary(int num, int binary[], int length) const
{
    unsigned int i = 0;
    while (num != 0) // gets each bit of binary number
    {
        binary[i] = num % 2;
        i++;
        num /= 2;
    }

    for (int i = i; i < length; i++) // match the length (bit size)
        binary[i] = 0;
}

void Multiplication::reverseArray(int arr[], int length) const
{
    int temp = 0;
    for (int i = 0; i < length / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[length - i - 1];
        arr[length - i - 1] = temp;
    }
}

void Multiplication::add(int accumulator[], int mcnadBinary[], int mplierLength) const
{
    int sum[mplierLength]; // arr to store sum
    int carry = 0;

    for (int i = 0; i <= (sizeof(accumulator) / sizeof(accumulator[0])) - 1; i++)
    {
        if (accumulator[i] == 1 && mcnadBinary[i] == 1)
        {
            if (carry == 1)
            {
                sum[i] = 1;
                carry = 1;
            }
            else
            {
                sum[i] = 0;
                carry = 1;
            }
        }
        else if ((accumulator[i] == 0 && mcnadBinary[i] == 1) || (accumulator[i] == 1 && mcnadBinary[i] == 0))
        {
            if (carry == 1)
                sum[i] = 0;
            else
                sum[i] = 1;
        }
        else
        {
            sum[i] = 0 + carry;
            carry = 0;
        }
    }

    // writing back to the accumulator
    for(int i = 0; i < mplierLength; i++)
        accumulator[i] = sum[i];
}