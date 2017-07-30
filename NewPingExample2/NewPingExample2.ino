// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about (insert) times per second.
// ---------------------------------------------------------------------------
#include <NewPing.h>

#define TRIGGER_PIN  10  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     12  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
  delay(400);                      // Wait 5000ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  int uScm=uS / US_ROUNDTRIP_CM;
  Serial.print(uScm);// Convert ping time to distance in cm and print result (0 = outside set distance range)
  if(uScm==0)
    digitalWrite(13,LOW);
  else if(uScm<20)
    tone(13,4000);
  else
    digitalWrite(13,LOW);
  Serial.println("cm");
}
