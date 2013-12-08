#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     backRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     backLeft,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     frontLeft,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     frontRight,    tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"


int encoderValue = 0;

void moveFoward() {
	motor[backRight] = -50;
	motor[frontRight] = -50;
	motor[backLeft] = 50;
	motor[frontLeft] = 50;
}

void moveRotate(int value) {
	motor[backRight] = -50 * value;
	motor[frontRight] = -50 * value;
	motor[backLeft] = -50 * value;
	motor[frontLeft] = -50 * value;
}

void stopMoving() {
	motor[backRight] = 0;
	motor[frontRight] = 0;
	motor[backLeft] = 0;
	motor[frontLeft] = 0;
}

task main()
{
  //waitForStart();
	moveFoward();
	wait1Msec(2500);
	stopMoving();
}