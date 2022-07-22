#include "helper.h"

WiFiClient httpClient;
HTTPClient http;
 
String sendHttp(measurements voltage, measurements current) {
    // Creates the HTTP header
    http.begin(httpClient, "http://dmdc-stagging.herokuapp.com/chart_data/");
    http.addHeader("Content-Type", "application/json");

    // Joins the values to a JavaScript Object string
    String jsonVoltage = "voltage\":{\"med\":" + String(voltage.med, 2) + ",\"max\":" + String(voltage.max, 2) + ",\"min\":" + String(voltage.min, 2) + "}";
    String jsonCurrent = "current\":{\"med\":" + String(current.med, 2) + ",\"max\":" + String(current.max, 2) + ",\"min\":" + String(current.min, 2) + "}";
    
    String body = "{" + jsonVoltage + "," + jsonCurrent + "}";

    int httpCode = http.POST(body); // Request a POST into the server
    String payload = http.getString(); // Get the JSON payload from the server

    http.end();
    return payload; // Return the JSON payload and finish the communication
}