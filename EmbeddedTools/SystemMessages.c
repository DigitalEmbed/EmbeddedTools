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

#include "./Configs.h"

//! System Message: Attribute Macro Status
/*!
  Please don't modify this.
*/
#if !defined(__ATTRIBUTE_MACROS_ENABLE__)
  #pragma message "Attribute macros disabled!"
#endif

//! System Message: Attribute Macro Status
/*!
  Please don't modify this.
*/
#if !defined(__PRIORITY_CONSTRUCTOR_DESTRUCTOR_ENABLE__) && defined(__ATTRIBUTE_MACROS_ENABLE__)
  #pragma message "Constructor/distructor priority disabled!"
#endif

//! System Message: Bitwise Status
/*!
  Please don't modify this.
*/
#if !defined(__BITWISE_MANAGER_ENABLE__)
  #pragma message "Bitwise operations manager disabled!"
#endif

//! System Message: SoftMath Status
/*!
  Please don't modify this.
*/
#if !defined(__SOFT_MATH_MANAGER_ENABLE__)
  #pragma message "Soft math manager disabled!"
#endif

//! System Message: SoftDecimal Status
/*!
  Please don't modify this.
*/
#if !defined(__SOFT_DECIMAL_MANAGER_ENABLE__)
  #pragma message "Fixed point manager disabled!"
#endif

//! System Message: SoftDecimal Infinite Arguments
/*!
  Please don't modify this.
*/
#if defined (__SOFT_DECIMAL_ENABLE_INFINITE_ARGUMENTS__)
  #warning FixedPoint uses stdarg.h library! You shoud be very cautious with your RAM. In projects with MISRA rules, this option should be disabled.
#endif

//! System Message: SoftDecimal Errors
/*!
  Please don't modify this.
*/
#if (!((defined(__SOFT_DECIMAL_MANAGER_ENABLE__) && (__SOFT_DECIMAL_AMOUNT_OF_FRACTIONARY_BITS__ > 0))&&\
((defined(__SOFT_DECIMAL_SIZE_8_BIT__) && (__SOFT_DECIMAL_AMOUNT_OF_FRACTIONARY_BITS__ < 8))||\
(defined(__SOFT_DECIMAL_SIZE_16_BIT__) && (__SOFT_DECIMAL_AMOUNT_OF_FRACTIONARY_BITS__ < 16))||\
(defined(__SOFT_DECIMAL_SIZE_32_BIT__) && (__SOFT_DECIMAL_AMOUNT_OF_FRACTIONARY_BITS__ < 32)))))
  #error Invalid __SOFT_DECIMAL_AMOUNT_OF_FRACTIONARY_BITS__ value!
#endif