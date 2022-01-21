#ifndef SDDS_PHONE_H
#define SDDS_PHONE_H

namespace sdds {
	// runs the phone directory appication
	void phoneDir(const char* programTitle, const char* fileName);
	// takes input from user and returns a character array
	char* input_function();
	// welcome function
	void welcome(char* title); 
}

#endif