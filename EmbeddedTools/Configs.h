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
#define __AMOUNT_OF_FRACTIONARY_BITS__                             7

#ifdef __cplusplus
  }
#endif

#endif
