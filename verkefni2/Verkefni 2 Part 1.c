#pragma config(Motor,  port2,           leftMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)

// This program will instruct the robot to move forwards 0.5m then backwards 1m until it reaches 2.5m

void drive(int power, int time)
{
	motor[rightMotor] = power;
	motor[leftMotor] = power;
	wait1Msec(time);
}

void stop(int time)
{
		motor[rightMotor] = 0;
		motor[leftMotor]  = 0;
		wait1Msec(time);
}

const int FULLPOWER = 127;
int time = 755;

task main()
{
	wait1Msec(5000);

	for(int i = 0; i < 6; i++)
	{
		drive(FULLPOWER, time*i);
		stop(1000);
		drive(-FULLPOWER, time*++i);
		stop(1000);
	}
}
