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

#ifndef __BITWISE_HEADER__
  #define __BITWISE_HEADER__

  //! Macro: Set a Bit
  /*!
    Set a bit of a number.
    \param uiNumber is an undefined parameter.It is the number that will have it bit seted.
    \param uiPosition is an undefined parameter. Position 0 is the least significant bit in the number.
  */
  #define Bitwise_setBit(uiNumber, uiPosition)\
    (uiNumber) |= (1 << (uiPosition))

  //! Macro: Set Bits
  /*!
    Set several bits of a number.
    \param uiNumber is an undefined parameter. It is the number that will have your bits seted.
    \param uiPosition is an undefined parameter. Position 0 is the least significant bit in the number.
    \param uiNumberOfBits is an undefined parameter. It is the number of bits that will be set.
  */
  #define Bitwise_setBits(uiNumber, uiPosition, uiNumberOfBits)\
    (uiNumber) |= ((uiNumberOfBits) << (uiPosition))

  //! Macro: Set a Byte
  /*!
    Set a byte of a number.
    \param uiNumber is an undefined parameter. It is the number that will have it byte seted.
    \param uiPosition is an undefined parameter. Position 0 is the least significant bit in the number.
  */
  #define Bitwise_setByte(uiNumber, uiPosition)\
    (uiNumber) |= (255 << ((uiPosition) << 3))


  //! Macro: Erase a Bit
  /*!
    Erase a bit of a number.
    \param uiNumber É um parâmetro indefinido. É o número que terá seu bit apagado.
  */
  #define Bitwise_clearBit(uiNumber, uiPosition)\
    (uiNumber) &= ~(1 << (uiPosition))

  //! Macro: Erase Bits
  /*!
    Erase several bits of a number.
    \param uiNumber is an undefined parameter. It is the number that will have your bits erased.
    \param uiPosition is an undefined parameter. Position 0 is the least significant number in the number.
    \param uiNumberOfBits is an undefined parameter. It is the number of bits that will be erase.
  */
  #define Bitwise_clearBits(uiNumber, uiPosition, uiNumberOfBits)\
    (uiNumber) &= ~(((1 << (uiNumberOfBits)) - 1) << (uiPosition))

  //! Macro: Erase a Byte
  /*!
    Erase a byte of a number.
    \param uiNumber is an undefined parameter. It is the number that will have it byte deleted.
    \param uiPosition is an undefined parameter. Position 0 is the least significant bit in the number.
  */
  #define Bitwise_clearByte(uiNumber, uiPosition)\
    (uiNumber) &= ~(255 << ((uiPosition) << 3))

  //! Macro: Read a Bit
  /*!
    Read a bit of a number.
    \param uiNumber is an undefined parameter. It is the number that will have it bit readed.
    \param uiPosition is an undefined parameter. Position 0 is the least significant bit in the number.
    \return "Returns" the bit readed.
  */
  #define Bitwise_readBit(uiNumber, uiPosition)\
    (((uiNumber) >> (uiPosition)) & 1)

  //! Macro: Read Bits
  /*!
    Returns a selection of bits of a number.
    \param uiNumber is an undefined parameter. It is the number that will have your bits selected.
    \param uiPositionByte is an undefined parameter. Position 0 is the least significant bit in the number.
    \param uiNumberOfBits It is an undefined parameter. It is the number of bits that will be erased.
    \return "Returns" bit selection of the "uiNumber" parameter.
  */
  #define Bitwise_readBits(uiNumber, uiPosition, uiNumberOfBits)\
    ((((1 << (uiNumberOfBits)) - 1) << (uiPosition)) & (uiNumber))

  //! Macro: Read a Byte
  /*!
    Read a byte of a number.
    \param uiNumber is an undefined parameter. It is the number that will have it byte readed.
    \param uiPosition is an undefined parameter. Position 0 is the least significant bit in the number.
    \return "Returns" the byte readed.
  */
  #define Bitwise_readByte(uiNumber, uiPosition)\
    (((uiNumber) >> ((uiPosition) << 3)) & 255)

  //! Macro: Invert a Bit
  /*!
    Invert a bit of a number.
    \param uiNumber is an undefined parameter. It is the number that will have it bit inverted.
    \param uiPosition is an undefined parameter. Position 0 is the least significant bit in the number.
  */
  #define Bitwise_toggleBit(uiNumber, uiPosition)\
    (uiNumber) ^= (1 << (uiPosition))

  //! Macro: Invert All Bits
  /*!
    Reverses all bits of a number.
    \param uiNumber is an undefined parameter. It is the number that will have its bits inverted.
  */
  #define Bitwise_toggleAllBits(uiNumber)\
    (uiNumber) = ~(uiNumber) + 1

  //! Macro: Copy Bits
  /*!
    Copy bits from one number and paste them into another number.
    \param uiDestiny is an undefined parameter. It is the number that will have its bits replaced.
    \param uiDestinyBitPosition is an undefined parameter. Position 0 is the least significant digit of the "uiDestiny" parameter.
    \param uiNumber is an undefined parameter. It is the number that will have your bits selected.
    \param uiDestinyBitPosition is an undefined parameter. Position 0 is the least significant digit of the "uiNumber" parameter.
    \param uiNumberOfBits It is an undefined parameter. It is the bit_numberOfBits that will be copied.
  */
  #define Bitwise_copyBits(uiDestiny, uiDestinyBitPosition, uiNumber, uiNumberBitPosition, uiNumberOfBits)\
    Bitwise_clearBits((uiDestiny), (uiDestinyBitPosition), (uiNumberOfBits));\
    (uiDestiny) |= (((Bitwise_readBits((uiNumber), (uiNumberBitPosition), (uiNumberOfBits))) >> (uiNumberBitPosition)) << (uiDestinyBitPosition));

  //! Macro: Copy a Byte
  /*!
    Copy a Byte from a number and paste it into another number.
    \param uiDestiny is an undefined parameter. It is the number that will have its bits replaced.
    \param uiDestinyBytePosition is an undefined parameter. Position 0 is the byte that contains the least significant digit of the "uiDestiny" parameter.
    \param uiNumber is an undefined parameter. It is the number that will have your bits selected.
    \param uiDestinyBytePosition is an undefined parameter. Position 0 is the byte that contains the least significant digit of the "uiNumber" parameter.
  */
  #define Bitwise_copyByte(uiDestiny, uiDestinyBytePosition, uiNumber, uiNumberBytePosition)\
    Bitwise_clearByte((uiDestiny), (uiDestinyBytePosition));\
    (uiDestiny) |= (((uiNumber >> ((uiNumberBytePosition) << 3)) & 255) << (((uiDestinyBytePosition) << 3)))

#endif
