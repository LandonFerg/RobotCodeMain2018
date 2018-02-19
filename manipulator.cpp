#include <iostream>
#include "manipulator.h"



manipulator::manipulator()
{
    manipulatorMotorRight = new VictorSPX(21);
    manipulatorMotorLeft = new VictorSPX(22);
    
    controllerClass1 = new CController();
    
    intakeMotorLeft = new VictorSPX(3);
    intakeMotorRight = new VictorSPX(17);
    
    intakeMotor2->SetInverted(true);
    
    intakeMotorLeft->Follow(*manipulatorMotorLeft);
    intakeMotorRight->Follow(*manipulatorMotorRight);
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
    double c2TRight = controllerClass->dTriggerRAxis[controller_Two]; // should move this...
    double c1TLeft = controllerClass->dTriggerLAxis[controller_One];
    double c2TLeft = controllerClass->dTriggerLAxis[controller_Two];
    
    manipulatorMotorRight->SetInverted(true);
    
    //std::cout << "RIGHT TRIG: "<< c2TRight << endl;
    //std::cout << "LEFT TRIG: "<< c1TLeft << endl;
    
    if (c1TLeft > 0)
    {
            manipulatorMotorLeft->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,-1*c1TLeft); //config of c2TRight moved to .h file
            manipulatorMotorRight->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -1*c1TLeft);
           // intakeMotor1->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, c2TRight);
            //intakeMotor2->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, c2TRight);
            
    }
    
    else if(c2TLeft > 0)
    {
    manipulatorMotorLeft->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,-1*c2TLeft); //config of c2TRight moved to .h file
    manipulatorMotorRight->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -1*c2TLeft);
    
    //intakeMotor1->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, c2TRight);
   // intakeMotor2->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, c2TRight);
    }
    else if (c2TRight > 0)
    {
        manipulatorMotorLeft->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,c2TRight); //config of c2TRight moved to .h file
        manipulatorMotorRight->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, c2TRight);
    }
    else
    {
            manipulatorMotorLeft->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,0); //config of c2TRight moved to .h file
            manipulatorMotorRight->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);        
    }
  //  intakeMotor1->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, c2TRight);
}
