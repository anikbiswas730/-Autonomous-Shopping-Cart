# Circuit Diagram and Wiring Guide

## Overview

This document provides detailed wiring instructions for the Autonomous Shopping Cart project. The system consists of three main components:
1. **Arduino Uno Rev 3** - Main controller
2. **Pixy2 CMUcam5** - Vision sensor
3. **L298N Motor Driver** - Motor control

---

## Component Pinout Reference

### Arduino Uno Pins Used

| Arduino Pin | Connected To | Function |
|-------------|--------------|----------|
| Pin 5 (PWM) | L298N ENA | Left motors speed control |
| Pin 6 | L298N IN1 | Left motors direction |
| Pin 7 | L298N IN2 | Left motors direction |
| Pin 8 | L298N IN3 | Right motors direction |
| Pin 9 (PWM) | L298N IN4 | Right motors direction |
| Pin 10 (PWM) | L298N ENB | Right motors speed control |
| Pin 11 (MOSI) | Pixy2 MOSI | SPI data out |
| Pin 12 (MISO) | Pixy2 MISO | SPI data in |
| Pin 13 (SCK) | Pixy2 SCK | SPI clock |
| Pin 10 (SS) | Pixy2 SS | SPI slave select (alternate) |
| 5V | Pixy2 VCC | Power supply |
| GND | Common Ground | Ground reference |

---

## Detailed Wiring Instructions

### 1. Arduino to L298N Motor Driver

```
Arduino          L298N Motor Driver
-------          ------------------
Pin 5 (PWM)  --> ENA (Speed control A)
Pin 6        --> IN1 (Direction A)
Pin 7        --> IN2 (Direction A)
Pin 8        --> IN3 (Direction B)
Pin 9 (PWM)  --> IN4 (Direction B)
Pin 10 (PWM) --> ENB (Speed control B)
GND          --> GND (Common ground)
```

**Notes:**
- Ensure ENA and ENB jumpers are **removed** for PWM speed control
- If jumpers are present, motors run at full speed
- Connect Arduino GND to motor driver GND

### 2. L298N to DC Motors

```
L298N            Motors
-----            ------
OUT1         --> Left Motor (+)
OUT2         --> Left Motor (-)
OUT3         --> Right Motor (+)
OUT4         --> Right Motor (-)
```

**Motor Configuration:**
- Motors 1 & 2 (left side) connected to OUT1/OUT2
- Motors 3 & 4 (right side) connected to OUT3/OUT4
- Parallel connection for motors on same side

**If motors run backward:**
- Swap the two wires for that motor
- Or modify code direction logic

### 3. Arduino to Pixy2 Camera (SPI Connection)

```
Arduino          Pixy2 (10-pin connector)
-------          -----------------------
Pin 13 (SCK) --> Pin 3 (SCLK)
Pin 12 (MISO)--> Pin 1 (MISO)
Pin 11 (MOSI)--> Pin 4 (MOSI)
Pin 10 (SS)  --> Pin 7 (SS) [or use different pin]
5V           --> Pin 2 (VCC)
GND          --> Pin 6 (GND)
```

**Pixy2 Connector Pinout:**
```
  1  2  3  4  5
  •  •  •  •  •
 MISO VCC SCLK MOSI OUT0
  
  6  7  8  9  10
  •  •  •  •  •
 GND SS  OUT1 OUT2 VIN
```

**Notes:**
- Use SPI communication for faster data transfer
- Alternative: Use I2C, but slower
- Do NOT connect both 5V and VIN simultaneously

### 4. Power Supply Connections

```
Battery Pack     L298N          Arduino
------------     -----          -------
(+) 7-12V    --> 12V input     
(-)          --> GND           --> GND
                5V output*     --> 5V (optional)
```

**Power Options:**

**Option A: Separate Power (Recommended)**
- Battery --> L298N 12V input (motors)
- USB/Separate 5V --> Arduino (logic)
- Common ground connected

**Option B: Shared Power**
- Battery --> L298N 12V input
- L298N 5V output --> Arduino 5V pin
-  Warning: May cause voltage drops under load

**Important:**
-  **NEVER** connect Arduino USB and external power simultaneously without proper isolation
- Always verify polarity before connecting power
- Use appropriate gauge wire for motor current (18-20 AWG recommended)

---

## Complete Wiring Diagram (Text Version)

```
                    +12V Battery
                         |
                    [Power Switch]
                         |
         +---------------+-----------------+
         |                                 |
    [L298N Motor Driver]            [DC Motors x4]
         |                           (2 left, 2 right)
         | (ENA,IN1-4,ENB)
         |
    [Arduino Uno]
         |
         | (SPI: MISO,MOSI,SCK,SS)
         |
    [Pixy2 Camera]
         |
    (Mounted on cart front)


Ground (GND) is common to all components
```

