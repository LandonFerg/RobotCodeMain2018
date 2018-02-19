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
    VictorSPX * intakeMotorRight;
    VictorSPX * manipulatorMotorLeft;
    VictorSPX * intakeMotorLeft;
    
    int count = 0;
    int *pCount = &count;
    
	public:
        CController *controllerClass1;
        void manipulatorPower();
		manipulator();

};

#endif
