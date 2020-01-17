#include "FixedPoint.h"

//! Macro: Rounding Factor Calculator
/*!
  This macro is for facilitate the use of this library.
*/
#define ROUNDING_FACTOR                                             (1UL << (__AMOUNT_OF_FRACTIONARY_BITS__ - 1))

//! Function: fixed_t Adder
/*!
  Summs fixed_t type numbers.
  \param iAmountOfNumbers is a integer number. This value is automatic and should ignored. It's the amount of numbers that will be summed. 
  \param ... is a fixed_t type numbers. It's the numbers that will be summed.
  \return Returns operation result.
*/
fixed_t (Fixed_sum)(long int iAmountOfNumbers, ...){
  va_list vaMyArguments;
  va_start(vaMyArguments, iAmountOfNumbers);
  __FIXED_BUFFER_T__ fxbSum = 0;
  fixed_t fxResult = 0;
  while (iAmountOfNumbers--){
    fxbSum += va_arg(vaMyArguments, long int);
  }
  va_end(vaMyArguments);
  if (fxbSum >= __FIXED_MAX_VALUE__){
    return __FIXED_MAX_VALUE__;
  }
  else if (fxbSum <= __FIXED_MIN_VALUE__){
    return __FIXED_MIN_VALUE__;
  }
  fxResult = (fixed_t) fxbSum;
  return fxResult;
}

//! Function: fixed_t Multiplier
/*!
  Multiplies fixed_t type numbers.
  \param iAmountOfNumbers is a integer number. This value is automatic and should ignored. It's the amount of numbers that will be multiplied. 
  \param ... is a fixed_t type numbers. It's the numbers that will be multiplied.
  \return Returns operation result.
*/
fixed_t (Fixed_multiply)(long int iAmountOfNumbers, ...){
  va_list vaMyArguments;
  va_start(vaMyArguments, iAmountOfNumbers);
  __FIXED_BUFFER_T__ fxbMultiply = 0;
  fixed_t fxResult = 0;
  while (iAmountOfNumbers--){
    if (fxbMultiply == 0){
        fxbMultiply = va_arg(vaMyArguments, long int);
    }
    else{
        fxbMultiply = (((fxbMultiply * va_arg(vaMyArguments, long int)) + ROUNDING_FACTOR) >> __AMOUNT_OF_FRACTIONARY_BITS__);
    }
  }
  va_end(vaMyArguments);
  if (fxbMultiply >= __FIXED_MAX_VALUE__){
    return __FIXED_MAX_VALUE__;
  }
  else if (fxbMultiply <= __FIXED_MIN_VALUE__){
    return __FIXED_MIN_VALUE__;
  }
  fxResult = (fixed_t) fxbMultiply;
  return fxResult;
}

//! Function: fixed_t Divider
/*!
  Divides fixed_t type numbers.
  \param iAmountOfNumbers is a integer number. This value is automatic and should ignored. It's the amount of numbers that will be divided. 
  \param ... is a fixed_t type numbers. It's the numbers that will be divided.
  \return Returns operation result.
*/
fixed_t (Fixed_divide)(long int iAmountOfNumbers, ...){
  va_list vaMyArguments;
  va_start(vaMyArguments, iAmountOfNumbers);
  __FIXED_BUFFER_T__ fxbDivisor = 0;
  __FIXED_BUFFER_T__ fxbDividend = 0;
  fixed_t fxResult = 0;
  while (iAmountOfNumbers--){
    if (fxbDivisor == 0){
        fxbDivisor = va_arg(vaMyArguments, long int);
    }
    else{
        fxbDividend = va_arg(vaMyArguments, long int);
        if (fxbDividend == 0){
            if (fxbDivisor > 0){
                return __FIXED_MAX_VALUE__;
            }
            else{
                return __FIXED_MIN_VALUE__;
            }
        }
        fxbDivisor = ((fxbDivisor << __AMOUNT_OF_FRACTIONARY_BITS__) + (fxbDividend >> 1)) / fxbDividend;
    }
  }
  va_end(vaMyArguments);
  if (fxbDivisor >= __FIXED_MAX_VALUE__){
    return __FIXED_MAX_VALUE__;
  }
  else if (fxbDivisor <= __FIXED_MIN_VALUE__){
    return __FIXED_MIN_VALUE__;
  }
  fxResult = (fixed_t) fxbDivisor;
  return fxResult;
}
