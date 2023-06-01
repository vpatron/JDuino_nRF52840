#include "Adafruit_TinyUSB.h"   // Need this for Serial on nRF52

/* JDuino addes these new GPIO pins:
#define PIN_N1      (33)
#define PIN_P008    (33)
#define PIN_R1      (34)
#define PIN_P109    (34)
#define PIN_U1      (35)
#define PIN_P012    (35)
#define PIN_AD10    (36)
#define PIN_P015    (36)
#define PIN_W24     (37)
#define PIN_P102    (37)
#define PIN_V23     (38)
#define PIN_P103    (38)
#define PIN_Y23     (39)
#define PIN_P101    (39)
*/

const int pin_id[] = {
    PIN_N1,
    PIN_P008,
    PIN_R1,
    PIN_P109,
    PIN_U1,
    PIN_P012,
    PIN_AD10,
    PIN_P015,
    PIN_W24,
    PIN_P102,
    PIN_V23,
    PIN_P103,
    PIN_Y23,
    PIN_P101,
};

const char* pin_name[] = {
    "PIN_N1",
    "PIN_P008",
    "PIN_R1",
    "PIN_P109",
    "PIN_U1",
    "PIN_P012",
    "PIN_AD10",
    "PIN_P015",
    "PIN_W24",
    "PIN_P102",
    "PIN_V23",
    "PIN_P103",
    "PIN_Y23",
    "PIN_P101",
};

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(115200);
  Serial.println("Test out JDuino extra GPIO"); Serial.flush();
  for (int i=0; i<13; i++) {
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
  if (i >= 13)
    i = 0;
}
