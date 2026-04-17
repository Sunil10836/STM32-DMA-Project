## STM32 UART Data Transfer Using DMA

## Project Overview
This project demonstrates UART data transmission using Direct Memory Access (DMA) on an STM32 microcontroller. The implementation eliminates continuous CPU involvement by offloading data transfer to DMA, enabling efficient and high-speed communication.

## Objectives
1. Implement UART transmission using DMA
2. Reduce CPU load during data transfer
3. Achieve efficient and non-blocking communication
4. Understand DMA configuration and workflow

## Features
1. UART transmission using DMA
2. Non-blocking data transfer
3. Reduced CPU utilization
4. Interrupt-based transfer completion
5. Scalable for real-time applications

## Concepts Covered
1. Direct Memory Access (DMA)
2. Memory-to-Peripheral Transfer
3. UART Communication
4. Interrupt Handling
5. Embedded C Programming

## Hardware Requirements
1. STM32 Microcontroller : STM32F446RE : NUCLEO-F446RE Board
2. USB Cable (for programming & UART communication)
3. PC with serial terminal.

## Software Requirements
1. STM32CubeIDE
2. Serial Terminal (PuTTY / Tera Term)

## Working Principle
1. Data is stored in a memory buffer (SRAM)
2. DMA is configured for Memory → UART TX
3. DMA transfers data directly to UART data register
4. UART transmits data without CPU intervention
5. Interrupt is triggered after transfer completion

## Advantages of DMA-Based UART
1. Faster data transfer
2. Frees CPU for other tasks
3. Non-blocking communication
4. Better power efficiency
