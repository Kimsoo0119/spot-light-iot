#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("김현수"); // Bluetooth 이름 설정
  pinMode(17, OUTPUT); // 17번 핀을 출력으로 설정
}

void loop() {
  if (SerialBT.available()) {
    String message = SerialBT.readString(); // SerialBT로부터 문자열을 읽어옴
    Serial.println(message);
    if (message == "ON") {
      analogWrite(17, 255); // 17번 핀에 LOW 신호 출력
    } else if (message == "OFF") {
      analogWrite(17, 0); // 17번 핀에 HIGH 신호 출력
    } else{
    float duty_cycle = message.toFloat() / 360.0; // 밝기를 나타내는 값 (0 ~ 1)
      analogWrite(17, (int) (duty_cycle * 255)); // PWM Duty 값 설정
    }
  }

  delay(100); // 0.1초 대기
}