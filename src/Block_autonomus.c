#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Sensor, S2,     light,          sensorLightActive)
#pragma config(Motor,  mtr_S1_C1_1,     motor1,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motor2,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motor3,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motor4,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     Flag,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


//void MoveFoward(){
	//motor[motor1]= -50;
	//motor[motor2]= 50;
//	motor[motor3]= 50;
	//motor[motor4]= -50;
//}

//void LiftUP(){
	//servo[servo1]=255;
	//servo[servo2]=255;
//}

task main()
{
motor[motor1]=-50;
motor[motor2]= 50;
motor[motor3]= 50;
motor[motor4]=-50;
	//LiftUP();
servo[servo1]=255;
servo[servo6]=255;
wait1Msec(1500);

motor[motor1]=50;
motor[motor2]=- 50;
motor[motor3]= -50;
motor[motor4]=50;
servo[servo1]=255;
servo[servo6]=255;
wait1Msec(1500);

motor[motor1]=-50;
motor[motor2]= 50;
motor[motor3]= 50;
motor[motor4]=-50;
servo[servo1]= 255;
servo[servo6]=255;
wait1Msec(1500);
}
