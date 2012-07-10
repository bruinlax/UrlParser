This is a library to assist a basic arduino restful interface.

the basic use of this is to add the input stream of a GET request, and get out the paths in an array.

eg a client creates a GET request of

GET /level1/level2/level3/level4 HTTP/1.1
Host: 192.168.0.133
Connection: keep-alive
Cache-Control: max-age=0
User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/536.11 (KHTML, like Gecko) Chrome/20.0.1132.47 Safari/536.11
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
Accept-Encoding: gzip,deflate,sdch
Accept-Language: en-US,en;q=0.8
Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.3

will return an array with "level1", "level2", "level3", "level4". . . (up to 8 levels)



SAMPLE usage:
using algorithm from:
http://arduino.cc/en/Tutorial/WebServer
for the ethernet client reading.


EthernetClient client = server.available();

if (client) {

	urlParser objRequest = urlParser();
    
    boolean currentLineIsBlank = true;
    while (client.connected()) {
		if (client.available()) {
			char c = client.read();
			objRequest.appendHeader(c);

			if (c == '\n' && currentLineIsBlank) {
				// end of Request
			  



				if(objRequest.returnPath(0).equalsIgnoreCase("level1")){
				
				// do Stuff based on the path
				}

			// send a standard http response header
			client.println("HTTP/1.1 200 OK");
			}
			if (c == '\n') {
			  // you're starting a new line
			  currentLineIsBlank = true;
			} 
			else if (c != '\r') {
			  // you've gotten a character on the current line
			  currentLineIsBlank = false;
			}
		}
	}
	delay(1);
    // close the connection:
    client.stop();
}	
