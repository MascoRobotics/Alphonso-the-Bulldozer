#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Hubs,  S3, HTMotor,  none,     none,     none)
#pragma config(Sensor, S2,     IR,             sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  motorA,          hand,           tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     spider1,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     spider2,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     frontLeft,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     frontRight,    tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C4_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     chucky,        tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S3_C1_1,     spinner1,      tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S3_C1_2,     spinner2,      tmotorTetrix, openLoop, encoder)
#pragma config(Servo,  srvo_S1_C3_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"


int encoderValue = 0;

void moveForward(int speed) {
	motor[frontRight] = -speed;
	motor[frontLeft] = speed;
}

void moveFast() {
	motor[frontRight] = -100;
	motor[frontLeft] = 100;
}

void moveRotate(int value) {
	motor[frontRight] = 50 * value;
	motor[frontLeft] = 50 * value;
}

void stopMoving() {
	motor[frontRight] = 0;
	motor[frontLeft] = 0;
}

int delay = 0;
void delayOption() {
	int odelay = -1;
	while (true) {
		if (nNxtButtonPressed == 3)
			break;
		else if (nNxtButtonPressed == 1) {
			delay++;
		} else if (nNxtButtonPressed == 2) {
			delay--;
		}
		if (delay < 0)
			delay = 0;
		eraseDisplay();
		nxtDisplayCenteredBigTextLine(3, "%d", delay);
		wait1Msec(1);
	}
}

task main()
{
	delayOption();
  waitForStart();
  wait1Msec(delay);

  moveForward(50);
  wait1Msec(1500);
  moveRotate(-50);
  wait1Msec(1000);
  moveForward(-50);
  wait1Msec(1800);
  stopMoving();
}