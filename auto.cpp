#include "auto.h"


AutoClass::AutoClass()
{
    autoDrivetrain = new DrivetrainClass();
    timer = new frc::Timer();
}

void AutoClass::mode0(void)    // 1st auto test drive forwards & turn
{
    static int current_state = 0;
    int retval = 0;
    
    switch(current_state)   // remember to reset time
    {
        case 0:
            autoDrivetrain->goForwards(/*speed*/ 4, /*accel*/ 3, /*Feet*/ 2); 
            break;
        case 1:
            retval = returnTime(3);  // if 3 seconds have passed, set retval to 1: current_state++;
            break;
        case 2:
            autoDrivetrain->turnLeft(4, 3, /* angle */ 90); 
            break;
        default:
            break;
            
    }
    
    if( retval  == 1 )
        current_state++;
}

void AutoClass::autoRun()   // Main case for choosing autonomous & running
{
    int automode = 0;
    switch(automode)
    {
        case 0:    
            mode0();
        default:
            break;
    }    
}

int AutoClass::returnTime(double timePassed)
{
    timer->Start();
    if(timer->Get() >= timePassed)
    {
        return 1;
    }
}

void AutoClass::resetTime()
{
    timer->Reset();
}

AutoClass::~AutoClass()
{

}
