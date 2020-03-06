//! Example 02 - Integer bit manipulation
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

/*!
  Declaration of the character that will count the order of the processes...
*/
char cProcessCounter = 'A';

void printBits(uint64_t ui64Number);                  /*!< Void type function. */

int main(){
  /*!
    A) Declaring a simple 64-bit variable...
  */
  uint64_t ui64Number = 7;
  printBits(ui64Number);

  /*!
    B) Erasing bit from position 0 (least significant)...
  */
  Bitwise.Bit.clear(&ui64Number, 0);
  printBits(ui64Number);

  /*!
    C) Seting byte from position 1...
  */
  Bitwise.Byte.set(&ui64Number, 1);
  printBits(ui64Number);

  /*!
    D) Copying the first byte of number 0xFFFF and pasting in the last position...
  */
  Bitwise.Byte.copy(&ui64Number, 3, 0xFFFF, 0);
  printBits(ui64Number);

  /*!
    E) Copying 3 bits at position 0 of number 4 and pasting them into position 10...
  */
  Bitwise.Bits.copy(&ui64Number, 10, 4, 0, 3);
  printBits(ui64Number);
  return 0;
}

//! Function: Bit Printer
/*!
  Print all bits of a 64-bits integer.
  \param ui64Number is a 64-bits integer.
*/
void printBits(uint64_t ui64Number){
  int8_t i8Counter = 64;
  printf("%c) ", cProcessCounter);
  for (i8Counter = 63 ; i8Counter > -1 ; i8Counter--){
    printf("%d", Bitwise.Bit.read(ui64Number, i8Counter));
  }
  printf("\n");
  cProcessCounter++;
}
