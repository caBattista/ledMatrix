#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
//#include <WiFiClient.h> //for softwareAP
#include <WebSocketsServer.h>
#include <ESP8266WebServer.h>
#include <Hash.h>//belongs to esp8266 library (not sure if necessary)
#include <EEPROM.h>
#include "web.cpp"

#define USE_SERIAL Serial //could also just have used Serial object (was in example)

//LEDs

#include <NeoPixelBus.h> //right library for esp8266
const uint16_t PixelCount = 300; //pixel count of matrix
NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> pixels(PixelCount); //pin3 on esp8266 (RX on nodeMCU)

const uint16_t m[12][25] = {
     {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24},
     {49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25},
     {50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74},
     {99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75},
     {100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124},
     {149,148,147,146,145,144,143,142,141,140,139,138,137,136,135,134,133,132,131,130,129,128,127,126,125},
     {150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174},
     {199,198,197,196,195,194,193,192,191,190,189,188,187,186,185,184,183,182,181,180,179,178,177,176,175},
     {200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224},
     {249,248,247,246,245,244,243,242,241,240,239,238,237,236,235,234,233,232,231,230,229,228,227,226,225},
     {250,251,252,253,254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,270,271,272,273,274},
     {299,298,297,296,295,294,293,292,291,290,289,288,287,286,285,284,283,282,281,280,279,278,277,276,275}
};

//Wifi and Servers

ESP8266WiFiMulti WiFiMulti;
ESP8266WebServer server = ESP8266WebServer(80);
WebSocketsServer webSocket = WebSocketsServer(85);//WebSocketServer available on specified port (85)

//these global values are necessary to get data from the webSocketEvent function
uint8_t pos = 0; //position data from first websocket connection
uint8_t pos1 = 0; //position data from second websocket connection
uint8_t wsFunction[5] = {0};//stores which websocket is used for what task

uint8_t select = 255; //task selector (used to select whicht task is currently running)
uint8_t pongInterval = 150; //used to set the speed of the pong game (millis per screen refresh)

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t lenght) {

    switch(type) {
        case WStype_DISCONNECTED:{
          //USE_SERIAL.printf("[%u] Disconnected!\n", num);
          wsFunction[num] = 0;
          }
          break;
        case WStype_CONNECTED: {
          IPAddress ip = webSocket.remoteIP(num);
          //USE_SERIAL.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);        
          }
          break;
        case WStype_TEXT: {
          //USE_SERIAL.printf("[%u] get Text: %s\n", num, payload);
          String str = (const char *) & payload[0];
          char chars[32];
          strcpy(chars, str.c_str());
          if(str == "view" && num < 5){
            wsFunction[num] = 2;
            }
          else if(str == "pong" && num < 5){
            wsFunction[num] = 1;
            }
          else if(str == "set" && num < 5){
            wsFunction[num] = 3;
            select = 3;
            }
          else if(chars[0] == '#' && num < 5 && wsFunction[num] == 3){
            addRouter(str);
            }
          else{ 
            //get number of players
            uint8_t count = 0;
            uint8_t players[2] = {0}; 
            for(int i=0; i<5; i++){
              if(wsFunction[i]==1 && count < 2){
                players[count] = i;
                count++;
                }
              }
            // decode data packet (string to long int, pointer to payload array, could use smaller datatype)
            uint32_t data = (uint32_t) strtol((const char *) & payload[0], NULL, 16);

            //limmit the data so the map function doesn't rollover
            if(data>=150){
              data=150;
              }
            else if(data<=104){
              data=104;
              }
            //map the data to values that the game can use
            if(num==players[0]){
              pos = map(data,104,150,0,11);//noninverted                 
              }
            else if(num==players[1]){
              pos1 = map(data,104,150,11,0);//inverted
              }
            }
          }
          break;
    }
}


