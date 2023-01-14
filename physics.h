class physics {
private:
    double timer;
    double aRadians;            // Angle in radians
    double accelerationThrust;  // Acceleration due to thrust 
    double ddxThrust;           // Horizontal acceleration due to thrust
    double ddyThrust;           // Vertical acceleration due to thrust
    double ddx;                 // Total horizontal acceleration
    double ddy;                 // Total vertical acceleration
	double v;                   // Total velocity
	double aDegrees;            // User input on the angle of the LM
    
public:
    // constructor
    physics();
    
    
	// getters
	double getTimer();
	double getRadians();
	double getAccelerationThrust();
	double getDdxThrust();
	double getDdyThrust();
	double getDdx();
	double getDdy();
	double getV();
	double getDegrees();
	
	// setters
	void setTimer(double newTimer);
	void setRadians(double r);
	void setAccelerationThrust(double at);
	void setDdxThrust(double dt);
	void setDdyThrust(double dt);
	void setDdx(double d);
	void setDdy(double d);
	void setV(double vel);
	void setDegrees(double d);
	
	// methods
    
	// Computes the distance traveled
    double computeDistance(double s, double v, double a, double t);

	// Computes the acceleration
    double computeAcceleration(double f, double m);

	// Computes the velocity
    double computeVelocity(double v, double a, double t);

	// Computes the vertical component of the acceleration
    double computeVerticalComponent(double a, double total);

	// Computes the horizontal component of the acceleration
    double computeHorizontalComponent(double a, double total);

	// Computes the total velocity
    double computeTotalComponent(double x, double y);

	// Converts degrees to radians
    double radiansFromDegrees(double d);
    
	// Shows the current status of the LM
	void variableOutput(double timer, double x, double y, double dx, double dy, double v, double aDegrees);
    
	// Receive user input for the angle of the LM
	double getAngle();
};

