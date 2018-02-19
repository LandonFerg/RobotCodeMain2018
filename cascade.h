#ifndef CASCADE_H
#define CASCADE_H


#include <phoenix.h>
#include "CController.h"
using namespace std;
//#include <VictorSPX.h>

extern CController * controllerClass;

class Cascade
{
    private:
        
        
        TalonSRX * cascadeTalon; 
        VictorSPX * cascadeVictorOne;
        VictorSPX * cascadeVictorTwo;
        VictorSPX * cascadeVictorThree;
        double getTicks(double distanceInches);
       
        //double distanceInches;
        
	public:
        Cascade();
        void manualElevator();
        void initElevator();
        void initTeleopElevator();
        void elevatorHeight(double);
        
        void controlElevator();
    
};

#endif // CASCADE_H
