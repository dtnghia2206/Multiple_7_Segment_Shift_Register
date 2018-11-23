#define dataPin  2  
#define latchPin 3 
#define clockPin 4 
#define COMMON_ANODE
 
void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  for (byte i = 0; i < 128; i++) {
    displayNumbers(i);    
    delay(500);                 
  }  
}

void displayNumbers(byte number) {
  
  digitalWrite(latchPin, LOW); 
  #ifdef COMMON_ANODE
  shiftOut(dataPin, clockPin, LSBFIRST, basicNumbers((number % 100) % 10) ^ B11111111); 
  shiftOut(dataPin, clockPin, LSBFIRST, basicNumbers(((number / 10) % 10)) ^ B11111111);
  shiftOut(dataPin, clockPin, LSBFIRST, basicNumbers((number / 100)) ^ B11111111);
  #endif
  digitalWrite(latchPin, HIGH); 
  
}

byte basicNumbers(byte number) {
  switch (number) {
    case 0:
      return B11111100;
      break;
    case 1:
      return B01100000;
      break;
    case 2:
      return B11011010;
      break;
    case 3:
      return B11110010;
      break;
    case 4:
      return B01100110;
      break;
    case 5:
      return B10110110;
      break;
    case 6:
      return B10111110;
      break;
    case 7:
      return B11100000;
      break;
    case 8:
      return B11111110;
      break;
    case 9:
      return B11110110;
      break;
    default:
      return B00000000; 
      break;   
  }
}
