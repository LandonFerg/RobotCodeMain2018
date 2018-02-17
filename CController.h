#ifndef CCONTROLLER_H
#define CCONTROLLER_H
//put includes
#include <Joystick.h>
#include <XboxController.h>
#include <iostream>
#include <GenericHID.h>

#define Button_A 1
#define Button_B 2
#define Button_X 3
#define Button_Y 4
#define Right_Bumper frc::GenericHID::JoystickHand::kRightHand
#define Left_Bumper frc::GenericHID::JoystickHand::kLeftHand
#define Button_Back 7
#define Button_Start 8
#define Left_Stick_Button Left_Bumper
#define Right_Stick_Button Right_Bumper
#define Left_Stick_X Left_Bumper
#define Left_Stick_Y Left_Bumper
#define Right_Stick_X Right_Bumper
#define Right_Stick_Y Right_Bumper
#define Left_Trigger Left_Bumper
#define Right_Trigger Right_Bumper
#define controller_One 0
#define controller_Two 1
#define leftBumperC1 controller_One
#define rightBumperC1 controller_One
#define leftBumperC2 controller_Two
#define rightBumperC2 controller_Two

using namespace std;

//class definition
class CController
{
    private:
        XboxController * ControllerOne;
        XboxController * ControllerTwo;
       /* XboxController * ControllerPanelOne;
        XboxController * ControllerPanelTwo; */
        Joystick * PanelJoysticks[2];
        void getControllerOne();
        void getControllerTwo();
        
        
        void getPanelButtons(); 
               
    public:
        
        bool bStartButtonPressed [2];
        bool bStartButtonReleased [2];
        bool bStartButtonRaw [2];
        
        bool bAButtonRaw [2];
        bool bBButtonRaw [2];
        bool bXButtonRaw [2];
        bool bYButtonRaw [2];
            
        bool bPanelButtons[24];
        
        bool bAButtonPressed [2];
        bool bBButtonPressed [2];
        bool bYButtonPressed [2];
        bool bXButtonPressed [2];
        
        double dTriggerLAxis [1]; // I added this - CR
        double dTriggerRAxis [1]; // I added this - CR
        
        bool bAButtonReleased [2];
        bool bBButtonReleased [2];
        bool bYButtonReleased [2];
        bool bXButtonReleased [2];
        
        bool bBumperPressed [4];
        bool bBumperReleased [4];
        
        double dLeftXAxis [2];
        double dLeftYAxis [2];
        
        double dRightXAxis [2];
        double dRightYAxis [2];
        

        //interface for babies to use
        CController();
        void Update();
        
};

#endif
