# Autonomous Shopping Cart 

An intelligent shopping cart system that autonomously follows a designated person using computer vision and robotics technology.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Arduino](https://img.shields.io/badge/Arduino-00979D?logo=Arduino&logoColor=white)](https://www.arduino.cc/)

## 📋 Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Installation](#installation)
- [Usage](#usage)
- [How It Works](#how-it-works)
- [Project Structure](#project-structure)
- [Results](#results)
- [Limitations](#limitations)
- [Future Improvements](#future-improvements)
- [Contributing](#contributing)
- [Team](#team)
- [License](#license)
- [Acknowledgments](#acknowledgments)

##  Overview

This project was developed as part of the EEE 318 Control System I Laboratory course at Bangladesh University of Engineering and Technology (BUET). The autonomous shopping cart uses a Pixy2 camera for color-based person tracking and an Arduino Uno for control logic, creating a hands-free shopping experience.

**Key Achievement:** Successfully implemented a person-following system using computer vision and motor control with a total cost of ~15,000 BDT (~$140 USD).

##  Features

- **Autonomous Person Following**: Tracks and follows a person based on unique color signatures
- **Real-time Object Detection**: Uses Pixy2 CMUcam5 for fast and accurate color detection
- **Adaptive Speed Control**: Adjusts motor speeds based on tracked object position
- **Safe Distance Maintenance**: Maintains appropriate following distance
- **Low-Cost Implementation**: Built with affordable, widely-available components

##  Hardware Requirements

| Component | Quantity | Price (BDT) |
|-----------|----------|-------------|
| Arduino Uno Rev 3 | 1 | 1,050 |
| Cart Chassis with DC Motors | 1 | 1,140 |
| L298N Dual Motor Driver | 1 | 200 |
| Pixy2 CMUcam5 | 1 | 12,000 |
| Cables and Connectors | - | 500 |
| Additional Components | - | 110 |
| **Total** | | **15,000** |

## Software Requirements

- **Arduino IDE** (v1.8.x or higher)
- **Pixy2 Arduino Library**
- **PixyMon v2** (for color signature training)
- **SPI Library** (included with Arduino IDE)

##  Installation

### 1. Hardware Setup

1. Assemble the cart chassis and mount the DC motors
2. Connect the L298N motor driver to the Arduino:
   - ENA → Pin 5
   - IN1 → Pin 6
   - IN2 → Pin 7
   - IN3 → Pin 8
   - IN4 → Pin 9
   - ENB → Pin 10
3. Connect the Pixy2 camera to Arduino via SPI
4. Power the system with appropriate voltage supply

Refer to `hardware/circuit-diagram.md` for detailed wiring instructions.

### 2. Software Setup

```bash
# Clone this repository
git clone https://github.com/yourusername/autonomous-shopping-cart.git

# Navigate to the project directory
cd autonomous-shopping-cart

# Open the Arduino sketch
# Open src/autonomous_cart.ino in Arduino IDE
```

### 3. Install Required Libraries

1. Open Arduino IDE
2. Go to **Sketch → Include Library → Manage Libraries**
3. Search and install:
   - `Pixy2` library by Charmed Labs

### 4. Configure Pixy2 Camera

1. Download and install PixyMon v2 from [Charmed Labs](https://pixycam.com/downloads-pixy2/)
2. Connect Pixy2 to your computer via USB
3. Open PixyMon and teach color signatures:
   - Point camera at the target color
   - Hold the button on Pixy2 until LED blinks
   - Release when desired color is captured
4. Save the signature

### 5. Upload Code

1. Connect Arduino to computer via USB
2. Select correct board and port in Arduino IDE
3. Upload `src/autonomous_cart.ino`

## 🚀 Usage

1. **Power On**: Turn on the cart's power supply
2. **Position**: Place the cart behind the person to follow
3. **Start Following**: The cart will automatically detect and follow the person wearing the trained color signature
4. **Adjust Settings** (optional): Modify `deadZone` and speed values in code for fine-tuning

### User Manual

For detailed operating instructions, see [docs/user-manual.md](docs/user-manual.md)

##  How It Works

### System Architecture

```
┌─────────────┐      ┌──────────────┐      ┌─────────────┐
│   Pixy2     │─────→│  Arduino Uno │─────→│   L298N     │
│   Camera    │      │              │      │Motor Driver │
└─────────────┘      └──────────────┘      └─────────────┘
      │                                            │
      │                                            ▼
      │                                     ┌─────────────┐
      └────→ Color Detection               │  DC Motors  │
             & Tracking                     └─────────────┘
```

### Control Algorithm

1. **Detection**: Pixy2 camera captures frames and detects trained color signatures
2. **Position Calculation**: Calculate normalized X-axis position of detected object
3. **Decision Making**: Arduino determines turning direction based on object position:
   - Object on left (`cx < -0.15`) → Turn left
   - Object on right (`cx > 0.15`) → Turn right
   - Object centered → Move forward
4. **Motor Control**: L298N driver adjusts individual motor speeds for desired movement

### Mathematical Model

```
cx = (x + width/2) mapped from [0, 320] to [-1, 1]
cy = (y + height/2) mapped from [0, 200] to [1, -1]
```

##  Project Structure

```
autonomous-shopping-cart/
├── src/
│   └── autonomous_cart.ino        # Main Arduino sketch
├── hardware/
│   ├── bill-of-materials.md       # Component list with prices
│   └── circuit-diagram.md         # Wiring instructions
├── docs/
│   ├── user-manual.md             # Operating instructions
│   └── *.png                      # Diagrams and images
├── data/
│   └── experimental-data.csv      # Test results data
├── images/                        # Project photos
├── README.md                      # This file
├── LICENSE                        # MIT License
├── .gitignore                     # Git ignore rules
└── CONTRIBUTING.md                # Contribution guidelines
```

##  Results

### Performance Data

| Distance (cm) | Pixy X | Pixy Y | Width | Height | Normalized X |
|---------------|--------|--------|-------|--------|--------------|
| 31            | 212    | 136    | 80    | 130    | 0.575        |
| 44            | 202    | 134    | 50    | 90     | 0.570        |
| 56            | 180    | 120    | 48    | 60     | 0.275        |
| 86            | 166    | 104    | 34    | 49     | 0.038        |
| 104           | 129    | 62     | 28    | 17     | -0.194       |

**Key Findings:**
- Successfully tracks person at distances from 30-100+ cm
- Responsive to lateral movements with normalized X-axis values
- Effective color signature detection in controlled environments

##  Limitations

1. **Color Confusion**: May fail if multiple objects share the same color signature
2. **Sharp Turns**: Limited response time for rapid directional changes
3. **Environmental Factors**: Performance affected by lighting conditions
4. **Obstacle Avoidance**: No built-in collision detection for static obstacles

##  Future Improvements

- [ ] **Real-time Product Information**: Display item details when selected
- [ ] **Voice Guidance**: Audio interface for visually impaired users
- [ ] **Automated Billing**: Integration with payment systems for seamless checkout
- [ ] **Multi-language Support**: Internationalization for diverse users
- [ ] **Enhanced Object Detection**: Deep learning for person identification
- [ ] **Omnidirectional Wheels**: Improve maneuverability with 360° wheels
- [ ] **Obstacle Avoidance**: Ultrasonic/LiDAR sensors for collision prevention
- [ ] **Battery Optimization**: Power management for extended operation

##  Contributing

Contributions are welcome! Please read [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines.

1. Fork the project
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

##  Team

**Group 5 - Section B2**

| Name | Student ID | Role |
|------|------------|------|
| Joydip Chakraborty | 1906117 | Hardware Assembly |
| Abdullah Al Numan | 1906121 | Hardware Assembly |
| K M Fahim Asif | 1906122 | Software Development |
| Md Galib Mahmud Sharif | 1906123 | Software Development |
| SK Shahriar Iqbal | 1906124 | Hardware Assembly |
| Anik Biswas | 1906125 | Software Development and Hardware Assembly|

**Course Instructors:**
- Shafin-Bin-Hamid, Lecturer
- Md. Jawad Ul Islam, Part-Time Lecturer

**Institution:** Department of Electrical and Electronic Engineering, Bangladesh University of Engineering and Technology (BUET)

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

##  Acknowledgments

- Charmed Labs for the excellent Pixy2 camera and documentation
- Arduino community for comprehensive libraries and support
- BUET EEE Department for project guidance and resources
- Research papers that inspired this work:
  - [Implementation of Camera Sensor Pixy 2 CMUcam5](https://journal.umy.ac.id/index.php/jrc/article/view/10110/6000)
  - [Colour tracking technique using Pixy CMUcam5](https://ieeexplore.ieee.org/document/8284402)

##  Contact

For questions or suggestions, please open an issue or contact the team members through the university email system.

---

**Note**: This project was completed in January 2023 as part of the EEE 318 curriculum. The code and documentation are provided for educational purposes.
