#include "manipulator.h"



manipulator::manipulator()
{
    manipulatorMotor1 = new VictorSPX(31);
    //manipulatorMotor2 = new VictorSPX(number); //The Intake motors appear to be attached to a Y-cable
    
    controllerClass1 = new CController();
    
    //intakeMotor1 = new VictorSPX(33);     uncomment for intake
    //manipulatorMotor2->Set(ctre::phoenix::motorcontrol::ControlMode::Follower,1);
    
    //intakeMotor1->Set(ctre::phoenix::motorcontrol::ControlMode::Follower,1);  // intake
    //intakeMotor2->Set(ctre::phoenix::motorcontrol::ControlMode::Follower,number); //Perhaps there will be a Y-cabled here too
}

/*void manipulator::manipulatorPower() // old and commented out for good reason
{
       
    while (controllerClass1->bXButtonRaw == true)
    {
        c2TRight = 1;
        manipulatorMotor1->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,c2TRight);
    }
    manipulatorMotor1->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,c2TRight);
}*/

void manipulator::manipulatorPower()
{
    double c2TRight = controllerClass1->dTriggerRAxis[controller_Two]; 
    manipulatorMotor1->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,c2TRight); //config of c2TRight moved to .h file
    
    
}
