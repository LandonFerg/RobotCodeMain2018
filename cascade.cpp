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
    
    //cascadeTalon->SetInverted(true);
    //cascadeVictorOne->SetInverted(true);
    //cascadeVictorTwo->SetInverted(true);
    //cascadeVictorThree>SetInverted(true);
    
    
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
     cascadeTalon->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, getTicks(targetInches));  
}

void Cascade::controlElevator()
{
    if (controllerClass->bYButtonRaw[controller_Two] == true)
    {
        cascadeTalon->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, getTicks(6*12)); // Highest height, which is on scale, is 6'
        cout << "Going to highest scale position." << endl;    
    }
    
    if (controllerClass->bAButtonRaw[controller_Two] == true)
    {
        cascadeTalon->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, getTicks(0.0)); // Cube intake position.
        cout << "Going to cube intake position." << endl;
    }
    
    
    if (controllerClass->bBButtonRaw[controller_Two] == true) // Ownership of scale is at 4'8"
    {
        cascadeTalon->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, getTicks((4*12)+8));
        cout << "Going to position 20.0." << endl;
    }
    
    if (controllerClass->bXButtonRaw[controller_Two] == true) // 
    {
        cascadeTalon->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, getTicks(30.0));
        cout << "Going to position 30.0." << endl;
    }
} 

void::Cascade::manualElevator()
{
    cascadeTalon->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, controllerClass->dRightYAxis[controller_Two]);
}
