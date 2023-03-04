//Emrik Bergman 2B
//chronograf


#include <U8glib.h>
#include <Arduino.h>

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);

const int LDR1 = A0; // LDR sensor 1
const int LDR2 = A1; // LDR sensor 2

unsigned long startTime;
unsigned long endTime;
float distance = 0.11; // distance between LDR sensors in meters
float speed;

void setup() {
  Serial.begin(9600); // start serial communication
  u8g.setFont(u8g_font_6x10);
  u8g.firstPage();
  do {
    u8g.drawStr(0, 10, "Initializing...");
  } while ( u8g.nextPage() );
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);
  Serial.print("Igång");
}

void loop() {
  int ldr1Value = analogRead(LDR1);
  int ldr2Value = analogRead(LDR2);

  

  if (ldr1Value > 600 && ldr2Value < 600) { // detect projectile passing LDR1
    startTime = millis();
  }
  if (ldr2Value > 600 && ldr1Value < 600) { // detect projectile passing LDR2
    endTime = millis();
    speed = distance / ((endTime - startTime) / 1000.0);
    Serial.print("Projectile speed: ");
    Serial.print(speed);
    Serial.println(" m/s");
    u8g.firstPage();
    do {
      u8g.drawStr(0, 10, "Projectile speed:");
      u8g.drawStr(0, 20, (String(speed) + " m/s").c_str());
    } while ( u8g.nextPage() );
  }
}
