/* Pin configuration:
 * 
 * PORTD PINS: 
 * 
 * 1 --> A 
 * 2 --> B
 * 3 --> C
 * 4 --> D
 * 5 --> E
 * 6 --> F
 * 7 --> G
 * 
 * PORTB PINS:
 * 
 * 8  --> DISPLAY 1
 * 9  --> DISPLAY 2
 * 10 --> DISPLAY 3
 * 11 --> DISPLAY 4
 * 
 */

unsigned num;

unsigned int_to_bin(unsigned num) {
  return (num == 0 || num == 1 ? num : ((num % 2) + 10 * int_to_bin(num / 2)));
}

void setup() {
  DDRD = B11111110;
  DDRB = B001111;
  Serial.begin(9600);
}

void loop() {
  PORTB = B000000;
  PORTD = B01111110;  // 0
  delay(1000);
  PORTD = B00001100;  // 1
  delay(1000);
  PORTD = B10110110;  // 2
  delay(1000);   
  PORTD = B10011110;  // 3
  delay(1000); 
  PORTD = B11001100;  // 4
  delay(1000);
  PORTD = B11011010;  // 5
  delay(1000);
  PORTD = B11111010;  // 6
  delay(1000);
  PORTD = B00001110;  // 7
  delay(1000);
  PORTD = B11111110;  // 8 
  delay(1000);
  PORTD = B11001110;  // 9 
  delay(1000);
}
