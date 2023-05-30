#include <WiFi.h>
#include <WiFiUdp.h>
#include <string.h>

const char ssid[] = "Shuyuan's Pixel 6a";
const char password[] = "',.pyfgcrl/=\\";
const IPAddress receiver_ip(192, 168, 126, 83);
const unsigned int receiver_port = 12345;

WiFiUDP udp;
uint8_t buffer[1024];

void setup()
{
    Serial.begin(115200);
    while (!Serial) { ; }
    
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.print("Connecting to AP ");
    Serial.print(ssid);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println(" connected.");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    memset(buffer, 'U', sizeof(buffer) * sizeof(buffer[0]));
    buffer[sizeof(buffer) - 1] = '\0';
}

void loop()
{
    udp.beginPacket(receiver_ip, receiver_port);
    udp.write(buffer, sizeof(buffer));
    udp.endPacket();
    delay(2);
}
