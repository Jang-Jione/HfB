import processing.serial.*;
Serial port;

void setup() {
  port = new Serial(this, Serial.list()[0], 9600); //포트 정의
  size(1000, 1000);  //화면 크기 설정
  background(255);  //배경색 설정
}

void drawGraph() {
  stroke(0);
  for (float x = 0; x < width; x += 0.01) {
      
  }
}

void draw() {
  float mouseXPos = mouseX; //현재 마우스 위치
  float pmouseXPos = pmouseX; //이전 프레임의 마우스 위치

  if (mouseY >= 80) { // 여기서의 숫자가 허용 범위 픽셀  
    
    if (mouseXPos > pmouseXPos) { // 마우스가 왼쪽에서 오른쪽으로 이동할 때
      // upper right
      if (slope >= 2) { 
          String dataToSend = "A";
          String str_slope = Float.toString(slope);
          port.write(dataToSend+str_slope);
          delay(1000);
      }
      else if (slope < 2 && slope >= 1) { 
          String dataToSend = "B";
          String str_slope = Float.toString(slope);
          port.write(dataToSend+str_slope);
          delay(1000);
      }
       else if (slope < 1 && slope >= 1/2) {
          String dataToSend = "C";
          String str_slope = Float.toString(slope);
          port.write(dataToSend+str_slope);
          delay(1000);
      }
       else if (slope < 1/2 && slope >= 0) {
          String dataToSend = "D";
          String str_slope = Float.toString(slope);
          port.write(dataToSend+str_slope);
          delay(1000);
      }
      // lower right
      else if (slope <= -2) { 
          String dataToSend = "E";
          String str_slope = Float.toString(-1*slope);
          port.write(dataToSend+str_slope);
          println(str_slope);
          delay(1000);
      }
      else if (-2 < slope && slope <= -1) { 
          String dataToSend = "F";
          String str_slope = Float.toString(-1*slope);
          port.write(dataToSend+str_slope);
          delay(1000);
      }
       else if (-1 < slope && slope <= -1/2) { 
          String dataToSend = "G";
          String str_slope = Float.toString(-1*slope);
          port.write(dataToSend+str_slope);
          delay(1000);
      }
       else if (-1/2 > slope && slope <= 0) { 
          String dataToSend = "H";
          String str_slope = Float.toString(-1*slope);
          port.write(dataToSend+str_slope);
          delay(1000);
      }
       else {
          port.write('Z'); 
      }
    }
    else if (mouseXPos < pmouseXPos) { // 마우스가 오른쪽에서 왼쪽으로 이동할 때
    }
    else if (mouseXPos == pmouseXPos) { // 마우스의 이전 프레임과 현재 프레임이 같을 때 
    }
  }
}
