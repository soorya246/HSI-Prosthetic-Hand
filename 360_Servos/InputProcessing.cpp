// Written by Anna Ledbetter, Apremeya Sudharsan, Soorya Nayarayan, Daniel Song.
// Last changes - 03/30/2025

#include <WiFi.h>
#include <ESP32Servo.h>
#include <list>
#include <WiFiUdp.h>
#define UDP_PORT = 4210
WiFiUDP UDP;
char packet[255];
char reply[] = "Packet Received"
// Define servo pins
static const int servoPin1 = 2;
static const int servoPin2 = 4;
static const int servoPin3 = 19;
static const int servoPin4 = 16;
static const int servoPin5 = 5;
int count1 = 0;
int count0 = 0;
std::list<int> my_list; 

// Servo objects
Servo servo1, servo2, servo3, servo4, servo5;
// Replace with your network credentials
const char* ssid     = "ESP32-Access-Point";
const char* password = "123456789";
// Set web server port number to 80
WiFiServer server(80);
// Variable to store the HTTP request
String header;
// Auxiliar variables to store the current output state
String output26State = "off";
String output27State = "off";
// Assign output variables to GPIO pins
const int output26 = 26;
const int output27 = 27;

void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(output26, OUTPUT);
  pinMode(output27, OUTPUT);
  // Set outputs to LOW
  digitalWrite(output26, LOW);
  digitalWrite(output27, LOW);
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  server.begin();
  UDP.begin(UDP_PORT);
  Serial.printl("Listening on UDP port ");
  serial.println(UDP_PORT)
}
void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients
  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            // turns the GPIOs on and off
            if (header.indexOf("GET /26/on") >= 0) {
              Serial.println("GPIO 26 on");
              output26State = "on";
              digitalWrite(output26, HIGH);
            } else if (header.indexOf("GET /26/off") >= 0) {
              Serial.println("GPIO 26 off");
              output26State = "off";
              digitalWrite(output26, LOW);
            } else if (header.indexOf("GET /27/on") >= 0) {
              Serial.println("GPIO 27 on");
              output27State = "on";
              digitalWrite(output27, HIGH);
            } else if (header.indexOf("GET /27/off") >= 0) {
              Serial.println("GPIO 27 off");
              output27State = "off";
              digitalWrite(output27, LOW);
            }
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");
            // Web Page Heading
            client.println("<body><h1>ESP32 Web Server</h1>");
            // Display current state, and ON/OFF buttons for GPIO 26
            client.println("<p>GPIO 26 - State " + output26State + "</p>");
            // If the output26State is off, it displays the ON button
            if (output26State=="off") {
              client.println("<p><a href=\"/26/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/26/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            // Display current state, and ON/OFF buttons for GPIO 27
            client.println("<p>GPIO 27 - State " + output27State + "</p>");
            // If the output27State is off, it displays the ON button
            if (output27State=="off") {
              client.println("<p><a href=\"/27/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/27/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("</body></html>");
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;

            UDP.begin(UDP_PORT);
            Serial.println("Listening on UDP port");
            Serial.println(UDP_PORT);
            
            while (client.connected()) {
              // if (client.available()) {
              //     char c = client.read();
              //     Serial.write(c);
              //     request += c;
              //     if (c == '\n') {
                    //   if (request.indexOf("GET /H") >= 0) {
                    //       Serial.println("Closing Hand...");    [ [0] [1] [0] ] -> [0,1,0,0,1]
                    
                    // Making the assumption that signals are 0 and 1 (No floats) 
                    // and that they are semi-continuous (not alternating like 0,1,0,1,0...)
                  while UDP.active(){
                        for (i = 0; i < 20; i++){
                            val = UDP.parsePacket(); // 

                            // We are getting a list (array) ([])
                            my_list.push_back([0]);
                            if (val[0] == 1) {
                                count1++;
                            }
                            else if (val[0] == 0){
                                count0++;
          
                    // FOR FUTURE REFERENCE //

                    // If user wants to send fast signals (open, close within seconds), then
                    // We probably need to use a window of some sort to keep track of the 
                    // Binary input being sent across different seconds.
                            }
                            }

                        if ((count1 == 13)){
                            Serialprint.ln("Closing Hand...")
                            moveServos(500, 1000, 20);
                            moveServos(1000, 2000, 20);
                            moveServos(2000, 2500, 20);
                            count1 = 0;
                            delay(2000);
                        }
                        
                        else if (count0 == 13){
                            Serial.println("Opening Hand...");
                            moveServos(2500, 2000, -20);
                            moveServos(2000, 1000, -20);
                            moveServos(1000, 500, -20);
                            count0 = 0;
                            delay(2000);
                        }
                        count1 = 0;
                        count0 = 0;
                        }
                    }

                    // for 
                    //   if () {

                    //       moveServos(500, 1000, 20);
                    //       moveServos(1000, 2000, 20);
                    //       moveServos(2000, 2500, 20);
                    //   }
                    //   else if (request.indexOf("GET /L") >= 0) {
                    //       Serial.println("Opening Hand...");
                    //       moveServos(2500, 2000, -20);
                    //       moveServos(2000, 1000, -20);
                    //       moveServos(1000, 500, -20);
                    //   }
                    //   // Send HTTP response
                    //   client.println("HTTP/1.1 200 OK");
                    //   client.println("Content-type:text/html");
                    //   client.println();
                    //   client.print("Click <a href=\"/H\">here</a> to close the hand.<br>");
                    //   client.print("Click <a href=\"/L\">here</a> to open the hand.<br>");
                    //   client.println();
                    //   break;
                  }
              }
          }

          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}