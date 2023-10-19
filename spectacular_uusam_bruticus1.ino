int pinTemp = A1;   //This is where our Output data goes
int pintempy = A2;
int pintempter = A3 ;
int pintempyter = A4 ;
void setup() {
  Serial.begin(9600);     
}
void loop() {
  int temp1 = analogRead(pinTemp);  
  temp1 = temp1 * 0.48828125;   // convert output (mv) to readable celcius
  temp1 = (temp1 * 9/5) + 32 ;  // converts fahrenheit to celciu
  Serial.print("Temperature1: ");
  Serial.print(temp1);
  Serial.println("F");  //print the temperature status  
  int temp2 = analogRead(pintempy);  
  temp2 = temp2 * 0.48828125;   // convert output (mv) to readable celcius
  temp2 = (temp2 * 9/5) + 32 ;
  Serial.print("Temperature2: ");
  Serial.print(temp2);
  Serial.println("F");  //print the temperature status
  int temp3 = analogRead(pintempter);  
  temp3 = temp3 * 0.48828125;   // convert output (mv) to readable celcius
  temp3 = (temp3 * 9/5) + 32 ;
  Serial.print("Temperature3: ");
  Serial.print(temp3);
  Serial.println("F");  //print the temperature status
   int temp4 = analogRead(pintempyter);  
  temp4 = temp4 * 0.48828125;   // convert output (mv) to readable celcius
  temp4 = (temp4 * 9/5) + 32 ;
  Serial.print("Temperature4: ");
  Serial.print(temp4);
  Serial.println("F");  //print the temperature status
  delay(1000);
}