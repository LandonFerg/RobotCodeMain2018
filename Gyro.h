#ifndef GYRO_H
#define GYRO_H

#include <AHRS.h>
#include "Gyro.h"
#include <iostream>
#include <WPIlib.h>
using namespace std;

class GyroClass
{
    public:
    void resetYaw();
    bool checkMoving();
    
    private:
	AHRS* ahrs;
	
	public:
    double getYaw();
	double getPitch();
	double getRoll();
		GyroClass();
		~GyroClass();
	protected:
};

#endif
