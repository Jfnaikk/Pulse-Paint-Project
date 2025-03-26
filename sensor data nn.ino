// Arduino Sketch: Compatible with Pulse Paint BPM Processing Sketch

const int pulseSensor1Pin = A0;
const int pulseSensor2Pin = A2;

const int threshold = 550;
const int debounceTime = 300; // milliseconds

unsigned long lastBeat1 = 0;
unsigned long lastBeat2 = 0;
bool beatDetected1 = false;
bool beatDetected2 = false;

int bpm1 = 0;
int bpm2 = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int signal1 = analogRead(pulseSensor1Pin);
  int signal2 = analogRead(pulseSensor2Pin);
  unsigned long now = millis();

  // Beat detection for Sensor 1
  if (!beatDetected1 && signal1 > threshold && now - lastBeat1 > debounceTime) {
    if (lastBeat1 > 0) {
      bpm1 = 60000 / (now - lastBeat1);
    }
    lastBeat1 = now;
    beatDetected1 = true;
    Serial.print("Pulse Sensor 1: Beat detected | Value: ");
    Serial.print(signal1);
    Serial.print(" | BPM: ");
    Serial.println(bpm1);
  } else if (signal1 < threshold) {
    beatDetected1 = false;
  }

  // Beat detection for Sensor 2
  if (!beatDetected2 && signal2 > threshold && now - lastBeat2 > debounceTime) {
    if (lastBeat2 > 0) {
      bpm2 = 60000 / (now - lastBeat2);
    }
    lastBeat2 = now;
    beatDetected2 = true;
    Serial.print("Pulse Sensor 2: Beat detected | Value: ");
    Serial.print(signal2);
    Serial.print(" | BPM: ");
    Serial.println(bpm2);
  } else if (signal2 < threshold) {
    beatDetected2 = false;
  }

  delay(5);
}
