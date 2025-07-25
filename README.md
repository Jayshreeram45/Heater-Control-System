
# Heater Control System

This project demonstrates a simple temperature-based heater controller using an Arduino Mega 2560 and DS18B20 sensor.

## Features

- Reads temperature using DS18B20
- Controls heater (LED) based on temperature thresholds
- Serial log of temperature and heater state

## States

- **HEATING**: Temp < 20°C
- **STABILIZING**: 20°C <= Temp < 24°C
- **TARGET REACHED**: 24°C <= Temp < 30°C
- **OVERHEAT**: Temp >= 80°C

## Components

- Arduino Mega 2560
- DS18B20 Temperature Sensor
- 4.7kΩ Resistor (pull-up)
- LED (simulated heater)
- Breadboard and jumper wires

## Simulation

Simulate this project on Wokwi by copying the `diagram.json` and source code.

## Wiring (Important)
- DS18B20 `VCC` → Arduino `5V`
- DS18B20 `GND` → Arduino `GND`
- DS18B20 `DQ`  → Arduino `Pin 2` + 4.7kΩ pull-up to 5V
- LED Anode → Pin 8, Cathode → GND
