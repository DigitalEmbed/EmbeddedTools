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

#ifndef __SOFT_MATH_CLASS_HEADER__
  #define __SOFT_MATH_CLASS_HEADER__

  #include <EmbeddedTools.h>

  #if defined(__SOFT_MATH_MANAGER_ENABLE__)

    #ifdef __cplusplus
      extern "C" {
    #endif

    #if defined(__AVR__)
      #include <avr/pgmspace.h>
    #endif

    //! Type Definition: bitwise_bit_manager_t
    /*!
      This is a "class" of bitwise_bit_manager_t type.
    */
    typedef struct {
      int64_t (*negative)(int32_t i32Number);                                       /*!< int64_t "method". */
      uint64_t (*module)(int64_t i64Number);                                        /*!< uint64_t "method". */
      int64_t (*twice)(int64_t i64Number);                                          /*!< int64_t "method". */
      int64_t (*half)(int64_t i64Half);                                             /*!< int64_t "method". */
      int64_t (*multiply)(int64_t i64Number, uint16_t ui16ExpoentOfTwo);            /*!< int64_t "method". */
      int64_t (*divide)(int64_t i64Number, uint16_t ui16ExpoentOfTwo);              /*!< int64_t "method". */
      int64_t (*divisionRest)(int64_t i64Number, uint16_t ui16ExpoentOfTwo);        /*!< int64_t "method". */
      int64_t (*bigger)(int64_t i64NumberA, int64_t i64NumberB);                    /*!< int64_t "method". */
      int64_t (*smaller)(int64_t i64NumberA, int64_t i64NumberB);                   /*!< int64_t "method". */
    } softmath_manager_t;

    #if defined(__AVR__)
      extern const softmath_manager_t SoftMath PROGMEM;                                                                                                       /*!< Bitwise manager "object". */
    #else
      extern const softmath_manager_t SoftMath;                                                                                                               /*!< Bitwise manager "object". */
    #endif

    #ifdef __cplusplus
      }
    #endif

  #endif
#endif