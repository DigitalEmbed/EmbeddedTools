#include "FixedPoint.h"

#if (!defined(__AMOUNT_OF_FRACTIONARY_BITS__)\
    ||((!defined(__SOFT_DECIMAL_SIZE_8_BIT__))\
    &&(!defined(__SOFT_DECIMAL_SIZE_16_BIT__))\
    &&(!defined(__SOFT_DECIMAL_SIZE_32_BIT__))))
  #pragma message "Buffer manager disabled!"
#else

  #if ((__AMOUNT_OF_FRACTIONARY_BITS__ > 0)\
      &&((defined(__SOFT_DECIMAL_SIZE_8_BIT__) && (__AMOUNT_OF_FRACTIONARY_BITS__ < 8))\
      ||(defined(__SOFT_DECIMAL_SIZE_16_BIT__) && (__AMOUNT_OF_FRACTIONARY_BITS__ < 16))\
      ||(defined(__SOFT_DECIMAL_SIZE_32_BIT__) && (__AMOUNT_OF_FRACTIONARY_BITS__ < 32))))

    #include <math.h>

    //! Macro: Rounding Factor Calculator
    /*!
      This macro is for facilitate the use of this library.
    */
    #define ROUNDING_FACTOR                                                     ((uint32_t)1 << (__AMOUNT_OF_FRACTIONARY_BITS__ - 1))

    //! Macro: fixed_t Type Abrangency
    /*!
      These macros are for facilitate the use of this library.
    */
    #define __SOFT_DECIMAL_MINIMUM_VALUE__                                      (-((int32_t)1 << ((sizeof(fixed_t) << 3) - __AMOUNT_OF_FRACTIONARY_BITS__ - 1)))
    #define __SOFT_DECIMAL_RESOLUTION__                                         (pow(2, (-(__AMOUNT_OF_FRACTIONARY_BITS__ - 1))))
    #define __SOFT_DECIMAL_MAXIMUM_VALUE__                                      (-(__SOFT_DECIMAL_MINIMUM_VALUE__ + __SOFT_DECIMAL_RESOLUTION__))

    float fMinimumValue = -1.0;                                                 /*!< float type. */
    float fResolution = -1.0;                                                   /*!< float type. */
    float fMaximumValue = -1.0;                                                 /*!< float type. */
    bool bReachedLimitFlag = false;                                             /*!< bool float type. */

    //! Function: Minimum value getter
    /*!
      Get the minimum possible value of fixed_t type.
      \return Returns the value.
    */
    float SoftDecimal_getMinimumValue(void){
      if (fMinimumValue == -1 && fMaximumValue == -1 && fResolution == -1){
        fMinimumValue = __SOFT_DECIMAL_MINIMUM_VALUE__;
        fResolution = __SOFT_DECIMAL_RESOLUTION__;
        fMaximumValue = __SOFT_DECIMAL_MAXIMUM_VALUE__;
      }
      return fMinimumValue;
    }

    //! Function: Maximum value getter
    /*!
      Get the maximum possible value of fixed_t type.
      \return Returns the value.
    */
    float SoftDecimal_getMaximumValue(void){
      if (fMinimumValue == -1 && fMaximumValue == -1 && fResolution == -1){
        fMinimumValue = __SOFT_DECIMAL_MINIMUM_VALUE__;
        fResolution = __SOFT_DECIMAL_RESOLUTION__;
        fMaximumValue = __SOFT_DECIMAL_MAXIMUM_VALUE__;
      }
      return fMaximumValue;
    }

    //! Function: Resolution getter
    /*!
      Get the resoltuion of fixed_t type.
      \return Returns the value.
    */
    float SoftDecimal_getResolution(void){
      if (fMinimumValue == -1 && fMaximumValue == -1 && fResolution == -1){
        fMinimumValue = __SOFT_DECIMAL_MINIMUM_VALUE__;
        fResolution = __SOFT_DECIMAL_RESOLUTION__;
        fMaximumValue = __SOFT_DECIMAL_MAXIMUM_VALUE__;
      }
      return fResolution;
    }

    //! Function: Error Checker
    /*!
      Checks if any limits were reached during any operation.
      \return Returns true in positive case or false in negative case.
    */
    bool SoftDecimal_error(void){
      if (bReachedLimitFlag == true){
        bReachedLimitFlag = false;
        return true;
      }
      return false;
    }

    #if defined (__FIXED_POINT_USE_INFINITE_ARGUMENTS__)
      #warning FixedPoint uses stdarg.h library! You shoud be very cautious with your RAM. In projects with MISRA rules, this option should be disabled.

      //! Function: fixed_t Adder
      /*!
        Summs fixed_t type numbers.
        \param iAmountOfNumbers is a integer number. This value is automatic and should ignored. It's the amount of numbers that will be summed.
        \param ... is a fixed_t type numbers. It's the numbers that will be summed.
        \return Returns operation result.
      */
      fixed_t (SoftDecimal_fixedSum)(long int iAmountOfNumbers, ...){
        va_list vaMyArguments;
        va_start(vaMyArguments, iAmountOfNumbers);
        __SOFT_DECIMAL_BUFFER_T__ fxbSum = 0;

        while (iAmountOfNumbers--){
          fxbSum += va_arg(vaMyArguments, int);
        }
        va_end(vaMyArguments);
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

      //! Function: float Adder
      /*!
        Convert float type numbers to fixed_t and summs it.
        \param iAmountOfNumbers is a integer number. This value is automatic and should ignored. It's the amount of numbers that will be summed.
        \param ... is a float type numbers. It's the numbers that will be summed.
        \return Returns operation result.
      */
      fixed_t (SoftDecimal_floatSum)(long int iAmountOfNumbers, ...){
        va_list vaMyArguments;
        va_start(vaMyArguments, iAmountOfNumbers);
        __SOFT_DECIMAL_BUFFER_T__ fxbSum = 0;

        while (iAmountOfNumbers--){
          fxbSum += SoftDecimal_toFixed(va_arg(vaMyArguments, double));
        }
        va_end(vaMyArguments);
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
        \param iAmountOfNumbers is a integer number. This value is automatic and should ignored. It's the amount of numbers that will be summed.
        \param ... is a fixed_t type numbers. It's the numbers that will be summed.
        \return Returns operation result.
      */
      fixed_t (SoftDecimal_fixedSubtract)(long int iAmountOfNumbers, ...){
        va_list vaMyArguments;
        va_start(vaMyArguments, iAmountOfNumbers);
        __SOFT_DECIMAL_BUFFER_T__ fxbSubtraction = 0;
        while (iAmountOfNumbers--){
          if (fxbSubtraction == 0){
            fxbSubtraction = va_arg(vaMyArguments, int);
          }
          else{
            fxbSubtraction -= va_arg(vaMyArguments, int);
          }
        }
        va_end(vaMyArguments);
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

      //! Function: float Subtracter
      /*!
        Convert float type numbers to fixed_t and subtracties it.
        \param iAmountOfNumbers is a integer number. This value is automatic and should ignored. It's the amount of numbers that will be summed.
        \param ... is a fixed_t type numbers. It's the numbers that will be summed.
        \return Returns operation result.
      */
      fixed_t (SoftDecimal_floatSubtract)(long int iAmountOfNumbers, ...){
        va_list vaMyArguments;
        va_start(vaMyArguments, iAmountOfNumbers);
        __SOFT_DECIMAL_BUFFER_T__ fxbSubtraction = 0;
        while (iAmountOfNumbers--){
          if (fxbSubtraction == 0){
            fxbSubtraction = SoftDecimal_toFixed(va_arg(vaMyArguments, double));
          }
          else{
            fxbSubtraction -= SoftDecimal_toFixed(va_arg(vaMyArguments, double));
          }
        }
        va_end(vaMyArguments);
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
        \param iAmountOfNumbers is a integer number. This value is automatic and should ignored. It's the amount of numbers that will be multiplied.
        \param ... is a fixed_t type numbers. It's the numbers that will be multiplied.
        \return Returns operation result.
      */
      fixed_t (SoftDecimal_fixedMultiply)(long int iAmountOfNumbers, ...){
        va_list vaMyArguments;
        va_start(vaMyArguments, iAmountOfNumbers);
        __SOFT_DECIMAL_BUFFER_T__ fxbMultiply = 0;
        while (iAmountOfNumbers--){
          if (fxbMultiply == 0){
            fxbMultiply = va_arg(vaMyArguments, int);
          }
          else{
            fxbMultiply = (((fxbMultiply * va_arg(vaMyArguments, int)) + ROUNDING_FACTOR) >> __AMOUNT_OF_FRACTIONARY_BITS__);
          }
        }
        va_end(vaMyArguments);
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

      //! Function: float Multiplier
      /*!
        Convert float type numbers to fixed_t and multiplies it.
        \param iAmountOfNumbers is a integer number. This value is automatic and should ignored. It's the amount of numbers that will be multiplied.
        \param ... is a float type numbers. It's the numbers that will be multiplied.
        \return Returns operation result.
      */
      fixed_t (SoftDecimal_floatMultiply)(long int iAmountOfNumbers, ...){
        va_list vaMyArguments;
        va_start(vaMyArguments, iAmountOfNumbers);
        __SOFT_DECIMAL_BUFFER_T__ fxbMultiply = 0;
        while (iAmountOfNumbers--){
          if (fxbMultiply == 0){
            fxbMultiply = SoftDecimal_toFixed(va_arg(vaMyArguments, double));
          }
          else{
            fxbMultiply = (((fxbMultiply * SoftDecimal_toFixed(va_arg(vaMyArguments, double))) + ROUNDING_FACTOR) >> __AMOUNT_OF_FRACTIONARY_BITS__);
          }
        }
        va_end(vaMyArguments);
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
        \param iAmountOfNumbers is a integer number. This value is automatic and should ignored. It's the amount of numbers that will be divided.
        \param ... is a fixed_t type numbers. It's the numbers that will be divided.
        \return Returns operation result.
      */
      fixed_t (SoftDecimal_fixedDivide)(long int iAmountOfNumbers, ...){
        va_list vaMyArguments;
        va_start(vaMyArguments, iAmountOfNumbers);
        __SOFT_DECIMAL_BUFFER_T__ fxbDividend = 0;
        __SOFT_DECIMAL_BUFFER_T__ fxbDivisor = va_arg(vaMyArguments, int);
        if (fxbDivisor == 0){
          return 0;
        }
        else{
          iAmountOfNumbers--;
        }
        while (iAmountOfNumbers--){
          fxbDividend = va_arg(vaMyArguments, int);
          if (fxbDividend == 0){
            bReachedLimitFlag = true;
            if (fxbDivisor > 0){
              return __SOFT_DECIMAL_MAX_VALUE__;
            }
            else{
              return __SOFT_DECIMAL_MIN_VALUE__;
            }
          }
          fxbDivisor = ((fxbDivisor << __AMOUNT_OF_FRACTIONARY_BITS__) + (fxbDividend >> 1)) / fxbDividend;
        }
        va_end(vaMyArguments);
        if (fxbDivisor >= __SOFT_DECIMAL_MAX_VALUE__){
          bReachedLimitFlag = true;
          return __SOFT_DECIMAL_MAX_VALUE__;
        }
        else if (fxbDivisor <= __SOFT_DECIMAL_MIN_VALUE__){
          bReachedLimitFlag = true;
          return __SOFT_DECIMAL_MIN_VALUE__;
        }
        return (fixed_t) fxbDivisor;
      }

      //! Function: fixed_t Divider
      /*!
        Convert float type numbers to fixed_t and multiplies it.
        \param iAmountOfNumbers is a integer number. This value is automatic and should ignored. It's the amount of numbers that will be divided.
        \param ... is a float type numbers. It's the numbers that will be divided.
        \return Returns operation result.
      */
      fixed_t (SoftDecimal_floatDivide)(long int iAmountOfNumbers, ...){
        va_list vaMyArguments;
        va_start(vaMyArguments, iAmountOfNumbers);
        __SOFT_DECIMAL_BUFFER_T__ fxbDividend = 0;
        __SOFT_DECIMAL_BUFFER_T__ fxbDivisor = SoftDecimal_toFixed(va_arg(vaMyArguments, double));
        if (fxbDivisor == 0){
          return 0;
        }
        else{
          iAmountOfNumbers--;
        }
        while (iAmountOfNumbers--){
          fxbDividend = SoftDecimal_toFixed(va_arg(vaMyArguments, double));
          if (fxbDividend == 0){
            bReachedLimitFlag = true;
            if (fxbDivisor > 0){
              return __SOFT_DECIMAL_MAX_VALUE__;
            }
            else{
              return __SOFT_DECIMAL_MIN_VALUE__;
            }
          }
          fxbDivisor = ((fxbDivisor << __AMOUNT_OF_FRACTIONARY_BITS__) + (fxbDividend >> 1)) / fxbDividend;
        }
        va_end(vaMyArguments);
        if (fxbDivisor >= __SOFT_DECIMAL_MAX_VALUE__){
          bReachedLimitFlag = true;
          return __SOFT_DECIMAL_MAX_VALUE__;
        }
        else if (fxbDivisor <= __SOFT_DECIMAL_MIN_VALUE__){
          bReachedLimitFlag = true;
          return __SOFT_DECIMAL_MIN_VALUE__;
        }
        return (fixed_t) fxbDivisor;
      }

    #else

      fixed_t SoftDecimal_fixedSum(fixed_t fxAddendA, fixed_t fxAddendB){
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

      fixed_t SoftDecimal_floatSum(float fAddendA, float fAddendB){
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

      fixed_t SoftDecimal_fixedSubtract(fixed_t fxMinuendo, fixed_t fxSubtrahend){
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

      fixed_t SoftDecimal_floatSubtract(float fMinuendo, float fSubtrahend){
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

      fixed_t SoftDecimal_fixedMultiply(fixed_t fxMultiplier, fixed_t fxMultiplicand){
        __SOFT_DECIMAL_BUFFER_T__ fxbMultiply = (((fxMultiplier * fxMultiplicand) + ROUNDING_FACTOR) >> __AMOUNT_OF_FRACTIONARY_BITS__);
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

      fixed_t SoftDecimal_floatMultiply(float fMultiplier, float fMultiplicand){
        __SOFT_DECIMAL_BUFFER_T__ fxbMultiply = (((SoftDecimal_toFixed(fMultiplier) * SoftDecimal_toFixed(fMultiplicand)) + ROUNDING_FACTOR) >> __AMOUNT_OF_FRACTIONARY_BITS__);
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

      fixed_t SoftDecimal_fixedDivide(fixed_t fxDivisor, fixed_t fxDividend){
        if (fxDividend == 0){
          bReachedLimitFlag = true;
          if (fxDivisor > 0){
            return __SOFT_DECIMAL_MAX_VALUE__;
          }
          else{
            return __SOFT_DECIMAL_MIN_VALUE__;
          }
        }
        __SOFT_DECIMAL_BUFFER_T__ fxbQuotient = ((fxDivisor << __AMOUNT_OF_FRACTIONARY_BITS__) + (fxDividend >> 1)) / fxDividend;
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

      fixed_t SoftDecimal_floatDivide(float fDividend, float fDivisor){
        if (fDividend == 0.0){
          bReachedLimitFlag = true;
          if (fDivisor > 0.0){
            return __SOFT_DECIMAL_MAX_VALUE__;
          }
          else{
            return __SOFT_DECIMAL_MIN_VALUE__;
          }
        }
        __SOFT_DECIMAL_BUFFER_T__ fxbQuotient = ((SoftDecimal_toFixed(fDivisor) << __AMOUNT_OF_FRACTIONARY_BITS__) + (SoftDecimal_toFixed(fDividend) >> 1)) / SoftDecimal_toFixed(fDividend);
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

  #else
    #error Invalid __AMOUNT_OF_FRACTIONARY_BITS__ value!
  #endif

#endif
