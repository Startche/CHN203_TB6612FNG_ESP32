#include <Arduino.h>
#include <TB6612FNG.h>

// Pins for all motor outputs.
#define AIN1 18
#define AIN2 19
#define PWMA 21
#define BIN1 4
#define BIN2 2
#define PWMB 15
#define STBY 5

// Pins for encoder inputs.
#define AC1 34
#define AC2 35
#define BC1 32
#define BC2 33

// Motor reduction ratio (1 : RATIO)
#define RATIO 29.0

T6621FNG motor1(AIN1, AIN2, PWMA, 1, STBY);
T6621FNG motor2(BIN1, BIN2, PWMB, -1, STBY);

CHN203 board1(&motor1, AC1, AC2, RATIO);
CHN203 board2(&motor2, BC1, BC2, RATIO);

void setup()
{
    Serial.begin(115200);

    board1.tuneSpeedPID(4, 3, 0);
    board2.tuneSpeedPID(4, 3, 0);

    board1.setSpeed(2);
    board2.setSpeed(-2);
}

void loop()
{
    Serial.print(board1.getSpeed());
    Serial.print('\t');
    Serial.print(board2.getSpeed());
    Serial.print('\n');

    delay(10);
}
