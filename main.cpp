#include "mbed.h"        // Mbed OS standard library
#include <cstdio>    // C-style input/output (printf)
#include <chrono>      // For time durations like 3s
using namespace std::chrono;

DigitalOut alertLED(LED1);        // Warning indicator
Timer timer;                      // Track runtime in seconds

// Simulated sensor value generator to simulate sensor readings within a range
int get_simulated_value(int min, int max) {
    return min + (rand() % (max - min + 1));
}

int main() {   //infifinte loop
    printf("Indoor Environment Monitoring System (Simulation)\n");
    printf("Time(s),Temperature(°C),Humidity(%%),AirQuality,LightLevel,Alert\n");             //Prints the simulated readings

    timer.start();  // Start runtime clock

    while (true) {                          // Simulates four sensor values: temperature (°C), humidity (%), air quality index, and light level
        int temperature = get_simulated_value(20, 40);
        int humidity    = get_simulated_value(20, 60);
        int airQuality  = get_simulated_value(100, 300);
        int lightLevel  = get_simulated_value(100, 700);

        // Check for any alerts 
        bool alert = false;
        if (temperature > 30 || humidity < 30 || airQuality > 200 || lightLevel < 300) {
            alert = true;
        }
        alertLED = alert ? 1 : 0;

        // Print in CSV format
        printf("%0.1f,%d,%d,%d,%d,%s\n",
               timer.read(),
               
               temperature, humidity, airQuality, lightLevel,
               alert ? "YES" : "NO");

        ThisThread::sleep_for(3000);     // Waits for 3 seconds before the next sensor reading
    }
}


* OUTPUT *

    Indoor Environment Monitoring System (Simulation)

--- Sensor Readings ---
Temperature : 34 °C
Humidity    : 28 %
Air Quality : 210
Light Level : 450
Warning: High temperature!
Warning: Low humidity!
Warning: Poor air quality!

--- Sensor Readings ---
Temperature : 25 °C
Humidity    : 45 %
Air Quality : 130
Light Level : 250
Warning: Room is dark!

...
prints every three seconds endlessly in a loop. The alert LED is also turned ON or OFF based on the logic.

