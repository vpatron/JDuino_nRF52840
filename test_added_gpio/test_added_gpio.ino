#include "Adafruit_TinyUSB.h"   // Need this for Serial on nRF52

/* JDuino addes these new GPIO pins:
#define PIN_N1      (33)
#define PIN_R1      (34)
#define PIN_U1      (35)
#define PIN_AD10    (36)
#define PIN_W24     (37)
#define PIN_V23     (38)
#define PIN_Y23     (39)
*/

const int pin_id[] = {
  PIN_N1,
  PIN_R1,
  PIN_U1,
  PIN_AD10,
  PIN_W24,
  PIN_V23,
  PIN_Y23
};

const char* pin_name[] = {
  "PIN_N1",
  "PIN_R1",
  "PIN_U1",
  "PIN_AD10",
  "PIN_W24",
  "PIN_V23",
  "PIN_Y23"
};

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(115200);
  Serial.println("Test out JDuino extra GPIO"); Serial.flush();
  for (int i=0; i<7; i++) {
    pinMode(pin_id[i], OUTPUT);
    digitalWrite(pin_id[i], LOW);
  }
  pinMode(LED_GREEN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  static int i=0;

  Serial.printf("Toggling pin ID:%i, name:%s\n", pin_id[i], pin_name[i]); Serial.flush();

  digitalWrite(pin_id[i], HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_GREEN, LOW);
  delay(1000);
  digitalWrite(pin_id[i], LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(LED_GREEN, HIGH);
  delay(1000);

  i++;
  if (i >= 7)
    i = 0;
}
