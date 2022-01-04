#include<stepper_control.h>
#include<display_control.h>

// Initiallize all the Board Pins
void init_pins(){
  pinMode(d1_step,OUTPUT);
  pinMode(d1_dir,OUTPUT);
  pinMode(d2_step,OUTPUT); 
  pinMode(d2_dir,OUTPUT);
  pinMode(d3_step,OUTPUT);
  pinMode(d3_dir,OUTPUT);
  pinMode(laser_1, OUTPUT);
  pinMode(LSBackLeft, INPUT);
  pinMode(LSBackRight, INPUT);
  pinMode(LSFrontLeft, INPUT);
  pinMode(LSFrontRight, INPUT);
  pinMode(BotStartSW, INPUT);
}

// work implemented here
void work(){
  Serial.println("I am work");
  if(BackTouchStatus==false){
    back_touch_bounce();
  }
  if(BotTouchStatus==false){
    bot_touch_bounce();
  }

  if(BackTouchStatus && BotTouchStatus){
    bot_get_sensor();
    BotTouchStatus = false;
    front_touch_bounce();
    BackTouchStatus = false;
  }

  bot_touch_bounce();
  back_touch_bounce();
}


// Get On the Bot axis and collect all ananlog sensor data
void bot_get_sensor(){
  digitalWrite(laser_1, HIGH);
  for(int i=0;i<1300;i++){
    D2_Backward();
    if(analogRead(sensor_0)>1000 || analogRead(sensor_1)>1000 || analogRead(sensor_2)>1000 || analogRead(sensor_3)>1000){
      /* Serial.print("Count: ");
      Serial.print(i);
      Serial.print("  Sensor_0: ");
      Serial.print(analogRead(sensor_0));
      Serial.print("  Sensor_1: ");
      Serial.print(analogRead(sensor_1));
      Serial.print("  Sensor_2: ");
      Serial.print(analogRead(sensor_2));
      Serial.print("  Sensor_3: ");
      Serial.print(analogRead(sensor_3));
      Serial.println(""); */
      delay(1000);// rest to do other
      int j=0;
      while(j<50){
        D2_Backward();
        j++;
      }
    }
	serial_check();
  }
  digitalWrite(laser_1, LOW);
}

// Function for bot Intial->Touch->Bounce
void bot_touch_bounce(){
	Serial.println("I am in bot bounce");
  while(digitalRead(BotStartSW)==0){
    D2_Forward();
	serial_check();
//    D2_Backward();
  }
  while(digitalRead(BotStartSW)){
//    D2_Forward();
    D2_Backward();
	serial_check();
  }
  //Serial.println("I am in bot bounce");
  BotTouchStatus = true;
}


// function to make the back touch -> bounce -> stop(waiting for next commands
void back_touch_bounce(){
  // Serial.println("I am in back bounce");
  while(1){
    if(digitalRead(LSBackRight)==0){
      D1_Front_to_Back();
    }
    if(digitalRead(LSBackLeft)==0){
      D3_Front_to_Back();
    }
    if(digitalRead(LSBackRight) && digitalRead(LSBackLeft))
      break;
	serial_check();
  }
	Serial.println("Back bounce 50");
  while(digitalRead(LSBackRight) || digitalRead(LSBackLeft)){
    if(digitalRead(LSBackRight)){
      D1_Back_to_Front();
    }
    if(digitalRead(LSBackLeft)){
      D3_Back_to_Front();
    }
    if(digitalRead(LSBackRight)==0 && digitalRead(LSBackLeft)==0)
      break;
	serial_check();
  }
  // Serial.println("I am out back bounce");
  BackTouchStatus = true;
  
}


// function to make the Front touch -> bounce -> stop(waiting for next commands
void front_touch_bounce(){
  while(1){
    if(digitalRead(LSFrontRight)==0){
      D1_Back_to_Front();
    }
    if(digitalRead(LSFrontLeft)==0){
      D3_Back_to_Front();
    }
    if(digitalRead(LSFrontRight) && digitalRead(LSFrontLeft))
      break;
	serial_check();
  }

  while(digitalRead(LSFrontRight) || digitalRead(LSFrontLeft)){
    if(digitalRead(LSFrontRight)){
      D1_Front_to_Back();
    }
    if(digitalRead(LSFrontLeft)){
      D3_Front_to_Back();
    }
    if(digitalRead(LSFrontRight)==0 && digitalRead(LSFrontLeft)==0)
      break;
	serial_check();
  }
  
}

// Function for Front Motion
void D1_Front_to_Back(){
  digitalWrite(d1_dir, LOW);
  digitalWrite(d1_step, HIGH);
  delayMicroseconds(step_size);
  digitalWrite(d1_step, LOW);
}
void D2_Forward(){
  digitalWrite(d2_dir, LOW);
  digitalWrite(d2_step, HIGH);
  delayMicroseconds(step_size);
  digitalWrite(d2_step, LOW);
}
void D3_Front_to_Back(){
  digitalWrite(d3_dir, LOW);
  digitalWrite(d3_step, HIGH);
  delayMicroseconds(step_size);
  digitalWrite(d3_step, LOW);
}

// Function for Backward Motion
void D1_Back_to_Front(){
  digitalWrite(d1_dir, HIGH);
  digitalWrite(d1_step, HIGH);
  delayMicroseconds(step_size);
  digitalWrite(d1_step, LOW);
}
void D2_Backward(){
  digitalWrite(d2_dir, HIGH);
  digitalWrite(d2_step, HIGH);
  delayMicroseconds(step_size);
  digitalWrite(d2_step, LOW);
}
void D3_Back_to_Front(){
  digitalWrite(d3_dir, HIGH);
  digitalWrite(d3_step, HIGH);
  delayMicroseconds(step_size);
  digitalWrite(d3_step, LOW);
}

// Function for STOP Motion
void D1_Stop(){
  digitalWrite(d1_dir, LOW);
  digitalWrite(d1_step, LOW);
}
void D2_Stop(){
  digitalWrite(d2_dir, LOW);
  digitalWrite(d2_step, LOW);
}
void D3_Stop(){
  digitalWrite(d3_dir, LOW);
  digitalWrite(d3_step, LOW);
}