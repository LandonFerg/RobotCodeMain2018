#include "Gyro.h"

GyroClass::GyroClass()
{
	ahrs = new AHRS(SPI::Port::kMXP);
}



double GyroClass::getPitch()
{

    double Pitch = ahrs->GetPitch();
    std::cout << "Pitch: " << Pitch << std::endl;

	return Pitch;
}

bool GyroClass::checkMoving()
{
    bool moving;
    
    if (ahrs->IsMoving())
    {
        moving = true;
    }
    else
    {
        moving = false;
        
        //std::cout << "ERROR: GYRO ISN'T MOVING" << endl;
    }
    
    return moving;
    
}


// - yaw = left + yaw = right

double GyroClass::getYaw()
{

    double Yaw = ahrs->GetYaw();
    std::cout << "Yaw: " << Yaw << std::endl;

	return Yaw;
}

void GyroClass::resetYaw()
{
    ahrs->Reset();  // Resets Z axis
}

double GyroClass::getRoll()
{

    double Roll = ahrs->GetRoll();
    std::cout << "Roll: " << Roll << std::endl;

	return Roll;
}

GyroClass::~GyroClass()
{

}
