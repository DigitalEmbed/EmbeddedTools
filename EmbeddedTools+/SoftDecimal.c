#include <EmbeddedTools.h>

#if defined(__SOFT_DECIMAL_MANAGER_ENABLE__)

  #include "./SoftDecimal.h"

  /*!
    Prototype public Bit "methods".
  */
  float __SoftDecimal_toFloat(fixed_t fxNumber);                                                /*!< float "method". */
  fixed_t __SoftDecimal_toFixed(float fNumber);                                                 /*!< int32_t "method". */
  __AUTO_SIZE_LIST_TYPE__ __SoftDecimal_toInt(fixed_t fxNumber);                                /*!< fixed_t "method". */

  #if defined (__SOFT_DECIMAL_ENABLE_INFINITE_ARGUMENTS__)
    
    //! Macro: Rounding Factor Calculator
    /*!
      This macro is for facilitate the use of this library.
    */
    #define __ROUNDING_FACTOR__\
      ((uint32_t)1 << (__SOFT_DECIMAL_AMOUNT_OF_FRACTIONARY_BITS__ - 1))

    extern bool bReachedLimitFlag;                                                              /*!< bool type variable. */

    /*!
      Prototype public Fixed "methods".
    */
    fixed_t __SoftDecimal_Fixed_sum(fixed_t fxAddendA, fixed_t fxAddendB);                      /*!< fixed_t "method". */
    fixed_t __SoftDecimal_Fixed_subtract(fixed_t fxMinuendo, fixed_t fxSubtrahend);             /*!< fixed_t "method". */
    fixed_t __SoftDecimal_Fixed_multiply(fixed_t fxMultiplier, fixed_t fxMultiplicand);         /*!< fixed_t "method". */
    fixed_t __SoftDecimal_Fixed_divide(fixed_t fxDividend, fixed_t fxDivisor);                  /*!< fixed_t "method". */
    
    /*!
      Prototype public Float "methods".
    */
    fixed_t __SoftDecimal_Float_sum(float fAddendA, float fAddendB);                            /*!< fixed_t "method". */
    fixed_t __SoftDecimal_Float_subtract(float fMinuendo, float fSubtrahend);                   /*!< fixed_t "method". */
    fixed_t __SoftDecimal_Float_multiply(float fMultiplier, float fMultiplicand);               /*!< fixed_t "method". */
    fixed_t __SoftDecimal_Float_divide(float fDividend, float fDivisor);                        /*!< fixed_t "method". */

    /*!
      Bitwise object "constructor".
    */
    #if defined(__AVR__)
      const softdecimal_manager_t SoftDecimal PROGMEM = {                                       /*!< Bitwise manager "object". */
    #else
      const softdecimal_manager_t SoftDecimal = {                                               /*!< Bitwise manager "object". */
    #endif
      .Float = {
        .toFixed = &__SoftDecimal_toFixed,
        .sum = &__SoftDecimal_Float_sum,
        .subtract = &__SoftDecimal_Float_subtract,
        .multiply = &__SoftDecimal_Float_multiply,
        .divide = &__SoftDecimal_Float_divide
      },
      .Fixed = {
        .toFloat = &__SoftDecimal_toFloat,
        .toInt = &__SoftDecimal_toInt,
        .sum = &__SoftDecimal_Fixed_sum,
        .subtract = &__SoftDecimal_Fixed_subtract,
        .multiply = &__SoftDecimal_Fixed_multiply,
        .divide = &__SoftDecimal_Fixed_divide
      },
      .getMinimumValue = &SoftDecimal_getMinimumValue,
      .getMaximumValue = &SoftDecimal_getMaximumValue,
      .getResolution = &SoftDecimal_getResolution,
      .checkError = &SoftDecimal_checkError
    };

  #else

    /*!
      Bitwise object "constructor".
    */
    #if defined(__AVR__)
      const softdecimal_manager_t SoftDecimal PROGMEM = {                                       /*!< Bitwise manager "object". */
    #else
      const softdecimal_manager_t SoftDecimal = {                                               /*!< Bitwise manager "object". */
    #endif
      .Float = {
        .toFixed = &__SoftDecimal_toFixed,
        .sum = &SoftDecimal_floatSum,
        .subtract = &SoftDecimal_floatSubtract,
        .multiply = &SoftDecimal_floatMultiply,
        .divide = &SoftDecimal_floatDivide
      },
      .Fixed = {
        .toFloat = &__SoftDecimal_toFloat,
        .toInt = &__SoftDecimal_toInt,
        .sum = &SoftDecimal_fixedSum,
        .subtract = &SoftDecimal_fixedSubtract,
        .multiply = &SoftDecimal_fixedMultiply,
        .divide = &SoftDecimal_fixedDivide
      },
      .getMinimumValue = &SoftDecimal_getMinimumValue,
      .getMaximumValue = &SoftDecimal_getMaximumValue,
      .getResolution = &SoftDecimal_getResolution,
      .checkError = &SoftDecimal_checkError
    };

  #endif

  //! Macro: Fixed to Float Converter
  /*!
    Converts a fixed_t number to float type.
    \param fxNumber is a fixed_t number.
    \return Returns the fixed_t number.
  */
  float __SoftDecimal_toFloat(fixed_t fxNumber){
    return SoftDecimal_toFloat(fxNumber);
  }

  //! Macro: Float to Fixed Converter
  /*!
    Converts a float number to fixed_t type.
    \param fNumber is a float number.
    \return Returns the fixed_t number.
  */
  fixed_t __SoftDecimal_toFixed(float fNumber){
    return SoftDecimal_toFixed(fNumber);
  }

  //! Macro: Fixed to Integer Converter
  /*!
    Converts a fixed_t number to int type.
    \param fxNumber is a fixed_t number.
    \return Returns the integer number.
  */
  __AUTO_SIZE_LIST_TYPE__ __SoftDecimal_toInt(fixed_t fxNumber){
    return SoftDecimal_toInt(fxNumber);
  }

  #if defined (__SOFT_DECIMAL_ENABLE_INFINITE_ARGUMENTS__)
    
    //! Function: fixed_t Adder
    /*!
      Summs fixed_t type numbers.
      \param fxAddendA is a fixed_t number.
      \param fxAddendB is a fixed_t number.
      \return Returns operation result.
    */
    fixed_t __SoftDecimal_Fixed_sum(fixed_t fxAddendA, fixed_t fxAddendB){
      __SOFT_DECIMAL_BUFFER_T__ fxbSum = fxAddendA + fxAddendB;
      if (fxbSum >= __SOFT_DECIMAL_MAX_VALUE__){
        bReachedLimitFlag = true;
        return __SOFT_DECIMAL_MAX_VALUE__;
      }
      else if (fxbSum <= __SOFT_DECIMAL_MIN_VALUE__){
        bReachedLimitFlag = true;
        return __SOFT_DECIMAL_MIN_VALUE__;
      }
      return (fixed_t) fxbSum;
    }
    
    //! Function: fixed_t Subtracter
    /*!
      Subtracts fixed_t type numbers.
      \param fxMinuendo is a fixed_t number.
      \param fxSubtrahend is a fixed_t number.
      \return Returns operation result.
    */
    fixed_t __SoftDecimal_Fixed_subtract(fixed_t fxMinuendo, fixed_t fxSubtrahend){
      __SOFT_DECIMAL_BUFFER_T__ fxbSubtraction = fxMinuendo - fxSubtrahend;
      if (fxbSubtraction >= __SOFT_DECIMAL_MAX_VALUE__){
        bReachedLimitFlag = true;
        return __SOFT_DECIMAL_MAX_VALUE__;
      }
      else if (fxbSubtraction <= __SOFT_DECIMAL_MIN_VALUE__){
        bReachedLimitFlag = true;
        return __SOFT_DECIMAL_MIN_VALUE__;
      }
      return (fixed_t) fxbSubtraction;
    }
    
    //! Function: fixed_t Multiplier
    /*!
      Multiplies fixed_t type numbers.
      \param fxMultiplier is a fixed_t number.
      \param fxMultiplicand is a fixed_t number.
      \return Returns operation result.
    */
    fixed_t __SoftDecimal_Fixed_multiply(fixed_t fxMultiplier, fixed_t fxMultiplicand){
      __SOFT_DECIMAL_BUFFER_T__ fxbMultiply = (((fxMultiplier * fxMultiplicand) + __ROUNDING_FACTOR__) >> __SOFT_DECIMAL_AMOUNT_OF_FRACTIONARY_BITS__);
      if (fxbMultiply >= __SOFT_DECIMAL_MAX_VALUE__){
        bReachedLimitFlag = true;
        return __SOFT_DECIMAL_MAX_VALUE__;
      }
      else if (fxbMultiply <= __SOFT_DECIMAL_MIN_VALUE__){
        bReachedLimitFlag = true;
        return __SOFT_DECIMAL_MIN_VALUE__;
      }
      return (fixed_t) fxbMultiply;
    }
    
    //! Function: fixed_t Divider
    /*!
      Divides fixed_t type numbers.
      \param fxDivisor is a fixed_t number.
      \param fxDividend is a fixed_t number.
      \return Returns operation result.
    */
    fixed_t __SoftDecimal_Fixed_divide(fixed_t fxDividend, fixed_t fxDivisor){
      if (fxDividend == 0){
        bReachedLimitFlag = true;
        if (fxDivisor > 0){
          return __SOFT_DECIMAL_MAX_VALUE__;
        }
        else{
          return __SOFT_DECIMAL_MIN_VALUE__;
        }
      }
      __SOFT_DECIMAL_BUFFER_T__ fxbQuotient = ((fxDivisor << __SOFT_DECIMAL_AMOUNT_OF_FRACTIONARY_BITS__) + (fxDividend >> 1)) / fxDividend;
      if (fxbQuotient >= __SOFT_DECIMAL_MAX_VALUE__){
        bReachedLimitFlag = true;
        return __SOFT_DECIMAL_MAX_VALUE__;
      }
      else if (fxbQuotient <= __SOFT_DECIMAL_MIN_VALUE__){
        bReachedLimitFlag = true;
        return __SOFT_DECIMAL_MIN_VALUE__;
      }
      return (fixed_t) fxbQuotient;
    }
    
    //! Function: float Adder
    /*!
      Summs float type numbers.
      \param fAddendA is a float number.
      \param fAddendB is a float number.
      \return Returns operation result.
    */
    fixed_t __SoftDecimal_Float_sum(float fAddendA, float fAddendB){
      __SOFT_DECIMAL_BUFFER_T__ fxbSum = SoftDecimal_toFixed(fAddendA) + SoftDecimal_toFixed(fAddendB);
      if (fxbSum >= __SOFT_DECIMAL_MAX_VALUE__){
        bReachedLimitFlag = true;
        return __SOFT_DECIMAL_MAX_VALUE__;
      }
      else if (fxbSum <= __SOFT_DECIMAL_MIN_VALUE__){
        bReachedLimitFlag = true;
        return __SOFT_DECIMAL_MIN_VALUE__;
      }
      return (fixed_t) fxbSum;
    }
    
    //! Function: float Subtracter
    /*!
      Subtracts float type numbers.
      \param fMinuendo is a float number.
      \param fSubtrahend is a float number.
      \return Returns operation result.
    */
    fixed_t __SoftDecimal_Float_subtract(float fMinuendo, float fSubtrahend){
      __SOFT_DECIMAL_BUFFER_T__ fxbSubtraction = SoftDecimal_toFixed(fMinuendo) - SoftDecimal_toFixed(fSubtrahend);
      if (fxbSubtraction >= __SOFT_DECIMAL_MAX_VALUE__){
        bReachedLimitFlag = true;
        return __SOFT_DECIMAL_MAX_VALUE__;
      }
      else if (fxbSubtraction <= __SOFT_DECIMAL_MIN_VALUE__){
        bReachedLimitFlag = true;
        return __SOFT_DECIMAL_MIN_VALUE__;
      }
      return (fixed_t) fxbSubtraction;
    }
    
    //! Function: float Multiplier
    /*!
      Multiplies float type numbers.
      \param fMultiplier is a float number.
      \param fMultiplicand is a float number.
      \return Returns operation result.
    */
    fixed_t __SoftDecimal_Float_multiply(float fMultiplier, float fMultiplicand){
      __SOFT_DECIMAL_BUFFER_T__ fxbMultiply = (((SoftDecimal_toFixed(fMultiplier) * SoftDecimal_toFixed(fMultiplicand)) + __ROUNDING_FACTOR__) >> __SOFT_DECIMAL_AMOUNT_OF_FRACTIONARY_BITS__);
      if (fxbMultiply >= __SOFT_DECIMAL_MAX_VALUE__){
        bReachedLimitFlag = true;
        return __SOFT_DECIMAL_MAX_VALUE__;
      }
      else if (fxbMultiply <= __SOFT_DECIMAL_MIN_VALUE__){
        bReachedLimitFlag = true;
        return __SOFT_DECIMAL_MIN_VALUE__;
      }
      return (fixed_t) fxbMultiply;
    }
    
    //! Function: float Divider
    /*!
      Divides float type numbers.
      \param fDivisor is a float number.
      \param fDividend is a float number.
      \return Returns operation result.
    */
    fixed_t __SoftDecimal_Float_divide(float fDividend, float fDivisor){
      if (fDividend == 0.0){
        bReachedLimitFlag = true;
        if (fDivisor > 0.0){
          return __SOFT_DECIMAL_MAX_VALUE__;
        }
        else{
          return __SOFT_DECIMAL_MIN_VALUE__;
        }
      }
      __SOFT_DECIMAL_BUFFER_T__ fxbQuotient = ((SoftDecimal_toFixed(fDivisor) << __SOFT_DECIMAL_AMOUNT_OF_FRACTIONARY_BITS__) + (SoftDecimal_toFixed(fDividend) >> 1)) / SoftDecimal_toFixed(fDividend);
      if (fxbQuotient >= __SOFT_DECIMAL_MAX_VALUE__){
        bReachedLimitFlag = true;
        return __SOFT_DECIMAL_MAX_VALUE__;
      }
      else if (fxbQuotient <= __SOFT_DECIMAL_MIN_VALUE__){
        bReachedLimitFlag = true;
        return __SOFT_DECIMAL_MIN_VALUE__;
      }
      return (fixed_t) fxbQuotient;
    }

  #endif

#endif
