# Bill of Materials (BOM)

## Complete Component List

### Core Electronics

| Item # | Component | Specification | Quantity | Unit Price (BDT) | Total (BDT) | Supplier/Notes |
|--------|-----------|---------------|----------|------------------|-------------|----------------|
| 1 | Arduino Uno Rev 3 | ATmega328P, 5V/16MHz | 1 | 1,050 | 1,050 | Local electronics store |
| 2 | Pixy2 CMUcam5 | Smart vision sensor | 1 | 12,000 | 12,000 | Charmed Labs / Import |
| 3 | L298N Motor Driver | Dual H-Bridge, 2A per channel | 1 | 200 | 200 | Local supplier |

**Subtotal: 13,250 BDT**

---

### Mechanical Components

| Item # | Component | Specification | Quantity | Unit Price (BDT) | Total (BDT) | Supplier/Notes |
|--------|-----------|---------------|----------|------------------|-------------|----------------|
| 4 | Cart Chassis | Metal/plastic frame | 1 | 500 | 500 | Local hardware store |
| 5 | DC Geared Motors | 12V, 100-200 RPM | 4 | 160 | 640 | Included with chassis |
| 6 | Wheels | Plastic, suitable for motors | 4 | - | - | Included with motors |

**Subtotal: 1,140 BDT**

---

### Power Supply

| Item # | Component | Specification | Quantity | Unit Price (BDT) | Total (BDT) | Supplier/Notes |
|--------|-----------|---------------|----------|------------------|-------------|----------------|
| 7 | Battery Pack | 7.4V-12V Li-ion/NiMH | 1 | - | - | User provided |
| 8 | Battery Holder | Appropriate for battery type | 1 | - | - | Included/improvised |
| 9 | Power Switch | SPST, 2A rated | 1 | 50 | 50 | Electronics store |

**Note:** Battery cost not included as it varies by user choice and availability.

---

### Wiring and Connectors

| Item # | Component | Specification | Quantity | Unit Price (BDT) | Total (BDT) | Supplier/Notes |
|--------|-----------|---------------|----------|------------------|-------------|----------------|
| 10 | Jumper Wires | Male-to-Male, various lengths | 20 | 5 | 100 | Electronics store |
| 11 | Jumper Wires | Male-to-Female | 10 | 5 | 50 | Electronics store |
| 12 | Dupont Connectors | For motor connections | 8 | 10 | 80 | Electronics store |
| 13 | Heat Shrink Tubing | Various sizes | 1 pack | 50 | 50 | Electronics store |
| 14 | Wire (22 AWG) | Red and Black | 2m each | 20/m | 80 | Electronics store |
| 15 | USB Cable | Type A to Type B for Arduino | 1 | 100 | 100 | Usually included with Arduino |

**Subtotal: 460 BDT**

---

### Mounting and Structural

| Item # | Component | Specification | Quantity | Unit Price (BDT) | Total (BDT) | Supplier/Notes |
|--------|-----------|---------------|----------|------------------|-------------|----------------|
| 16 | M3 Screws | Various lengths (10-30mm) | 20 | 2 | 40 | Hardware store |
| 17 | M3 Nuts | Standard | 20 | 1 | 20 | Hardware store |
| 18 | Standoffs | M3, 10mm height | 8 | 5 | 40 | Electronics store |
| 19 | Double-sided Tape | Strong adhesive | 1 roll | 50 | 50 | General store |
| 20 | Zip Ties | Cable management | 10 | 2 | 20 | Hardware store |
| 21 | Velcro Strips | For battery mounting | 1 set | 30 | 30 | General store |

**Subtotal: 200 BDT**

---

### Optional Components (Recommended)

| Item # | Component | Purpose | Quantity | Unit Price (BDT) | Total (BDT) | Notes |
|--------|-----------|---------|----------|------------------|-------------|-------|
| 22 | Voltage Regulator | 7805, 5V output | 1 | 20 | 20 | For stable Arduino power |
| 23 | Capacitors | 100µF electrolytic | 2 | 10 | 20 | Power smoothing |
| 24 | LED Indicators | Status lights | 3 | 5 | 15 | Green, Red, Yellow |
| 25 | Resistors | 220Ω for LEDs | 3 | 2 | 6 | Current limiting |
| 26 | Buzzer | Audio feedback | 1 | 30 | 30 | Optional alerts |
| 27 | Emergency Stop Button | Large red pushbutton | 1 | 80 | 80 | Safety feature |

**Subtotal (Optional): 171 BDT**

---

## Cost Summary

