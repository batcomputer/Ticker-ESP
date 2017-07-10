#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#define OLED_RESET LED_BUILTIN  //4
Adafruit_SSD1306 display(OLED_RESET);




 
const char* ssid = "";
const char* password = "";

void setup () {
  

 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
// display.setTextWrap(false);

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ");
   
   while(WiFi.status() != WL_CONNECTED)
   {
     delay(500);
     Serial.print(".");
   }
 
   Serial.println("Connected");
}




  
   
  

 void loop() {   
  
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
  
    HTTPClient http;  //Declare an object of class HTTPClient
 
    http.begin("");  //Specify request destination
    
    Serial.print("[HTTP] GET...\n");
    int httpCode = http.GET();  
    display.clearDisplay();
    //Send the request
 
    if (httpCode == 200) { //Check the returning code
        //Serial.println(httpCode);
        //String payload = http.getString();






        
        String payload = http.getString();
                  //Serial.println(payload);
             // http.writeToStream(&Serial);
              //Serial.println(payload);
              payload.remove(1,72);
           
              display.setCursor(5,0);
              display.println(payload);
              //display.startscrolldiagright(0x00, 0x07);
              //display.stopscroll();
              //display.startscrollright(0x00, 0x1E);
              display.display(); 
          
              
              
                   
    }

    http.end();   //Close connection
 

delay(1000);
 
    http.begin("");  //Specify request destination
    
    Serial.print("[HTTP] GET...\n");
    int Code = http.GET();  
    display.clearDisplay();
    //Send the request
 
    if (Code == 200) { //Check the returning code
        //Serial.println(httpCode);
        //String payload = http.getString();
        String value = http.getString();
                  //Serial.println(payload);
             // http.writeToStream(&Serial);
              //Serial.println(payload);
              value.remove(1,72);
              display.setCursor(10,0);
              display.println(value);
              //display.startscrolldiagright(0x00, 0x07);
             // delay(5000);
             // display.stopscroll();
              //display.startscrollright(0x00, 0x1E);
              display.display();
    }
  http.end(); //Close connection
 }
 delay(1000);
}
