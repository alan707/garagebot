/*
 * Project Garagebot
 * Description: An internet connected garage door opener
 * Author: Alan Mond
 * Date:2/6/2018
 */

// This #include statement was automatically added by the Particle IDE.
#include <blynk.h>

// This #include statement was automatically added by the Particle IDE.
#include <RelayShield.h>

SYSTEM_THREAD(ENABLED);

int garagedoor = D0;               
int val = 0; 


//Create an instance of the RelayShield library, so we have something to talk to
RelayShield myRelays;
int relayOn(String command);
int relayOff(String command);

int garageOpen(String command);
int garageClosed(String command);


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "7317bfac5d1a49e2852fcc88104adf40";

WidgetLED BlynkLED1(V4); // define LED to turn on and off on Blynk App.
WidgetLED BlynkLED2(V5); // define LED to turn on and off on Blynk App.


void setup()
{
 //.begin() sets up a couple of things and is necessary to use the rest of the functions
 
 // read garage door switch
 pinMode(garagedoor, INPUT_PULLDOWN);
 
 
    myRelays.begin();
    Blynk.begin(auth);
    myRelays.off(1);
    BlynkLED1.off(); // Start with all Bynk app LEDs turned off
    BlynkLED2.off(); // Start with all Bynk app LEDs turned off
    Particle.function("garageOpen", garageOpen);
    Particle.function("garageClosed", garageClosed);
}

void loop() {
    
    Blynk.run();
    if (digitalRead(garagedoor)) {
    BlynkLED2.on();
    BlynkLED1.off();
    }
    else{
    BlynkLED1.on();
    BlynkLED2.off();
    }
}

BLYNK_WRITE(V1) {
  static int oldParam = 0;
  if (param.asInt() && !oldParam) { // On button press
    toggleGarage();
  }
  oldParam = param.asInt();
}

void toggleGarage() {
    myRelays.on(1);
    delay(500);
    myRelays.off(1);
}


int relayOn(String command){
    // Ritual incantation to convert String into Int
    char inputStr[64];
    command.toCharArray(inputStr,64);
    int i = atoi(inputStr);

    // Turn the desired relay on
    myRelays.on(i);

    // Respond
    return 1;
}

int relayOff(String command){
    // Ritual incantation to convert String into Int
    char inputStr[64];
    command.toCharArray(inputStr,64);
    int i = atoi(inputStr);

    // Turn the desired relay off
    myRelays.off(i);

    // Respond
    return 1;
}

// TODO: Integrate with IFTTT
int garageOpen(String command)
{
  if (command == "garageOpen") // look for the matching argument from IFTTT <-- max of 64 characters long
    {
        toggleGarage();
    }
    return 1;
}

// TODO: Integrate with IFTTT
int garageClosed(String command) 
    {
    if(command == "garageClosed") // look for the matching argument  from IFTTT <-- max of 64 characters long
    {
        toggleGarage();
    }
    return 1;
}
