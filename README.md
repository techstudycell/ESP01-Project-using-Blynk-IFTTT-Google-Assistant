# ESP01-Project-using-Blynk-IFTTT-Google-Assistant
In this IoT project, I have shown how to make an ESP01 Project using Blynk IFTTT to control a 2-channel relay module with the Google Assistant, and manual switch.

During the article, I have shown all the steps to make this Blynk home automation system.

## Tutorial Video on new Blynk ESP8266 ESP01 Project

Video Link:  https://youtu.be/0mAwbRi_CD4

This Blynk ESP8266 control smart relay has the following features:

1. Control home appliances with Google Assistant.
2. Control home appliances with the Blynk IoT app.
3. Control home appliances with Blynk web dashboard.
4. Control home appliances manually with push buttons.
5. Monitor real-time feedback in the Blynk IoT App.

So, you can easily make this home automation project at home just by using an ESP01 and relay module. Or you can also use a custom-designed PCB for this project.

## Required Components for the PCB
1. ESP01 ESP8266
2. Relays 5v (SPDT) (2 no)
3. BC547 Transistors (2 no)
4. PC817 Optocuplors (2 no)
5. 510-ohm 0.25-watt Resistor (2 no) (R1 -- R2)
6. 1k 0.25-watt Resistors (3 no) (R3 -- R5)
7. LED 5-mm (3 no)
8. 1N4007 Diodes (2 no) (D1 -- D2)
9. Push Buttons (3 no)
10. Terminal Connectors
11. Jumper (2no)
12. Switch (1no)
13. 5V DC supply

## Circuit Diagram of the ESP01 Home Automation Project
This is the complete circuit diagram for this home automation project. I have explained the circuit in the tutorial video.
The circuit is very simple, I have used GPIO-0 and GPIO-2 to control the 2 relays.
And the GPIO pins GPIO-3 and GPIO-1are connected with push buttons to control the 2 relays manually.
I have used the INPUT_PULLUP function in Arduino IDE instead of using the pull-up resistors.
I have used a 5V mobile charger to supply the smart relay module.
After programming the ESP01 disconnect the GPIO-0 from the GND pin.

## Setup Blynk Cloud FREE Account
For this smart house project, I have used the Blynk IoT Cloud Free plan.
Click on the following link to create a Blynk Cloud account.
https://blynk.cloud/dashboard/register

1. Enter email ID, then click on "Sign Up".
2. You will receive a verification email.
3. Click on Create Password in the email, Then set the password, click on Next.
4. Enter your first name, click on Done.
5. After that Blynk cloud dashboard will open.
Then, you have to create a template in the Blynk cloud.

## Steps to Create New Template for ESP8266

1. Click on New Template.
2. Enter a template name, select the hardware as ESP8266, and the connection type will WiFi.
3. Then click on DONE.
You will get the BLYNK_TEMPLATE_ID and BLYNK_DEVICE_NAME after creating the temple.

The BLYNK_TEMPLATE_ID and BLYNK_DEVICE_NAME will be required while programming the ESP01 ESP8266.

## Create Datastreams in Blynk Cloud
After that, you have to create Datastreams. Here I will control 2 relays, so I have to create 2 Datastreams.

1. Go to the Datastreams tab.
2. Click on New Datastream and select Virtual Pin.
3. Enter a name, select the virtual pin V1, and the datatype will be Integer.
4. Then click on Create.
In a similar way, create the next datastreams with virtual pin V2.

## Set Up Blynk Cloud Web Dashboard
Now go to the web dashboard tab.
Drag and drop 2 Switch widgets.
Go to the settings of each widget, and select a Datastream.

## Install Blynk IoT App to Configure Mobile Dashboard
1. Install the Blynk IoT app from Google Play Store or App Store. Then log in.
2. Go to Developer Mode.
3. Tap on the template that you have already made.
4. Now go to the Widget box (on the right) to add widgets.

## Add Widgets in Blynk IoT App
1. 4 Button widgets from Widget Box.
2. Go to Button widget settings.
3. Enter the name, select Datastream, Mode will be Switch. Then exit.
4. After setting all the Buttons tap on exit.

## Design the PCB for This Smart Home System
To make the circuit compact and give a professional look, I have designed the PCB after testing all the features of the smart relay module.

You can download the PCB Gerber file of this home automation project from the following link:
https://iotcircuithub.com/wp-content/uploads/2021/12/PCB_Gerber_ESP01_Relay2_Manual_01.zip

## Order the PCB from JLCPCB
After downloading the Garber file you can easily order the PCB

Visit https://jlcpcb.com/RAB and Sign in / Sign up.

