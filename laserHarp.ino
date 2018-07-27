#include "pitches.h"

int speakerPin = 3;
int duration = 100;

int laser1 = A1;
int laser2 = A2;
int laser3 = A3;
int laser4 = A4;
int laser5 = A5;
int laser6 = A6;
int laser7 = A7;
int laser8 = A8;
int allLasers[8] = {laser1, laser2, laser3, laser4, laser5, laser6, laser7, laser8};
int *trigLaser;

int val1;
int val2;
int val3;
int val4;
int val5;
int val6;
int val7;
int val8;

int tone1 = NOTE_C4;
int tone2 = NOTE_D4;
int tone3 = NOTE_E4;
int tone4 = NOTE_G4;
int tone5 = NOTE_A4;
int tone6 = NOTE_B4;
int tone7 = NOTE_D5;
int tone8 = NOTE_F5;
int allTones[8] = {tone1, tone2, tone3, tone4, tone5, tone6, tone7, tone8};

int* minVal(int *allVals[]);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  val1 = analogRead(laser1);
  val2 = analogRead(laser2);
  val3 = analogRead(laser3);
  val4 = analogRead(laser4);
  val5 = analogRead(laser5);
  val6 = analogRead(laser6);
  val7 = analogRead(laser7);
  val8 = analogRead(laser8);
  int allVals[8] = {val1, val2, val3, val4, val5, val6, val7, val8};
  trigLaser = minVal(allVals);

  for(int i = 0; i < 8; i++)
  {
    if(*trigLaser == allLasers[i])
    {
      tone(speakerPin, allTones[i], duration);
    }
  }
}

int* minVal(int allVals[])
{
  int lowestVal = 1023;
  int *lowestLaser;
  int *ptr = allVals;
  for(; ptr < ptr + 8; ++ptr)
  {
      if(*ptr < lowestVal)
      {
        lowestVal = *ptr;
        lowestLaser = ptr;
      }
  }
  return ptr;
}
