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

#ifndef __BITWISE_CLASS_HEADER__
  #define __BITWISE_CLASS_HEADER__

  #include <EmbeddedTools.h>

  #if defined(__BITWISE_MANAGER_ENABLE__)

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
      void (*set)(uint64_t* ui64Number, uint8_t ui8Position);                                                                                               /*!< void "method". */
      void (*clear)(uint64_t* ui64Number, uint8_t ui8Position);                                                                                             /*!< void "method". */
      void (*toggle)(uint64_t* ui64Number, uint8_t ui8Position);                                                                                            /*!< void "method". */
      bool (*read)(uint64_t ui64Number, uint8_t ui8Position);                                                                                               /*!< bool "method". */
      void (*copy)(uint64_t* ui64Destiny, uint8_t ui8DestinyBitPosition, uint64_t ui64Origin, uint8_t ui8OriginBitPosition);                                /*!< void "method". */
    } bitwise_bit_manager_t;

    //! Type Definition: bitwise_bits_manager_t
    /*!
      This is a "class" of bitwise_bits_manager_t type.
    */
    typedef struct {
      void (*set)(uint64_t* ui64Number, uint8_t ui8Position, uint8_t ui8AmountOfBits);                                                                      /*!< void "method". */
      void (*clear)(uint64_t* ui64Number, uint8_t ui8Position, uint8_t ui8AmountOfBits);                                                                    /*!< void "method". */
      void (*toggleAll)(uint64_t* ui64Number);                                                                                                              /*!< void "method". */
      uint8_t (*read)(uint64_t ui64Number, uint8_t ui8Position, uint8_t ui8AmountOfBits);                                                                   /*!< uint8_t "method". */
      void (*copy)(uint64_t* ui64Destiny, uint8_t ui8DestinyBitPosition, uint64_t ui64Origin, uint8_t ui8OriginBitPosition, uint8_t ui8AmountOfBits);       /*!< void "method". */
    } bitwise_bits_manager_t;

    //! Type Definition: bitwise_byte_manager_t
    /*!
      This is a "class" of bitwise_byte_manager_t type.
    */
    typedef struct {
      void (*set)(uint64_t* ui64Number, uint8_t ui8Position);                                                                                               /*!< void "method". */
      void (*clear)(uint64_t* ui64Number, uint8_t ui8Position);                                                                                             /*!< void "method". */
      uint8_t (*read)(uint64_t ui64Number, uint8_t ui8Position);                                                                                            /*!< uint8_t "method". */
      void (*copy)(uint64_t* ui64Destiny, uint8_t ui8DestinyBytePosition, uint64_t ui64Origin, uint8_t ui8OriginBytePosition);                              /*!< void "method". */
    } bitwise_byte_manager_t;

    //! Type Definition: bitwise_manager_t
    /*!
      This is a "class" of bitwise_manager_t type.
    */
    typedef struct {
      bitwise_bit_manager_t Bit;                                                                                                                            /*!< bitwise_bit_manager_t "object". */
      bitwise_bits_manager_t Bits;                                                                                                                          /*!< bitwise_bits_manager_t "object". */
      bitwise_byte_manager_t Byte;                                                                                                                          /*!< bitwise_byte_manager_t "object". */
    } bitwise_manager_t;

    #if defined(__AVR__)
      extern const bitwise_manager_t Bitwise PROGMEM;                                                                                                       /*!< Bitwise manager "object". */
    #else
      extern const bitwise_manager_t Bitwise;                                                                                                               /*!< Bitwise manager "object". */
    #endif

    #ifdef __cplusplus
      }
    #endif

  #endif
#endif