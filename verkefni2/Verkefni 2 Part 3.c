#pragma config(Motor,  port2,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           rightMotor,    tmotorServoContinuousRotation, openLoop)

// This program will instruct the robot to move forwards 0.5m then backwards 1m until it reaches 2.5m

bool turnArray[14] = {true,false,false,true,false,true,false,false,false,true,true,false,false,true};

void drive()
{
		motor[rightMotor] = 127;
		motor[leftMotor]  = 127;
		wait1Msec(755);
}

void stopMotors(int time)
{
		motor[rightMotor] = 0;
		motor[leftMotor]  = 0;
		wait1Msec(time);
}

void turn(bool L_R)
{
	if(L_R == true)
	{
		motor[rightMotor] = 90;
		motor[leftMotor]  = -90;
		wait1Msec(755);
	}
	else
	{
		motor[rightMotor] = -90;
		motor[leftMotor]  = 90;
		wait1Msec(755);
	}

}

task main()
{
	wait1Msec(3000);

	for(int i = 0; i < 14; i++ )
	{
		drive();
		stopMotors(1000);
		turn(turnArray[i]);
		stopMotors(1000);
	}
}
