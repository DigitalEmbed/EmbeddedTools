//! Example 03 - Fixed point number manipulation
/*!
  This simply example demonstrates the use of fixed_t type number manipulation.

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

#include <stdio.h>
#include <EmbeddedTools.h>

int main(){
  /*!
    A) Printing SoftDecimal configurations and limits...
    Configure it on Configs.h file in EmbeddedTools folder.
  */
  printf("Maximum possible value: %f\n", (double) SoftDecimal_getMaximumValue());
  printf("Minimum possible value: %f\n", (double) SoftDecimal_getMinimumValue());
  printf("Resolution: %f\n\n", (double) SoftDecimal_getResolution());

  /*!
    B) Declaring a fixed point type variables...
  */
  newSoftDecimal(fxNumberA, 3.14);
  newSoftDecimal(fxNumberB, 2.0);

  /*!
    C) Printing a fixed point type variable...
  */
  printf("Fixed point number A: %f\n", (double) SoftDecimal_toFloat(fxNumberA));
  printf("Fixed point number B: %f\n\n", (double) SoftDecimal_toFloat(fxNumberB));

  /*!
    D) Changing fxNumberA value...
  */
  fxNumberA = SoftDecimal_toFixed(0.0);
  printf("Fixed point number A changed to 0: %f\n\n", (double) SoftDecimal_toFloat(fxNumberA));

  /*!
    F) Summing...
  */
  fxNumberA = SoftDecimal_floatSum(3.14, 2.71);
  printf("Fixed point number A summed with 3.14 and 2.71: %f\n\n", (double) SoftDecimal_toFloat(fxNumberA));

  /*!
    E) Subtracting...
  */
  fxNumberB = SoftDecimal_fixedSubtract(fxNumberB, fxNumberA);
  printf("Fixed point number B subtracted with number A: %f\n\n", (double) SoftDecimal_toFloat(fxNumberB));

  /*!
    G) Other way to subtracting (or summing with a negative number)...
    Notes:
      - Infinite arguments (stdarg.h) makes your program more elegant, but you should be cautious with your RAM.
      - In projects with MISRA rules, this option must be disabled.
  */
  #if defined(__FIXED_POINT_ENABLE_INFINITE_ARGUMENTS__)
    fxNumberB = SoftDecimal_fixedSum(fxNumberA, -(fxNumberB), SoftDecimal_toFixed(-1.5));
  #else
    fxNumberB = SoftDecimal_fixedSum(fxNumberA, -(fxNumberB));
    fxNumberB = SoftDecimal_fixedSum(fxNumberB, SoftDecimal_toFixed(-1.5));
  #endif
  printf("Fixed point number B subtracted by number A and 1.5: %f\n\n", (double) SoftDecimal_toFloat(fxNumberB));

  /*!
    H) Multiplying...
    Notes:
      - Infinite arguments (stdarg.h) makes your program more elegant, but you should be cautious with your RAM.
      - In projects with MISRA rules, this option must be disabled.
  */
  #if defined(__FIXED_POINT_ENABLE_INFINITE_ARGUMENTS__)
    fxNumberA = SoftDecimal_floatMultiply(SoftDecimal_toFloat(fxNumberA), 2.0, 3.5);
  #else
    fxNumberA = SoftDecimal_floatMultiply(SoftDecimal_toFloat(fxNumberA), 2.0);
    fxNumberA = SoftDecimal_floatMultiply(SoftDecimal_toFloat(fxNumberA), 3.5);
  #endif
  printf("Fixed point number A multiplied by 2 and 3.5: %f\n\n", (double) SoftDecimal_toFloat(fxNumberA));

  /*!
    I) Multiplying fixed_t types...
  */
  fxNumberB = SoftDecimal_fixedMultiply(fxNumberA, fxNumberB);
  printf("Fixed point number A multiplied by number B: %f\n\n", (double) SoftDecimal_toFloat(fxNumberB));

  /*!
    J) Dividing...
  */
  fxNumberB = SoftDecimal_fixedDivide(fxNumberB, SoftDecimal_toFixed(2.0));
  printf("Fixed point number B divided by 2: %f\n\n", (double) SoftDecimal_toFloat(fxNumberB));

  /*!
    K) Another way to divide (is more faster for CPU and more accurate, but is more "ugly")...
  */
  fxNumberA = SoftDecimal_floatMultiply(SoftDecimal_toFloat(fxNumberA), 0.5);
  printf("Fixed point number A multiplied by 0.5 (or divided by 2): %f\n", (double) SoftDecimal_toFloat(fxNumberA));

  /*!
    L) Checking if the calculations were performed safely ...
  */
  if (SoftDecimal_checkError() == true){
    printf("\nWarning! A limit has been reached! Probably, the calculations are wrongs!\n");
    return -1;
  }
  return 0;
}

