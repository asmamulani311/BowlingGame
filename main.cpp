#include <iostream>
#include <vector>

using namespace std;

class BowlingGame {
private:
    vector<int> rolls;
    
public:
    void roll(int pins) {
        rolls.push_back(pins);
    }
    
    int score() {
        int totalScore = 0;
        int rollIndex = 0;
        
        for (int frame = 0; frame < 10; ++frame) {
            if (rolls[rollIndex] == 10) { // Strike
                totalScore += 10 + rolls[rollIndex + 1] + rolls[rollIndex + 2];
                rollIndex += 1;
            } else if (rolls[rollIndex] + rolls[rollIndex + 1] == 10) { // Spare
                totalScore += 10 + rolls[rollIndex + 2];
                rollIndex += 2;
            } else { // Normal frame
                totalScore += rolls[rollIndex] + rolls[rollIndex + 1];
                rollIndex += 2;
            }
        }
        
        return totalScore;
    }
};

int main() {
    BowlingGame game;
    
    cout << "Enter your rolls (press Enter after each roll): " << endl;
    for (int i = 0; i < 21; ++i) { // Max 21 rolls in case of 10th frame spare/strike
        int pins;
        cin >> pins;
        game.roll(pins);
        if (i >= 18 && pins == 10) continue; // Handling extra rolls for the 10th frame
    }
    
    cout << "Total Score: " << game.score() << endl;
    
    return 0;
}
