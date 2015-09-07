// I don't feel like modifying the led configs
// in the standard blink sketch every time,
// that is why I keep this between the ArduinoISP test cases...

#define LED_RED 	4
#define LED_GREEN  	2

void setup( void )
{
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  // Serial.begin(115200);
}

static unsigned char x;

void loop( void )
{
//  int i;

  digitalWrite(LED_RED, x);
  digitalWrite(LED_GREEN, 1 ^ x);
  x ^= 1;
  delay (1000);

//  for(i=0; i<10; i++)
//    Serial.println("hello");
}
