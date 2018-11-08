// Wemos D1 Mini E1.31 - 6 channel dumb RGB led sketch.

#include <ESP8266WiFi.h>
#include <E131.h> // Copyright (c) 2015 Shelby Merrick http://www.forkineye.com

// ***** USER SETUP STUFF *****
const char ssid[] = "SSID";  // replace with your SSID.
const char passphrase[] = "PASSPHRASE"; // replace with your PASSWORD.
const int universe = 1; // this sets the universe number you are using.

// this sets the channel number used by the output.
const int channel_1_green = 1; // the channel number to link to output 1 red.



// this sets the pin numbers to use as outputs.
const int output_1_green = D1; // the pin to use as output 1 red (D2).


E131 e131;

void setup() {
  Serial.begin(115200);

  // set the pins chosen above as outputs.
  pinMode(output_1_green, OUTPUT);

  // set the pins chosen above to low / off.
  digitalWrite(output_1_green, LOW);

  /* Choose one to begin listening for E1.31 data */
 e131.begin(ssid, passphrase);               /* via Unicast on the default port */
//   e131.beginMulticast(ssid, passphrase, universe); /* via Multicast for Universe 1 */
}

void loop() {
  /* Parse a packet */
  uint16_t num_channels = e131.parsePacket();

  /* Process channel data if we have it */
  if (num_channels) {
  Serial.println("we have data");
    Serial.println(e131.data[channel_1_green]);

if (e131.data[channel_1_green] >= 200) //if channel value is greater then 127
      {
       digitalWrite(output_1_green, HIGH); //turn relay on
            } 
      else
      {
       digitalWrite(output_1_green, LOW); //else turn it off 
  }
}
}
 
