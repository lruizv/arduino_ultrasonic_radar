# Script Guide: Radar Serial Plot

## Overview

This guide explains how to use the `radar_serial_plot.py` script for real-time plotting of radar data received via serial communication.

## Data Format

- **Expected format:** `Degree:xxx,Distance:xxx`

- **Example:**

  ```text
  Degree:45.3,Distance:12.5
  Degree:60.0,Distance:10.2
  ```

- The script parses each line by splitting the string and extracting the values for degree and distance.
- **Invalid data** is ignored to prevent crashes.

## Error Handling

- The script includes checks to ensure malformed serial data does not crash the program.

## Memory Efficiency

- Only the latest 100 degree and distance values are stored to prevent memory overuse during long-term execution.

## Requirements

Before running the script, install the required Python packages:

```bash
pip install pyserial matplotlib
```

## Usage

1. **Run the script:**
   - Open a terminal in the `script` directory.
   - Execute: `python radar_serial_plot.py`
2. **GUI Operation:**
   - Verify the COM port and baud rate.
   - Click Start to begin data acquisition.
   - Click Stop to end data acquisition.
3. **Plot:**
   - The plot updates displaying Distance vs. Degree in real-time.
