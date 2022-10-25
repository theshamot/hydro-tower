const int MOTOR = 11;
const int RGBLED = 10;
const int POT = A0;

const int MOTOR_OK_FLOW = 120;
const int MOTOR_NOTIFICATION = 70;

const unsigned long SECOND = 1000;
const unsigned long MINUTE = 60 * SECOND;
const unsigned long HOUR = 60 * MINUTE;

const unsigned long PRERUN_NOTIFICATION = 1 * SECOND;
const unsigned long RUN_TIME = 1 * MINUTE + 30 * SECOND - PRERUN_NOTIFICATION;
const unsigned long PAUSE_TIME = 13 * HOUR - RUN_TIME;
const unsigned long NIGHT_TIME = 11 * HOUR;
const unsigned long DAY_TIME = 24 * HOUR - NIGHT_TIME;
unsigned long DAY_RUN_TIME_COUNTER = 0;

void setup() {
// Serial.begin(115200);
      delay(1000);
      analogWrite(MOTOR, 50);
      delay(800);
      analogWrite(MOTOR, 0);
      delay(30);
      analogWrite(MOTOR, 80);
      delay(800);
      analogWrite(MOTOR, 0);
      delay(30);
      analogWrite(MOTOR, 100);
      delay(800);
      analogWrite(MOTOR, 0);
      delay(3000);
}

void loop() {
//  word pot_input = analogRead(POT) >> 2;
//  Serial.println(pot_input);
//  analogWrite(MOTOR, pot_input);

  digitalWrite(RGBLED, false);
  delay(NIGHT_TIME);
  DAY_RUN_TIME_COUNTER = 0;
  while(DAY_RUN_TIME_COUNTER < DAY_TIME) {
    digitalWrite(RGBLED, true);
    analogWrite(MOTOR, MOTOR_NOTIFICATION);
    delay(PRERUN_NOTIFICATION);
    analogWrite(MOTOR, MOTOR_OK_FLOW);
    delay(RUN_TIME);
    analogWrite(MOTOR, 0);
    delay(PAUSE_TIME);
    DAY_RUN_TIME_COUNTER += PRERUN_NOTIFICATION + RUN_TIME + PAUSE_TIME;
  }
}
