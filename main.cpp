
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2         // DS18B20 data pin
#define HEATER_PIN 8           // Simulated heater (LED)

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

enum HeaterState {
  IDLE,
  HEATING,
  STABILIZING,
  TARGET_REACHED,
  OVERHEAT
};

HeaterState currentState = IDLE;
float currentTemp = 0;

void setup() {
  Serial.begin(9600);
  sensors.begin();
  pinMode(HEATER_PIN, OUTPUT);
  digitalWrite(HEATER_PIN, LOW);
}

void loop() {
  sensors.requestTemperatures();
  currentTemp = sensors.getTempCByIndex(0);

  Serial.print("Temperature: ");
  Serial.print(currentTemp);
  Serial.println(" °C");

  if (currentTemp < 20) {
    currentState = HEATING;
  } else if (currentTemp >= 20 && currentTemp < 24) {
    currentState = STABILIZING;
  } else if (currentTemp >= 24 && currentTemp < 30) {
    currentState = TARGET_REACHED;
  } else if (currentTemp >= 80) {
    currentState = OVERHEAT;
  }

  switch (currentState) {
    case HEATING:
      digitalWrite(HEATER_PIN, HIGH);
      Serial.println("State: HEATING - Heater ON");
      break;
    case STABILIZING:
      digitalWrite(HEATER_PIN, HIGH);
      Serial.println("State: STABILIZING - Heater ON");
      break;
    case TARGET_REACHED:
      digitalWrite(HEATER_PIN, LOW);
      Serial.println("State: TARGET REACHED - Heater OFF");
      break;
    case OVERHEAT:
      digitalWrite(HEATER_PIN, LOW);
      Serial.println("State: OVERHEAT - Heater OFF, Alert!");
      break;
    default:
      digitalWrite(HEATER_PIN, LOW);
      Serial.println("State: IDLE");
      break;
  }

  delay(1000);
}
