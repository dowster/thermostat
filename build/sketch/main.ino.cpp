#include <Arduino.h>
#line 1 "/home/dowster/Programs/thermostat/embedded/main/main.ino"
#line 1 "/home/dowster/Programs/thermostat/embedded/main/main.ino"


#include "lib/thermostat/Thermostat.cpp"
#include "lib/thermostat/sensors/TMP36.cpp"

#include "lib/thermostat/Relay.cpp"
#include "lib/thermostat/Temperature.cpp"



Thermostat * thermostatA;
Relay * heatingRelay;
Relay * coolingRelay;

#line 15 "/home/dowster/Programs/thermostat/embedded/main/main.ino"
void setup();
#line 33 "/home/dowster/Programs/thermostat/embedded/main/main.ino"
void loop();
#line 15 "/home/dowster/Programs/thermostat/embedded/main/main.ino"
void setup()
{
    heatingRelay = new Relay(5);
    coolingRelay = new Relay(6);

    thermostatA  = new Thermostat(
        new TMP36(0),
        heatingRelay,
        coolingRelay
        );

    thermostatA->setTarget(new Temperature(75, Temperature::Unit::FARENHEIT));
    thermostatA->setOperatingMode(Thermostat::OperatingModes::Cooling);

    Serial.begin(115200);

}

void loop()
{
    thermostatA->loop();

    Serial.println("----------------Update Message----------------");
    Serial.println(thermostatA->getStatus());
    Serial.println("----------------------------------------------");

    delay(100);

    
}

