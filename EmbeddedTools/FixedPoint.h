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

#ifndef __FIXED_POINT_HEADER__
#define __FIXED_POINT_HEADER__

#ifdef __cplusplus
  extern "C" {
#endif

#include <stdint.h>
#include <stdarg.h>
#include <math.h>
#include "./Configs.h"

//! Macro: fixed_t Macros
/*!
  This macros are for facilitate the use of this library.
*/
#if defined(__FIXED_SIZE_8_BIT__)
    typedef int8_t fixed_t;
    typedef int16_t __FIXED_BUFFER_T__;
    #define __FIXED_MAX_VALUE__                                     INT8_MAX
    #define __FIXED_MIN_VALUE__                                     INT8_MIN
#elif defined(__FIXED_SIZE_16_BIT__)
    typedef int16_t fixed_t;
    typedef int32_t __FIXED_BUFFER_T__;
    #define __FIXED_MAX_VALUE__                                     INT16_MAX
    #define __FIXED_MIN_VALUE__                                     INT16_MIN
#elif defined(__FIXED_SIZE_32_BIT__)
    typedef int32_t fixed_t;
    typedef int64_t __FIXED_BUFFER_T__;
    #define __FIXED_MAX_VALUE__                                     INT32_MAX
    #define __FIXED_MIN_VALUE__                                     INT32_MIN
#endif

//! Macro: fixed_t Type Abrangency
/*!
  These macros are for facilitate the use of this library.
*/
#define Fixed_getMinimumValue()                                     -((uint32_t) 1 << ((((uint8_t) sizeof(fixed_t)) << 3) - __AMOUNT_OF_FRACTIONARY_BITS__ - 1))
#define Fixed_getResolution()                                       pow(2, -(__AMOUNT_OF_FRACTIONARY_BITS__ - 1))
#define Fixed_getMaximumValue()                                     (-Fixed_getMinimumValue() - Fixed_getResolution())

//! Macro: fixed_t Type Constructor
/*!
  These macros are for facilitate the use of this library.
*/
#define newFixed(fNumber)                                           ((fixed_t) (((float) fNumber) * (float)((uint32_t) 1 << (__AMOUNT_OF_FRACTIONARY_BITS__))))

//! Macro: fixed_t Type Convertions
/*!
  These macros are for facilitate the use of this library.
*/
#define Fixed_toFixed(fNumber)                                      newFixed(fNumber)
#define Fixed_toFloat(fxNumber)                                     ((float) ((fxNumber) / (float) ((uint32_t) 1 << (__AMOUNT_OF_FRACTIONARY_BITS__))))
#define Fixed_toInt(fxNumber)                                       ((fxNumber) >> __AMOUNT_OF_FRACTIONARY_BITS__)

//! Macro: Auto iAmountOfNumbers Calculator
/*!
  These macros are for facilitate the use of this library.
*/
#define Fixed_sum(...)                                              Fixed_sum(sizeof((int32_t []) {__VA_ARGS__}) / sizeof(int32_t), __VA_ARGS__)
#define Fixed_multiply(...)                                         Fixed_multiply(sizeof((int32_t []) {__VA_ARGS__}) / sizeof(int32_t), __VA_ARGS__)
#define Fixed_divide(...)                                           Fixed_divide(sizeof((int32_t []) {__VA_ARGS__}) / sizeof(int32_t), __VA_ARGS__)

fixed_t (Fixed_sum)(long int iAmountOfNumbers, ...);                /*!< fixed_t type function. */
fixed_t (Fixed_multiply)(long int iAmountOfNumbers, ...);           /*!< fixed_t type function. */
fixed_t (Fixed_divide)(long int iAmountOfNumbers, ...);             /*!< fixed_t type function. */

#ifdef __cplusplus
  }
#endif

#endif
