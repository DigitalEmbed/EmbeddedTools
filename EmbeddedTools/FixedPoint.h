//! EmbeddedTools Version 1.0b
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

#ifndef FixedPoint_H
#define FixedPoint_H

#ifdef __cplusplus
  extern "C" {
#endif

#include "EmbeddedTools.h"

//#define FIXED_SIZE_8_BIT
//#define FIXED_SIZE_16_BIT
#define FIXED_SIZE_32_BIT

#define AMOUNT_OF_FRACTIONARY_BITS                                  21

#if defined(FIXED_SIZE_8_BIT)
    #define fixed_t                                                 int8_t
    #define fixed_buffer_t                                          int16_t
    #define FIXED_MAX_VALUE                                         INT8_MAX
    #define FIXED_MIN_VALUE                                         INT8_MIN
#elif defined(FIXED_SIZE_16_BIT)
    #define fixed_t                                                 int16_t
    #define fixed_buffer_t                                          int32_t
    #define FIXED_MAX_VALUE                                         INT16_MAX
    #define FIXED_MIN_VALUE                                         INT16_MIN
#elif defined(FIXED_SIZE_32_BIT)
    #define fixed_t                                                 int32_t
    #define fixed_buffer_t                                          int64_t
    #define FIXED_MAX_VALUE                                         INT32_MAX
    #define FIXED_MIN_VALUE                                         INT32_MIN
#endif

#define uiRoundingFactor                                            (1 << (AMOUNT_OF_FRACTIONARY_BITS - 1))

#define uiGetFixedMinimumNumber()                                   -(1 << ((((uint8_t) sizeof(fixed_t)) << 3) - AMOUNT_OF_FRACTIONARY_BITS - 1))
#define fGetFixedResolution()                                       pow(2, -(AMOUNT_OF_FRACTIONARY_BITS - 1))
#define fGetFixedMaximumNumber()                                    (-uiGetFixedMinimumNumber() - fGetFixedResolution())

#define fxFloatToFixed(fNumber)                                     ((fixed_t) ((fNumber) * (float)(1 << (AMOUNT_OF_FRACTIONARY_BITS))))
#define fFixedToFloat(fxNumber)                                     ((float) ((fxNumber) / (float) (1 << (AMOUNT_OF_FRACTIONARY_BITS))))
#define uiFixedToInt(fxNumber)                                      ((fxNumber) >> AMOUNT_OF_FRACTIONARY_BITS)

#define fxFixedAdd(...)                                             fxFixedAdd(sizeof((int []) {__VA_ARGS__}) / sizeof(int), __VA_ARGS__)
#define fxFixedMultiply(...)                                        fxFixedMultiply(sizeof((int []) {__VA_ARGS__}) / sizeof(int), __VA_ARGS__)
#define fxFixedDivide(...)                                          fxFixedDivide(sizeof((int []) {__VA_ARGS__}) / sizeof(int), __VA_ARGS__)

fixed_t (fxFixedAdd)(int iAmountOfNumbers, ...);
fixed_t (fxFixedMultiply)(int iAmountOfNumbers, ...);
fixed_t (fxFixedDivide)(int iAmountOfNumbers, ...);

#ifdef __cplusplus
  }
#endif

#endif
