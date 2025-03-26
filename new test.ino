// Pulse Paint - Send raw pulse data for interactive visuals
const int pulseSensor1Pin = A0; // Controls stroke and color
const int pulseSensor2Pin = A2; // Controls motion

const int threshold = 400;
const int smoothingWindow = 10;
int buffer1[smoothingWindow] = {0};
int buffer2[smoothingWindow] = {0};
int index = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int raw1 = analogRead(pulseSensor1Pin);
  int raw2 = analogRead(pulseSensor2Pin);

  raw1 = (raw1 > threshold) ? raw1 : 0;
  raw2 = (raw2 > threshold) ? raw2 : 0;

  buffer1[index] = raw1;
  buffer2[index] = raw2;
  index = (index + 1) % smoothingWindow;

  int avg1 = average(buffer1, smoothingWindow);
  int avg2 = average(buffer2, smoothingWindow);

  Serial.print(avg1);
  Serial.print(",");
  Serial.println(avg2);

  delay(10);
}

int average(int* buffer, int size) {
  long sum = 0;
  for (int i = 0; i < size; i++) {
    sum += buffer[i];
  }
  return sum / size;
}
