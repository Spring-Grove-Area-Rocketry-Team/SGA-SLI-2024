// https://create.arduino.cc/projecthub/infoelectorials/project-003-arduino-lm35-temperature-sensor-project-0a43ba
// https://create.arduino.cc/projecthub/electropeak/sd-card-module-with-arduino-how-to-read-write-data-37f390
// https://www.mytechfun.com/video/77
#include <SPI.h>
#include <SD.h>
File myFile;
int val;
int tempPin = 0; //analog 0
int val2;
int tempPin2 = 1; //analog 1

//this function will be called from the loop (writes c1, c2 values to file)
void save_temperature(float c1, float c2) {
  myFile = SD.open("templog.txt", FILE_WRITE);
  myFile.print(millis());
  myFile.print("\t");
  myFile.print(c1);
  myFile.print("\t");
  myFile.println(c2);
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
  float mv = ( val / 1024.0) * 5000;
  float cel = mv / 10;

  float mv2 = ( val2 / 1024.0) * 5000;
  float cel2 = mv2 / 10;

  Serial.print("TEMPRATURE = ");
  Serial.print(cel);
  Serial.print("*C , ");
  Serial.print(cel2);
  Serial.print("*C");
  Serial.println();
  save_temperature(cel, cel2);
  delay(60000); //wait 1 minute //for testing change this to 2000 (2 seconds)
}