#include <SoftwareSerial.h>
SoftwareSerial s(5,6);

void aqi(int a,int b,int c,int d);
void setup()
{
  // put your setup code here, to run once:
 pinMode(A0,INPUT);
 pinMode(A1,INPUT);
 pinMode(A2,INPUT);
 pinMode(A3,INPUT);
 pinMode(A4,INPUT);
 Serial.begin(115200);
 s.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
int co,pm2_5,o3,nh3,temp_hum,c,d,e,f,g;
c=analogRead(A0);
d=analogRead(A1);
e=ppm_to_ppb(analogRead(A2));
f=ppm_to_ppb(analogRead(A3));
g=analogRead(A4);
co=(c*28.01/24.45);
pm2_5=d/0.001;
o3=(e*48/24.45);
nh3=(f*17.031/24.25);
Serial.print("Co=");
Serial.print(co);
Serial.println("mg/m3");
Serial.print("PM2.5=");
Serial.print(pm2_5);
Serial.println("ug/m3");
Serial.print("o3=");
Serial.print(o3);
Serial.println("ug/m3");
Serial.print("NH3=");
Serial.print(nh3);
Serial.println("ug/m3");
delay(1000);
aqi(co,pm2_5,o3,nh3);
//delay(100000);
}
int ppm_to_ppb(int a)
{
  return (a*1000);
}
void aqi(int a,int b,int c,int d)
{
  int e,f,g;
  e=(a>b)?a:b;
  f=(c>d)?c:d;
  g=(e>f)?e:f;
  Serial.print("Air Quality Index is=");
  Serial.println(g);
    if (0<=g>=50){Serial.println("Air Quality is Good.");}  
    else if (51<=g>=100){Serial.println("Air Quality is Satisfactory.");}
    else if (101<=g>200){Serial.println("Air Quality is Moderately Polluted.");}
    else if (201<=g>=300){Serial.println("Air Quality is Poor.");}
    else if (301<=g>=400){Serial.println("Air Quality is Very Poor.");} 
    else {Serial.println("Air Quality is Severe.");}   
    if(s.available()>0)
       {
         s.write(g);
        }
        delay(10000);                                                                 
}
