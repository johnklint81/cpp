#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <functional>
#include <numeric>

using namespace std;

// cstdlib is considered a legacy library in c++ and alternative libraries
// should be used instead.


float generateGaussian(const float mean, const float stddev) {
    // Box-Müller transform from U(0, 1) -> N(0, 1)
    // u0, u1 are two normally distributed numbers, z is N(0, 1) and
    // Z is N(mean, stddev)
    
    // Here we cast without static_cast<>, but are aware of this being inferior
    float u0 = (float)rand() / RAND_MAX;
    float u1 = (float)rand() / RAND_MAX;
    float z = sqrt(-2.0 * log(u0)) * cos(2.0 * M_PI * u1);
    float Z = z * stddev + mean;
    return Z;
}

int generatePoisson(const int lambda) {
    // Inverse transform sampling method. Sample until we have a probability
    // that exceeds the cutoff
    float cutoff = exp(-lambda);
    float p = 1;
    int i = 0;
    while (p > cutoff) {
        p *= (float)rand() / RAND_MAX;
        i++;
    }
    return i;
}

// Generate a vector of numbers from a float-returning generator
vector<float> generateNumbers(const float mean, const float stddev, 
                              const int size,
                              function<float(float, float)> generator) {
    vector<float> numbers(size);
    for (int i = 0; i < size; i++) {
        numbers[i] = generator(mean, stddev);
    }
    return numbers;
}

// Overloaded function to generate a vector of numbers from an int-returning
// generator
vector<int> generateNumbers(const int lambda, const int size,
                            function<int(int)> generator) {
    vector<int> numbers(size);
    for (int i = 0; i < size; i++) {
        numbers[i] = generator(lambda);
    }
    return numbers;
}

pair<float, float> verifyGaussian(vector<float> numbers) {
    // This function computes mean and standard deviation for the numbers
    // vector<> and returns them as a pair<> type
    int size = numbers.size();
    float sum = 0;
    float sumOfSquares = 0;
    // Compute sum and sum of squares in same loop for efficiency
    for (float x : numbers) {
        sum += x;
        sumOfSquares += x * x;
    }
    // Compute the statistics
    float mean = sum / size;
    float stddev = sqrt((sumOfSquares / size) - (mean * mean));
    return {mean, stddev};
}

int verifyPoisson(vector<int> numbers) {
    // The mean of a Poisson distribution is lambda, so is the variance
    float mean = accumulate(numbers.begin(), numbers.end(), 0) 
        / numbers.size();
    return mean;
}

int main() {
    // Seed with current time
    srand(time(0));
    const float mean = 1;
    const float stddev = 10;
    const int lambda = 30;
    const int size = 1000000;
    
    // Generate Gaussian distributed numbers with specified mean, stddev and
    // size
    vector<float> numsGauss = 
        generateNumbers(mean, stddev, size, generateGaussian);
    pair<float, float> gaussianStatistics = verifyGaussian(numsGauss);
    // Verify
    cout << "(mu, sigma) = (" << gaussianStatistics.first << ", " 
        << gaussianStatistics.second << ")" << endl;

    // Generate Poisson distributed numbers with specified lambda
    vector<int> numsPoisson =
        generateNumbers(lambda, size, generatePoisson);
    // Verify
    int poissonStatistics = verifyPoisson(numsPoisson);
    cout << "lambda = " << poissonStatistics << endl;
    return 0;

}
