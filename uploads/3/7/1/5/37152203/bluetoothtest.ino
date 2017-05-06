#include <SoftwareSerial.h>
int led = 13;

//Bluetooth Modülünün TX ---> RX,  RX---> TX e bağlanmalı
SoftwareSerial mySerial(10, 11); // RX, TX

void setup(){
  
  
 Serial.begin(9600);
Bluetooth.begin(9600); 
pinMode(led, OUTPUT);
Serial.println("Program basliyor");

}

void loop(){
  
 String input = "";
 
 //indexof kullanılmasının nedeni bluetooth modülleri yazdığınız datanın sonuna bazı karakterler eklemektedir, 
 //bu nedenle gelen string'i birşeyle eşit olup olmadığına bakmak yerine stringin içinde aradğımız şey var mı diye bakmak gerek.
 
  while (mySerial.avaible() > 0)
  {
    input += (char)mySerial.read();
    delay(5);
  }
 
 if (input.indexOf("on") > -1){
  
   digitalWrite(led, HIGH);
   
 }
 //eger gönderilen stringin içinde off varsa led kapanıcak, gelen string mesela off_ olursa input.indexOf("off") = 0 olucak,
 //eğer gönderilen string "mahmut" ise input.indexOf("off") = -1 olur, bu nedenle aşşağıdaki ifade de > -1 ifadesi kullanılır.
 
 else if (input.indexOf("off") > -1)
 {
   digitalWrite(led, LOW);
   
 }
 
 
  
  
}
