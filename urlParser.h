#ifndef urlParser_H
#define urlParser_H
 
#include <Arduino.h> //It is very important to remember this! note that if you are using Arduino 1.0 IDE, change "WProgram.h" to "Arduino.h"
 
class urlParser {
public:
        urlParser();
        ~urlParser();
		void setURLHeader(String initString);
		void appendHeader(char newChar);
		void parseHeaders();
        String printit();
		String parseURLHeader();
		String returnPath(int pathNum);
		void parsePaths(String fullPathReq);
};
 
#endif