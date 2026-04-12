#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

int motor_vals[7] = { 0, 0, 0, 0, 0, 0, 10 };
int curr_degree[6] = { 90, 30, 90, 90, 0, 0 };
int curr_pulse[6] = { 0, 0, 0, 0, 0, 0 };

// ----- 서보 관련 상수 정의 -----
#define SERVOMIN 102
#define SERVOMAX 512
#define DEGREE_MIN 0
#define DEGREE_MAX 180

// ----- PCA9685 객체 정의 (외부에서 extern으로 참조됨) -----
Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(0x40);


void firstSet() {
  for (int i = 0; i < 6; i++) {
    curr_pulse[i] = setPulse(curr_degree[i]);
  }

  for (int i = 0; i < 6; i++) {
    setServoAngle(i);
  }
}

void checklimit() {
  curr_pulse[0] = constrain(curr_pulse[0], 102, 512);
  curr_pulse[1] = constrain(curr_pulse[1], 102, 256);
  curr_pulse[2] = constrain(curr_pulse[2], 102, 512);
  curr_pulse[3] = constrain(curr_pulse[3], 102, 512);
  curr_pulse[4] = constrain(curr_pulse[4], 102, 512);
  curr_pulse[5] = constrain(curr_pulse[5], 102, 512);
}

void setServoAngle(int pinNum) {
  pca9685.setPWM(pinNum, 0, curr_pulse[pinNum]);
}

int setPulse(int degree) {
  int pulse = map(degree, DEGREE_MIN, DEGREE_MAX, SERVOMIN, SERVOMAX);
  return pulse;
}

void moving() {  // 해당 방향으로 1도 움직임

  for (int i = 0; i < 4; i++) {
    curr_pulse[i] += motor_vals[i];
    checklimit();
    setServoAngle(i);
  }
  delay(motor_vals[6]);
}

// 시리얼 입력 기반 동작 테스트 함수
void moveArm() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    uint8_t idx = 0;
    char* token = strtok((char*)input.c_str(), ",");

    while (token && idx < 7) {
      motor_vals[idx++] = atoi(token);
      token = strtok(NULL, ",");
    }

    moving();
  }
}

void setup() {
  Serial.begin(115200);

  pca9685.begin();
  pca9685.setPWMFreq(50);

  firstSet();
  delay(50);
}

void loop() {
  moveArm();
}

void test() {
    for (int i = 0; i < 50; i++) {
        curr_pulse[0]++;
        moving();
    }

    for (int i = 0; i < 50; i++) {
        curr_pulse[0]--;
        moving();
    }
}