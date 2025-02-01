void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

// 기울기 2~5
int A1_result_1(float intensity) {
  if (intensity < 0.4){
    intensity = 0.4;
  }
  int result = int(sqrt(1 - ((intensity - 0.4) / (1.0 - 0.4))) * 255);
  return result;
}
int A2_result_1(float intensity) {
  if (intensity < 0.4){
    intensity = 0.4;
  }
  int result = int(sqrt((intensity - 0.4) / (1.0 - 0.4)) * 255);
  return result;
}

// 기울기 -2~-5
int A1_result_2(float intensity) {
  if (intensity > -0.4){
    intensity = -1.0;
  }
  int result = int(sqrt(1 - ((intensity + 1.0) / (-0.4 + 1.0))) * 255);
  return result;
}
int A2_result_2(float intensity) {
  if (intensity > -0.4){
    intensity = -1.0;
  }
  int result = int(sqrt((intensity + 1.0) / (- 0.4 + 1.0)) * 255);
  return result;
}

// 기울기 1~2
 
void loop() {
  if(Serial.available()){
    char val = Serial.read(); // read 후에는 값이 비어있다.
    char val2; // 값을 저장해 놓을 변수
    bool read = false;
    switch (val)
    {
      // A
      case 'A': 
      val2 = 'A';
      read = true;
      break;
      // B
      case 'B': 
      val2 = 'B';
      read = true;
      break;
      // C
      case 'C': 
      val2 = 'C';
      read = true;
      break;
      // D
      case 'D': 
      val2 = 'D';
      read = true;
      break;
      // E
      case 'E': 
      val2 = 'E';
      read = true;
      break;
      // F
      case 'F': 
      val2 = 'F';
      read = true;
      break;
      // Z
      case 'Z':
      break;
    }
    
    if (read) // Z외의 나머지 문자가 들어온 경우
    { 
      if (val2 == 'A') { 
        // 이거 함수로 만들기
        float intensity = Serial.parseFloat(); // 프로세싱을 통해 받은 값 (2/slope)
        float intensity_ = intensity/2;
        unsigned long duration = 160;      // 각 actuator의 동작 기간 (160은 임의의 값)
        unsigned long SOA = 98.5;          // 각 actuator 간의 간격 (Apparent Motion 수식에 대입한 값)
        unsigned long time_set = millis(); // 시작 시간 (msec단위이기 때문에 최대한 시작 지점에 가깝게 작성해야한다)
        while (millis() <= time_set + SOA){
          analogWrite(3,255);
        };
        while (time_set + SOA <= millis() && millis() <= time_set + SOA + (duration - SOA)){
          analogWrite(4,A1_result_1(intensity_));
          analogWrite(7,A2_result_1(intensity_));
        }
        analogWrite(3,0);
        while (time_set + SOA + (duration - SOA) <= millis() && millis() <= time_set + SOA + SOA){
        }
        while (time_set + SOA + SOA <= millis() && millis() <= time_set + SOA + SOA + (duration - SOA)){
          analogWrite(5,A1_result_1(intensity));
          analogWrite(8,A2_result_1(intensity));
        }
        analogWrite(4,0);
        analogWrite(7,0);
        while (time_set + SOA + SOA + (duration - SOA) <= millis() && millis() <= time_set + SOA + SOA + duration){
        }
        analogWrite(5,0);
        analogWrite(8,0);
      }
    }
    else {
      analogWrite(3,0);
      analogWrite(4,0);
      analogWrite(5,0);
      analogWrite(6,0);
      analogWrite(7,0);
      analogWrite(8,0);
      analogWrite(9,0);
      analogWrite(10,0);
      analogWrite(11,0);
    }
  }
}
