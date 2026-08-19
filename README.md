# 4-Way Traffic Light Control System (STM32F411)

A real-time embedded system that manages traffic light sequencing for a 4-direction 
intersection, built using bare-metal register programming on the STM32F411 microcontroller.

## Overview
This project simulates a 4-way traffic signal controller with live countdown timers 
displayed on two 4-digit seven-segment displays (SSDs). LED indicators (red/yellow/green) 
show the current signal state for each direction, synced with the countdown.

## Features
- Real-time countdown using Timer2 hardware interrupts
- Two 4-digit seven-segment displays driven via GPIOC and GPIOD (digit multiplexing)
- LED signal indicators controlled via GPIOA and GPIOB
- Fully bare-metal: direct register access (no HAL library), including RCC clock 
  configuration, GPIO mode setup, and NVIC interrupt handling
- Modular code structure (separate files for LED control, SSD display, and main logic)

## Hardware Used
- STM32F411 Discovery
- 2x 4-digit seven-segment displays
- LEDs (red, yellow, green) x4 sets
- Current-limiting resistors

## Key Concepts Demonstrated
- GPIO configuration via direct register manipulation
- RCC (Reset and Clock Control) peripheral clock enabling
- Timer interrupt configuration (TIM2 + NVIC)
- Seven-segment display multiplexing
- Real-time embedded system design

## File Structure
├── main.c        # Core application logic, timer ISR, counter management
├── main.h         # Register struct definitions, base addresses, macros
├── led.c            # LED GPIO initialization
├── ssd.c            # Seven-segment display driver

## How to Build and Run
1. Open the project in STM32CubeIDE (or your preferred ARM toolchain)
2. Connect the STM32F411 board via ST-Link
3. Build the project
4. Flash it to the board
5. Observe the countdown timers on the SSDs and LED signal changes

## Author
Khushnuda Shaik — B.Tech ECE
