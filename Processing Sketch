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
 * This program is part of the Pulse Paint project, an interactive art tool 
 * for couples in long-distance relationships. The program uses two pulse 
 * sensors to control digital painting collaboratively. One participant's 
 * pulse determines the color and stroke thickness, while the other's pulse 
 * governs movement and speed. The project is implemented in Processing and 
 * integrates Arduino for biometric data input.
 */

import processing.serial.*;
import java.text.SimpleDateFormat;
import java.util.Date;

// Serial communication object
Serial myPort;

// Pulse sensor variables
int pulse1 = 0; // Pulse Sensor 1 controls color and stroke thickness
int pulse2 = 0; // Pulse Sensor 2 controls movement and speed

// Brush properties
float brushX, brushY; // Current position of the brush
float targetX, targetY; // Target position for smooth movement

// Threshold value for detecting active pulse inputs
final int pulseThreshold = 580;

void setup() {
  // Set the canvas size to full screen for large displays (e.g., iMac 27 inches)
  fullScreen();
  background(0); // Set the canvas background color to black

  // Initialize serial communication with Arduino
  myPort = new Serial(this, "/dev/cu.usbmodem14101", 9600); // Replace with your Arduino port
  myPort.bufferUntil('\n'); // Read data line by line for processing

  // Initialize the brush position at the center of the canvas
  brushX = width / 2;
  brushY = height / 2;
  targetX = brushX;
  targetY = brushY;
}

void draw() {
  // Disable outlines for smooth and clean brush strokes
  noStroke();

  // Check if either pulse sensor exceeds the threshold to activate drawing
  if (pulse1 > pulseThreshold || pulse2 > pulseThreshold) {
    updateTargetPosition(); // Calculate new target position based on Sensor 2 input
    drawBrush(brushX, brushY, pulse1); // Render brush strokes based on Sensor 1 input
    smoothMovement(); // Gradually move the brush toward the target position
  }

  // Display user instructions at the bottom of the screen
  displayInstructions();
}

void serialEvent(Serial myPort) {
  // Read data from Arduino as a string
  String data = myPort.readStringUntil('\n');
  if (data != null) {
    // Split the data into pulse values for both sensors
    String[] values = trim(data).split(",");
    if (values.length == 2) {
      pulse1 = int(values[0]); // Assign Sensor 1 value (color and stroke thickness)
      pulse2 = int(values[1]); // Assign Sensor 2 value (movement and speed)
    }
  }
}

void drawBrush(float x, float y, int pulse) {
  // Map pulse values to brush size for dynamic visual effects
  float size = map(pulse, pulseThreshold, 1023, 50, 300); 
  float hue = frameCount % 360; // Generate continuous rainbow hues over time

  colorMode(HSB, 360, 100, 100); // Use HSB color mode for vibrant colors
  fill(hue, 100, 100, 100); // Set the fill color dynamically based on hue
  ellipse(x, y, size, size); // Render a circular brush stroke at the specified position
}

void updateTargetPosition() {
  // Map pulse values to determine the movement range of the brush
  float movementRange = map(pulse2, pulseThreshold, 1023, 10, 50);
  targetX += random(-movementRange, movementRange); // Update X-coordinate
  targetY += random(-movementRange, movementRange); // Update Y-coordinate

  // Apply wrap-around behavior for the brush position
  if (targetX < 0) targetX = width;
  if (targetX > width) targetX = 0;
  if (targetY < 0) targetY = height;
  if (targetY > height) targetY = 0;
}

void smoothMovement() {
  // Apply easing for smooth transitions toward the target position
  float easing = 0.08;
  brushX += (targetX - brushX) * easing;
  brushY += (targetY - brushY) * easing;
}

void displayInstructions() {
  // Render instructional text for the user
  fill(255); // Set text color to white
  textSize(20); // Adjust font size for visibility
  textAlign(CENTER, BOTTOM);
  text("Press SPACE BAR to save artwork and reset canvas.", width / 2, height - 20);
}

void keyPressed() {
  // Save the artwork and reset the canvas when the space bar is pressed
  if (key == ' ') {
    saveScreenshot(); // Save the current canvas as an image
    background(0); // Clear the canvas to black
  }
}

void saveScreenshot() {
  // Generate a timestamped filename for the saved artwork
  String timestamp = new SimpleDateFormat("yyyy-MM-dd_HH-mm-ss").format(new Date());
  String filename = "artwork_" + timestamp + ".png";
  save(filename); // Save the artwork as a PNG file
  println("Artwork saved as: " + filename); // Print confirmation in the console
}
