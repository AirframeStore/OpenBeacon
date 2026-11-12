const uint8_t BUS = 2;            //sync bus pin
const uint8_t LED = LED_BUILTIN;  //output pin or builtin LED for tests
const uint16_t PERIOD = 3000;     //frame length

volatile uint32_t t0;
volatile bool selfPulse = false;

void onBusFall() {
  if (!selfPulse) t0 = millis();  // another device fired: restart cycle
}

void busPulse() {
  if (digitalRead(BUS) == LOW) return;  // someone else is already pulsing
  selfPulse = true;
  digitalWrite(BUS, LOW);
  pinMode(BUS, OUTPUT);
  delay(2);
  pinMode(BUS, INPUT_PULLUP);  // release
  delayMicroseconds(100);      // let the line rise
  selfPulse = false;
}

void setup() {
  pinMode(LED, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(BUS), onBusFall, FALLING);
  t0 = millis();
  busPulse();
}

void loop() {
  noInterrupts();
  uint32_t start = t0;
  interrupts();
  uint32_t t = millis() - start;

  if (t >= PERIOD) {
    noInterrupts();
    if (t0 == start) t0 = start + PERIOD;  // advance unless a sync just arrived
    interrupts();
    busPulse();
    return;
  }
  //Beacon
  //bool on = (t < 750);
  //ACL
  bool on = (t < 50) || (t > 150 && t < 200) || (t > 1500 && t < 1550) || (t > 1650 && t < 1700);
  //WigWag_left
  //bool on = (t < 1500);
  //WigWag_right
  //bool on = (t > 1500);
  digitalWrite(LED, on ? HIGH : LOW);
}
