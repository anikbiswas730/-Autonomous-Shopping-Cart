# User Manual - Autonomous Shopping Cart

## Table of Contents
1. [Safety Instructions](#safety-instructions)
2. [Getting Started](#getting-started)
3. [Training Color Signatures](#training-color-signatures)
4. [Operating the Cart](#operating-the-cart)
5. [Troubleshooting](#troubleshooting)
6. [Maintenance](#maintenance)

---

## Safety Instructions

 **IMPORTANT: Read all safety instructions before operating the cart**

### Before Use
- Ensure all connections are secure and insulated
- Check battery voltage is within safe operating range (7-12V recommended)
- Verify motors are firmly attached to chassis
- Inspect wheels for damage or obstructions
- Keep loose cables away from moving parts

### During Operation
- Maintain a safe distance (30-100 cm recommended)
- Avoid sudden movements that may confuse the tracking system
- Do not operate in crowded areas during initial testing
- Keep hands and clothing away from wheels and motors
- Have an emergency stop method ready (power switch accessible)

### Environmental Considerations
- Use in well-lit environments for optimal camera performance
- Avoid direct sunlight which may interfere with color detection
- Do not use near stairs or elevated platforms
- Avoid wet or slippery surfaces
- Keep away from strong magnetic fields

---

## Getting Started

### Initial Setup

#### 1. Hardware Assembly
Ensure your cart is assembled with:
- 4 DC motors mounted on chassis
- L298N motor driver connected to Arduino
- Pixy2 camera securely mounted at front
- Battery pack installed and secured
- All wiring connections verified against circuit diagram

#### 2. Power Up Sequence
1. **Connect battery** to motor driver power input
2. **Connect Arduino** to computer via USB (for initial setup)
3. **Power on** motor driver
4. **LED indicators** should illuminate on Arduino and Pixy2
5. Wait for **Pixy2 initialization** (LED changes from red to multicolor)

---

## Training Color Signatures

The cart follows objects based on color. You must first "teach" the Pixy2 camera what to follow.

### Method 1: Using PixyMon (Computer)

#### Step 1: Connect Pixy2 to Computer
1. Disconnect Pixy2 from Arduino
2. Connect Pixy2 to computer using USB cable
3. Launch **PixyMon v2** application

#### Step 2: Teach Color Signature
1. In PixyMon, select **"Action → Set Signature 1"**
2. Point camera at the target color/object
3. Click and drag a box around the color you want to track
4. The software will highlight detected areas in that color
5. Click **"OK"** to save the signature

#### Step 3: Verify Detection
1. Move the colored object around
2. Pixy2 should draw boxes around detected colors
3. Check detection is consistent and accurate
4. If needed, retrain by repeating Step 2

#### Step 4: Save and Reconnect
1. Disconnect Pixy2 from computer
2. Reconnect Pixy2 to Arduino via SPI connection
3. Signature is saved in Pixy2 memory

### Method 2: Using Pixy2 Button (Without Computer)

#### Quick Training Process
1. **Press and hold** the button on top of Pixy2
2. **Point camera** at the target color
3. **Release button** when LED turns off (1-2 seconds)
4. **LED will blink** to confirm signature saved
5. Signature is now stored as "Signature 1"

### Choosing Good Colors

**Best Colors to Track:**
-  Bright, saturated colors (red, orange, blue, green)
-  Unique colors not commonly found in environment
-  Matte finishes (avoid shiny or reflective surfaces)
-  Large colored areas (at least 10cm x 10cm)

**Avoid:**
-  White, black, or gray (poor contrast)
-  Colors matching floor, walls, or common items
-  Metallic or reflective materials
-  Very small colored objects

**Pro Tip:** Use a colored vest, armband, or marker attached to clothing for consistent tracking.

---

## Operating the Cart

### Basic Operation

#### 1. Pre-Flight Check
- [ ] Battery charged and connected
- [ ] All cables secure
- [ ] Pixy2 camera trained on target color
- [ ] Clear area with no obstacles
- [ ] Emergency stop accessible

#### 2. Starting the Cart
1. **Upload code** to Arduino (if first time or code changed)
2. **Disconnect USB** cable from Arduino
3. **Power on** the system
4. **Wait 3-5 seconds** for initialization
5. **Position cart** behind the person/object to follow
6. **Wear/hold** the trained colored marker
7. Cart should **automatically detect and follow**

#### 3. Normal Operation

**Forward Movement:**
- Stand in front of cart wearing colored marker
- Cart moves forward when object is centered
- Maintain distance of 30-100 cm for best results

**Turning:**
- Move left/right to guide the cart
- Cart adjusts direction to keep object centered
- Allow 1-2 seconds for cart to respond

**Stopping:**
- Remove colored object from view
- Cart will stop after losing tracking for ~10 seconds
- Or use emergency power switch

### Advanced Settings

You can modify behavior by changing values in the code:

#### Adjusting Dead Zone
```cpp
float deadZone = 0.15;  // Default value
```
- **Increase** (e.g., 0.20) = Less sensitive, smoother movement
- **Decrease** (e.g., 0.10) = More sensitive, may oscillate

#### Adjusting Motor Speeds
```cpp
// In loop() function:
moveRobot(-80, 170);  // Left turn
moveRobot(170, -80);  // Right turn
moveRobot(70, 70);    // Forward
```
- **First number**: Left motor speed (-255 to 255)
- **Second number**: Right motor speed (-255 to 255)
- Increase for faster movement, decrease for slower

---

## Troubleshooting

### Cart Doesn't Move

**Possible Causes:**
1. **No power**
   - Check battery voltage (should be 7-12V)
   - Verify power switch is ON
   - Check LED indicators on Arduino and motor driver

2. **Motor driver not receiving commands**
   - Verify all pin connections
   - Check for loose wires
   - Test with multimeter at motor driver inputs

3. **Code not uploaded**
   - Re-upload sketch to Arduino
   - Check for compilation errors
   - Verify correct board selected in Arduino IDE

### Cart Doesn't Follow Object

**Possible Causes:**
1. **Color not detected**
   - Open Serial Monitor (9600 baud) to see detection data
   - If no data appears, retrain color signature
   - Improve lighting conditions
   - Ensure color is within camera field of view

2. **Multiple colors detected**
   - Remove other objects with similar colors
   - Choose more unique color signature
   - Adjust camera angle to avoid background interference

3. **Poor lighting**
   - Move to better-lit area
   - Avoid backlighting (light behind object)
   - Avoid direct sunlight on camera lens

### Cart Moves Erratically

**Possible Causes:**
1. **Dead zone too small**
   - Increase `deadZone` value to 0.20-0.25
   - Re-upload code and test

2. **Motor speeds too high**
   - Reduce speed values in `moveRobot()` calls
   - Start with speeds around 50-100

3. **Interference**
   - Check for loose connections
   - Ensure battery provides stable voltage
   - Move away from electromagnetic interference sources

### Cart Turns in Wrong Direction

**Possible Cause:**
- Motor wires reversed

**Solution:**
1. Power off the system
2. Swap the two wires for the affected motor at motor driver
3. Test again

### Pixy2 Not Detecting Color

**Possible Causes:**
1. **Signature not trained**
   - Retrain using PixyMon or button method
   - Verify signature saved to Slot 1

2. **Camera angle wrong**
   - Adjust camera to point at expected object height
   - Tilt slightly downward for ground-level markers

3. **Color too similar to background**
   - Choose more contrasting color
   - Use brighter, more saturated colors

---

## Maintenance

### Daily Checks (Before Each Use)
- [ ] Inspect all wire connections
- [ ] Check battery voltage
- [ ] Clean camera lens with soft cloth
- [ ] Verify wheels rotate freely
- [ ] Check for loose screws or components

### Weekly Maintenance
- [ ] Clean dust from motors and electronics
- [ ] Tighten all mounting screws
- [ ] Inspect wheels for wear
- [ ] Check motor driver for overheating signs
- [ ] Test all functions in safe area

### Monthly Maintenance
- [ ] Deep clean all components
- [ ] Check solder joints for cracks
- [ ] Lubricate wheel bearings if necessary
- [ ] Update firmware if improvements available
- [ ] Document any issues or modifications

### Battery Care
- **Charging**: Fully charge before use
- **Storage**: Store at 40-60% charge if not using for extended period
- **Temperature**: Avoid charging in extreme temperatures
- **Replacement**: Replace if battery doesn't hold charge

### Pixy2 Camera Care
- **Cleaning**: Use microfiber cloth only
- **Protection**: Avoid touching lens
- **Storage**: Keep lens cap on when not in use
- **Moisture**: Keep away from water and humidity

---

## Specifications

### Performance Specifications
| Parameter | Value |
|-----------|-------|
| Following distance | 30-100 cm |
| Maximum speed | ~0.3 m/s |
| Response time | 1-2 seconds |
| Detection range | 30-200 cm |
| Operating time | 30-60 minutes (battery dependent) |

### Technical Specifications
| Component | Specification |
|-----------|--------------|
| Microcontroller | Arduino Uno Rev 3 (ATmega328P) |
| Camera | Pixy2 CMUcam5 |
| Motor driver | L298N Dual H-Bridge |
| Motors | 4x DC geared motors |
| Power | 7-12V DC |
| Communication | SPI (Pixy2 to Arduino) |

---

## Tips for Best Performance

###  Tracking Tips
1. Use bright, unique colors
2. Maintain consistent distance (50-80 cm optimal)
3. Move smoothly, avoid sudden changes
4. Ensure good lighting (natural or artificial)
5. Keep colored marker clearly visible

###  Shopping Mall Use
1. Start in less crowded areas
2. Avoid peak shopping hours during testing
3. Use high-visibility colored marker
4. Inform others about the autonomous cart
5. Always maintain manual override capability

###  Camera Optimization
1. Position camera at waist height
2. Angle slightly downward (10-15°)
3. Keep lens clean and free of smudges
4. Avoid pointing at windows or bright lights
5. Recalibrate if changing environments

---

## Emergency Procedures

### Emergency Stop
1. **Method 1**: Remove colored object from view
2. **Method 2**: Power off using main switch
3. **Method 3**: Physically block cart (use caution)

### In Case of Malfunction
1. **Immediately power off**
2. Remove battery connection
3. Check for loose wires or damaged components
4. Do not restart until issue identified
5. Contact technical support if needed

### Fire Safety
- Use appropriate fire extinguisher (Class C for electrical)
- Never use water on electrical fires
- Keep fire extinguisher accessible during operation

---

## Support and Resources

### Documentation
- Full project report: See main repository
- Circuit diagrams: `hardware/circuit-diagram.md`
- Source code: `src/autonomous_cart.ino`

### Additional Help
- GitHub Issues: Report bugs or ask questions
- Arduino Forums: Community support
- Pixy2 Documentation: https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:start

### Useful Links
- Arduino IDE: https://www.arduino.cc/en/software
- PixyMon Download: https://pixycam.com/downloads-pixy2/
- L298N Datasheet: Available online

---

## Appendix: Serial Monitor Commands

When connected to computer via USB, open Serial Monitor at 9600 baud to see:

```
Object Signature: 1, X: 180, Y: 120, Width: 48, Height: 60
```

**Output Explanation:**
- **Signature**: Which trained color (1-7)
- **X**: Horizontal position (0-320 pixels)
- **Y**: Vertical position (0-200 pixels)
- **Width/Height**: Size of detected object

This data helps debug tracking issues.

---

**For additional assistance, please refer to the main README.md or open an issue on GitHub.**

Last Updated: January 2023
