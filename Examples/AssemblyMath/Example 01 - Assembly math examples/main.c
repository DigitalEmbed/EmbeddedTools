//! Example 01 - Assembly math examples
/*!
  This simply example demonstrates the use of bit manipulation.

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
    -> Distribution;
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
    Declaring variables...
  */
  int32_t i32NumberA = 32;
  int32_t i32NumberB = 18;
  int32_t i32SumNumber = i32NumberA + i32NumberB;

  /*!
    Printing the bigger variable...
  */
  printf("Bigger variable: %d\n", iBigger(i32NumberA, i32NumberB));

  /*!
    Printing the smaller variable...
  */
  printf("Smaller variable: %d\n", iSmaller(i32NumberA, i32NumberB));

  /*!
    Printing the sum of variables...
  */
  printf("Sum: %d\n", i32SumNumber);

  /*!
    Printing the double of sum of variables...
  */
  printf("Double of sum: %d\n", uiDouble(i32SumNumber));

  /*!
    Printing the half of sum of variables...
  */
  printf("Half of sum: %d\n", uiHalf(i32SumNumber));

  /*!
    Multiplying the sum of the variables by 16 (2^4)...
  */
  printf("Sum time 16: %d\n", uiMultiply(i32SumNumber, 4));

  /*!
    Dividing the sum of the variables by 8 (2^3)...
  */
  printf("Integer part of sum divided by 8: %d\n", uiDivide(i32SumNumber, 3));

  /*!
    Rest of division of the sum of the variables by 8 (2^3)...
  */
  printf("Rest of division of sum divided by 8: %d\n", uiRestOfDivision(i32SumNumber, 3));
  return 0;
}
