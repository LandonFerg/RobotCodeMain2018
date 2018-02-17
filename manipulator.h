#ifndef MANIPULATOR_H
#define MANIPULATOR_H

#include <iostream>
#include <WPIlib.h>
#include <Victor.h>
#include <Phoenix.h>
#include "CController.h"
#include <PowerDistributionPanel.h>
using namespace std;

class manipulator
{
    VictorSPX * manipulatorMotor1;
    VictorSPX * intakeMotor1;
    
    double c2TRight = controllerClass1->dTriggerRAxis[controller_Two];
	public:
        CController *controllerClass1;
        void manipulatorPower();
		manipulator();

};

#endif
