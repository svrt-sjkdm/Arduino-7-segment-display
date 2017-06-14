/*  ARDUINO NANO
 *   
 *      SEGMENTS
 * A  B  C  D  E  F  G 
 * D0 D1 D2 D3 D4 D5 D6
 *      DISPLAYS
 * D1 D2 D3 D4
 * B0 B1 B2 B3
 *      PORTD 
 * B|X|X|X|X|X|X|X|X
 *  |X|G|F|E|D|C|B|A
 *  
 */
#include "math.h"

int num,numDigits;
int displayNumber[4];
 
void BCDdecoder(int num);
 
void setup() {
  DDRD = B11111111;
  DDRB = B001111; 
}

void loop() {
  num = analogRead(A0);
  // The number of digits is calculated
  numDigits = (int)(log10((float)num)) + 1; 
  // The number is converted into a reversed array
  for(int i = 0; i < 4; i++) {
    if(num == 0)
      break;
    else {
      displayNumber[i] = num % 10;
      num /= 10;
    }
  }
  // switch case to display the number in the 4 digit 7 segment display
    switch(numDigits){
    case 1:
      PORTB = B001110;              // Display 1
      BCDdecoder(displayNumber[0]);
      delay(5);
    break;
    case 2:
      PORTB = B001110;              // Display 1
      BCDdecoder(displayNumber[1]);
      delay(5);
      PORTB = B001101;              // Display 2
      BCDdecoder(displayNumber[0]);
      delay(5);
    break;
    case 3:
      PORTB = B001110;              // Display 1
      BCDdecoder(displayNumber[2]);
      delay(5);
      PORTB = B001101;              // Display 2
      BCDdecoder(displayNumber[1]);
      delay(5);
      PORTB = B001011;              // Display 3
      BCDdecoder(displayNumber[0]);
      delay(5);
    break;
    case 4:
      PORTB = B001110;              // Display 1
      BCDdecoder(displayNumber[3]);
      delay(5);
      PORTB = B001101;              // Display 2
      BCDdecoder(displayNumber[2]);
      delay(5);
      PORTB = B001011;              // Display 3
      BCDdecoder(displayNumber[1]);
      delay(5);
      PORTB = B000111;              // Display 4
      BCDdecoder(displayNumber[0]);
      delay(5);
    break;
    default:
    break;
  }  
}

void BCDdecoder(int num) {
  switch(num) {
    case 0:
      PORTD = B00111111;
    break;
    case 1:
      PORTD = B00000110;
    break;
    case 2:
      PORTD = B01011011;
    break;
    case 3:
      PORTD = B01001111;
    break;
    case 4:
      PORTD = B01100110;
    break;
    case 5:
      PORTD = B01101101; 
    break;
    case 6:
      PORTD = B01111101;
    break;
    case 7:
      PORTD = B00000111;
    break;
    case 8:
      PORTD = B01111111;
    break;
    case 9:
      PORTD = B01100111;
    break;
    default:
      PORTD = B00000000;
    break;
  }
}

