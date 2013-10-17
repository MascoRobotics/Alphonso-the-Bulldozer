#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S2,     GRYO,           sensorLightActive)
#pragma config(Motor,  mtr_S1_C1_1,     motorA,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorB,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorC,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorD,        tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"


task main()
{
	int value = 0;
	int ovalue = 1;
	int count = 0;
	while (true) {
		value = SensorValue[GRYO];
		eraseDisplay();
		nxtDisplayBigStringAt(0, 25, "%d", ovalue);
		if (count % 1000 == 0 && ovalue != value) {
			eraseDisplay();
			nxtDisplayBigStringAt(0, 25, "%d", value);
			ovalue = value;
			count = 1;
		} else {
			count++;
		}
	}
}
