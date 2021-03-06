#include "Drivetrain.h"
#include "Gyro.h"


# define M_PI 3.14159265358979323846  /* pi */

#include <iostream>
#include <cmath>
#include <cfenv>
#include <climits>
#include <chrono>
#include <ctime>

#include "Gyro.h"
#include "CController.h"

/* ***Motor Controllers*** */

#define leftTPort 1
#define rightTPort 4

#define leftVOnePort 5
#define leftVTwoPort 6

#define rightVOnePort 7
#define rightVTwoPort 8

GyroClass *gyroClassTwo;

DrivetrainClass::DrivetrainClass()
{
    gyroClassTwo = new GyroClass;
    controllerClass = new CController;
    
	leftTalon = new TalonSRX(leftTPort);
	rightTalon = new TalonSRX(rightTPort);

	//Follower motors 
	leftVictor1 = new VictorSPX(leftVOnePort);
	leftVictor2 = new VictorSPX(leftVTwoPort);

	rightVictor1 = new VictorSPX(rightVOnePort);
	rightVictor2 = new VictorSPX(rightVTwoPort);
	
}
void DrivetrainClass::linkMotors()
{
    
	   leftTalon->SetInverted(true);
	   leftVictor1->SetInverted(true);
	   leftVictor2->SetInverted(true);
	   
	   rightTalon->SetInverted(false);
	   rightVictor1->SetInverted(false);
	   rightVictor2->SetInverted(false);
	   
}

void DrivetrainClass::linkFollowers()   // THIS SHOULD GO INTO THE ROBOT INIT() FUNCTION IN ROBOT.CPP -LF
{
	   rightVictor1->Follow(*rightTalon);    
	   rightVictor2->Follow(*rightTalon);  
       leftVictor1->Follow(*leftTalon);
	   leftVictor2->Follow(*leftTalon);   
}


void DrivetrainClass::Drive()
{
    
double Left = controllerClass->dLeftYAxis[controller_One];
double Right = controllerClass->dRightYAxis[controller_One];

controllerClass->Update();

double upDeadzone = 0.1;
double downDeadzone = -0.1;
//std::cout << "Right DAVID: " << Right << std::endl;
//     --LEFT DEADZONE --

       if(Left > upDeadzone)        // If more than the up deadzone, ok good
       {
            leftTalon->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,Left);
       }
       else if (Left < downDeadzone)    // If less than the down deadzone, ok good
       {
                    leftTalon->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,Left);
       }
       else                                 // Else - in the deadzone - turn motors off
       {
                        leftTalon->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,0);
                        //std::cout << "Left Dead: " << Left << std::endl;
       }
       //Code still sucks
//     --RIGHT DEADZONE --

       if(Right > upDeadzone)        // If more than the up deadzone, ok good
       {
            rightTalon->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,Right);
       }
       
       else if (Right < downDeadzone)    // If less than the down deadzone, ok good
       {
               rightTalon->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,Right);
       }    
       
        else                                 // Else - in the deadzone - turn motors off
       { 
                    rightTalon->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,0);
                    //std::cout << "Right Dead: " << Right << std::endl;
       }

        
       this->linkMotors();
}


void DrivetrainClass::resetSensor()
{
    
    leftTalon->SetSelectedSensorPosition(0,0,0);    // Reset encoders
    rightTalon->SetSelectedSensorPosition(0,0,0);
    
}


int DrivetrainClass::goForwards(double speed, double accel, double feet) // Motion Magic?
{
    //TODO CRAIG: if good to go forwards returns true, continue
    
    this->linkMotors();
    
    //Set Max accel and cruise velocity (should be in native units since we aren't scaling using encoder counts per rev)
    leftTalon->SetSensorPhase(true);
    rightTalon->SetSensorPhase(true);

    
    
    leftTalon->SetSelectedSensorPosition(0,0,0);    // Reset encoders
    rightTalon->SetSelectedSensorPosition(0,0,0);


    
    leftTalon->ConfigMotionCruiseVelocity(DrivetrainClass::nativeVelFromVel(speed),0); // Pass 0 for timeoutMS to avoid blocking in loop / or 10 out of loop
    rightTalon->ConfigMotionCruiseVelocity(DrivetrainClass::nativeVelFromVel(speed),0);
    
    leftTalon->ConfigMotionAcceleration(DrivetrainClass::nativeVelFromVel(accel),0);
    rightTalon->ConfigMotionAcceleration(DrivetrainClass::nativeVelFromVel(accel),0);
    
    
    leftTalon->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, DrivetrainClass::nativeFromFeet(feet)*-1);   // Set motion magic to go (feet) value
    rightTalon->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, DrivetrainClass::nativeFromFeet(feet)*-1);
    
	//Return error message if running into wall
	
	if(leftTalon->GetSelectedSensorVelocity(leftTPort) < 10) // If velocity less than 100 (~14.6RPM) return 1...
{
        return 1;
    }  // ~14.6 RPM)    // Multiply by (600/SensorUnitsPerRotation) to convert into RPM.    input*(600/4096)
	
}

