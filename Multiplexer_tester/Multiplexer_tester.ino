/* Multiplexer CD74HC4067 */

const int s[4] = {9, 8, 7, 6};
const int sig =  5;

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 4; i++) {  
    pinMode(s[i], OUTPUT);     //setup S pins
  }
  pinMode(sig, INPUT_PULLUP);  //setup Sig pin
}

void loop() {
  for(int i = 0; i < 16; i++) {
    int binary = i;
    for(int j = 0; j < 4; j++) {
      digitalWrite(s[j], (binary % 2 == 1) ? HIGH : LOW);
      binary /= 2;
    }
    Serial.print(digitalRead(sig));
    Serial.print(" ");
  }
  Serial.println();
}