void setup() {

    USE_SERIAL.begin(74880);
    delay(250);//Serial bug if no delay
/*  USE_SERIAL.setDebugOutput(true);
    USE_SERIAL.println();
    USE_SERIAL.println("Trying to connect to Router");
 */   
    EEPROM.begin(32);
    String ssid, pass;
    uint8_t j = 0;
    for(int i = 1; i < 32; i++){
      if(EEPROM.read(i) == '#'){
        j++;
        }
      else{
        if(j==0){
          ssid += (const char) EEPROM.read(i); 
          }
        else{
          pass += (const char) EEPROM.read(i);  
          }
        }  
      }
    //USE_SERIAL.println("AP from EEPROM " +ssid + " " + pass);  
    const char* ssid1 = ssid.c_str();
    const char* pass1 = pass.c_str();
    WiFiMulti.addAP(ssid1, pass1);
    WiFiMulti.addAP("TP-LINK_8B1E", "94077278");
    WiFiMulti.addAP("WLAN-B52287", "4294206527437190");
    WiFiMulti.addAP("FRITZ!Box 7490", "85779328566871614986");
    WiFi.mode(WIFI_AP_STA);
    WiFi.softAP("LedMatrix", "hier1234");
    IPAddress myIP = WiFi.softAPIP();

    //try to connect to local infrastructure for 5 seconds
    uint8_t i = 0;
    while((WiFiMulti.run() != WL_CONNECTED) && (i<5)) {
        delay(1000);
        //USE_SERIAL.println(i);
        i++;
    }
    
    if(i>4){
      WiFi.mode(WIFI_AP);
      USE_SERIAL.println("Could not connect to Router");
      }
    USE_SERIAL.print("WiFi.softAPIP: ");
    USE_SERIAL.println(WiFi.softAPIP());
    USE_SERIAL.print("WiFi.SSID: ");
    USE_SERIAL.println(WiFi.SSID());
    USE_SERIAL.print("WiFi.localIP: ");
    USE_SERIAL.println(WiFi.localIP());
    USE_SERIAL.print("WiFi.gatewayIP: ");
    USE_SERIAL.println(WiFi.gatewayIP());
    USE_SERIAL.print("WiFi.subnetMask: ");
    USE_SERIAL.println(WiFi.subnetMask());

    // start webSocket server
    webSocket.begin();
    webSocket.onEvent(webSocketEvent);

    // setup http server

    server.on("/", []() {
      server.send(200, "text/html", _index);   
      });
    
    server.on("/pong", []() {
      server.send(200, "text/html", _pong);
      pixels.ClearTo(RgbColor(0, 0, 0));
      select = 0;     
      });

    server.on ( "/xmas", []() {
      server.send(200, "text/html", _index);
      pixels.ClearTo(RgbColor(0, 0, 0));
      select = 1;
      });

    server.on ( "/ran", []() {
      server.send(200, "text/html", _index);
      pixels.ClearTo(RgbColor(0, 0, 0));
      select = 2;
      });

    server.on ( "/view", []() {
      server.send(200, "text/html", _view);
      });
      
    server.on ( "/settings", []() {
      server.send(200, "text/html", _settings);
      });

    server.begin();

    //start neopixel library
    pixels.Begin();

    //show ip on matrix (will show ip assigned by router when in infrastructure mode)
    String ip;
    
    if(i>4){
      ip = WiFi.softAPIP().toString();
      }
    else{
      ip = WiFi.localIP().toString();
      }
    
    char ipc [13];
    strcpy(ipc, ip.c_str());
    
    for(int i=0;i<3;i++){
        showDigit(ipc[i]-'0',i*4,0,0);
      }
    for(int i=4;i<7;i++){
        showDigit(ipc[i]-'0',((i-1)*4)+2,0,0);
      }
        showDigit(ipc[8]-'0',0,6,0);
    for(int i=10;i<13;i++){
        showDigit(ipc[i]-'0',((i-9)*4)+2,6,0);
      }
    
    pixels.Show();
}

