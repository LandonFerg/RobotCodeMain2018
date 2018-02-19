#ifndef MANIPULATOR_H
#define MANIPULATOR_H

#include <iostream>
#include <WPIlib.h>
#include <Victor.h>
#include <Phoenix.h>
#include "CController.h"
#include <PowerDistributionPanel.h>
using namespace std;

extern CController * controllerClass;

class manipulator
{
    VictorSPX * manipulatorMotorRight;
    VictorSPX * intakeMotor1;
    VictorSPX * manipulatorMotorLeft;
    VictorSPX * intakeMotor2;
    
    int count = 0;
    int *pCount = &count;
    
	public:
        CController *controllerClass1;
        void manipulatorPower();
		manipulator();

};

#endif
