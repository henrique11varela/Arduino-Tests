/* passive buzzer */
const int buzzPin = 10;
const int buttonPin = 9;

int frequency = 440;
long oldMicros = 0;
long curMicros = micros();
bool buzzState = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {

  curMicros = micros();
  if (curMicros - oldMicros >= frequency / 2 && !digitalRead(buttonPin)) {
    oldMicros = curMicros;
    digitalWrite(buzzPin, buzzState ? LOW : HIGH);
    buzzState = buzzState ? false : true;
  }
  

}
