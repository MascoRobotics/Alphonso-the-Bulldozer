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
int encoder = 0;
int value = 0;

/**
Open the hand to drop the block
*/
void openHand() {
	motor[hand] = 100;
	wait1Msec(1000);
	motor[hand] = -100;
	wait1Msec(100);
	motor[hand] = 0;
}

/**
Slame the arm down and give the basket a smack
*/
void releaseArm() {
	motor[chucky] = -60;
	nMotorEncoder[chucky]=0;
	wait1Msec(700);
	motor[chucky] = 0;
	openHand();
}

/**
Raise the arm up and make it hit itself
*/
void raiseArm() {
	motor[chucky] = 60;
	wait1Msec(1000);
	//while(value < -290) {
	//	value = nMotorEncoder[chucky];
	//}
	motor[chucky] = 0;
}

/**
Drive foward
The speed provided in the parameter will be the amount of power given to the motor
*/
void moveForward(int speed) {
	motor[frontRight] = -speed;
	motor[frontLeft] = speed;
}

/**
FULL SPEED AHEAD!
Move foward with full power
*/
void moveFast() {
	motor[frontRight] = -100;
	motor[frontLeft] = 100;
}

/**
Rotate the robot. The value provided in the parameter will be multiplied by 50, the result will be used as the amount of
power given to the motor
*/
void moveRotate(int value) {
	motor[frontRight] = 50 * value;
	motor[frontLeft] = 50 * value;
}

/**
Stop moving..
*/
void stopMoving() {
	motor[frontRight] = 0;
	motor[frontLeft] = 0;
}

/**
==== UTILITY METHODS, DO NOT MODIFY ===
*/

int delay = 0;
bool waitForS = true;
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

void askWaitForStart() {
	while (true) {
		if (nNxtButtonPressed == 1) {
			waitForS = false;
			break;
		} else if (nNxtButtonPressed == 2) {
			waitForS = true;
			break;
		}
		eraseDisplay();
		nxtDisplayCenteredTextLine(5, "(Y) Wait? (N)");
		wait1Msec(1);
	}
}

/**
Run the init code for the robot. This will run the Utility methods and activate waitForStart() if
requested by the user
*/
void initRobot() {
	delayOption();
	askWaitForStart();
	if (waitForS) waitForStart();
	wait1Msec(delay);
}


/**
=== MAIN TASK ===
*/
int irvalue = 0;
const int RAMP = -50;
task main()
{
	initRobot(); //DO NOT REMOVE


	nMotorEncoder[frontRight] = 0;
	moveForward(30);

	wait1Msec(2000);
	//while (irvalue != 5) {
	//	irvalue = SensorValue[IR];
	//}

	//wait1Msec(300);

	stopMoving();

	releaseArm();
	wait1Msec(500);
	raiseArm();

	wait1Msec(1000);
	moveForward(-50);
	encoder = nMotorEncoder[frontRight];

	while (encoder < RAMP) encoder = nMotorEncoder[frontRight];

	stopMoving();

	moveRotate(-50);
	wait1Msec(650);
	stopMoving();

	moveForward(50);
	wait1Msec(2500);

	stopMoving();

	moveRotate(-50);
	wait1Msec(450);

	stopMoving();

	moveForward(-50);
	wait1Msec(2000);
}
