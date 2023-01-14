#include "physics.h"

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

physics::physics() {
	timer = 0;
	aRadians = 0;
	accelerationThrust = 0;
	ddxThrust = 0;
    ddyThrust = 0;
	ddx = 0;
	ddy = 0;
	v = 0;
	aDegrees = 0;
};

// Getters
double physics::getTimer() {
	return timer;
}

double physics::getRadians() {
	return aRadians;
}

double physics::getAccelerationThrust() {
	return accelerationThrust;
}

double physics::getDdxThrust() {
	return ddxThrust;
}

double physics::getDdyThrust() {
	return ddyThrust;
}

double physics::getDdx() {
	return ddx;
}

double physics::getDdy() {
	return ddy;
}

double physics::getV() {
	return v;
}

double physics::getDegrees() {
	return aDegrees;
}

// setters

void physics::setTimer(double t) {
	timer = t;
}

void physics::setRadians(double r) {
	aRadians = r;
}

void physics::setAccelerationThrust(double at) {
	accelerationThrust = at;
}

void physics::setDdxThrust(double dt) {
	ddxThrust = dt;
}

void physics::setDdyThrust(double dt) {
	ddyThrust = dt;
}

void physics::setDdx(double d) {
	ddx = d;
}

void physics::setDdy(double d) {
	ddy = d;
}

void physics::setV(double vel) {
	v = vel;
}

void physics::setDegrees(double d) {
	aDegrees = d;
}


// methods

double physics::computeDistance(double s, double v, double a, double t) {
	return s + v * t + 0.5 * a * t * t;
}

double physics::computeAcceleration(double f, double m) {
    return f / m;
}
double physics::computeVelocity(double v, double a, double t) {
    return v + a * t;
}
double physics::computeVerticalComponent(double a, double total) {
    return total * cos(a);
}
double physics::computeHorizontalComponent(double a, double total) {
    return total * sin(a);
}
double physics::computeTotalComponent(double x, double y) {
    return sqrt((x * x) + (y * y));
}
double physics::radiansFromDegrees(double d) {
    double pi = 2 * asin(1.0);
    return d * 2 * pi / 360;
}

void physics::variableOutput(double timer, double x, double y, double dx, double dy, double v, double aDegrees) {
	cout << timer << "s - x,y:(" << x << ", " << y << ")m  dx,dy:(" << dx << ", " << dy << ")m/s  speed:" << v << "m/s  angle:" << aDegrees << "deg" << endl;
}

double physics::getAngle() {
	cout << "What is the angle of the LM where 0 is up (degrees)? ";
	cin >> aDegrees;
	setDegrees(aDegrees);
	return aDegrees;
}