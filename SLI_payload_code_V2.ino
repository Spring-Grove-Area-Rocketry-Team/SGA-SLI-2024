// https://create.arduino.cc/projecthub/infoelectorials/project-003-arduino-lm35-temperature-sensor-project-0a43ba
// https://create.arduino.cc/projecthub/electropeak/sd-card-module-with-arduino-how-to-read-write-data-37f390
// https://www.mytechfun.com/video/77
#include <SPI.h>
#include <SD.h>
File myFile;
int val;
int tempPin = 1; 
int val2;
int tempPin2 = 2; 
int val3;
int tempPin3 = 3;
int val4;
int tempPin4 = 4;

//this function will be called from the loop (writes c1, c2, c3, and c4 values to file)
void save_temperature(float c1, float c2, float c3, float c4) {
  myFile = SD.open("templog.txt", FILE_WRITE);
  myFile.print(millis());
  myFile.print("\t");
  myFile.print(c1);
  myFile.print("\t");
  myFile.println(c2);
  myFile.print("\t");
  myFile.println(c3);
  myFile.print("\t");
  myFile.println(c4);
  myFile.close();
}


void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.print("Initializing SD card...");
  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1);
  }

}

void loop() {
  val = analogRead(tempPin);
  val2 = analogRead(tempPin2);
  val3 = analogRead(tempPin3);
  val4 = analogRead(tempPin4);
  float mv = ( val / 1024.0) * 5000;
  float cel = mv / 10;
  float F = cel*9/5 + 32;

  float mv2 = ( val2 / 1024.0) * 5000;
  float cel2 = mv2 / 10;
  float F2 = cel2*9/5 + 32;

  float mv3 = ( val3 / 1024.0) * 5000;
  float cel3 = mv3 / 10;
  float F3 = cel*9/5 + 32;

  float mv4 = ( val4 / 1024.0) * 5000;
  float cel4 = mv4 / 10;
  float F4 = cel4*9/5 + 32;

  Serial.print("TEMPRATURE = ");
  Serial.print(F);
  Serial.print("*F, ");
  Serial.print(F2);
  Serial.print("*F, ");
  Serial.print(F3);
  Serial.print("*F, ");
  Serial.print(F4);
  Serial.print("*F, ");
  Serial.print(millis()/1000);
  Serial.println();
  delay(1000);
}