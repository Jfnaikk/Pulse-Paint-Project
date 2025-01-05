/* 
 * Date: November 23, 2024
 * Author: Jawad F. Naik
 * Class/Professor: Elements of Media / Fred Wolflink
 * Institution: Massachusetts College of Art and Design
 * Location: Boston, Massachusetts, USA
 * 
 * 
 * Description:
 *
 * This Arduino program reads data from two pulse sensors and sends the 
 * processed values to a connected Processing sketch. It uses a moving 
 * average to smooth the readings and filters out noise below a defined 
 * threshold. The data is sent to Processing in a comma-separated format 
 * for use in interactive visualizations, such as the Pulse Paint project.
 */

// Define pins for the two pulse sensors
const int pulseSensor1Pin = A0; // Pulse Sensor 1 (controls stroke and color)
const int pulseSensor2Pin = A2; // Pulse Sensor 2 (controls movement)

// Define parameters for noise filtering and smoothing
const int threshold = 500; // Minimum valid reading to filter noise
const int smoothingFactor = 10; // Number of readings for moving average
int pulse1Buffer[smoothingFactor]; // Buffer for smoothing Sensor 1 data
int pulse2Buffer[smoothingFactor]; // Buffer for smoothing Sensor 2 data
int bufferIndex = 0; // Index to track the current position in the buffer

void setup() {
  // Initialize serial communication with Processing
  Serial.begin(9600);

  // Initialize the buffers with zeros
  for (int i = 0; i < smoothingFactor; i++) {
    pulse1Buffer[i] = 0;
    pulse2Buffer[i] = 0;
  }
}

void loop() {
  // Read raw values from the pulse sensors
  int rawPulse1 = analogRead(pulseSensor1Pin);
  int rawPulse2 = analogRead(pulseSensor2Pin);

  // Filter out noise by ignoring values below the threshold
  if (rawPulse1 > threshold) {
    pulse1Buffer[bufferIndex] = rawPulse1;
  } else {
    pulse1Buffer[bufferIndex] = 0; // Set to zero if below the threshold
  }

  if (rawPulse2 > threshold) {
    pulse2Buffer[bufferIndex] = rawPulse2;
  } else {
    pulse2Buffer[bufferIndex] = 0; // Set to zero if below the threshold
  }

  // Calculate smoothed values using a moving average
  int pulse1Value = averageBuffer(pulse1Buffer, smoothingFactor);
  int pulse2Value = averageBuffer(pulse2Buffer, smoothingFactor);

  // Update the buffer index and wrap around when it reaches the end
  bufferIndex = (bufferIndex + 1) % smoothingFactor;

  // Send the smoothed pulse data to Processing in a comma-separated format
  Serial.print(pulse1Value); // Send Sensor 1 value
  Serial.print(",");         // Add a comma separator
  Serial.println(pulse2Value); // Send Sensor 2 value followed by a newline

  delay(20); // Short delay to control the data transmission rate
}

// Function to calculate the average of a buffer
int averageBuffer(int buffer[], int size) {
  int sum = 0; // Initialize sum for the buffer
  for (int i = 0; i < size; i++) {
    sum += buffer[i]; // Accumulate buffer values
  }
  return sum / size; // Return the average value
}