void loop() {
    server.handleClient();
    webSocket.loop();

    if(select == 0){//pong task
      static uint32_t A = 0;//used for multitasking (Kongruenzaritmetrik)
      static uint32_t B = 0;
  
      if(millis()-A >= pongInterval){//main pong task
        A = millis();
        pong(pos,pos1);
        }
      
      if(millis()-B >= 30){//pongbats task
        B = millis();
        pongBats(pos,pos1,(0,0,127));
        }
      }

     if(select == 1){
      select=255;
      xmas();
      }
      
      if(select == 2){
      static uint32_t D = 0;
      if(millis()-D >= 100){
        D = millis();
        ran();
        }
      }
      
      static uint32_t E = 0;
      if(millis()-E >= 30){
        E = millis();
        view();
        }
        
      if(select == 3){
        select=4;
        set();
      }
}

void addRouter(String str){
  char chars[32];
  strcpy(chars, str.c_str());

  for(int i=0; i<32; i++){
    EEPROM.write(i, chars[i]);
    }
  EEPROM.commit();
}

void set(){
  //sends detected wifi networks information to client
  uint8_t n = 0;
  String networks;
  n = WiFi.scanNetworks();
  for (int i = 0; i < n; i++){
    String networks =  (String) i + "#" + WiFi.SSID(i) 
                          + "#" + WiFi.RSSI(i)
                          + "#" + WiFi.channel(i)
                          + "#" + WiFi.BSSIDstr(i)   
                          + "#" + encryptionName(WiFi.encryptionType(i))
                          + "#" + WiFi.isHidden(i);
    uint8_t sc = 0;
    for(int i=0; i<5; i++){
      if(wsFunction[i]==3){
        sc++;
        webSocket.sendTXT(i,networks);
        } 
      }
    }
    WiFi.scanDelete();
    for(int j=0; j<5; j++){
      if(wsFunction[j]==3){
        webSocket.sendTXT(j,"*");
        } 
      }

    String curNet = WiFi.SSID() 
            + "#" + WiFi.softAPIP().toString()
            + "#" + WiFi.localIP().toString()
            + "#" + WiFi.gatewayIP().toString()  
            + "#" + WiFi.subnetMask().toString();
    USE_SERIAL.print(curNet);
    for(int i=0; i<5; i++){
      if(wsFunction[i]==3){
        webSocket.sendTXT(i,curNet);
        } 
      }
}

//could be handled by client 
String encryptionName(uint8_t type) {
// read the encryption type and return the name
  String str;
  
  switch (type) {
    case 2:{
        str = "WPA (TKIP)";
        break;
      }
    case 4:{
        str = ("WPA2 (CCMP)");
        break;
      }
    case 5:{
        str = ("WEP");
        break;
      }
    case 7:{
        str = ("Open Network");
        break;
      }
    case 8:{
        str = ("Auto");
        break;
      }
  }
  return str;
}

void view(){
  //sends the pixels of the matrix back to client
  uint8_t v = 0;
    for(int i=0; i<5; i++){
      if(wsFunction[i]==2){
        v++;
        }
      }
    if(v==0){
      return;
      }
  String frame;
  for(int i=0; i<300; i++){
      HtmlColor c = pixels.GetPixelColor(i);//takes RgbColor object from pixels and stores it in an html color
      char chars[7] = {0};
      c.ToNumericalString(chars, 9);
      frame += chars;
    }
    uint8_t vc = 0;
    for(int i=0; i<5; i++){
      if(wsFunction[i]==2 && vc < 3){
        vc++;
        webSocket.sendTXT(i,frame);
        }
      }
  }
  
void ran(){//shows randmom collors on matrix
    for(int i=0; i<12; i++){
      for(int j=0; j<25; j++){
        pixels.SetPixelColor(m[i][j], RgbColor(random(0,1270), random(0,1270), random(0,1270)));
        }  
      }
    pixels.Show();
  }

