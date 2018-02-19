#include "CController.h"
#include <iostream> 
#include <Joystick.h>
#include <XboxController.h>
#include <iostream>
#include <GenericHID.h>

using namespace std;

CController::CController()
{
    ControllerOne = new XboxController(1);
    ControllerTwo = new XboxController(2);
  //  ControllerPanelOne = new XboxController(3);
  // ControllerPanelTwo = new XboxController(4);
    PanelJoysticks[0] = new Joystick(3);
    PanelJoysticks[1] = new Joystick(4);
}

void CController::getControllerOne()
{
    bStartButtonPressed[controller_One] = ControllerOne->GetStartButtonPressed();
    bStartButtonReleased[controller_One] = ControllerOne->GetStartButtonReleased();
    bStartButtonRaw[controller_One] = ControllerOne->GetRawButton(Button_Start);
    
    bAButtonRaw[controller_One] = ControllerOne->GetRawButton(Button_A);
    bBButtonRaw[controller_One] = ControllerOne->GetRawButton(Button_B);
    bXButtonRaw[controller_One] = ControllerOne->GetRawButton(Button_X);
    bYButtonRaw[controller_One] = ControllerOne->GetRawButton(Button_Y);
    
    bAButtonPressed[controller_One] = ControllerOne->GetAButtonPressed();
    bBButtonPressed[controller_One] = ControllerOne->GetBButtonPressed();
    bYButtonPressed[controller_One] = ControllerOne->GetYButtonPressed();
    bXButtonPressed[controller_One] = ControllerOne->GetXButtonPressed();
    
    bAButtonReleased[controller_One] = ControllerOne->GetAButtonReleased();
    bBButtonReleased[controller_One] = ControllerOne->GetBButtonReleased();
    bYButtonReleased[controller_One] = ControllerOne->GetYButtonReleased();
    bXButtonReleased[controller_One] = ControllerOne->GetXButtonReleased();
    
    bBumperPressed[leftBumperC1] = ControllerOne->GetBumperPressed(Left_Bumper);
    bBumperPressed[rightBumperC1] = ControllerOne->GetBumperPressed(Right_Bumper);
    bBumperReleased[leftBumperC1] = ControllerOne->GetBumperReleased(Left_Bumper);
    bBumperReleased[rightBumperC1] = ControllerOne->GetBumperReleased(Right_Bumper);
    
    dLeftXAxis[controller_One] = ControllerOne->GetX(Left_Stick_X);
    dLeftYAxis[controller_One] = ControllerOne->GetY(Left_Stick_Y);
    dRightXAxis[controller_One] = ControllerOne->GetX(Right_Stick_X);
    dRightYAxis[controller_One] = ControllerOne->GetY(Right_Stick_Y);
    
    dTriggerLAxis[controller_One] = ControllerOne->GetTriggerAxis(Left_Trigger); // I added this - CR
    dTriggerRAxis[controller_One] = ControllerOne->GetTriggerAxis(Right_Trigger); // I added this - CR
}

void CController::getControllerTwo()
{
    bStartButtonPressed[controller_Two] = ControllerTwo->GetStartButtonPressed();
    bStartButtonReleased[controller_Two] = ControllerTwo->GetStartButtonReleased();
    bStartButtonRaw[controller_Two] = ControllerTwo->GetRawButton(Button_Start);
    
    bAButtonRaw[controller_Two] = ControllerTwo->GetRawButton(Button_A);
    bBButtonRaw[controller_Two] = ControllerTwo->GetRawButton(Button_B);
    bXButtonRaw[controller_Two] = ControllerTwo->GetRawButton(Button_X);
    bYButtonRaw[controller_Two] = ControllerTwo->GetRawButton(Button_Y);
    
    bAButtonPressed[controller_Two] = ControllerTwo->GetAButtonPressed();
    bBButtonPressed[controller_Two] = ControllerTwo->GetBButtonPressed();
    bYButtonPressed[controller_Two] = ControllerTwo->GetYButtonPressed();
    bXButtonPressed[controller_Two] = ControllerTwo->GetXButtonPressed();
    
    bAButtonReleased[controller_Two] = ControllerTwo->GetAButtonReleased();
    bBButtonReleased[controller_Two] = ControllerTwo->GetBButtonReleased();
    bYButtonReleased[controller_Two] = ControllerTwo->GetYButtonReleased();
    bXButtonReleased[controller_Two] = ControllerTwo->GetXButtonReleased();
    
    bBumperPressed[leftBumperC2] = ControllerTwo->GetBumperPressed(Left_Bumper);
    bBumperPressed[rightBumperC2] = ControllerTwo->GetBumperPressed(Right_Bumper);
    bBumperReleased[leftBumperC2] = ControllerTwo->GetBumperReleased(Left_Bumper);
    bBumperReleased[rightBumperC2] = ControllerTwo->GetBumperReleased(Right_Bumper);
    
    dLeftXAxis[controller_Two] = ControllerTwo->GetX(Left_Stick_X);
    dLeftYAxis[controller_Two] = ControllerTwo->GetY(Left_Stick_Y);
    dRightXAxis[controller_Two] = ControllerTwo->GetX(Right_Stick_X);
    dRightYAxis[controller_Two] = ControllerTwo->GetY(Right_Stick_Y);
    
    dTriggerLAxis[controller_Two] = ControllerTwo->GetTriggerAxis(Left_Trigger); // I added this - CR
    dTriggerRAxis[controller_Two] = ControllerTwo->GetTriggerAxis(Right_Trigger); // I added this - CR
}

void CController::getPanelButtons()
{
    for(int i = 1 ; i < 12; i++) 
    {
        bPanelButtons[i] = PanelJoysticks[0]->GetRawButton(i);
        bPanelButtons[12+i] = PanelJoysticks[1]->GetRawButton(i);
    }
}

void CController::Update()
{
    getPanelButtons();
    getControllerOne();
    getControllerTwo();   
}


