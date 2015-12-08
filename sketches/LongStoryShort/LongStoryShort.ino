/*

 A small sketch to test support for big flash (>128KB) without having to write
 that many data.

 The sketch writes a message to the serial line.
 It reads that message from flash starting at 0x20000 (128KB).
 
 A hex file containing the sketch and the data can be handcrafted as follows:

 1. First compile the sketch e.g. with the Arduino IDE.
    Suppose this results in a hex file LongStoryShort.ino.hex (found somewhere in /tmp/build...).

 2. Strip the end of file marker from the hex file, it is the last line and looks like this
      :00000001FF

 3. Suppose you have some message in a file KnightsTale.txt.
    Convert it to hex that starts at 0x20000:
      avr-objcopy --change-addresses=0x20000 -I binary -O ihex KnightsTale.txt KightsTale.hex
 
 4. Concatenate to the sketch:
      cat LongStoryShort.ino.hex KightsTale.hex > LongStoryShort.m2560.hex

*/
#define DATA_START	0x20000
#define LED			13

void setup() {
  digitalWrite(LED, LOW);
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  Serial.println("Here we go");
}

void loop() {
  static uint32_t address = DATA_START;
  uint8_t c;
  
  c = pgm_read_byte_far(address);
  if (c != 0xff) {
    Serial.write(c);
    address++;
  } else {
    address = DATA_START;
  }
  digitalWrite(LED, address & 1 ? LOW : HIGH);
  delay(100);                                  
}

