#ifndef AUTO_H
#define AUTO_H

#include <AHRS.h>
#include "Gyro.h"
#include <iostream>
#include <WPIlib.h>
#include <Timer.h>
#include "Drivetrain.h"
#include "manipulator.h"
#include "cascade.h" 

#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
using namespace std;

class AutoClass
{
    
    private:
        DrivetrainClass *autoDrivetrain;
        Cascade *autoCascade;
        manipulator *autoManip;

        frc::Timer *timer;
        void mode0(void);
	    void resetTime();
	    int returnTime(double timePassed);
	public:
        void autoRun();
		AutoClass();
		~AutoClass();
	protected:
};

#endif
