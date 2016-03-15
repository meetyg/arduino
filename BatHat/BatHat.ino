// Include Libraries:
#include <NewPing.h> // For Sonar Sensor
#include <LiquidCrystal.h> // For LCD Display
#include <NewTone.h>

// Initialize the LCD library with the numbers of the interface pins
// Do not change!
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


#define TRIGGER_PIN  3  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     2  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 300 // Maximum distance we want to ping for (in centimeters). 

#define SPEAKER_PIN 1

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

// Setup function.
void setup() 
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  lcd.clear();
  lcd.print("Range:");  
}

void loop() 
{    
  // Send ping, get distance in cm
  unsigned long distance = sonar.ping_cm();

  // Move LCD cursor to proper position
  lcd.setCursor(7, 0);
  
   // Check distance result (0 = outside set distance range)
  if(distance == 0)
  {
    lcd.print("> ");
    lcd.print(MAX_DISTANCE);
    lcd.print(" cm     ");  
    noNewTone(SPEAKER_PIN); // stop the tone
  }
  else
  {
    lcd.print(distance);
    lcd.print(" cm     ");  
    
    // Play tone (50ms)    
    NewTone(SPEAKER_PIN,1000, 50);
    // "Sleep" longer time for longer distance,
    // will make tone shorter.
    delay(distance);        
  } 

  lcd.print(" cm     ");  
  
  // Wait 50ms between pings 
  delay(50); 
}
