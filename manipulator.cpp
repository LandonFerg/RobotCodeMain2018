#include <iostream>
#include "manipulator.h"



manipulator::manipulator()
{
    manipulatorMotor1 = new VictorSPX(1);
    //manipulatorMotor2 = new VictorSPX(number); //The Intake motors appear to be attached to a Y-cable
    
    controllerClass1 = new CController();
    
    intakeMotor1 = new VictorSPX(3);
    //manipulatorMotor2->Set(ctre::phoenix::motorcontrol::ControlMode::Follower,1);
    
    intakeMotor1->Set(ctre::phoenix::motorcontrol::ControlMode::Follower,1);
    //intakeMotor2->Set(ctre::phoenix::motorcontrol::ControlMode::Follower,number); //Perhaps there will be a Y-cabled here too
}

/*void manipulator::manipulatorPower() // old and commented out for good reason
{
    double c2TRight = controllerClass->dTriggerRAxis[controller_Two];    
    while (controllerClass1->bXButtonRaw == true)
    {
        c2TRight = 1;
        manipulatorMotor1->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,c2TRight);
    }
    manipulatorMotor1->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,c2TRight);
}*/

void manipulator::manipulatorPower()
{
    manipulatorMotor1->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,c2TRight); //config of c2TRight moved to .h file
    
    
}
