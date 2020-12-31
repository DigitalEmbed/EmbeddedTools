//! EmbeddedTools Version 2.0b
/*!
  This code file was written by Jorge Henrique Moreira Santana and is under
  the GNU GPLv3 license. All legal rights are reserved.

  Permissions of this copyleft license are conditioned on making available
  complete source code of licensed works and modifications under the same
  license or the GNU GPLv3. Copyright and license notices must be preserved.
  Contributors provide an express grant of patent rights. However, a larger
  work using the licensed work through interfaces provided by the licensed
  work may be distributed under different terms and without source code for
  the larger work.

  * Permissions:
    -> Commercial use;
    -> Modification;
    -> Distribuition;
    -> Patent Use;
    -> Private Use;

  * Limitations:
    -> Liability;
    -> Warranty;

  * Conditions:
    -> License and copyright notice;
    -> Disclose source;
    -> State changes;
    -> Same license (library);

  For more informations, check the LICENSE document. If you want to use a
  commercial product without having to provide the source code, send an email
  to jorge_henrique_123@hotmail.com to talk.
*/

#ifndef __SOFT_DECIMAL_HEADER__
  #define __SOFT_DECIMAL_HEADER__

  #include "./Configs.h"

  #if defined(__SOFT_DECIMAL_MANAGER_ENABLE__)

    #ifdef __cplusplus
      extern "C" {
    #endif

    #include <stdint.h>
    #include <stdbool.h>
    #include <stdarg.h>

    //! Macro: fixed_t Macros
    /*!
      This macros are for facilitate the use of this library.
    */
    #if defined(__SOFT_DECIMAL_SIZE_8_BIT__)
      typedef int8_t fixed_t;
      typedef int16_t __SOFT_DECIMAL_BUFFER_T__;
      #define __SOFT_DECIMAL_MAX_VALUE__                      INT8_MAX
      #define __SOFT_DECIMAL_MIN_VALUE__                      INT8_MIN
      #define __AUTO_SIZE_LIST_TYPE__                         int16_t
    #elif defined(__SOFT_DECIMAL_SIZE_16_BIT__)
      typedef int16_t fixed_t;
      typedef int32_t __SOFT_DECIMAL_BUFFER_T__;
      #define __SOFT_DECIMAL_MAX_VALUE__                      INT16_MAX
      #define __SOFT_DECIMAL_MIN_VALUE__                      INT16_MIN
      #define __AUTO_SIZE_LIST_TYPE__                         fixed_t
    #elif defined(__SOFT_DECIMAL_SIZE_32_BIT__)
      typedef int32_t fixed_t;
      typedef int64_t __SOFT_DECIMAL_BUFFER_T__;
      #define __SOFT_DECIMAL_MAX_VALUE__                      INT32_MAX
      #define __SOFT_DECIMAL_MIN_VALUE__                      INT32_MIN
      #define __AUTO_SIZE_LIST_TYPE__                         fixed_t
    #endif

    //! Macro: fixed_t Type Constructor
    /*!
      Creates a fixed_t number.
      \param fxNumberName is a name of variable.
      \param fNumber is a float number.
    */
    #define newSoftDecimal(fxNumberName, fNumber)\
      fixed_t (fxNumberName) = ((fixed_t) (((float) fNumber) * (float)((uint32_t) 1 << (__SOFT_DECIMAL_AMOUNT_OF_FRACTIONARY_BITS__))))

    //! Macro: Float to Fixed Converter
    /*!
      Converts a float number to fixed_t type.
      \param fNumber is a float number.
      \return Returns the fixed_t number.
    */
    #define SoftDecimal_toFixed(fNumber)\
      ((fixed_t) (((float) fNumber) * (float)((uint32_t) 1 << (__SOFT_DECIMAL_AMOUNT_OF_FRACTIONARY_BITS__))))
    
    //! Macro: Fixed to Float Converter
    /*!
      Converts a fixed_t number to float type.
      \param fxNumber is a fixed_t number.
      \return Returns the fixed_t number.
    */
    #define SoftDecimal_toFloat(fxNumber)\
      ((float) ((fxNumber) / (float) ((uint32_t) 1 << (__SOFT_DECIMAL_AMOUNT_OF_FRACTIONARY_BITS__))))
    
    //! Macro: Fixed to Integer Converter
    /*!
      Converts a fixed_t number to int type.
      \param fxNumber is a fixed_t number.
      \return Returns the integer number.
    */
    #define SoftDecimal_toInt(fxNumber)\
      ((fxNumber) >> __SOFT_DECIMAL_AMOUNT_OF_FRACTIONARY_BITS__)

    #if defined (__SOFT_DECIMAL_ENABLE_INFINITE_ARGUMENTS__)

      //! Macro: Auto iAmountOfNumbers Calculator
      /*!
        These macros are for facilitate the use of this library.
      */
      #define SoftDecimal_floatSum(...)\
        SoftDecimal_floatSum(sizeof((float []) {__VA_ARGS__}) / sizeof(float), __VA_ARGS__)
      
      #define SoftDecimal_fixedSum(...)\
        SoftDecimal_fixedSum(sizeof((__AUTO_SIZE_LIST_TYPE__ []) {__VA_ARGS__}) / sizeof(__AUTO_SIZE_LIST_TYPE__), __VA_ARGS__)
      
      #define SoftDecimal_floatSubtract(...)\
        SoftDecimal_floatSubtract(sizeof((float []) {__VA_ARGS__}) / sizeof(float), __VA_ARGS__)

      #define SoftDecimal_fixedSubtract(...)\
        SoftDecimal_fixedSubtract(sizeof((__AUTO_SIZE_LIST_TYPE__ []) {__VA_ARGS__}) / sizeof(__AUTO_SIZE_LIST_TYPE__), __VA_ARGS__)

      #define SoftDecimal_floatMultiply(...)\
        SoftDecimal_floatMultiply(sizeof((float []) {__VA_ARGS__}) / sizeof(float), __VA_ARGS__)

      #define SoftDecimal_fixedMultiply(...)\
        SoftDecimal_fixedMultiply(sizeof((__AUTO_SIZE_LIST_TYPE__ []) {__VA_ARGS__}) / sizeof(__AUTO_SIZE_LIST_TYPE__), __VA_ARGS__)
      
      #define SoftDecimal_floatDivide(...)\
        SoftDecimal_floatDivide(sizeof((float []) {__VA_ARGS__}) / sizeof(float), __VA_ARGS__)
      
      #define SoftDecimal_fixedDivide(...)\
        SoftDecimal_fixedDivide(sizeof((__AUTO_SIZE_LIST_TYPE__ []) {__VA_ARGS__}) / sizeof(__AUTO_SIZE_LIST_TYPE__), __VA_ARGS__)

      fixed_t (SoftDecimal_fixedSum)(long int iAmountOfNumbers, ...);                           /*!< fixed_t type function. */
      fixed_t (SoftDecimal_floatSum)(long int iAmountOfNumbers, ...);                           /*!< fixed_t type function. */
      fixed_t (SoftDecimal_fixedSubtract)(long int iAmountOfNumbers, ...);                      /*!< fixed_t type function. */
      fixed_t (SoftDecimal_floatSubtract)(long int iAmountOfNumbers, ...);                      /*!< fixed_t type function. */
      fixed_t (SoftDecimal_fixedMultiply)(long int iAmountOfNumbers, ...);                      /*!< fixed_t type function. */
      fixed_t (SoftDecimal_floatMultiply)(long int iAmountOfNumbers, ...);                      /*!< fixed_t type function. */
      fixed_t (SoftDecimal_fixedDivide)(long int iAmountOfNumbers, ...);                        /*!< fixed_t type function. */
      fixed_t (SoftDecimal_floatDivide)(long int iAmountOfNumbers, ...);                        /*!< fixed_t type function. */

    #else

      fixed_t SoftDecimal_fixedSum(fixed_t fxAddendA, fixed_t fxAddendB);                       /*!< fixed_t type function. */
      fixed_t SoftDecimal_floatSum(float fAddendA, float fAddendB);                             /*!< fixed_t type function. */
      fixed_t SoftDecimal_fixedSubtract(fixed_t fxMinuendo, fixed_t fxSubtrahend);              /*!< fixed_t type function. */
      fixed_t SoftDecimal_floatSubtract(float fMinuendo, float fSubtrahend);                    /*!< fixed_t type function. */
      fixed_t SoftDecimal_fixedMultiply(fixed_t fxMultiplier, fixed_t fxMultiplicand);          /*!< fixed_t type function. */
      fixed_t SoftDecimal_floatMultiply(float fMultiplier, float fMultiplicand);                /*!< fixed_t type function. */
      fixed_t SoftDecimal_fixedDivide(fixed_t fxDividend, fixed_t fxDivisor);                   /*!< fixed_t type function. */
      fixed_t SoftDecimal_floatDivide(float fDividend, float fDivisor);                         /*!< fixed_t type function. */

    #endif

    float SoftDecimal_getMinimumValue(void);                                                    /*!< float type function. */
    float SoftDecimal_getMaximumValue(void);                                                    /*!< float type function. */
    float SoftDecimal_getResolution(void);                                                      /*!< float type function. */
    bool SoftDecimal_error(void);                                                               /*!< boolean type function. */

    #ifdef __cplusplus
      }
    #endif

  #endif
#endif
