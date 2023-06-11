#include <SPI.h> 
#include <RFID.h>
RFID rfid(10,9);
void setup() {
  Serial.begin(9600);   
  SPI.begin();          
  rfid.init();          
}

void loop() {
  if(rfid.isCard()){  
   if(rfid.readCardSerial()){
    
      Serial.print("Card ID: ");
      Serial.print(rfid.serNum[0],HEX);
      Serial.print(rfid.serNum[1],HEX);
      Serial.print(rfid.serNum[2],HEX);
      Serial.print(rfid.serNum[3],HEX);
      Serial.println(rfid.serNum[4],HEX);

    }
    rfid.halt();  
  }
}
