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

#ifndef __EMBEDDED_TOOLS_CONFIGS_HEADER__
  #define __EMBEDDED_TOOLS_CONFIGS_HEADER__

  #ifdef __cplusplus
    extern "C" {
  #endif
  
  //! Configuration: Attribute Macros
  /*!
    Enable system attribute macros here. The available values for this macro are:
      - __ATTRIBUTE_MACROS_ENABLE__
      - __ATTRIBUTE_MACROS_DISABLE__
  */
  #define __ATTRIBUTE_MACROS_ENABLE__
  
  //! Configuration: Attribute Macros
  /*!
    Enable priority for constructor and destructor attributes. . The available values for this macro are:
      - __PRIORITY_CONSTRUCTOR_DESTRUCTOR_ENABLE__
      - __PRIORITY_CONSTRUCTOR_DESTRUCTOR_DISABLE__
  */
  #define __PRIORITY_CONSTRUCTOR_DESTRUCTOR_DISABLE__

  //! Configuration: Bitwise Manager
  /*!
    Enable system bitwise manager here. The available values for this macro are:
      - __BITWISE_MANAGER_ENABLE__
      - __BITWISE_MANAGER_DISABLE__
  */
  #define __BITWISE_MANAGER_ENABLE__
  
  //! Configuration: SoftMath Manager
  /*!
    Enable system soft math manager here. The available values for this macro are:
      - __SOFT_MATH_MANAGER_ENABLE__
      - __SOFT_MATH_MANAGER_DISABLE__
  */
  #define __SOFT_MATH_MANAGER_ENABLE__

  //! Configuration: FixedPoint Manager
  /*!
    Configure system soft decimal manager here. The available values for this macro are:
      - __SOFT_DECIMAL_MANAGER_ENABLE__
      - __SOFT_DECIMAL_MANAGER_DISABLE__
  */
  #define __SOFT_DECIMAL_MANAGER_ENABLE__
  
  #if defined(__SOFT_DECIMAL_MANAGER_ENABLE__)

    //! FixedPoint: Amount of fixed_t Bits Macro
    /*!
      It's amount of bits used by fixed_t types. The available values for this macro are:
        - __SOFT_DECIMAL_SIZE_8_BIT__
        - __SOFT_DECIMAL_SIZE_16_BIT__
        - __SOFT_DECIMAL_SIZE_32_BIT__
    */
    #define __SOFT_DECIMAL_SIZE_16_BIT__

    //! FixedPoint: Amount of Fractionary fixed_t Bits Macro
    /*!
      It's amount of fractionary bits used by fixed_t types. Don't forget: this value must be smaller than amount of bits used by fixed_t types!
    */
    #define __SOFT_DECIMAL_AMOUNT_OF_FRACTIONARY_BITS__ 6

    //! FixedPoint: Use Infinite Arguments
    /*!
      Infinite arguments (stdarg.h) makes your program more elegant, but you should be cautious with your RAM. In projects with MISRA rules, this option must be disabled.
      The available values for this macro are:
        - __SOFT_DECIMAL_ENABLE_INFINITE_ARGUMENTS__
        - __SOFT_DECIMAL_DISABLE_INFINITE_ARGUMENTS__
    */
    #define __SOFT_DECIMAL_DISABLE_INFINITE_ARGUMENTS__
    
  #endif

  #ifdef __cplusplus
    }
  #endif

#endif