1. Click on the QUOTE NOW button.
2. Click on the "Add gerber file" button. Then browse and select the Gerber file you have downloaded.
3. Set the required parameter like Quantity, PCB masking color, etc.
4. After selecting all the Parameters for PCB click on SAVE TO CART button.
5. Type the Shipping Address.
6. Select the Shipping Method suitable for you.
7. Submit the order and proceed with the payment.
8. You can also track your order from the JLCPCB.com

My PCBs took 2 days to get manufactured and arrived within a week using the DHL delivery option. PCBs were well packed and the quality was really good at this affordable price.


## Solder All the Components on PCB
After that, I have soldered all the components as per the circuit diagram.
Then connect the ESP01 board with the PCB.

## Program the ESP-01 With Arduino IDE
If you use the PCB, then you can easily go to program mode with a switch (PMOD) and directly connect the FTDI232 USB to serial interface board with ESP-01.
Otherwise, you refer to this circuit to program the ESP-01. During programming, the GPIO-0 and GND should be connected.

## Code for This ESP-01 Home Automation Project
First, download the code from the following link.
Download the Source Code
You have to keep all the 10 files in the same folder.
1. Open the .ino file in Arduino IDE.
2. In the code, you have to update the BLYNK_TEMPLATE_ID and BLYNK_DEVICE_NAME.
3. For this project, you have to install the Blynk 1.0.1 library.
4. Now select the "Generic ESP8266 Module" and proper PORT.
5. Then upload the code to ESP01 Board.
After uploading the code, turn off the PMOD switch on the PCB and press the reset button.

## Update the WiFi Credentials Through OTA
After programming the ESP01, you have to update the WiFi credentials from the Blynk IoT app.

In the tutorial video, I have explained all the steps to update the WiFi credentials to ESP-01 through OTA.

## Testing the PCB
After the ESP-01 connects with the Blynk server, control the relay from the Blynk IoT app to test the PCB.
Now we will connect the Google Assistant with Blynk using IFTTT.

## Create FREE Account in IFTTT
Create an IFTTT account, then log in.
https://ifttt.com/
In the FREE plan, you can create 5 Applets. To control each relay you need 2 Applets, so to control 2 relays you need 4 Applets.
For each applet, you have to define a trigger and related action. In this project, if you say any pre-define commands in Google assistant, then the related Webhook request will be sent to the Blynk Cloud server.

## Create Google Assistant Trigger for Applet in IFTTT
Steps to add Google Assistant Trigger in Applet

1. Click on Create (on the top).
2. Click on Add.
3. Search for "Google Assistant" and click on it.
4. Click on "Say a Simple phrase".
5. Click on Connect and give the required permission.
6. Then enter "What you want to say" and "response" for Google Assistant (as shown in the picture).
7. Click on "Create trigger".

## Create Webhooks Action for Applet in IFTTT
Here in the action, we will add Webhooks to send web requests to update the Datastream value in the Blynk server.

1. Now click on the next Add button.
2. Search for Webhooks and click on it.
3. In Webhooks you have to mention the Blynk API URL.
Please refer to the following Blynk API URL syntax to update the Datastream value.
Syntax: https://{server_address}/external/api/update?token={token}&{pin}={value}

1. fra1.blynk.cloud – Frankfurt
2. lon1.blynk.cloud – London
3. ny3.blynk.cloud – New York
4. sgp1.blynk.cloud – Singapore
5. blr1.blynk.cloud – Bangalore
The server region could be found in the right bottom corner of the web interface.
You can get the Auth Token from the Device Info tab. (Refer to tutorial video on top)
Now, enter the related Blynk URL to update the Datastream value. The method will be "GET". Keep other details as it is. (Refer to the picture)

1. Click on Create Action.
2. Click on Continue.
3. Click on Finish.
Our first Applet is created. In a similar way, you have to create the next 3 Applets. Please refer to the tutorial video.

## Control Relays Using Blynk IoT App
If the ESP01 is connected with WiFi, then you can control the home appliances from Blynk IoT App.
You also use multiple smartphones to control the appliances with Blynk IoT App. For that, you have to log in same Blynk account from all the smartphones. In this way, all smartphones will be sink to the Blynk server.

## Control Relays With Google Assistant
You can also control the relay from Google Assistant with pre-defined voice commands.

## Control Relays Manually With Buttons
You can also control the relays from the pushbuttons.

If the ESP01 is connected with Wi-Fi then you can monitor the real-time feedback in the Blynk IoT App.

I hope you have liked this new Blynk home automation project. I have shared all the required information for this project.

I will really appreciate it if you share your valuable feedbacks. Also if you have any query please write in the comment section. 
Thank you & Happy Learning.
