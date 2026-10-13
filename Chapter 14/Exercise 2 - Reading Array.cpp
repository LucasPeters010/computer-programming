// Exercise 2 - Reading Array (EASY -> MEDIUM)
// Goal: Practice dynamic arrays of class objects and delete[].
//
// Tasks:
// 1. Complete setBpm() and getBpm().
// 2. Use the pointer array to store 65, 72, and 79 BPM.
// 3. Use a loop to calculate and print the average BPM.
// 4. Release the entire dynamic array correctly.
//
// Expected output:
// Average BPM: 72
//
// Hint: readings[i].setBpm(...) works because readings[i] is an object.
// Bonus: Try (readings + i)->getBpm() in the loop.

#include <iostream>

class HeartRate {
public:
    HeartRate() : bpm(0) {}

    void setBpm(int newBpm) {
        // TODO 1a: Store newBpm.
    }

    int getBpm() const {
        // TODO 1b: Return bpm (replace the placeholder).
        return 0;
    }

private:
    int bpm;
};

int main() {
    const int count = 3;
    HeartRate* readings = new HeartRate[count];

    // TODO 2: Set the three objects' BPM values: 65, 72, 79.

    int total = 0;
    for (int i = 0; i < count; ++i) {
        // TODO 3a: Add the i-th BPM value to total.
    }

    // TODO 3b: Print "Average BPM: " followed by total / count.

    // TODO 4: Release the dynamic array (not just one object).

    return 0;
}
