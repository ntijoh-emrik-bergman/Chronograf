//Emrik Bergman 2B
//chronograph

#include <U8glib.h>
#include <Arduino.h>

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);

const int LDR1 = A0; // LDR sensor 1
const int LDR2 = A1; // LDR sensor 2


void setup() {
  Serial.begin(9600); // start serial communication
  u8g.setFont(u8g_font_helvB10); // Set font to helvetica
  u8g.firstPage();
  do {
    u8g.drawStr(0, 13, "Initializing...");
  } while ( u8g.nextPage() );
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);
  Serial.print("Igång");
}

void loop() {
  //in: ldrvalues
  //out: None
  //do: Measures the time that it takes for a projectile to travel between LDR1 and LDR2 and calculates the speed based on a preset distance and displays the resuölt on an oled screen
  int ldr1Value = analogRead(LDR1);
  int ldr2Value = analogRead(LDR2);
  Serial.println(ldr1Value);
  Serial.println(ldr2Value);
 
}
