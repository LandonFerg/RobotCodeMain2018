#ifndef AUTO_H
#define AUTO_H

#include <AHRS.h>
#include "Gyro.h"
#include <iostream>
#include <WPIlib.h>
#include <Timer.h>
#include "Drivetrain.h"
using namespace std;

class AutoClass
{
    
    private:
        DrivetrainClass *autoDrivetrain;
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
