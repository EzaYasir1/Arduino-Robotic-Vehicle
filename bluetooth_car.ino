/*
  Arduino Bluetooth Car Code
  IN1=13, IN2=12, IN3=11, IN4=10 (no headlight LED used in this build)
  ENA/ENB are jumper-capped on the L298N (always enabled, fixed full speed).
  No PWM speed control with this wiring -- see note at bottom to add it.

  NOTE: this was rebuilt from memory of a competition project from
  7-8 months ago. Double-check pin numbers against your own wiring
  before uploading, since some connections were customized at the time.
*/

#define IN1 13   // Left motors forward
#define IN2 12   // Left motors reverse
#define IN3 11   // Right motors forward
#define IN4 10   // Right motors reverse

char command;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Stop();  // clear previous direction before applying a new one
    switch (command) {
      case 'F': forward(); break;
      case 'B': back(); break;
      case 'L': left(); break;
      case 'R': right(); break;
      case 'S': Stop(); break;
    }
  }
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void back() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

/*
  NOTE on speed control:
  ENA and ENB currently have jumper caps on the L298N board, so both
  motor channels run at fixed full speed whenever an IN pin is HIGH.
  To get variable speed (like your original ENA/ENB idea):
    1. Physically REMOVE the ENA and ENB jumper caps on the L298N.
    2. Wire ENA and ENB to two free Arduino PWM-capable pins (e.g. 9 and 3).
    3. Add analogWrite(ENA, Speed) / analogWrite(ENB, Speed) calls in each
       movement function, alongside the digitalWrite() calls above.
*/
