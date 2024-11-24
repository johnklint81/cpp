#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;
using Clock = chrono::high_resolution_clock;

unsigned getCPUTemperature() {
    // Returns the temperature in millidegree Celcius.
    unsigned temperature = 0;
    // This is the primary temperature sensor for the core die in the Ryzen CPU
    ifstream temperatureFile("/sys/class/hwmon/hwmon2/temp3_input");
    // Read the temperature from the sensor file.
    if (temperatureFile.is_open()) {
        temperatureFile >> temperature;
        temperatureFile.close();
    }
    return temperature;

}

unsigned mixTimeAndTemp(unsigned temperature) {
    auto now = Clock::now().time_since_epoch().count();
    // 0x5bd1e995 is a MurMurHash inspired value.
    auto mixed = (temperature ^ now) * 0x5bd1e995;
    return mixed;
}

// Assumes a 32-bit integer
unsigned hashFunction(unsigned value) {
    // Shift the bits 16 steps to the right, then XOR them with the input value
    // to mix the most and least significant digits of the value. Then multiply
    // by 0x459f3b = 73199375. This value is carefully selected to 
    // significantly diffuse the term it is multiplied with. Note that it is
    // odd and avoids excessive repetetive patterns. We repeat this several
    // times to further increase diffusion.
    value = ((value >> 16) ^ value) * 0x459df3b;
    // Note we can repeat this line for extra layers of complexity.
    return value;
}



int main(int argc, char *argv[]) {
    
    // Cast to unsigned long, then to unsigned via a static_cast, the last cast
    // is not really necessary, more for learning purposes.
    // static_cast is safer than C-style casting (and more precise)
    unsigned min = static_cast<unsigned>(stoul(argv[1]));
    unsigned max = static_cast<unsigned>(stoul(argv[2]));
    
    // Get the CPU temperature, the mix this source of entropy with current
    // time and lastly apply a hash function.
    unsigned temp = getCPUTemperature();
    unsigned mixed = mixTimeAndTemp(temp);
    unsigned randInt = hashFunction(mixed);

    unsigned randInRange = (randInt % ( max - min + 1)) + min;

    cout << randInRange << endl;
    
}
