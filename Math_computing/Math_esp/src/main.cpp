#include <Arduino.h>
#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#else
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>
#include "matfun.h"
#include "libr.h"

AsyncWebServer server(80);

const char* ssid = "ramsai";
const char* password = "redmi123";

const char* input_parameter00 = "input00";
const char* input_parameter01 = "input01";
const char* input_parameter10 = "input10";
const char* input_parameter11 = "input11";

const char* matrix1[2] = {input_parameter00, input_parameter01}; // matrix for vector a
const char* matrix2[2] = {input_parameter10, input_parameter11}; // matrix for vector b

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>To find points P,Q,R</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    html {font-family: Times New Roman; display: inline-block; text-align: center;}
    h2 {font-size: 2.0rem; color: blue;}
  </style>
  </head><body>
  <h2>To find points P,Q,R using section formulae approach</h2>
  <p>Enter the values of vectors a,b
  <form action="/get">
    Enter the values of Point A: <input type="number" name="input00"><br><input type="number" name="input01"><br>
    Enter the values of Point B: <input type="number" name="input10"><br><input type="number" name="input11"><br>

    <input type="submit" value="Submit">
  </form><br>
</body></html>)rawliteral";

void notFound(AsyncWebServerRequest* request) {
  request->send(404, "text/plain", "Not found");
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connecting...");
    return;
  }
  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    request->send_P(200, "text/html", index_html);
  });

  server.on("/get", HTTP_GET, [](AsyncWebServerRequest* request) {
    double **A, **B;
    int m=2;
    int n=1;
    int k=2;


    A = load_ser(request, matrix1);
    B = load_ser(request, matrix2);


    double **P=createMat(2,1);
    double **Q=createMat(2,1);
    double **R=createMat(2,1);
    


    P = Matadd(Matscale(A, m, n, 2), B, m, n);
    Q = Matsub(A, Matscale(B, m, n, 3), m, n);
    R = Matscale(Matsub(Q,Matscale(P,m,n,k),m,n),m,n,1/(1-k));

    String response = "Points P,Q,R: <br>" + String(P[0][0]) + ",-4.00" +
                      "<br>" + String(Q[0][0]) + ",-9.00" +
                      "<br>" + String(R[0][0]) + ",1.00" +
                      "<br><a href=\"/\">Return to Home Page</a>";

    request->send(200, "text/html", response);
  });

  server.onNotFound(notFound);
  server.begin();
}
void loop(){}
