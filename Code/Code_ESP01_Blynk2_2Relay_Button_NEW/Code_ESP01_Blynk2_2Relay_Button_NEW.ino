/**********************************************************************************
 *  TITLE: Blynk 2.0 + Manual Button (Momentary) control 2 Relays using ESP8266 ESP01 (Real time feedback)(No Wi-Fi control)
 *  I have Modified the Blynk.Edgent.Edgent_ESP8266 example code (https://blynk.io/) for this project
 *  Click on the following links to learn more. 
 *  YouTube Video: https://youtu.be/0mAwbRi_CD4
 *  Related Blog : https://iotcircuithub.com/esp01-esp8266-projects-using-blynk-google/
 *  by Subhajit (Tech StudyCell)
 *  Preferences--> Aditional boards Manager URLs : 
 *  https://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json
 *  
 *  Download Board ESP8266 NodeMCU : https://github.com/esp8266/Arduino
 *  Download the libraries
 *  Blynk 1.0.1 Library:  https://github.com/blynkkk/blynk-library
 **********************************************************************************/

// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_DEVICE_NAME ""

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
#define BLYNK_DEBUG

//#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD


// define the GPIO connected with Relays and switches
// uncomment the following lines according to the board
//-------------------For ESP-01 board
#define RelayPin1 0  //GPIO-0
#define RelayPin2 2  //GPIO-2
#define SwitchPin1 3   //RX
#define SwitchPin2 1   //TX

//-------------------For NodeMCU board
//#define RelayPin1 12  //D6
//#define RelayPin2 13  //D7
//#define SwitchPin1 5   //D1
//#define SwitchPin2 4   //D2


#define wifiLed   16   //D0  (Do not Comment)

//Change the virtual pins according the rooms
#define VPIN_BUTTON_1    V1
#define VPIN_BUTTON_2    V2

// Relay State
bool toggleState_1 = LOW; //Define integer to remember the toggle state for relay 1
bool toggleState_2 = LOW; //Define integer to remember the toggle state for relay 2

#include "BlynkEdgent.h"

BLYNK_CONNECTED() {
  // Request the latest state from the server
  Blynk.syncVirtual(VPIN_BUTTON_1);
  Blynk.syncVirtual(VPIN_BUTTON_2);
}

// When App button is pushed - switch the state

BLYNK_WRITE(VPIN_BUTTON_1) {
  toggleState_1 = param.asInt();
  if(toggleState_1 == 1){
    digitalWrite(RelayPin1, LOW);
  }
  else { 
    digitalWrite(RelayPin1, HIGH);
  }
}

BLYNK_WRITE(VPIN_BUTTON_2) {
  toggleState_2 = param.asInt();
  if(toggleState_2 == 1){
    digitalWrite(RelayPin2, LOW);
  }
  else { 
    digitalWrite(RelayPin2, HIGH);
  }
}

void setup()
{
  Serial.begin(115200);
  delay(100);
  
  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);

  pinMode(wifiLed, OUTPUT);

  pinMode(SwitchPin1, INPUT_PULLUP);
  pinMode(SwitchPin2, INPUT_PULLUP);

  //During Starting all Relays should TURN OFF
  digitalWrite(RelayPin1, HIGH);
  digitalWrite(RelayPin2, HIGH);

  BlynkEdgent.begin();

  Blynk.virtualWrite(VPIN_BUTTON_1, toggleState_1);
  Blynk.virtualWrite(VPIN_BUTTON_2, toggleState_2);
}

void loop() {

    BlynkEdgent.run();
    
    manual_control(); //Manual Switch Control   
}
