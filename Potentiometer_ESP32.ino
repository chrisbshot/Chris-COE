const int potPin = 34;      
const int ledPin = 25;   

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  analogReadResolution(12);  
}

void loop() {
  int potValue = analogRead(potPin);  

  // Map potentiometer value to PWM range (0-255)
  int pwmValue = map(potValue, 0, 4095, 0, 255);

  // Write PWM value to LED
  analogWrite(ledPin, pwmValue);  // Note: analogWrite is often remapped for ESP32

  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(" | PWM: ");
  Serial.println(pwmValue);

  delay(100);
}
