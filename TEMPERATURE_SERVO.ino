#include <M5Stack.h>      //Memasukkan Library M5stack
#include <DHT12.h>        //Memasukkan Library DHT12
#include "driver/ledc.h"  //Memasukkan Library driver ledchannel
#include <Wire.h>         //The DHT12 uses I2C comunication.
DHT12 DHT(&Wire);         //Preset scale CELSIUS and ID 0x5c.
const int servo_pin = 15; //Inisialisasi Pin Servo di PIN 15 
int freq = 50;            //Inisialisasi Frequensi 50
int ledChannel = 0;       //Inisialisasi ledchannel = 0 
int resolution = 8;       //Inisialisasi resolution = 8 
void setup() 
{
  M5.begin();
  Wire.begin();
  M5.Lcd.setCursor(80, 0, 4);                 //Letak setCursor 
  M5.Lcd.print("TEMPERATURE");                //Mencetak "TEMPERATURE" di LCD
  ledcSetup(ledChannel, freq, resolution);    //setup pada led (Yang berisikan ledchannel, frequensi, dan resolution)
  ledcAttachPin(servo_pin, ledChannel);       //menyematkan pin servo dan ledchannel
}

void loop() 
{
  float tmp = DHT.readTemperature();    //menampilkan temperature dengan bilangan  bulat
  M5.Lcd.setCursor(30, 100, 4);         //letak setCursor
  if (tmp>=30)                          //kondisi bila temperature diatas 30
  {
    ledcWrite(ledChannel, 18);//90°     //Membaca data pada ledchannel sebesar 90°
    delay(1000);                        //Memberikan delay 1 detik
  }

}
