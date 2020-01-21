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

#ifndef __SOFT_MATH_H__
  #define __SOFT_MATH_H__

  #include "./Configs.h"

  #if defined(__ENABLE_SOFT_MATH_MANAGER__)

    //! Macro: Negative
    /*!
      Negative a number.
      \param iNumber is an undefined parameter. It's the number that will be denied.
      \return "Returns" the negative parameter.
    */
    #define SoftMath_negative(iNumber)\
      (((iNumber) > 0) ?\
        (-(iNumber)) :\
        (iNumber))

    //! Macro: Module
    /*!
      Calculates the magnitude of a number.
      \param iNumber is an undefined parameter. It's the number that will have its calculated module.
      \return "Returns" the parameter module.
    */
    #define SoftMath_module(iNumber)\
      (((iNumber) < 0) ?\
      (-(iNumber)) :\
      (iNumber))

    //! Macro: Double
    /*!
      Calculates double a number.
      \param iNumber is an undefined parameter. It's the number that will have your double calculated.
      \return "Returns" twice the parameter.
    */
    #define SoftMath_double(iNumber)\
      (((iNumber) > 0) ?\
        ((iNumber) << 1) :\
        (-((-(iNumber)) << 1)))

    //! Macro: Half
    /*!
      Calculates half a number.
      \param iNumber is an undefined parameter. It's the number that will have your half calculated.
      \return "Returns" to half of the parameter.
    */
    #define SoftMath_half(iNumber)\
      (((iNumber) > 0) ?\
        ((iNumber) >> 1) :\
        (-((-(iNumber)) >> 1)))

    //! Macro: Multiplication
    /*!
      Multiply one number by another.
      \param iNumber is an undefined parameter. It's the number that will have your half calculated.
      \param uiExpoentOfTwo is an undefined parameter. It's the multiplier: this parameter must be "n" for 2^n, n >= 0.
      \return "Returns" the result of multiplication.
    */
    #define SoftMath_multiply(iNumber, uiExpoentOfTwo)\
      (((iNumber) >= 0) ?\
        ((iNumber) << (uiExpoentOfTwo)) :\
        (-((-(iNumber)) << (uiExpoentOfTwo))))

    //! Macro: Division
    /*!
      Divide one number by another.
      \param iNumber is an undefined parameter. It's the number that will have your split remainder calculated.
      \param uiExpoentOfTwo is an undefined parameter. It's the divisor of division: this parameter must be "n" for 2^n, n >= 0.
      \return "Returns" the rest of the division of the parameter.
    */
    #define SoftMath_divide(iNumber, uiExpoentOfTwo)\
      (((iNumber) >= 0) ?\
        ((iNumber) >> (uiExpoentOfTwo)) :\
        (-((-(iNumber)) >> (uiExpoentOfTwo))))

    //! Macro: Rest of Division
    /*!
      Calculates the rest of division of one number by another.
      \param iNumber is an undefined parameter. It's the number that will have your split remainder calculated.
      \param uiExpoentOfTwo is an undefined parameter. It's the divisor of division: this parameter must be "n" for 2^n, n >= 0.
      \return "Returns" the rest of the division of the parameter.
    */
    #define SoftMath_divisionRest(iNumber, uiExpoentOfTwo)\
      (((iNumber) >= 0) ?\
        ((iNumber) & (((1 << (uiExpoentOfTwo)) - 1))) :\
        (-((-(iNumber)) & (((1 << (uiExpoentOfTwo)) - 1))))) 

    //! Macro: Larger
    /*!
      Checks the largest of two numbers.
      \param iNumberA is an undefined parameter. It's the number that will be compared for the larger check.
      \param iNumberB is an undefined parameter. It's the number that will be compared for the larger check.
      \return "Returns" the largest parameter.
    */
    #define SoftMath_bigger(iNumberA, iNumberB)\
      (((iNumberA) >= (iNumberB)) ?\
        (iNumberA) :\
        (iNumberB))

    //! Macro: Minor
    /*!
      Checks the smallest of two numbers.
      \param iNumberA is an undefined parameter. It's the number that will be compared for the verification of the child.
      \param iNumberB is an undefined parameter. It's the number that will be compared for the verification of the child.
      \return "Returns" the smallest parameter.
    */
    #define SoftMath_smaller(iNumberA, iNumberB)\
      (((iNumberA) <= (iNumberB)) ?\
        (iNumberA) : \
        (iNumberB))
  
  #endif
#endif