int DrivetrainClass::checkForward()     // Used for checking if done going forwards in autonomous
{
    
}

int DrivetrainClass::turnLeft(double speed, double accel, double angle)
{
    //Set Max accel and cruise velocity (should be in native units since we aren't scaling using encoder counts per rev)
    leftTalon->SetSensorPhase(true);
    rightTalon->SetSensorPhase(true);
    
    this->linkMotors();
    	
    leftTalon->SetSelectedSensorPosition(0,0,0);    // Reset encoders
    rightTalon->SetSelectedSensorPosition(0,0,0);


    
    leftTalon->ConfigMotionCruiseVelocity(DrivetrainClass::nativeVelFromVel(speed),0); // Pass 0 for timeoutMS to avoid blocking in loop / or 10 out of loop
    rightTalon->ConfigMotionCruiseVelocity(DrivetrainClass::nativeVelFromVel(speed),0);
    
    leftTalon->ConfigMotionAcceleration(DrivetrainClass::nativeVelFromVel(accel),0);
    rightTalon->ConfigMotionAcceleration(DrivetrainClass::nativeVelFromVel(accel),0);
    
    
    leftTalon->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, DrivetrainClass::nativeFromAngle(angle));   // Se motion magic to go (feet) value
    rightTalon->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, DrivetrainClass::nativeFromAngle(angle)*-1);
    
    	if(leftTalon->GetSelectedSensorVelocity(leftTPort) < 10) // If velocity is less than 10 (~1.5RPM) return 1...
        {
        return 1;
        }  // Multiply by (600/SensorUnitsPerRotation) to convert into RPM.    input*(600/4096)
    
}

int DrivetrainClass::turnRight(double speed, double accel, double angle)
{
    //Set Max accel and cruise velocity (should be in native units since we aren't scaling using encoder counts per rev)
    leftTalon->SetSensorPhase(true);
    rightTalon->SetSensorPhase(true);
    
    this->linkMotors();
    	
    leftTalon->SetSelectedSensorPosition(0,0,0);    // Reset encoders
    rightTalon->SetSelectedSensorPosition(0,0,0);


    
    leftTalon->ConfigMotionCruiseVelocity(DrivetrainClass::nativeVelFromVel(speed),0); // Pass 0 for timeoutMS to avoid blocking in loop / or 10 out of loop
    rightTalon->ConfigMotionCruiseVelocity(DrivetrainClass::nativeVelFromVel(speed),0);
    
    leftTalon->ConfigMotionAcceleration(DrivetrainClass::nativeVelFromVel(accel),0);
    rightTalon->ConfigMotionAcceleration(DrivetrainClass::nativeVelFromVel(accel),0);
    
    
    leftTalon->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, DrivetrainClass::nativeFromAngle(angle)*-1);   // Se motion magic to go (feet) value
    rightTalon->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, DrivetrainClass::nativeFromAngle(angle));
    
    	if(leftTalon->GetSelectedSensorVelocity(leftTPort) < 10) // If velocity is less than 10 (~1.5RPM) return 1...
        {
        return 1;
        }  // Multiply by (600/SensorUnitsPerRotation) to convert into RPM.    input*(600/4096)
    
}

void DrivetrainClass::stop()
{
    leftTalon->ConfigMotionCruiseVelocity(0,0); // Pass 0 for timeoutMS to avoid blocking in loop / or 10 out of loop
    rightTalon->ConfigMotionCruiseVelocity(0,0);
    
    leftTalon->ConfigMotionAcceleration(0,0);
    rightTalon->ConfigMotionAcceleration(0,0);
}

// Native Unit Equations

double DrivetrainClass::nativeFromAngle(double angleIn)
{
    return angleIn*55.236;
}

int DrivetrainClass::feetFromNative(double nativePosition)
{
    return double(nativePosition)*(1.0/4096.0)*(6.0*3.141)*(1.0/12.0);
}

int DrivetrainClass::nativeFromFeet (double feetIn) // Convert feet input to dumb numbers
{
    return feetIn*2607.513;     // MAGIC NUMBER IS 2607.513
}

int DrivetrainClass::nativeVelFromVel(int vel)
{
    double x = vel*12.0*(1.0/(6.0*3.14159)*4096.0*(1.0/10.0));
    vel = std::round(x);
    return vel;
}


DrivetrainClass::~DrivetrainClass()
{

}
