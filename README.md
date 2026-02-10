# Real-Time Actuator Control

## Overview

This project implements a real-time, deterministic, safety-aware actuator control subsystem designed to model embedded architectures used in robotics and defense-oriented applications.

The system is structured as a multi-node embedded platform comprising:
- A real-time sensor ECU
- A hardware-accelerated control core
- A Linux-based supervisory node

The emphasis of the project is on deterministic timing, explicit hardware/software partitioning, and fault-managed operation, rather than high-level autonomy, middleware, or user-interface features.

## System Goals

- Deterministic sensor acquisition and processing
- Hardware-accelerated signal conditioning using FPGA fabric
- Clear separation between sensing, control, and supervision
- Explicit safety states and fault handling
- Measurable latency, jitter, and timing guarantees

## Hardware Platform

### Sensor ECU

- Arduino Uno R4
- Rotary encoder (primary position feedback)
- Hall-effect sensor (secondary plausibility and safety feedback)
- IR proximity / break-beam sensor (obstruction detection)

The sensor ECU is responsible for deterministic data acquisition and reporting. It does not perform control or system-level decision-making.

### Control Core

- PYNQ-Z2 (Zynq-7020)
- FPGA fabric for signal filtering, validation, and rate calculations
- ARM processor for control logic and safety state management

This node forms the real-time control boundary of the system.

### Supervisory Node

- Raspberry Pi 5
- System supervision and health monitoring
- Data logging
- Operator command interface

The supervisory node operates outside the real-time control loop and does not impose timing constraints on the system.

## High-Level Architecture

```text
[Sensors]
    |
[Arduino Uno R4]  (FreeRTOS Sensor ECU)
    |
    |  SPI (1 kHz, fixed-length packets)
    |
[PYNQ-Z2]
    |
    |  FPGA: filtering, validation
    |  ARM : control, safety state machine
    |
    |  Status / telemetry
    |
[Raspberry Pi 5]  (Supervisory Node)
```

## Safety Model

The system implements explicit operating states:

- INIT  
- SAFE  
- ACTIVE  
- FAULT  

State transitions are triggered by sensor faults, communication timeouts, or operator commands.

In the **FAULT** state, actuator authority is removed via a hardware relay, modeling power or drive isolation commonly used in safety-critical systems.

## Scope and Constraints

The following constraints are intentionally enforced:

- No dynamic memory allocation in real-time execution paths  
- Fixed-size binary communication packets  
- No floating-point math in time-critical paths  
- Deterministic task scheduling  
- No ROS or middleware dependencies  

These constraints reflect common industry practices in safety-critical and real-time embedded systems.

## Skills Demonstrated

- Embedded C/C++ with FreeRTOS  
- Interrupt-driven sensor acquisition  
- SPI-based MCU ↔ SoC communication  
- FPGA/ARM hardware–software co-design  
- Safety state machines and fault handling  
- Embedded Linux system integration  
- Timing, latency, and jitter analysis  

## Project Status

Current focus:
- Sensor ECU task and ISR architecture  
- Snapshot buffering and deterministic data pipelines  
- Definition of fixed-format communication packets  