void xmas(){//shows xmas tree on martix
  const uint8_t tree[12][25] = {
        {0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,1,1,1,0,1,1,1,0,1,1,0,0,1,0,0,0,0,0,0,0,0},
        {1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,0,1,0,0,0},
        {1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0},
        {1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,0,0,0,0,0},
        {1,0,0,0,1,1,1,0,1,1,1,0,1,1,0,0,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        };

      //reads 2D array and sets pixel values
      for(int i=0; i<12; i++){
        for(int j=0; j<25; j++){
          pixels.SetPixelColor(m[i][j], RgbColor(0, tree[i][j]*127, 0));
          }  
        }
      pixels.Show();
  }

void pong(int baPos1, int bbPos1){
  RgbColor field (31, 31, 31);
  RgbColor On (127, 0, 0);
  RgbColor Off (0, 0, 0);
  static uint8_t paScore = 0;
  static uint8_t pbScore = 0;
  static uint8_t baPos = 0;
  static uint8_t bbPos = 0;
  static uint8_t baPosOld = 0;
  static uint8_t bbPosOld = 0;
  static uint8_t x = 3;//x ball position
  static uint8_t y = 3;//y ball position
  static int8_t xr = 1;//x speed 
  static int8_t yr = 1;//y speed
  static uint8_t showNrTime = 5;//time the score is displayed
  static int t = 0;//time counter for the score display
  static uint8_t sNr = 0;//is 1 when numbers should be displayed
  
  //get number of players
  uint8_t players = 0; 
  for(int i=0; i<5; i++){
    if(wsFunction[i]==1){
      players++;
      }
    }

  //clear screen
  for(int i=1; i<24; i++){
    for(int j=0; j<12; j++){
      pixels.SetPixelColor(m[j][i], Off);
    }
  }

  //show Numbers
  if(sNr==1){
    t=showNrTime;
    sNr=0;
    }
  if(t>0){
    showNumber(paScore,16,2,3);
    showNumber(pbScore,4,2,2);
    t--;
  }

  //Computerbats

  if(players==0){//if no player is present the computerbats are drawn
    pixels.SetPixelColor(m[baPosOld][0], Off);
    pixels.SetPixelColor(m[(baPosOld+1)][0], Off);
    baPosOld=baPos;
    
    pixels.SetPixelColor(m[baPos][0], On);
    pixels.SetPixelColor(m[(baPos+1)][0], On);
    baPos=y;
    

    pixels.SetPixelColor(m[bbPosOld][24], Off);
    pixels.SetPixelColor(m[(bbPosOld+1)][24], Off);
    bbPosOld=bbPos;
    
    pixels.SetPixelColor(m[bbPos][24], On);
    pixels.SetPixelColor(m[(bbPos+1)][24], On);
    bbPos=y;
    

    paScore=0;
    pbScore=0;
    pongInterval=150;
    }
    
  if(players==1){//if one player is conected the the computerbat ba is removed

    pixels.SetPixelColor(m[bbPosOld][24], Off);
    pixels.SetPixelColor(m[(bbPosOld+1)][24], Off);
    bbPosOld=bbPos;

    baPos=baPos1;
    
    pixels.SetPixelColor(m[bbPos][24], On);
    pixels.SetPixelColor(m[(bbPos+1)][24], On);
    bbPos=y;   
    }
    
  if(players==2){//if two websockets are conected the the computerbat bb is removed
    baPos=baPos1;
    bbPos=bbPos1;   
    }

  //Playing field
  for(int i=0; i<12; i++){
    pixels.SetPixelColor(m[i][12], field);
  }
  
  //Ball on
  pixels.SetPixelColor(m[y][x], On);

  pixels.Show();

  if(x>24){//player a misses
    x=1;
    y=baPos;
    xr=-xr;
    pbScore++;
    sNr=1;
    pongInterval=150;
    }

  if(x<0){//player b misses
    x=23;
    y=bbPos;
    xr=-xr; 
    paScore++;
    sNr=1;
    pongInterval=150;
    }
    
  if(((baPos == y) || (baPos+1 == y)) && (x<2)){//player a hits the ball
    xr=-xr;
    if(pongInterval>30){
      pongInterval-=5;
    }
    }

  if(((bbPos == y) || (bbPos+1 == y)) && (x>22)){//playerb hits the ball
    xr=-xr;
    if(pongInterval>30){
      pongInterval-=5;
    }
    }
  
  if(y>=11){//ball hits lower wall
    yr=-yr;
    }
    
  if(y<=0){//ball hits upper wall
    yr=-yr;
    }
    
  x=x+xr;//xpos is incremented by xr
  y=y+yr;//ypos is incremented by yr
  
}

void pongBats(int aPos, int bPos, RgbColor batColor){
  
  RgbColor batOn = batColor;
  RgbColor batOff (0, 0, 0);

    //get number of players
  uint8_t players = 0; 
  for(int i=0; i<5; i++){
    if(wsFunction[i]==1){
      players++;
      }
    }

  if(players>=1){

    //clear space around the bat
    for(int i = 0; i<12; i++){ 
      if(aPos != i || aPos + 1 !=i){
        pixels.SetPixelColor(m[i][0], batOff);
      }
    }
    
    if(aPos<0){
      aPos=0;
    }
    else if(aPos>=11){
      aPos=10;
    }

    pixels.SetPixelColor(m[aPos][0], batOn);
    pixels.SetPixelColor(m[(aPos+1)][0], batOn);
    
  }

  if(players>=2){
    
    //clear space around the bat
    for(int i = 0; i<12; i++){ 
      if(bPos != i || bPos + 1 !=i){
        pixels.SetPixelColor(m[i][24], batOff);
      }
    }

   if(bPos<0){
      bPos=0;
      }
    else if(bPos>=11){
      bPos=10;
      }
    
    pixels.SetPixelColor(m[bPos][24], batOn);
    pixels.SetPixelColor(m[(bPos+1)][24], batOn);
  }
  
  if(players!=0){
    pixels.Show();
  }
  
}

void showNumber(int num, uint8_t x, uint8_t y, uint8_t rot){
  int number = num;
  int i=0;   
  do {
    int digit = number % 10;
    number /= 10;
    i++; 
    } while (number > 1);

  if(rot==1||rot==3){
    i=0;
      }

  do {
    int digit = num % 10;
    num /= 10;
    if(rot==0||rot==1){
     showDigit(digit,x+i*4,y,rot); 
      }
    else{
     showDigit(digit,x,y+i*4,rot);
      }
    if(rot==1||rot==3){
      i++;
      }
    else{
      i--;
      }
    } while (num > 0);

}
  
void showDigit(uint8_t num, uint8_t x, uint8_t y, uint8_t rot){//rotation 1: normal, 2: upside down 3: turned 90°, 4 turned 90° upside down 
                            //one uint16_t represents one number on a 3x5 matrix the last bit is unused
                            //0       1       2       3       4       5       6       7       8       9
const uint16_t numbers[10] = {0x7B6F, 0x2492, 0x73E7, 0x73CF, 0x5BC9, 0x79CF, 0x79EF, 0x7249, 0x7BEF, 0x7BCF };

    uint16_t k = 14;

    if(rot==3){
      for(int i = 0; i<5; i++){
        for(int j = 2; j>-1; j--){
          uint16_t o = ((numbers[num] >> k) & 0x0001);//shift num by k and then and it with 0x0001
          pixels.SetPixelColor(m[j+y][i+x], RgbColor (127*o,0,0));
          k--;  
        }
      }
    }
     else if(rot==2){
      for(int i = 4; i>-1; i--){
        for(int j = 0; j<3; j++){
          uint16_t o = ((numbers[num] >> k) & 0x0001);//shift num by k and then and it with 0x0001
          pixels.SetPixelColor(m[j+y][i+x], RgbColor (127*o,0,0));
          k--;         
        }
      }
    }
    else if(rot==1){
      for(int i = 4; i>-1; i--){
        for(int j = 2; j>-1; j--){
          uint16_t o = ((numbers[num] >> k) & 0x0001);//shift num by k and then and it with 0x0001
          pixels.SetPixelColor(m[i+y][j+x], RgbColor (127*o,0,0));
          k--;      
        }
      }
    }
    else{
      for(int i = 0; i<5; i++){
        for(int j = 0; j<3; j++){
          uint16_t o = ((numbers[num] >> k) & 0x0001);//shift num by k and then and it with 0x0001
          pixels.SetPixelColor(m[i+y][j+x], RgbColor (127*o,0,0));
          k--;      
        }
      }
    }
 }
