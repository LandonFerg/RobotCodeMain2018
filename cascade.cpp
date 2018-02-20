#include "cascade.h" 

// class constructor
Cascade::Cascade()
{
    cascadeTalon = new TalonSRX(10);
	cascadeVictorOne = new VictorSPX(11);
	cascadeVictorTwo = new VictorSPX(12);
	cascadeVictorThree = new VictorSPX(13);

}

void Cascade::initElevator()
{
    cascadeVictorOne->Follow(*cascadeTalon);
    cascadeVictorTwo->Follow(*cascadeTalon);
    cascadeVictorThree->Follow(*cascadeTalon); 
     
    cascadeTalon->Config_kP(0, 1, 10);
    cascadeTalon->Config_kI(0, 0, 10);
    cascadeTalon->Config_kD(0, 0, 10);
    cascadeTalon->Config_kF(0, 0, 10);
    
    cascadeTalon->SetInverted(false);
    cascadeVictorOne->SetInverted(false);
    cascadeVictorTwo->SetInverted(false);
    cascadeVictorThree->SetInverted(false);
    
    
    cascadeTalon->SetSensorPhase(true); 
   cascadeTalon->SetSelectedSensorPosition(0,0,10);
   cascadeTalon->ConfigMotionAcceleration(7000, 10);
   cascadeTalon->ConfigMotionCruiseVelocity(7000, 10);
}

void Cascade::initTeleopElevator() //NEEDED to prevent elevator from freaking out, not sure why -SM
{

    cascadeTalon->SetSelectedSensorPosition(cascadeTalon->GetSelectedSensorPosition(0),0,0);
  
}

double Cascade::getTicks(double distanceInches)
{
    // 5.667in per rotation
    // 4096 ticks per rotation
    
    double ticksToGo = (distanceInches*722.8)/2.0; 
    return ticksToGo;
}

void Cascade::elevatorHeight(double targetInches)
{
     cascadeTalon->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, getTicks(-targetInches));  //changed to - by LF and SM
}

void Cascade::controlElevator()
{
    if (controllerClass->bYButtonRaw[controller_Two] == true)
    {
        cascadeTalon->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, getTicks(-6*12 - 8)); // Highest height, which is on scale, is 6' //Negative Required if not inverting -SM
        cout << "Going to highest scale position." << endl;                                             //-8 added by SM to clear wall
    }
    
    if (controllerClass->bAButtonRaw[controller_Two] == true)
    {
        cascadeTalon->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, getTicks(-1.0)); // Cube intake position. //Negative Required if not inverting and should not be 0 -SM
        cout << "Going to cube intake position." << endl;
    }
    
    
    if (controllerClass->bBButtonRaw[controller_Two] == true) // Ownership of scale is at 4'8" //Negative Required if not inverting -SM
    {
        cascadeTalon->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, getTicks((-4*12)-8-8)); //-8 added by SM to clear wall
        cout << "Going to position 20.0." << endl;
    }
    
    if (controllerClass->bXButtonRaw[controller_Two] == true) //Negative Required if not inverting -SM 
    {
        cascadeTalon->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, getTicks(-30.0));
        cout << "Going to position 30.0." << endl;
    }
} 

void::Cascade::manualElevator()
{
    cascadeTalon->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, controllerClass->dRightYAxis[controller_Two]);
}
