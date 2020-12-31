#include "../EmbeddedTools/EmbeddedTools.h"

#if defined(__BITWISE_MANAGER_ENABLE__)

  #include "./Bitwise.h"

  /*!
    Prototype public Bit "methods".
  */
  void __Bitwise_Bit_set(uint64_t* ui64Number, uint8_t ui8Position);
  void __Bitwise_Bit_clear(uint64_t* ui64Number, uint8_t ui8Position);
  void __Bitwise_Bit_toggle(uint64_t* ui64Number, uint8_t ui8Position);
  bool __Bitwise_Bit_read(uint64_t ui64Number, uint8_t ui8Position);
  void __Bitwise_Bit_copy(uint64_t* ui64Destiny, uint8_t ui8DestinyBitPosition, uint64_t ui64Origin, uint8_t ui8OriginBitPosition);

  /*!
    Prototype public Bits "methods".
  */
  void __Bitwise_Bits_set(uint64_t* ui64Number, uint8_t ui8Position, uint8_t ui8AmountOfBits);
  void __Bitwise_Bits_clear(uint64_t* ui64Number, uint8_t ui8Position, uint8_t ui8AmountOfBits);
  void __Bitwise_Bits_toggleAll(uint64_t* ui64Number);
  uint8_t __Bitwise_Bits_read(uint64_t ui64Number, uint8_t ui8Position, uint8_t ui8AmountOfBits);
  void __Bitwise_Bits_copy(uint64_t* ui64Destiny, uint8_t ui8DestinyBitPosition, uint64_t ui64Origin, uint8_t ui8OriginBitPosition, uint8_t ui8AmountOfBits);

  /*!
    Prototype public Byte "methods".
  */
  void __Bitwise_Byte_set(uint64_t* ui64Number, uint8_t ui8Position);
  void __Bitwise_Byte_clear(uint64_t* ui64Number, uint8_t ui8Position);
  uint8_t __Bitwise_Byte_read(uint64_t ui64Number, uint8_t ui8Position);
  void __Bitwise_Byte_copy(uint64_t* ui64Destiny, uint8_t ui8DestinyBytePosition, uint64_t ui64Origin, uint8_t ui8OriginBytePosition);

  /*!
    Bitwise object "constructor".
  */
  #if defined(__AVR__)
    const bitwise_manager_t Bitwise PROGMEM = {                             /*!< Bitwise manager "object". */
  #else
    const bitwise_manager_t Bitwise = {                                     /*!< Bitwise manager "object". */
  #endif
    .Bit = {
      .set = &__Bitwise_Bit_set,
      .clear = &__Bitwise_Bit_clear,
      .toggle = &__Bitwise_Bit_toggle,
      .read = &__Bitwise_Bit_read,
      .copy = &__Bitwise_Bit_copy,
    },
    .Bits = {
      .set = &__Bitwise_Bits_set,
      .clear = &__Bitwise_Bits_clear,
      .toggleAll = &__Bitwise_Bits_toggleAll,
      .read = &__Bitwise_Bits_read,
      .copy = &__Bitwise_Bits_copy,
    },
    .Byte = {
      .set = &__Bitwise_Byte_set,
      .clear = &__Bitwise_Byte_clear,
      .read = &__Bitwise_Byte_read,
      .copy = &__Bitwise_Byte_copy,
    }
  };

  //! Public Method: Set a Bit
  /*!
    Set a bit of a number.
  */
  void __Bitwise_Bit_set(uint64_t* ui64Number, uint8_t ui8Position){
    Bitwise_setBit((*ui64Number), (ui8Position));
  }

  //! Public Method: Erase a Bit
  /*!
    Erase a bit of a number.
  */
  void __Bitwise_Bit_clear(uint64_t* ui64Number, uint8_t ui8Position){
    Bitwise_clearBit((*ui64Number), (ui8Position));
  }

  //! Public Method: Invert a Bit
  /*!
    Invert a bit of a number.
  */
  void __Bitwise_Bit_toggle(uint64_t* ui64Number, uint8_t ui8Position){
    Bitwise_toggleBit((*ui64Number), (ui8Position));
  }

  //! Public Method: Read a Bit
  /*!
    Read a bit of a number.
  */
  bool __Bitwise_Bit_read(uint64_t ui64Number, uint8_t ui8Position){
    return Bitwise_readBit((ui64Number), (ui8Position));
  }

  //! Public Method: Copy Bits
  /*!
    Copy a bit from a number and paste them into another number.
  */
  void __Bitwise_Bit_copy(uint64_t* ui64Destiny, uint8_t ui8DestinyBitPosition, uint64_t ui64Origin, uint8_t ui8OriginBitPosition){
    Bitwise_copyBit((*(ui64Destiny)), (ui8DestinyBitPosition), (ui64Origin), (ui8OriginBitPosition));
  }

  //! Public Method: Set Bits
  /*!
    Set several bits of a number.
  */
  void __Bitwise_Bits_set(uint64_t* ui64Number, uint8_t ui8Position, uint8_t ui8AmountOfBits){
    Bitwise_setBits((*ui64Number), (ui8Position), (ui8AmountOfBits));
  }

  //! Public Method: Erase Bits
  /*!
    Erase several bits of a number.
  */
  void __Bitwise_Bits_clear(uint64_t* ui64Number, uint8_t ui8Position, uint8_t ui8AmountOfBits){
    Bitwise_clearBits((*ui64Number), (ui8Position), (ui8AmountOfBits));
  }

  //! Public Method: Invert All Bits
  /*!
    Invert all bits of a number.
  */
  void __Bitwise_Bits_toggleAll(uint64_t* ui64Number){
    Bitwise_toggleAllBits((*ui64Number));
  }

  //! Public Method: Read Bits
  /*!
    Returns a selection of bits of a number.
  */
  uint8_t __Bitwise_Bits_read(uint64_t ui64Number, uint8_t ui8Position, uint8_t ui8AmountOfBits){
    return Bitwise_readBits((ui64Number), (ui8Position), (ui8AmountOfBits));
  }

  //! Public Method: Copy Bits
  /*!
    Copy bits from a number and paste them into another number.
  */
  void __Bitwise_Bits_copy(uint64_t* ui64Destiny, uint8_t ui8DestinyBitPosition, uint64_t ui64Origin, uint8_t ui8OriginBitPosition, uint8_t ui8AmountOfBits){
    Bitwise_copyBits((*(ui64Destiny)), (ui8DestinyBitPosition), (ui64Origin), (ui8OriginBitPosition), (ui8AmountOfBits));
  }

  //! Public Method: Set a Byte
  /*!
    Set a byte of a number.
  */
  void __Bitwise_Byte_set(uint64_t* ui64Number, uint8_t ui8Position){
    Bitwise_setByte((*ui64Number), (ui8Position));
  }

  //! Public Method: Erase a Byte
  /*!
    Erase a byte of a number.
  */
  void __Bitwise_Byte_clear(uint64_t* ui64Number, uint8_t ui8Position){
    Bitwise_clearByte((*ui64Number), (ui8Position));
  }

  //! Public Method: Read a Byte
  /*!
    Read a byte of a number.
  */
  uint8_t __Bitwise_Byte_read(uint64_t ui64Number, uint8_t ui8Position){
    return Bitwise_readByte((ui64Number), (ui8Position));
  }

  //! Public Method: Copy Byte
  /*!
    Copy a byte from a number and paste them into another number.
  */
  void __Bitwise_Byte_copy(uint64_t* ui64Destiny, uint8_t ui8DestinyBytePosition, uint64_t ui64Origin, uint8_t ui8OriginBytePosition){
    Bitwise_copyByte((*(ui64Destiny)), (ui8DestinyBytePosition), (ui64Origin), (ui8OriginBytePosition));
  }

#endif
