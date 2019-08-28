#include "FixedPoint.h"

fixed_t (fxFixedAdd)(int iAmountOfNumbers, ...){
  va_list vaMyArguments;
  va_start(vaMyArguments, iAmountOfNumbers);
  int32_t i32Sum = 0;
  int16_t i16Result = 0;
  while (iAmountOfNumbers--){
    i32Sum += va_arg(vaMyArguments, int);
  }
  va_end(vaMyArguments);
  if (i32Sum >= INT16_MAX){
    return INT16_MAX;
  }
  else if (i32Sum <= INT16_MIN){
    return INT16_MIN;
  }
  i16Result = (int16_t) i32Sum;
  return i16Result;
}

fixed_t (fxFixedMultiply)(int iAmountOfNumbers, ...){
  va_list vaMyArguments;
  va_start(vaMyArguments, iAmountOfNumbers);
  int32_t i32Multiply = 0;
  int16_t i16Result = 0;
  while (iAmountOfNumbers--){
    if (i32Multiply == 0){
        i32Multiply = va_arg(vaMyArguments, int);
    }
    else{
        i32Multiply = (((i32Multiply * va_arg(vaMyArguments, int)) + uiRoundingFactor) >> AMOUNT_OF_FRACTIONARY_BITS);
    }
  }
  va_end(vaMyArguments);
  if (i32Multiply >= INT16_MAX){
    return INT16_MAX;
  }
  else if (i32Multiply <= INT16_MIN){
    return INT16_MIN;
  }
  i16Result = (int16_t) i32Multiply;
  return i16Result;
}

fixed_t (fxFixedDivide)(int iAmountOfNumbers, ...){
  va_list vaMyArguments;
  va_start(vaMyArguments, iAmountOfNumbers);
  int32_t i32Divisor = 0;
  int32_t i32Dividend = 0;
  int16_t i16Result = 0;
  while (iAmountOfNumbers--){
    if (i32Divisor == 0){
        i32Divisor = va_arg(vaMyArguments, int);
    }
    else{
        i32Dividend = va_arg(vaMyArguments, int);
        if (i32Dividend == 0){
            if (i32Divisor > 0){
                return INT16_MAX;
            }
            else{
                return INT16_MIN;
            }
        }
        i32Divisor = ((i32Divisor << AMOUNT_OF_FRACTIONARY_BITS) + (i32Dividend >> 1)) / i32Dividend;
    }
  }
  va_end(vaMyArguments);
  if (i32Divisor >= INT16_MAX){
    return INT16_MAX;
  }
  else if (i32Divisor <= INT16_MIN){
    return INT16_MIN;
  }
  i16Result = (int16_t) i32Divisor;
  return i16Result;
}
