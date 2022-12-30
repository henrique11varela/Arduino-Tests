/* Multiplexer CD74HC4067 */

const int s[4] = { 15, 14, 16, 10 };
const int sig = 9;

void setup() {
  Serial.begin(9600);  //setup Serial bus
  for (int i = 0; i < 4; i++) {
    pinMode(s[i], OUTPUT);  //setup S pins
  }
  pinMode(sig, INPUT_PULLUP);  //setup Sig pin
}

void loop() {
  for (int i = 0; i < 16; i++) {  //for each output/input pin
    int binary = i;
    for (int j = 0; j < 4; j++) {  //write binary to S pins
      digitalWrite(s[j], (binary % 2 == 1) ? HIGH : LOW);
      binary /= 2;
    }
    Serial.print(digitalRead(sig)); //read Sig pin
    Serial.print(" ");
  }
  Serial.println();
}
