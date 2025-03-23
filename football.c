#include "football.h"
#include <stdio.h>

void findCombinations(int score, int td2pt, int tdFG, int td, int fg, int safety, int td2ptVal, int tdFGVal, int tdVal, int fgVal, int safetyVal) {
    // Base condition: if the score is 0, print the combination
    if (score == 0) {
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2pt, tdFG, td, fg, safety);
        return;
    }
    
    // Check all possible combinations of scoring plays
    if (score >= td2ptVal) findCombinations(score - td2ptVal, td2pt + 1, tdFG, td, fg, safety, td2ptVal, tdFGVal, tdVal, fgVal, safetyVal);
    if (score >= tdFGVal) findCombinations(score - tdFGVal, td2pt, tdFG + 1, td, fg, safety, td2ptVal, tdFGVal, tdVal, fgVal, safetyVal);
    if (score >= tdVal) findCombinations(score - tdVal, td2pt, tdFG, td + 1, fg, safety, td2ptVal, tdFGVal, tdVal, fgVal, safetyVal);
    if (score >= fgVal) findCombinations(score - fgVal, td2pt, tdFG, td, fg + 1, safety, td2ptVal, tdFGVal, tdVal, fgVal, safetyVal);
    if (score >= safetyVal) findCombinations(score - safetyVal, td2pt, tdFG, td, fg, safety + 1, td2ptVal, tdFGVal, tdVal, fgVal, safetyVal);
}

int main() {
    int score;
    int td2ptVal = 8, tdFGVal = 7, tdVal = 6, fgVal = 3, safetyVal = 2;

    // Loop for user input until a value <= 1 is entered
    while (1) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        
        if (score <= 1) {
            break;
        }
        
        printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);
        findCombinations(score, 0, 0, 0, 0, 0, td2ptVal, tdFGVal, tdVal, fgVal, safetyVal);
    }
    
    return 0;
}
