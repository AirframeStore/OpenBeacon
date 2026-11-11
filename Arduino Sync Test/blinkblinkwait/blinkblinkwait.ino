const uint8_t BUS = 2;
const uint8_t LED = 13;
const uint16_t PERIOD = 1750;

volatile uint32_t t0;
volatile bool selfPulse = false;

void onBusFall() {
  if (!selfPulse) t0 = millis();   // another device fired: restart cycle
}

void busPulse() {
  if (digitalRead(BUS) == LOW) return;   // someone else is already pulsing
  selfPulse = true;
  pinMode(BUS, OUTPUT);
  digitalWrite(BUS, LOW);
  delay(2);
  pinMode(BUS, INPUT_PULLUP);            // release
  delayMicroseconds(100);                // let the line rise
  selfPulse = false;
}

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUS, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUS), onBusFall, FALLING);
  t0 = millis();
  busPulse();
}

void loop() {
  noInterrupts(); uint32_t start = t0; interrupts();
  uint32_t t = millis() - start;

  if (t >= PERIOD) {
    noInterrupts();
    if (t0 == start) t0 = start + PERIOD;   // advance unless a sync just arrived
    interrupts();
    busPulse();
    return;
  }
  bool on = (t < 50) || (t >= 200 && t < 250);
  digitalWrite(LED, on ? HIGH : LOW);
}