// apolloLander.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "physics.h" // Header file for physics calculations
#include <iostream>  // for CIN and COUT
#include <cmath>     // for MATH functions
using namespace std;

#define WEIGHT   15103.000   // Weight in KG
#define GRAVITY     -1.625   // Vertical acceleration due to gravity, in m/s^2
#define THRUST   45000.000   // Thrust of main engine, in Newtons (kg m/s^2)

/**************************************************
 * PROMPT
 * A generic function to prompt the user for a double
 * INPUT
 *      message : the message to display to the user
 * OUTPUT
 *      response : the user's response
 ***************************************************/
double prompt(string message) {
    double response;
    cout << message;
    cin >> response;
    return response;
}


/****************************************************************
 * MAIN
 * Prompt for input, compute new position, and display output
 ****************************************************************/
int main()
{
	// create an instance of the physics class
	physics p;
    
    // call the variables from the physics class
    double timer = p.getTimer();
    double aRadians = p.getRadians();
    double accelerationThrust = p.getAccelerationThrust();
    double ddxThrust = p.getDdxThrust();
    double ddyThrust = p.getDdyThrust();
    double ddx = p.getDdx();
    double ddy = p.getDdy();
    double v = p.getV();
    double aDegrees = p.getDegrees();

    // Prompt for input and variables to be computed
    double dx = prompt("What is your horizontal velocity (m/s)? ");
    double dy = prompt("What is your vertical velocity (m/s)? ");
    double y = prompt("What is your altitude (m)? ");
    aDegrees = p.getAngle();
    double x = 0;               // horizontal position, start at 0
    double t = 1;               // one second intervals

    // while keepGoing is true, keep going
    bool keepGoing = true;
    while (keepGoing) {
        cout << "For the next 5 seconds with the main engine on, the position of the lander is:\n";

        // Go through the simulator for 5 seconds
        for (int i = 1; i <= 5; i++) {
            
            // update time
			timer += t;
            
            // Compute the angle in radians
			aRadians = p.radiansFromDegrees(aDegrees);

            // Compute the acceleration due to thrust
			accelerationThrust = p.computeAcceleration(THRUST, WEIGHT);

            // Compute the horizontal and vertical components of the acceleration
			ddxThrust = p.computeHorizontalComponent(aRadians, accelerationThrust);
			ddyThrust = p.computeVerticalComponent(aRadians, accelerationThrust);

            // Compute the total acceleration
			ddx = ddxThrust;
			ddy = ddyThrust + GRAVITY;

            // Compute the new velocity
			dx = p.computeVelocity(dx, ddx, t);
			dy = p.computeVelocity(dy, ddy, t);

            // Compute the new position
			x = p.computeDistance(x, dx, ddx, t);
			y = p.computeDistance(y, dy, ddy, t);

            // Compute the total velocity
			v = p.computeTotalComponent(dx, dy);

            // Output
            cout.setf(ios::fixed | ios::showpoint);
            cout.precision(2);

            //  New output with all the variables
			p.variableOutput(timer, x, y, dx, dy, v, aDegrees);

            
            // if the altitude is 0 and the angle is 0 and the velocity is less than 4m/s
            if (y <= 0 && v < 4 && aDegrees >= -5 && aDegrees <= 5) {
                cout << "The lander has landed successfully!\n";

                // Press ENTER to exit the program
                cout << "Press ENTER to exit the program.";
                cin.ignore();
                cin.get();
                
                keepGoing = false;
                break;
            }
            else if (y <= 0 && v >= 4) {
                cout << "The lander has crashed!\n";
                
                // Press ENTER to exit the program
                cout << "Press ENTER to exit the program.";
                cin.ignore();
                cin.get();
                
                keepGoing = false;
                break;
            }
            else if (y <= 0 && (aDegrees < -5 || aDegrees > 5)) {
                cout << "The lander has crashed!\n";
                
                // Press ENTER to exit the program
				cout << "Press ENTER to exit the program.";
				cin.ignore();
				cin.get();
                
                keepGoing = false;
                break;
            }
        }

        if (keepGoing == true) {
            // Asks for the angle of the LM after 5 seconds
            aDegrees = prompt("What is the angle of the LM where 0 is up (degrees)? ");
            // If the user enters -360, the program ends
            if (aDegrees == -360) {
                
                // Press ENTER to exit the program
                cout << "Press ENTER to exit the program.";
                cin.ignore();
                cin.get();

                keepGoing = false;
                break;
            }
        }
    }

    return 0;
}