---

## Physical Layout Recommendations

### Component Placement

1. **Arduino Uno**: Center of cart, accessible for USB connection
2. **L298N Driver**: Near motors, minimize wire length
3. **Pixy2 Camera**: Front of cart, ~30cm height, slight downward tilt (10-15°)
4. **Battery Pack**: Low center of gravity, secured with Velcro
5. **Power Switch**: Easily accessible from outside

### Cable Management

- Use zip ties to bundle wires
- Separate power and signal wires when possible
- Keep motor wires away from Arduino/Pixy2 (reduce EMI)
- Label all connections for maintenance
- Leave slack for component movement

---

## Testing Procedure

### Step 1: Visual Inspection
- [ ] Verify all connections match diagram
- [ ] Check polarity of power connections
- [ ] Ensure no short circuits
- [ ] Verify wire gauge appropriate for current

### Step 2: Continuity Test (Power OFF)
- [ ] Use multimeter to verify connections
- [ ] Check for shorts between power and ground
- [ ] Test motor connections for continuity

### Step 3: Initial Power-On
- [ ] Connect Arduino via USB (no battery yet)
- [ ] Upload test sketch
- [ ] Verify Arduino powers on (LED lights up)
- [ ] Check Pixy2 LED indicators

### Step 4: Motor Test (With Battery)
- [ ] Disconnect USB from Arduino
- [ ] Connect battery (motors may twitch - normal)
- [ ] Upload final code
- [ ] Test each motor individually if possible
- [ ] Verify direction control works

### Step 5: Full System Test
- [ ] Power on complete system
- [ ] Train Pixy2 on color signature
- [ ] Test tracking with colored object
- [ ] Verify motors respond to detected object

---

## Safety Warnings

### Before Wiring
 **Disconnect all power sources**
 **Double-check polarity**
 **Never hot-swap connections while powered**

### During Operation
 **Keep fingers away from motors and wheels**
 **Monitor for overheating components**
 **Have emergency stop accessible**
 **Don't exceed 12V on motor driver input**

### Troubleshooting Power Issues
 **If smoke appears, disconnect power immediately**
 **Check for hot components (may indicate short circuit)**
 **Verify battery voltage before connecting**

---

## Common Wiring Mistakes

| Problem | Cause | Solution |
|---------|-------|----------|
| Motors don't move | ENA/ENB jumpers in place | Remove jumpers |
| Motors run backward | Reversed polarity | Swap motor wires |
| Arduino resets randomly | Insufficient power | Use separate power supply |
| Pixy2 not detected | Wrong SPI pins | Verify MISO/MOSI/SCK/SS |
| Erratic behavior | Ground not common | Connect all grounds together |
| No speed control | PWM pins not used | Use pins 5,6,9,10,11 |

---

## Alternative Connection Methods

### I2C Connection (Alternative to SPI)

If SPI pins are needed for other purposes:

```
Arduino          Pixy2
-------          -----
A4 (SDA)     --> SDA
A5 (SCL)     --> SCL
5V           --> VCC
GND          --> GND
```

**Code changes required** - use Pixy2 I2C library functions.

### UART Connection (Serial)

```
Arduino          Pixy2
-------          -----
TX (Pin 1)   --> RX
RX (Pin 0)   --> TX
5V           --> VCC
GND          --> GND
```

**Note:** This uses same pins as USB, cannot debug simultaneously.

---

## Schematic Symbol Legend

```
[Component]  = Physical component
    -->      = Wire connection
    |        = Vertical connection
    +        = Connection junction
   PWM       = Pulse Width Modulation capable pin
   GND       = Ground / Common reference
```

---

## Bill of Wires

| Wire Purpose | Color | Length | Gauge |
|--------------|-------|--------|-------|
| Motor power | Red | 30cm x 4 | 20 AWG |
| Motor ground | Black | 30cm x 4 | 20 AWG |
| Signal wires | Various | 20cm x 10 | 22-24 AWG |
| Power to driver | Red | 15cm | 18 AWG |
| Ground (common) | Black | Various | 18-20 AWG |

---

## Revision History

| Date | Version | Changes |
|------|---------|---------|
| Jan 2023 | 1.0 | Initial wiring documentation |

---

## Additional Resources

- L298N Datasheet: [ST Microelectronics](https://www.st.com/resource/en/datasheet/l298.pdf)
- Arduino Uno Pinout: [Arduino Official](https://docs.arduino.cc/hardware/uno-rev3)
- Pixy2 Hardware Guide: [Charmed Labs Docs](https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:hooking_up_pixy_to_a_microcontroller_-28like_an_arduino-29)

---

*For circuit diagram images, see the `docs/` folder in the repository.*
