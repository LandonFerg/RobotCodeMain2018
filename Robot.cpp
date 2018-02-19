/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

/*
// Buttons
#define Button_A 1
#define Button_B 2
#define Button_X 3
#define Button_Y 4
#define Left_Bumper 5
#define Right_Bumper 6
#define Button_Back 7
#define Button_Start 8
#define Left_Stick_Button 9
#define Right_Stick_Button 10

// Sticks
#define Left_Stick_X 0
#define Left_Stick_Y 1
#define Right_Stick_X 4
#define Right_Stick_Y 5
#define Left_Trigger 2
#define Right_Trigger 3
*/

#include <iostream>
#include <string>

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include <WPIlib.h>
#include <Victor.h>
#include <Phoenix.h>
#include "Drivetrain.h"
#include "CController.h"
#include "manipulator.h"
#include "cascade.h"
#include "Gyro.h"

CController *controllerClass;
DrivetrainClass *drivetrain;
manipulator *manipulatorClass;
Cascade *elevator;
//GyroClass *gyroClassOne;

class Robot : public frc::IterativeRobot {


    int switchSide;
	int scaleSide;  
	

public:
	void RobotInit()
	{
        manipulatorClass = new manipulator();
        controllerClass = new CController();
	    //gyroClassOne = new GyroClass;
	    elevator = new Cascade();
		m_chooser.AddDefault(kAutoNameDefault, kAutoNameDefault);
		m_chooser.AddObject(kAutoNameCustom, kAutoNameCustom);
		frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

    
		drivetrain = new DrivetrainClass();
		elevator->initElevator();
		drivetrain->linkMotors();
	    drivetrain->linkFollowers();
	    //gyroClassOne->resetYaw();
	    
        drivetrain->resetSensor(); // resets sensor pos
	}

	/*
	 * This autonomous (along with the chooser code above) shows how to
	 * select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString line to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional comparisons to
	 * the
	 * if-else structure below with additional strings. If using the
	 * SendableChooser make sure to add them to the chooser code above as
	 * well.
	 */
	void AutonomousInit() override {

       // gyroClassOne->resetYaw();
        
	/*	m_autoSelected = m_chooser.GetSelected();
		// m_autoSelected = SmartDashboard::GetString(
		// 		"Auto Selector", kAutoNameDefault);
		std::cout << "Auto selected: " << m_autoSelected << std::endl;*/

		// FMS AUTO
		std::string gameData;
		gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();

		if(gameData[0] == 'L')		// Our switch side is on the left
		{
			switchSide = 0;

			cout << "switch is on left" << endl;
			cout << "v9" << endl;

			//Put left auto code here
		}

		else 						// Our switch side is on the right
		{
			switchSide = 1;

			cout << "switch is on right" << endl;

			//Put right auto code here
		}
		
    	    if(gameData[1] == 'L')		// Our scale side is on the left
    		{
    			scaleSide = 0;
    
    			cout << "scale is on left" << endl;
    
    			//Put left auto code here
    		}
    
    		else if (gameData[1] == 'R')				// Our scale side is on the right
    		{
    		    scaleSide = 1;
    
    			cout << "scale is on right" << endl;
    
    			//Put right auto code here
    		}
    		
    		//drivetrain->goForwards(/*speed*/ 4, /*accel*/ 3, /*Feet*/ 2);
    		
    		
    		
    		
    		//drivetrain->turnLeft(4, 3, /* angle */ 90); 

	}

	void AutonomousPeriodic() 
    {
		/*if (m_autoSelected == kAutoNameCustom) {
			// Custom Auto goes here
		} else
		{    
			// Default Auto goes here
		}
	
    	// Throw error if not moving
    	
    	// TODO add timer
    	
    /*	if(gyroClassOne->checkMoving() == false)
    	{
            std::cout << "ERROR: NOT MOVING" << endl; 
        }*/
    	
    	//std::cout << "YAW: " << gyroClassOne->getYaw() << endl;
	}

	void TeleopInit()
	{
        elevator->initTeleopElevator();
        elevator->elevatorHeight(5);
	}

	void TeleopPeriodic()
	{
        //gyroClassOne->getYaw();
        controllerClass->Update();
        //elevator->controlElevator();
		drivetrain->Drive();
        manipulatorClass->manipulatorPower();
        elevator->manualElevator();
		
	}

	void TestPeriodic()
	{

	}

private:
	frc::LiveWindow& m_lw = *LiveWindow::GetInstance();
	frc::SendableChooser<std::string> m_chooser;
	const std::string kAutoNameDefault = "Default";
	const std::string kAutoNameCustom = "My Auto";
	std::string m_autoSelected;
};

START_ROBOT_CLASS(Robot)
