#include "urlParser.h" //include the declaration for this class
 
String urlHeader = "";
String fullHeader = "";
String paths[8];
int numPaths;
//String fullPathReq = "";
 
//<<constructor>> setup the LED, make pin 13 an OUTPUT
urlParser::urlParser(){
	urlHeader = "";
	fullHeader ="";
	//fullPathReq = "";
	numPaths =0;
	
	for(int i = 0; i<8; i++){
	
		paths[i] = "";
	
	}
}
 
//<<destructor>>
urlParser::~urlParser(){
	urlHeader = "";
	fullHeader ="";
	//fullPathReq = "";
	
	
	for(int i = 0; i<8; i++){
	
		paths[i] = "";
	
	}

}
 

 
//blink the LED in a period equal to paramterer -time.
String urlParser::printit(){
        return urlHeader;
}

void urlParser::setURLHeader(String initString){
        urlHeader = initString;
}

void urlParser::appendHeader(char newChar){
        fullHeader += newChar;
}

void urlParser::parseHeaders(){
	/*extracts full header string (fullHeader) into the urlHeader file
	*/
	
	String readString = "";
	char tempC;
	
	for (int i = 0; i< fullHeader.length(); i++){
		tempC = fullHeader[i];
		readString += tempC;
		
		if (tempC == '\n') {
          if(readString.indexOf("GET ")==0){

            urlHeader = readString;
            //Serial.println("-------about to parse IN LIBRARY------");
			//Serial.println("get Request is:");
			
            //Serial.println(urlHeader);
            
          
            //Serial.println("parsed get request is:");
			parseURLHeader();
			//Serial.println(fullPathReq);
			//Serial.println("-------Parsed in LIBRARY------");

          }   
          readString = "";
        }
		
		
		
		
		
		
		
	
	}
	//Serial.println(readString);
	

        
}

String urlParser::parseURLHeader(){
	/*extracts the url header string (urlHeader) into the path 
	*/



 // Serial.println(""); 
 String getString;
 getString = urlHeader;
 // Serial.println("begin parse function");
 
 int space1;
 int space2; 
 String temp = "";
 
 //Serial.println("getString = ");
 //Serial.println(getString);

 space1 = getString.indexOf("GET ");

 //Serial.print("Space1 = ");
 //Serial.println(space1);
 temp = getString.substring(space1 + 4,getString.length()); 
  //Serial.print("temp.1 = ");
  //Serial.println(temp);


 space2 = temp.indexOf(" ");

   //Serial.print("space2 = ");
  //Serial.println(space2);

 temp = temp.substring(0,space2); 

  //Serial.print("temp.2 = ");
  //Serial.println(temp);

 
 //Serial.println("end  parse function"); 
  //Serial.println(""); 
  
  
  
  //fullPathReq = temp;
  parsePaths(temp);
  
	return temp;
}


String urlParser::returnPath(int pathNum){

	return paths[pathNum];

}

void urlParser::parsePaths(String fullPathReq){
	
	
	char tempC;
	for (int i =0; i<fullPathReq.length(); i++){
		tempC = fullPathReq[i];
		switch(tempC) {
			case '/':
				
				numPaths++;
				break;
			default:
				
				paths[numPaths-1]+= tempC;
				break;
     
		}
	
	}
	
	//Serial.println(paths[0]);
	//Serial.println(paths[1]);
	//Serial.println(paths[2]);
	//Serial.println(paths[3]);
	//Serial.println(paths[4]);
	
	
	
}