#include "FixedPoint.h"

fixed_t (fxFixedAdd)(int iAmountOfNumbers, ...){
  va_list vaMyArguments;
  va_start(vaMyArguments, iAmountOfNumbers);
  fixed_buffer_t fxbSum = 0;
  fixed_t fxResult = 0;
  while (iAmountOfNumbers--){
    fxbSum += va_arg(vaMyArguments, int);
  }
  va_end(vaMyArguments);
  if (fxbSum >= FIXED_MAX_VALUE){
    return FIXED_MAX_VALUE;
  }
  else if (fxbSum <= FIXED_MIN_VALUE){
    return FIXED_MIN_VALUE;
  }
  fxResult = (fixed_t) fxbSum;
  return fxResult;
}

fixed_t (fxFixedMultiply)(int iAmountOfNumbers, ...){
  va_list vaMyArguments;
  va_start(vaMyArguments, iAmountOfNumbers);
  fixed_buffer_t fxbMultiply = 0;
  fixed_t fxResult = 0;
  while (iAmountOfNumbers--){
    if (fxbMultiply == 0){
        fxbMultiply = va_arg(vaMyArguments, int);
    }
    else{
        fxbMultiply = (((fxbMultiply * va_arg(vaMyArguments, int)) + uiRoundingFactor) >> AMOUNT_OF_FRACTIONARY_BITS);
    }
  }
  va_end(vaMyArguments);
  if (fxbMultiply >= FIXED_MAX_VALUE){
    return FIXED_MAX_VALUE;
  }
  else if (fxbMultiply <= FIXED_MIN_VALUE){
    return FIXED_MIN_VALUE;
  }
  fxResult = (fixed_t) fxbMultiply;
  return fxResult;
}

fixed_t (fxFixedDivide)(int iAmountOfNumbers, ...){
  va_list vaMyArguments;
  va_start(vaMyArguments, iAmountOfNumbers);
  fixed_buffer_t fxbDivisor = 0;
  fixed_buffer_t fxbDividend = 0;
  fixed_t fxResult = 0;
  while (iAmountOfNumbers--){
    if (fxbDivisor == 0){
        fxbDivisor = va_arg(vaMyArguments, int);
    }
    else{
        fxbDividend = va_arg(vaMyArguments, int);
        if (fxbDividend == 0){
            if (fxbDivisor > 0){
                return FIXED_MAX_VALUE;
            }
            else{
                return FIXED_MIN_VALUE;
            }
        }
        fxbDivisor = ((fxbDivisor << AMOUNT_OF_FRACTIONARY_BITS) + (fxbDividend >> 1)) / fxbDividend;
    }
  }
  va_end(vaMyArguments);
  if (fxbDivisor >= FIXED_MAX_VALUE){
    return FIXED_MAX_VALUE;
  }
  else if (fxbDivisor <= FIXED_MIN_VALUE){
    return FIXED_MIN_VALUE;
  }
  fxResult = (fixed_t) fxbDivisor;
  return fxResult;
}
