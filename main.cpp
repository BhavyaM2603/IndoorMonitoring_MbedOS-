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


* OUTPUT *        prints in csv format 
     Indoor Environment Monitoring System (Simulation)
[?2004l
Time(s),Temperature(°C),Humidity(%),AirQuality,LightLevel,Alert
0,26,41,116,286,YES
1,28,49,229,264,YES
2,25,54,108,365,NO
3,20,56,135,379,NO
4,23,52,126,208,YES
5,29,21,290,505,YES
6,30,22,292,459,YES
7,34,51,242,659,YES
8,22,44,134,376,NO
9,33,49,101,278,YES
10,22,29,155,391,YES
11,26,30,137,190,YES
12,31,51,127,636,YES
13,31,59,197,218,YES
14,34,56,232,232,YES
15,26,32,178,508,NO
16,34,34,144,288,YES
17,26,24,263,655,YES
18,20,54,137,696,NO
19,40,43,195,268,YES

   


