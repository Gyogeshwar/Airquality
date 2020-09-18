#include <SoftwareSerial.h>
#include <Arduino.h>
int i=8;
SoftwareSerial s(5,6);
char mystr1[100] = "http://aqigroup.herokuapp.com/add_data.php?ID=7&STATION=1";
char mystr2 [100]= "&CO=12&PM2_5=13&O3=12&NH3=44&HUMIDITY=13&TEMP=29&AQI=44"; //String data
int data;
void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(115200);
  s.begin(115200);
}

void loop() {
sprintf(mystr1,"http://aqigroup.herokuapp.com/add_data.php?ID=%d&STATION=1",i);  
//sprintf(mystr2,"http://aqigroup.herokuapp.com/add_data.php?ID=%d&STATION=1",i); 
while(s.available()>0)
{  
  data=s.read();
  Serial.println(data);
  if(data==1)
 { 
  delay(100);
  s.write(mystr2,100); //Write the serial data 
 }
  if(data==2)
 { 
  delay(100);
  s.write(mystr1,100); //Write the serial data 
  }
  i=i+1;
}
}
