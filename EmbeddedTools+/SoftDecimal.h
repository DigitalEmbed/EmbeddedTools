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

#ifndef __SOFT_DECIMAL_CLASS_HEADER__
  #define __SOFT_DECIMAL_CLASS_HEADER__

  #include <EmbeddedTools.h>
  #include <stdarg.h>

  #if defined(__SOFT_DECIMAL_MANAGER_ENABLE__)

    #ifdef __cplusplus
      extern "C" {
    #endif

    #if defined(__AVR__)
      #include <avr/pgmspace.h>
    #endif

    typedef struct {
      fixed_t (*toFixed)(float fNumber);
      fixed_t (*sum)(float fAddendA, float fAddendB);
      fixed_t (*subtract)(float fMinuendo, float fSubtrahend);
      fixed_t (*multiply)(float fMultiplier, float fMultiplicand);
      fixed_t (*divide)(float fDividend, float fDivisor);
    } softdecimal_float_t;


    typedef struct {
      float (*toFloat)(fixed_t fxNumber);
      __AUTO_SIZE_LIST_TYPE__ (*toInt)(fixed_t fxNumber);
      fixed_t (*sum)(fixed_t fxAddendA, fixed_t fxAddendB);
      fixed_t (*subtract)(fixed_t fxMinuendo, fixed_t fxSubtrahend);
      fixed_t (*multiply)(fixed_t fxMultiplier, fixed_t fxMultiplicand);
      fixed_t (*divide)(fixed_t fxDividend, fixed_t fxDivisor);
    } softdecimal_fixed_t;

    typedef struct {
      softdecimal_float_t Float;
      softdecimal_fixed_t Fixed;
      float (*getMinimumValue)(void);
      float (*getMaximumValue)(void);
      float (*getResolution)(void);
      bool (*checkError)(void);
    } softdecimal_manager_t;

    #if defined(__AVR__)
      extern const softdecimal_manager_t SoftDecimal PROGMEM;                           /*!< SoftMath manager "object". */
    #else
      extern const softdecimal_manager_t SoftDecimal;                                   /*!< SoftMath manager "object". */
    #endif

    #ifdef __cplusplus
      }
    #endif

  #endif
#endif