| Category | Subtotal (BDT) | Percentage |
|----------|----------------|------------|
| Core Electronics | 13,250 | 88.3% |
| Mechanical Components | 1,140 | 7.6% |
| Power Supply | 50 | 0.3% |
| Wiring and Connectors | 460 | 3.1% |
| Mounting and Structural | 200 | 1.3% |
| **TOTAL (Required)** | **15,100** | **100%** |
| Optional Components | 171 | - |
| **GRAND TOTAL** | **15,271** | - |

*Note: Actual project cost reported as 15,000 BDT (rounded)*

---

## Cost Breakdown by Vendor

### Local Electronics Stores (~2,200 BDT)
- Arduino Uno Rev 3
- L298N Motor Driver
- Jumper wires and connectors
- Small components (resistors, LEDs, etc.)

### Hardware Stores (~1,340 BDT)
- Cart chassis
- Motors and wheels
- Screws, nuts, standoffs
- Zip ties and mounting materials

### Import/Specialty (~12,000 BDT)
- Pixy2 CMUcam5 (major cost component)

### General Stores (~100 BDT)
- Tape, Velcro
- Miscellaneous supplies

---

## Alternative Components (Cost Optimization)

If budget is constrained, consider these alternatives:

### Lower-Cost Options

| Original Component | Alternative | Cost Savings | Trade-offs |
|-------------------|-------------|--------------|------------|
| Pixy2 CMUcam5 (12,000 BDT) | OpenMV Cam H7 | Save ~4,000 | Different programming required |
| Arduino Uno Rev 3 (1,050 BDT) | Arduino Nano/Clone | Save ~400 | Smaller, fewer pins |
| New chassis (1,140 BDT) | Repurposed materials | Save ~800 | Requires fabrication skills |

### DIY Alternatives
- **Chassis**: Repurpose old cart or build from wood/acrylic
- **Connectors**: Solder wires directly (saves ~150 BDT)
- **Mounting**: Use hot glue instead of screws (saves ~100 BDT)

**Potential savings: 2,000-5,000 BDT** (but may affect reliability)

---

## Tools Required (Not Included in BOM)

You will need access to:

| Tool | Purpose | Essential? |
|------|---------|------------|
| Soldering Iron | Wire connections | Highly recommended |
| Multimeter | Testing and debugging | Essential |
| Screwdriver Set | Assembly | Essential |
| Wire Strippers | Cable preparation | Recommended |
| Hot Glue Gun | Mounting components | Optional |
| Drill | Mounting holes | Optional |

---

## Where to Buy (Bangladesh)

### Dhaka Area
- **Arduino & Electronics**: 
  - Computer City (Multiplan)
  - BPL Electronics (Elephant Road)
  - Robotic Shop BD (online)

- **Motors & Mechanical**:
  - Joydevpur Market (Gazipur)
  - Local hardware stores

- **Import (Pixy2)**:
  - Order from Charmed Labs website
  - Use courier services (DHL, FedEx)
  - Local robotics importers

### Online Options
- daraz.com.bd
- robu.in (India - ships to BD)
- aliexpress.com (international)

---

## Import Considerations for Pixy2

### Ordering from Charmed Labs
- **Official price**: ~$60 USD
- **Shipping**: $20-40 USD (varies)
- **Customs duty**: ~25% of value
- **Total estimated**: 10,000-13,000 BDT

### Delivery Time
- Standard: 2-4 weeks
- Express: 1-2 weeks (higher cost)

### Tips
- Check for regional distributors
- Consider group orders to save shipping
- Verify customs regulations

---

## Maintenance Costs (Annual Estimate)

| Item | Frequency | Cost (BDT/year) |
|------|-----------|-----------------|
| Battery replacement | Once | 1,500-2,500 |
| Wire replacements | As needed | 100-200 |
| Motor maintenance | As needed | 200-500 |
| Miscellaneous | Ongoing | 500 |
| **Total** | | **2,300-3,700** |

---

## Notes

1. **Prices are approximate** and may vary by supplier and location
2. **Exchange rate used**: 1 USD ≈ 110 BDT (approximate, varies)
3. **Bulk discounts** may be available for educational institutions
4. **Quality matters**: Don't compromise on core components (Arduino, Pixy2, Motor Driver)
5. **Keep receipts** for documentation and warranty purposes

---

## Revision History

| Date | Version | Changes |
|------|---------|---------|
| Jan 2023 | 1.0 | Initial BOM for project |
| - | - | - |

---

*For questions about component sourcing or alternatives, please open an issue on GitHub.*
