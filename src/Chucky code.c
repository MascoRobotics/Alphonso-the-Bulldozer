#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Sensor, S2,     IR,             sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C1_1,     backRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     backLeft,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     frontLeft,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     frontRight,    tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C4_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     chucky,        tmotorTetrix, openLoop, encoder)
#pragma config(Servo,  srvo_S1_C3_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#include "JoystickDriver.c"
const int RAMP = -10500;
int encoder = 0;
int value = 0;
void releaseArm() {
	motor[chucky] = -40;
	nMotorEncoder[chucky]=0;
	while(value > -190) {
		value = nMotorEncoder[chucky];
	}
}

void raiseArm() {
	motor[chucky] = 30;
	while(value < -50) {
		value = nMotorEncoder[chucky];
	}
}




void moveForward(int speed) {
	motor[backRight] = -speed;
	motor[frontRight] = -speed;
	motor[backLeft] = speed;
	motor[frontLeft] = speed;
}

void moveFast() {
	motor[backRight] = -100;
	motor[frontRight] = -100;
	motor[backLeft] = 100;
	motor[frontLeft] = 100;
}

void moveRotate(int value) {
	motor[backRight] = 50 * value;
	motor[frontRight] = 50 * value;
	motor[backLeft] = 50 * value;
	motor[frontLeft] = 50 * value;
}

void stopMoving() {
	motor[backRight] = 0;
	motor[frontRight] = 0;
	motor[backLeft] = 0;
	motor[frontLeft] = 0;
}

int irvalue = 0;

task main()
{
	waitForStart();
	nMotorEncoder[frontRight] = 0;
	moveForward(30);
	while (irvalue != 5) {
		irvalue = SensorValue[IR];
	}

	wait1Msec(250);

	stopMoving();

	releaseArm();
	wait1Msec(500);
	raiseArm();

	wait1Msec(1000);
	moveForward(50);
	encoder = nMotorEncoder[frontRight];

	while (encoder > RAMP) encoder = nMotorEncoder[frontRight];

	stopMoving();

	moveRotate(-50);
	wait1Msec(500);
	stopMoving();

	moveForward(50);
	wait1Msec(2500);

	stopMoving();

	moveRotate(-50);
	wait1Msec(500);

	stopMoving();

	moveForward(50);
	wait1Msec(2000);

}
