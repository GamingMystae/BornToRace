# BornToRace

**BornToRace** is a small arcade racing game prototype I created during the summer after my first semester in college, as a way to practice Unreal Engine C++ gameplay programming and build a complete playable project from scratch.

The project focuses on core racing systems such as player movement, AI path-following, lap progression, and simple track hazards.

---

## Overview

In **BornToRace**, the player controls a car in a top-down / 2D-style racing setup and competes on a track while completing laps.  
The game includes a basic AI opponent, a finish line system for lap counting, and oil spill obstacles that temporarily reduce speed.

This project was created mainly as a learning and practice exercise to improve my understanding of:

- Unreal Engine C++ class structure
- actor setup and component hierarchy
- player input and movement
- spline-based AI movement
- overlap events and collision-driven gameplay
- simple race progression logic

---

## Features

- **Player-controlled car**
  - Forward movement
  - Rotation-based steering
  - Camera setup using a spring arm and camera component

- **AI car**
  - Follows a predefined **Spline Path**
  - Moves automatically along the racing route

- **Lap system**
  - Finish line overlap detection
  - Lap counting through the GameMode
  - Race completion trigger after the required number of laps

- **Track hazards**
  - Oil spill obstacle
  - Temporarily reduces the speed of the player car
  - Designed to also affect AI cars

- **Paper2D-based setup**
  - Uses sprite components for cars and track elements
  - Combines simple visuals with C++ gameplay systems

---

## Tech Stack

- **Engine:** Unreal Engine 5.2
- **Language:** C++
- **Framework/Modules:** Unreal Engine Gameplay Framework, Paper2D
- **Project Type:** Practice / learning project

---

## Main Classes

### `APlayerCar`
Handles:
- player input
- forward movement
- turning/rotation
- temporary speed reduction and recovery

### `AAIcar`
Handles:
- AI car movement along a spline path
- basic automated racing behaviour
- temporary speed reduction support

### `ASplinePath`
Defines the route used by the AI car.

### `AOil`
Hazard actor that detects overlap and reduces car speed temporarily.

### `AFinishLine`
Detects when the player crosses the finish line and updates lap progression.

### `ABornToRaceGameModeBase`
Controls:
- lap counting
- race state
- race completion condition

---

## What I Learned

This project helped me practice some of the most important gameplay programming fundamentals in Unreal Engine, including:

- creating custom gameplay actors in C++
- working with components like box collision, sprites, cameras, and spring arms
- binding input in a custom pawn
- using timers to create temporary gameplay effects
- building simple race progression systems
- moving AI actors along a spline path

It was one of my early projects, but it played an important role in helping me become more comfortable with Unreal Engine programming.

---

## Project Purpose

This was not intended as a large commercial game, but as a **personal practice project** created after my first semester of college.

Its main goal was to help me improve my technical skills and gain hands-on experience by building a complete gameplay loop in Unreal Engine using C++.

---

## Repository Structure

- `PlayerCar` – player movement and controls
- `AIcar` – spline-following AI opponent
- `SplinePath` – path actor for AI movement
- `Oil` – track hazard with speed reduction effect
- `FinishLine` – lap trigger
- `BornToRaceGameModeBase` – race/lap management

---

## Future Improvements

Possible improvements for this prototype include:

- HUD for lap display and race feedback
- countdown before race start
- better win/lose flow and end screen
- multiple AI opponents
- improved lap validation logic
- polished track art and audio
- power-ups and more racing hazards

---

## Status

**Completed as an early practice project**  
Created as a summer learning project after my first semester in college.

---

## Author

**George Bolias**  
Game Programmer / Unreal Engine Developer

- Portfolio: [georgebolias.com](https://www.georgebolias.com/)
- LinkedIn: [linkedin.com/in/georgebolias](https://www.linkedin.com/in/georgebolias/)
- GitHub: [GamingMystae](https://github.com/GamingMystae)
