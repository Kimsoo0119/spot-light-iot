#include "BluetoothSerial.h"
BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("김현수"); // Bluetooth 이름 설정
  pinMode(17, OUTPUT); // 17번 핀을 출력으로 설정
}

void loop() {
  static bool led_is_on = false;
  if (SerialBT.available()) {
    String message = SerialBT.readString(); // SerialBT로부터 문자열을 읽어옴
    if (message == "ON") {
      analogWrite(17, 255); // LED ON
      led_is_on = true;
    } else if (message == "OFF") { 
      analogWrite(17, 0); // LED OFF
      led_is_on = false;
    } else if (led_is_on) {
      float duty_cycle = message.toFloat() / 360.0; // 밝기를 나타내는 값 (0 ~ 1)
      analogWrite(17, (int) (duty_cycle * 255)); // PWM Duty 값 설정
    } else {
      // LED가 꺼져 있으므로 아무 동작도 수행하지 않음
    }
  }

  delay(10); // 0.01초 대기
}