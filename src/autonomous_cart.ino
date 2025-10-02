/*
 * Autonomous Shopping Cart - Person Following System
 * 
 * Description:
 *   This program controls an autonomous shopping cart that follows a person
 *   based on color signature detection using a Pixy2 camera. The cart uses
 *   an Arduino Uno for control logic and L298N motor driver for movement.
 * 
 * Hardware:
 *   - Arduino Uno Rev 3
 *   - Pixy2 CMUcam5
 *   - L298N Dual Motor Driver
 *   - 4x DC Motors with cart chassis
 * 
 * Pin Configuration:
 *   ENA  - Pin 5  (Left motor speed control)
 *   IN1  - Pin 6  (Left motor direction)
 *   IN2  - Pin 7  (Left motor direction)
 *   IN3  - Pin 8  (Right motor direction)
 *   IN4  - Pin 9  (Right motor direction)
 *   ENB  - Pin 10 (Right motor speed control)
 * 
 * Authors: Group 5 - Section B2
 *   - Joydip Chakraborty (1906117)
 *   - Abdullah Al Numan (1906121)
 *   - K M Fahim Asif (1906122)
 *   - Md Galib Mahmud Sharif (1906123)
 *   - SK Shahriar Iqbal (1906124)
 *   - Anik Biswas (1906125)
 * 
 * Course: EEE 318 - Control System I Laboratory
 * Institution: BUET - Department of Electrical and Electronic Engineering
 * Date: January 2023
 * 
 * License: MIT
 */

#include <SPI.h>
#include <Pixy2.h>

// Create Pixy2 object
Pixy2 pixy;

// Pin Configuration
// Format: {ENA, IN1, IN2, IN3, IN4, ENB}
int myPins[6] = {5, 6, 7, 8, 9, 10};

// Control Parameters
float deadZone = 0.15;    // Dead zone for center position (prevents oscillation)
// int baseSpeed = 130;   // Base speed for motors (optional, for future use)

// Variables for tracking
int cont = 0;                                      // Counter for lost object
int signature, x, y, width, height;                // Object detection variables
float cx, cy, area;                                // Calculated center and area

/*
 * Setup Function
 * Initializes serial communication, Pixy2 camera, and motor control pins
 */
void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.print("Starting...\n");
  
  // Initialize Pixy2 camera
  pixy.init();
  
  // Configure motor control pins as outputs
  for (int i = 0; i < 6; i++) {
    pinMode(myPins[i], OUTPUT);
  }
}

/*
 * Main Loop
 * Continuously checks Pixy2 camera for detected objects and controls robot movement
 */
void loop() {
  // Get turning value from Pixy camera
  float turn = pixyCheck();
  
  // Apply dead zone to prevent small oscillations
  if ((-turn) > -deadZone && (-turn) < deadZone) {
    turn = 0;
  }
  
  // Determine robot movement based on object position
  if ((-turn) < 0) {
    // Object is on the left - turn left
    moveRobot(-80, 170);
  }
  else if ((-turn) > 0) {
    // Object is on the right - turn right
    moveRobot(170, -80);
  }
  else {
    // Object is centered - move forward
    moveRobot(70, 70);
  }
  
  // Small delay for stability
  delay(1);
}

/*
 * Pixy Camera Check Function
 * 
 * Returns:
 *   float: Normalized X-axis position of detected object (-1 to 1)
 *          Negative = left, Positive = right, 0 = center
 */
float pixyCheck() {
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32];
  
  // Request blocks from Pixy2
  pixy.ccc.getBlocks();
  
  // Variables for object information
  int objectSignature, objectX, objectY, objectWidth, objectHeight;
  
  // Check if any objects are detected
  if (pixy.ccc.numBlocks) {
    // Iterate through all detected blocks
    for (int i = 0; i < pixy.ccc.numBlocks; i++) {
      // Get object information from detected block
      objectSignature = pixy.ccc.blocks[i].m_signature;
      objectX = pixy.ccc.blocks[i].m_x;
      objectY = pixy.ccc.blocks[i].m_y;
      objectWidth = pixy.ccc.blocks[i].m_width;
      objectHeight = pixy.ccc.blocks[i].m_height;
      
      // Print object information to serial monitor for debugging
      Serial.print("Object Signature: ");
      Serial.print(objectSignature);
      Serial.print(", X: ");
      Serial.print(objectX);
      Serial.print(", Y: ");
      Serial.print(objectY);
      Serial.print(", Width: ");
      Serial.print(objectWidth);
      Serial.print(", Height: ");
      Serial.println(objectHeight);
    }
    
    // Small delay for readability
    delay(100);
    
    // Update tracking variables with latest detection
    x = objectX;
    y = objectY;
    width = objectWidth;
    height = objectHeight;
    
    // Calculate center position of detected object
    cx = (x + (width / 2));
    cy = (y + (height / 2));
    
    // Normalize coordinates to -1 to 1 range
    // Pixy2 resolution: 320x200 pixels
    cx = mapfloat(cx, 0, 320, -1, 1);
    cy = mapfloat(cy, 0, 200, 1, -1);
    
    // Calculate object area (for future use)
    area = width * height;
  }
  else {
    // No object detected - increment lost counter
    cont += 1;
    
    // Reset position after 100 failed detections
    if (cont == 100) {
      cont = 0;
      cx = 0;
    }
  }
  
  return cx;
}

/*
 * Map Float Function
 * Maps a float value from one range to another
 * 
 * Parameters:
 *   x       - Input value
 *   in_min  - Input range minimum
 *   in_max  - Input range maximum
 *   out_min - Output range minimum
 *   out_max - Output range maximum
 * 
 * Returns:
 *   float: Mapped value
 */
float mapfloat(long x, long in_min, long in_max, long out_min, long out_max) {
  return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
}

/*
 * Move Robot Function
 * Controls the direction and speed of both motors
 * 
 * Parameters:
 *   leftSpeed  - Speed for left motor (-255 to 255)
 *                Positive = forward, Negative = backward
 *   rightSpeed - Speed for right motor (-255 to 255)
 *                Positive = forward, Negative = backward
 */
void moveRobot(int leftSpeed, int rightSpeed) {
  // Control left motor direction
  if (leftSpeed >= 0) {
    digitalWrite(myPins[1], 1);  // IN1
    digitalWrite(myPins[2], 0);  // IN2
  }
  else {
    digitalWrite(myPins[1], 0);
    digitalWrite(myPins[2], 1);
  }
  
  // Control right motor direction
  if (rightSpeed >= 0) {
    digitalWrite(myPins[3], 1);  // IN3
    digitalWrite(myPins[4], 0);  // IN4
  }
  else {
    digitalWrite(myPins[3], 0);
    digitalWrite(myPins[4], 1);
  }
  
  // Set motor speeds using PWM
  analogWrite(myPins[0], abs(leftSpeed));  // ENA - Left motor speed
  analogWrite(myPins[5], abs(rightSpeed)); // ENB - Right motor speed
}
