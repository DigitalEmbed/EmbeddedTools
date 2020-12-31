#include <EmbeddedTools.h>

#if defined(__SOFT_MATH_MANAGER_ENABLE__)

  #include "./SoftMath.h"

  /*!
    Prototype public Bit "methods".
  */
  int64_t __SoftMath_negative(int32_t i32Number);                                       /*!< int64_t "method". */
  uint64_t __SoftMath_module(int64_t i64Number);                                        /*!< uint64_t "method". */
  int64_t __SoftMath_twice(int64_t i64Number);                                          /*!< int64_t "method". */
  int64_t __SoftMath_half(int64_t i64Half);                                             /*!< int64_t "method". */
  int64_t __SoftMath_multiply(int64_t i64Number, uint16_t ui16ExpoentOfTwo);            /*!< int64_t "method". */
  int64_t __SoftMath_divide(int64_t i64Number, uint16_t ui16ExpoentOfTwo);              /*!< int64_t "method". */
  int64_t __SoftMath_divisionRest(int64_t i64Number, uint16_t ui16ExpoentOfTwo);        /*!< int64_t "method". */
  int64_t __SoftMath_bigger(int64_t i64NumberA, int64_t i64NumberB);                    /*!< int64_t "method". */
  int64_t __SoftMath_smaller(int64_t i64NumberA, int64_t i64NumberB);                   /*!< int64_t "method". */
  
  /*!
    Bitwise object "constructor".
  */
  #if defined(__AVR__)
    const softmath_manager_t SoftMath PROGMEM = {                                       /*!< Bitwise manager "object". */
  #else
    const softmath_manager_t SoftMath = {                                               /*!< Bitwise manager "object". */
  #endif
    .negative = &__SoftMath_negative,
    .module = &__SoftMath_module,
    .twice = &__SoftMath_twice,
    .half = &__SoftMath_half,
    .multiply = &__SoftMath_multiply,
    .divide = &__SoftMath_divide,
    .divisionRest = &__SoftMath_divisionRest,
    .bigger = &__SoftMath_bigger,
    .smaller = &__SoftMath_smaller,
  };

  //! Public Method: Negative
  /*!
    Negative a number.
  */
  int64_t __SoftMath_negative(int32_t i32Number){
    return SoftMath_negative(i32Number);
  }

  //! Public Method: Module
  /*!
    Calculates the magnitude of a number.
  */
  uint64_t __SoftMath_module(int64_t i64Number){
    return SoftMath_module(i64Number);
  }

  //! Public Method: Double
  /*!
    Calculates double a number.
  */
  int64_t __SoftMath_twice(int64_t i64Number){
    return SoftMath_double(i64Number);
  }

  //! Public Method: Half
  /*!
    Calculates half a number.
  */
  int64_t __SoftMath_half(int64_t i64Half){
    return SoftMath_half(i64Half);
  }

  //! Public Method: Multiplication
  /*!
    Multiply one number by another.
  */
  int64_t __SoftMath_multiply(int64_t i64Number, uint16_t ui16ExpoentOfTwo){
    return SoftMath_multiply(i64Number, ui16ExpoentOfTwo);
  }

  //! Public Method: Division
  /*!
    Divide one number by another.
  */
  int64_t __SoftMath_divide(int64_t i64Number, uint16_t ui16ExpoentOfTwo){
    return SoftMath_divide(i64Number, ui16ExpoentOfTwo);
  }

  //! Public Method: Rest of Division
  /*!
    Calculates the rest of division of one number by another.
  */
  int64_t __SoftMath_divisionRest(int64_t i64Number, uint16_t ui16ExpoentOfTwo){
    return SoftMath_divisionRest(i64Number, ui16ExpoentOfTwo);
  }

  //! Public Method: Larger
  /*!
    Checks the largest of two numbers.
  */
  int64_t __SoftMath_bigger(int64_t i64NumberA, int64_t i64NumberB){
    return SoftMath_bigger(i64NumberA, i64NumberB);
  }

  //! Public Method: Minor
  /*!
    Checks the smallest of two numbers.
  */
  int64_t __SoftMath_smaller(int64_t i64NumberA, int64_t i64NumberB){
    return SoftMath_smaller(i64NumberA, i64NumberB);
  }

#endif