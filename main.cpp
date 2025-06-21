#include "mbed.h"
#include <cstdio>
#include <chrono>
using namespace std::chrono;

DigitalOut alertLED(LED1);        // Warning indicator
Timer timer;                      // Track runtime in seconds

// Simulated sensor value generator
int get_simulated_value(int min, int max) {
    return min + (rand() % (max - min + 1));
}

int main() {
    printf("Indoor Environment Monitoring System (Simulation)\n");
    printf("Time(s),Temperature(°C),Humidity(%%),AirQuality,LightLevel,Alert\n");

    timer.start();  // Start runtime clock

    while (true) {
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

        ThisThread::sleep_for(3000);
    }
}
