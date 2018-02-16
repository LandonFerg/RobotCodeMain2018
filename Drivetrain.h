#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include <iostream>
#include <WPIlib.h>
#include <Victor.h>
#include <Phoenix.h>
#include "CController.h"
using namespace std;

    	
extern CController *controllerClass;

class DrivetrainClass
{
private:
	Joystick *Controller;


	
	int feetFromNative(double nativePosition);
	int nativeVelFromVel(int vel);
	
	int nativeFromFeet (double feetIn);
	double nativeFromAngle(double angleIn);

	public:
        void goForwards(double speed, double accel, double feet);
        void turnLeft(double speed, double accel, double angle); // add double angle
        
        void resetSensor();
        
    	TalonSRX *leftTalon;
    	TalonSRX *rightTalon;

    	
        VictorSPX *leftVictor1;
    	VictorSPX *leftVictor2;
    
    	VictorSPX *rightVictor1;
    	VictorSPX *rightVictor2;

        void linkFollowers();
		void linkMotors();
        void Drive();
        void stop();
        
        

		DrivetrainClass();
		~DrivetrainClass();
	protected:
};

#endif
