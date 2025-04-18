/*
   Arduino Sketch: Pulse Paint Dual-Sensor BPM Output
   Sends formatted BPM data for Processing sketches BridgeOfBeats.pde and PulseGarden.pde
   Sensors connected to A0 and A2
   Ensure Serial Monitor is closed; Processing reads from the same port at 9600 baud.
*/

const int pulseSensor1Pin = A0;
const int pulseSensor2Pin = A2;

const int threshold = 550;      // Raw analog threshold for beat detection
const int debounceTime = 300;   // Minimum time between beats in milliseconds

unsigned long lastBeat1 = 0;
unsigned long lastBeat2 = 0;
bool beatDetected1 = false;
bool beatDetected2 = false;

int bpm1 = 0;
int bpm2 = 0;

void setup() {
  // Initialize serial for Processing at 9600 baud
  Serial.begin(9600);
}

void loop() {
  int signal1 = analogRead(pulseSensor1Pin);
  int signal2 = analogRead(pulseSensor2Pin);
  unsigned long now = millis();

  // Sensor 1 beat detection
  if (!beatDetected1 && signal1 > threshold && now - lastBeat1 > debounceTime) {
    if (lastBeat1 > 0) {
      bpm1 = 60000 / (now - lastBeat1);
    }
    lastBeat1 = now;
    beatDetected1 = true;
    // Print formatted line for Processing
    Serial.print("Pulse Sensor 1: Beat detected | Value: ");
    Serial.print(signal1);
    Serial.print(" | BPM: ");
    Serial.println(bpm1);
  } else if (signal1 < threshold) {
    beatDetected1 = false;
  }

  // Sensor 2 beat detection
  if (!beatDetected2 && signal2 > threshold && now - lastBeat2 > debounceTime) {
    if (lastBeat2 > 0) {
      bpm2 = 60000 / (now - lastBeat2);
    }
    lastBeat2 = now;
    beatDetected2 = true;
    // Print formatted line for Processing
    Serial.print("Pulse Sensor 2: Beat detected | Value: ");
    Serial.print(signal2);
    Serial.print(" | BPM: ");
    Serial.println(bpm2);
  } else if (signal2 < threshold) {
    beatDetected2 = false;
  }

  // Short delay to reduce noise
  delay(5);
}
