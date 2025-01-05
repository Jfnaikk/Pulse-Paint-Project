Pulse Paint: Arduino and Processing Integration

Pulse Paint is an interactive project designed to foster creativity and connection between individuals in long-distance relationships. By leveraging biometric data from pulse sensors, the project enables participants to collaboratively create digital artwork in real-time. One person controls the brush's color and stroke thickness, while the other controls its movement and speed, creating a dynamic and meaningful shared experience.

Features

Biometric-Driven Art
Pulse-Controlled Stroke: Sensor 1 adjusts brush stroke size and dynamic colors based on heartbeat intensity.
Pulse-Controlled Movement: Sensor 2 governs brush movement and speed, allowing fluid and intuitive control.
Real-Time Interaction
Data is captured by Arduino, processed, and sent to Processing for immediate visualization.
Smooth and Dynamic Visuals
Brush strokes feature continuous rainbow hues and fluid motion across the canvas.
How It Works

Arduino
Sensor Inputs: Two pulse sensors capture heartbeat data.
Noise Filtering: Readings below a threshold are ignored to reduce interference.
Data Smoothing: A moving average algorithm ensures stable and smooth data transmission.
Serial Communication: Processed data is sent to Processing in a comma-separated format.
Processing
Data Visualization: Receives sensor data and translates it into dynamic visuals.
Interactive Brush: One sensor adjusts color and stroke thickness, while the other controls movement.
User-Friendly Design: Includes instructions for saving artworks and resetting the canvas.
Usage

Set Up Arduino:
Connect two pulse sensors to pins A0 and A2 on the Arduino board.
Upload the provided Arduino code to the board.
Run Processing Sketch:
Open the Processing sketch in the Processing IDE.
Ensure the correct serial port is specified for communication.
Press play to start the sketch.
Interact:
Place fingers on the pulse sensors.
Observe how your heartbeat dynamically controls the painting process.
Save Artwork:
Press the space bar to save your artwork with a timestamp.
File Structure

This project includes the following files:

PulsePaint_Arduino.ino: The Arduino code for reading and transmitting pulse sensor data.
PulsePaint_Processing.pde: The Processing sketch for rendering the interactive artwork.
README.md: Documentation for the project.
example.png: A sample image of the generated artwork (optional).
Controls

Pulse Sensors: Control stroke size, color, and brush movement.
Space Bar: Save the current artwork and reset the canvas.
Customization

Threshold Values: Adjust noise filtering by modifying the threshold variable in the Arduino code.
Smoothing Factor: Change the moving average sensitivity by altering the smoothingFactor variable.
Brush Dynamics: Personalize stroke size and colors by editing the drawBrush() function in the Processing sketch.
Canvas Size: Adjust the canvas resolution by modifying the fullScreen() function in Processing.
Author

This project was created by Jawad F. Naik as part of the course Elements of Media, taught by Professor Fred Wolflink at the Massachusetts College of Art and Design, located in Boston, Massachusetts, USA.

License

This project is open-source and licensed under the MIT License. See the LICENSE file for details.

Acknowledgments

Special thanks to:

The Processing Foundation for their exceptional IDE and creative coding tools.
The Massachusetts College of Art and Design for providing a platform to explore innovative ideas.
Professor Fred Wolflink for guidance and inspiration in the field of interactive media.
