#include <DHT.h>
#include <DHT_U.h>

#include <RTClib.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h>
//Mux control pins
int s0 = 8;
int s1 = 9;
int s2 = 10;
int s3 = 7;

//Mux in "SIG" pin
//int SIG_pin = 0;


RTC_DS1307 rtc;

const int chipSelect = 4;

const int PulseWire = 0;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
int Threshold = 550;           // Determine which Signal to "count as a beat" and which to ignore.
                               // Use the "Gettting Started Project" to fine-tune Threshold Value beyond default setting.
                               // Otherwise leave the default "550" value. 
                               
PulseSensorPlayground pulseSensor;
int serialData;

void setup() {
  Serial.begin(9600);  //initialize serial comms
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);


  // Open serial communications and wait for port to open:
  //Serial.begin(9600);
  while (!Serial)
    {
      ; // wait for serial port to connect. Needed for native USB port only
    }
  Serial.print("Initializing SD card...");
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect))
    {
      Serial.println("Card failed, or not present");
      // don't do anything more:
      while (1);
    }
  Serial.println("card initialized.");
  pulseSensor.analogInput(PulseWire);   
//  pulseSensor.blinkOnPulse(LED13);       //auto-magically blink Arduino's LED with heartbeat.
  pulseSensor.blinkOnPulse(CMD13);       //auto-magically blink Arduino's LED with heartbeat.
  pulseSensor.setThreshold(Threshold);
  if (pulseSensor.begin())
  {
    Serial.println("We created a pulseSensor Object !");  
  }
  Wire.begin();
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
  File dataFile = SD.open("pulse.txt", FILE_WRITE);
  dataFile.println("Date      , Time     , BPM");
  dataFile.close();
    Serial.println("Date      , Time     , BPM");
}
void loop() {
  if (Serial.available()) {
    serialData = Serial.read();
    if(serialData == '1'){
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(7, LOW);
    }
    else if(serialData == '0'){
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(7, LOW);
    }
     else if(serialData == '2'){
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(7, LOW);
    }
     else if(serialData == '3'){
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(7, LOW);
    }
     else if(serialData == '4'){
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(7, LOW);
    }
    else if(serialData == '5'){
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(7, LOW);
    }
        else if(serialData == '6'){
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(7, LOW);
    }
      else if(serialData == '7'){
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(7, LOW);
    }
          else if(serialData == '8'){
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(7, HIGH);
    }
      else if(serialData == '9'){
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(7, HIGH);
  }
    else if(serialData == 'A'){
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(7, HIGH);
}
  else if(serialData == 'B'){
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(7, HIGH);}
       else if(serialData =='C'){
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(7, HIGH);}
   else if(serialData == 'D'){
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(7, HIGH);}
       else if(serialData == 'E'){
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(7, HIGH);}
       else if(serialData == 'F'){
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(7, HIGH);}
}


  if (Serial.available()) {
    serialData = Serial.read();
    if(serialData == '1'){
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(7, LOW);
    }
    else if(serialData == '0'){
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(7, LOW);
    }
     else if(serialData == '2'){
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(7, LOW);
    }
     else if(serialData == '3'){
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(7, LOW);
    }
     else if(serialData == '4'){
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(7, LOW);
    }
    else if(serialData == '5'){
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(7, LOW);
    }
        else if(serialData == '6'){
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(7, LOW);
    }
      else if(serialData == '7'){
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(7, LOW);
    }
          else if(serialData == '8'){
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(7, HIGH);
    }
      else if(serialData == '9'){
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(7, HIGH);
  }
    else if(serialData == 'A'){
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(7, HIGH);
}
  else if(serialData == 'B'){
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(7, HIGH);}
       else if(serialData =='C'){
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(7, HIGH);}
   else if(serialData == 'D'){
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(7, HIGH);}
       else if(serialData == 'E'){
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(7, HIGH);}
       else if(serialData == 'F'){
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(7, HIGH);}
}
  // make a string for assembling the data to log:
  String dataString = "";

  int myBPM = pulseSensor.getBeatsPerMinute(); 
  if(myBPM)
  {
      dataString = String(myBPM);
  }
  else
  {
    dataString = "";
  }
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("pulse.txt", FILE_WRITE);
  DateTime now = rtc.now();
  //sprintf(t, "%02d:%02d:%02d %02d/%02d/%02d", now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year());  
  //Serial.print(F("Date/Time: "));
  //Serial.println(t);
  // if the file is available, write to it:
  if (dataFile) {
    if(dataString != "")
    {
        Serial.print(now.day());
        Serial.print('-');
        Serial.print(now.month());
        Serial.print('-');
        Serial.print(now.year());
        Serial.print(" , ");
        Serial.print(now.hour());
        Serial.print(':');
        Serial.print(now.minute());
        Serial.print(':');
        Serial.print(now.second());
        Serial.print(" , ");        
        Serial.println(dataString);      
        dataFile.print(now.day());
        dataFile.print('-');
        dataFile.print(now.month());
        dataFile.print('-');
        dataFile.print(now.year());
        dataFile.print(" , ");
        dataFile.print(now.hour());
        dataFile.print(':');
        dataFile.print(now.minute());
        dataFile.print(':');
        dataFile.print(now.second());
        dataFile.print(" , ");        
        dataFile.println(dataString);      
    } 
    dataFile.close();
    // print to the serial port too:
           
  }
  // if the file isn't open, pop up an error:
   else {
    Serial.println("error opening datalog.txt");
    while(1); 
  }
  delay(1000);
}
