#pragma once
// clang-format off

/*
   tmc2209_Pen_Laser.h
    Part of Grbl_ESP32

    Pin assignments for the TMC2130 Pen/Laser controller
    https://github.com/bdring/Grbl_ESP32_TMC2130_Plotter_Controller

    2021-02-21 B. Dring

    Grbl_ESP32 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Grbl is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Grbl_ESP32.  If not, see <http://www.gnu.org/licenses/>.
*/
#define MACHINE_NAME            "TMC2209 Pen Laser"

#define N_AXIS 3

#define TRINAMIC_RUN_MODE           TrinamicMode :: StealthChop // Optional TrinamicMode :: CoolStep or TrinamicMode :: StallGuard
#define TRINAMIC_HOMING_MODE        TrinamicMode :: StealthChop // Optional TrinamicMode :: CoolStep or TrinamicMode :: StallGuard

#define TMC_UART                UART_NUM_1
#define TMC_UART_RX             GPIO_NUM_21
#define TMC_UART_TX             GPIO_NUM_22 

#define X_TRINAMIC_DRIVER       2209
#define X_STEP_PIN              GPIO_NUM_12
#define X_DIRECTION_PIN         GPIO_NUM_26
#define X_RSENSE                TMC2209_RSENSE_DEFAULT
#define X_DRIVER_ADDRESS        0
#define DEFAULT_X_MICROSTEPS    16

#define Y_TRINAMIC_DRIVER       2209
#define Y_STEP_PIN              GPIO_NUM_14
#define Y_DIRECTION_PIN         GPIO_NUM_25
#define Y_RSENSE                TMC2209_RSENSE_DEFAULT
#define Y_DRIVER_ADDRESS        1
#define DEFAULT_Y_MICROSTEPS    16

// OK to comment out to use pin for other features
//#define STEPPERS_DISABLE_PIN GPIO_NUM_13

#define CUSTOM_CODE_FILENAME    "../Custom/CoreXY.cpp"

#define USE_KINEMATICS      // there are kinematic equations for this machine
#define USE_FWD_KINEMATICS   // report in cartesian
#define USE_MACHINE_INIT     //???
//#define USE_CUSTOM_HOMING  //???

//#define USE_STALLGUARD_LIMITS  // uncomment to use stallguard as limit switches
#ifdef USE_STALLGUARD_LIMITS
    // StallGuard Limit Pins
    #define X_LIMIT_PIN             GPIO_NUM_4
    #define Y_LIMIT_PIN             GPIO_NUM_15
#else
    // Switch Limit Pins
    #define X_LIMIT_PIN             GPIO_NUM_33
    #define Y_LIMIT_PIN             GPIO_NUM_32
#endif

#define DEFAULT_HOMING_ENABLE           1  // 1=true
#define DEFAULT_HOMING_DIR_MASK         3 // move positive dir Z,negative X,Y
#define DEFAULT_HOMING_FEED_RATE        500.0 // mm/min
#define DEFAULT_HOMING_SEEK_RATE        1000.0 // mm/min
#define DEFAULT_HOMING_DEBOUNCE_DELAY   250 // msec (0-65k)
#define DEFAULT_HOMING_PULLOFF          15.0 // mm distance to clear trigger
#define DEFAULT_INVERT_LIMIT_PINS       0 // boolean 0=NO

#define DEFAULT_HOMING_CYCLE_0      bit(Y_AXIS) //Home Y first, skip Z
#define DEFAULT_HOMING_CYCLE_1      bit(X_AXIS) //Home X second

//#define DEFAULT_X_HOMING_MPOS 3.0   // MPos will be set to 5mm after homing
//#define DEFAULT_Y_HOMING_MPOS 12.0   // MPos will be set to 5mm after homing

#define DEFAULT_X_STEPS_PER_MM 100.0
#define DEFAULT_Y_STEPS_PER_MM 100.0

#define DEFAULT_X_MAX_RATE 8000.0 // mm/min
#define DEFAULT_Y_MAX_RATE 8000.0 // mm/min

#define DEFAULT_X_ACCELERATION 300.0 // mm/sec^2
#define DEFAULT_Y_ACCELERATION 300.0 // mm/sec^2

#define SPINDLE_TYPE                SpindleType::NONE
