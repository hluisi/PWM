#include <EL.h>

EL channel_a(A);
EL channel_b(B);
EL channel_c(C);

void setup() {
  channel_a.SetMaxBrightness(128);
  channel_b.SetMaxBrightness(128);
  channel_c.SetMaxBrightness(128); 
}

void loop() {
  channel_a.On();
  delay(1000);
  channel_a.Off();
  channel_b.On();
  delay(1000);
  channel_b.Off();
  channel_c.On();
  delay(1000);
  channel_c.Off();
}