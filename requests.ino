#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>

// Tus datos WiFi
const char* ssid = "caliope";
const char* password = "sinlugar";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  Serial.print("Conectando al WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n✅ ¡Conectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  if (WiFi.status() == WL_CONNECTED) {
    WiFiClientSecure client;
    client.setInsecure();  

    HTTPClient https;
    https.begin(client, "https://panelistas.onrender.com/search?code=tau");

    int httpCode = https.GET();

    if (httpCode > 0) {
      Serial.printf("Código de respuesta: %d\n", httpCode);
      String payload = https.getString();
      Serial.println("Respuesta:");
      Serial.println(payload);
    } else {
      Serial.printf("Error en GET: %s\n", https.errorToString(httpCode).c_str());
    }

    https.end();
  }
}

void loop() {
}
