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
#include <EmbeddedTools+.h>

int main(){
  /*!
    A) Printing SoftDecimal configurations and limits...
    Configure it on Configs.h file in EmbeddedTools folder.
  */
  printf("Maximum possible value: %f\n", (double) SoftDecimal.getMaximumValue());
  printf("Minimum possible value: %f\n", (double) SoftDecimal.getMinimumValue());
  printf("Resolution: %f\n\n", (double) SoftDecimal.getResolution());

  /*!
    B) Declaring a fixed point type variables...
  */
  newSoftDecimal(fxNumberA, 3.14);
  newSoftDecimal(fxNumberB, 2.0);

  /*!
    C) Printing a fixed point type variable...
  */
  printf("Fixed point number A: %f\n", (double) SoftDecimal.Fixed.toFloat(fxNumberA));
  printf("Fixed point number B: %f\n\n", (double) SoftDecimal.Fixed.toFloat(fxNumberB));

  /*!
    D) Changing fxNumberA value...
  */
  fxNumberA = SoftDecimal.Float.toFixed(0.0);
  printf("Fixed point number A changed to 0: %f\n\n", (double) SoftDecimal.Fixed.toFloat(fxNumberA));

  /*!
    F) Summing...
  */
  fxNumberA = SoftDecimal.Float.sum(3.14, 2.71);
  printf("Fixed point number A summed with 3.14 and 2.71: %f\n\n", (double) SoftDecimal.Fixed.toFloat(fxNumberA));

  /*!
    E) Subtracting...
  */
  fxNumberB = SoftDecimal.Fixed.subtract(fxNumberB, fxNumberA);
  printf("Fixed point number B subtracted with number A: %f\n\n", (double) SoftDecimal.Fixed.toFloat(fxNumberB));

  /*!
    G) Other way to subtracting (or summing with a negative number)...
  */
  fxNumberB = SoftDecimal.Fixed.sum(fxNumberA, -(fxNumberB));
  fxNumberB = SoftDecimal.Fixed.sum(fxNumberB, SoftDecimal_toFixed(-1.5));
  printf("Fixed point number B subtracted by number A and 1.5: %f\n\n", (double) SoftDecimal.Fixed.toFloat(fxNumberB));

  /*!
    H) Multiplying...
  */
  fxNumberA = SoftDecimal.Float.multiply(SoftDecimal_toFloat(fxNumberA), 2.0);
  fxNumberA = SoftDecimal.Float.multiply(SoftDecimal_toFloat(fxNumberA), 3.5);
  printf("Fixed point number A multiplied by 2 and 3.5: %f\n\n", (double) SoftDecimal.Fixed.toFloat(fxNumberA));

  /*!
    I) Multiplying fixed_t types...
  */
  fxNumberB = SoftDecimal.Fixed.multiply(fxNumberA, fxNumberB);
  printf("Fixed point number A multiplied by number B: %f\n\n", (double) SoftDecimal.Fixed.toFloat(fxNumberB));

  /*!
    J) Dividing...
  */
  fxNumberB = SoftDecimal.Fixed.divide(fxNumberB, SoftDecimal.Float.toFixed(2.0));
  printf("Fixed point number B divided by 2: %f\n\n", (double) SoftDecimal.Fixed.toFloat(fxNumberB));

  /*!
    K) Another way to divide (is more faster for CPU and more accurate, but is more "ugly")...
  */
  fxNumberA = SoftDecimal.Float.multiply(SoftDecimal.Fixed.toFloat(fxNumberA), 0.5);
  printf("Fixed point number A multiplied by 0.5 (or divided by 2): %f\n", (double) SoftDecimal.Fixed.toFloat(fxNumberA));

  /*!
    L) Checking if the calculations were performed safely ...
  */
  if (SoftDecimal.checkError() == true){
    printf("\nWarning! A limit has been reached! Probably, the calculations are wrongs!\n");
    return -1;
  }
  return 0;
}
