namespace constants {
	constexpr double gravity{ 9.8 }; // has internal linkage only accessible to constants.cpp
}

double getGravity() { // has external linkage, can be accessed by other files
	return constants::gravity;
}

double instantVelocity(int time, double gravity) {
	return time * gravity;
}




//Global const variables have internal linkage by default, gravity doesn’t need to be static.