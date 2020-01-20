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

#ifndef __BIT_VECTOR_HEADER__
  #define __BIT_VECTOR_HEADER__

  #include <stdint.h>
  #include "./Bitwise.h"

  //! Type Definition: bitvector_t
  /*!
    This typedef exist for organization purpose. This type is equivalent of a 8-bit unsigned integer.
  */
  typedef uint8_t bitvector_t;

  //! Macro: Static Bit Vector Allocation
  /*!
    This macro is for calculate the iNumber of cell of bit-vectors type.
  */
  #define       BitVector_getSize(uiNumberOfBits)                                 (((uiNumberOfBits) < 8) ? 1 : (((uiNumberOfBits - 1) >> 3) + 1))

  //! Macros: Bit Vector Position Calculus
  /*!
    These macros are for calculate the uiPosition of cell of bit-vectors type and the bit uiPosition of iNumber of cell.
  */
  #define       BitVector_getBitPosition(uiPosition)                              ((BitVector_getSize(uiPosition)) - (1))
  #define       BitVector_getBytePosition(uiPosition)                             ((uiPosition) & (7))

  //! Macros: Bit Vector Manipulation
  /*!
    These macros are for calculate the iNumber of cell of bit-vectors type.
  */
  #define       BitVector_setBit(bvBitVector, uiPosition)                         Bitwise_setBit(bvBitVector[(BitVector_getBitPosition(uiPosition))], (BitVector_getBytePosition(uiPosition)))
  #define       BitVector_clearBit(bvBitVector, uiPosition)                       Bitwise_clearBit(bvBitVector[(BitVector_getBitPosition(uiPosition))], (BitVector_getBytePosition(uiPosition)))
  #define       BitVector_readBit(bvBitVector, uiPosition)                        Bitwise_readBit(bvBitVector[(BitVector_getBitPosition(uiPosition))], (BitVector_getBytePosition(uiPosition)))

  //! Macros: Bit Vector Creation
  /*!
    This macro creates a bit vectors.
  */
  #define       newBitVector(bvName, uiSize)                                      bitvector_t bvName[BitVector_getSize(uiSize)] = {0}

#endif
