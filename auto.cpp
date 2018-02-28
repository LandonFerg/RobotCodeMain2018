#include "auto.h"


AutoClass::AutoClass()
{
    autoDrivetrain = new DrivetrainClass();
    autoCascade = new Cascade();
    autoManip = new manipulator();
    timer = new frc::Timer();
}

void AutoClass::mode0(void)    // 1st auto - Far left place on switch
{
    static int current_state = 0;
    int retval = 0;
    
    std::string gameData;
	gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	
    switch(current_state)
    {
        case 0:
            retval = autoDrivetrain->goForwards(/*speed*/ 4, /*accel*/ 3, /*Feet*/ 4.5);
            break;
        case 1:
            if(gameData[0] == 'R')		// Our switch side is on the right
		    {
                // Call another method. We need to turn right, go forwards, and turn left before placing
                retval = autoDrivetrain->turnRight(4, 3, /* angle */ 90);
		    }
		    else{/* switch is in front of us, place cube, skip turning states*/ current_state = 4;}
            break;
        case 2:
            retval = autoDrivetrain->goForwards(/*speed*/ 4, /*accel*/ 3, /*Feet*/ 9);
            break;
        case 3:
            retval = autoDrivetrain->turnLeft(4, 3, /* angle */ 90);
        case 4:
            autoCascade->elevatorHeight(22);    // go up to switch height
            returnTime(1);
        case 5:
            resetTime();
            autoManip->autoManipOut();  // foof out
            returnTime(2);
        case 6:
            autoManip->autoManipStop(); // cease foof
            timer->Reset();
            retval = 1;
        case 7:
            autoCascade->elevatorHeight(0);   // Bring cascade back down
            retval = 1;
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
