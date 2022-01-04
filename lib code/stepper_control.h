#ifndef STEPPER_CONTROL_H
#define STEPPER_CONTROL_H

#include<Arduino.h>

// All Libraries and function declare here

// Variable
// Stepper motor Front RIGHT
#define d1_step  11
#define d1_dir   10
// Stepper motor Bot Move
#define d2_step  8
#define d2_dir   9
// Stepper motor Front LEFT
#define d3_step  3
#define d3_dir   2

// LIMIT SWITCH
#define LSBackLeft 29
#define LSBackRight 31
#define LSFrontLeft 33 // 33
#define LSFrontRight 27  // 28
#define BotStartSW 28 //

// LDR SENSOR
const int sensor_0 = A2;
const int sensor_1 = A0;
const int sensor_2 = A1;
const int sensor_3 = A3;
const int laser_1 = 34;
const long step_size = 1000;

static bool BackAndTouchStatus = false;
static bool BackTouchStatus = false;
static bool BotTouchStatus = false;

// Functions
void init_pins();
void work();
void bot_get_sensor();
void bot_touch_bounce();
void back_touch_bounce();
void front_touch_bounce();

void D1_Front_to_Back();
void D2_Forward();
void D3_Front_to_Back();
void D1_Back_to_Front();
void D2_Backward();
void D3_Back_to_Front();
void D1_Stop();
void D2_Stop();
void D3_Stop();

#endif