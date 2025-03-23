#include "football.h"
#include <stdio.h>

//Recursive function to find all possible combinations of scoring plays
void findCombinations(int score, int td2pt, int tdFG, int td, int fg, int safety, int td2ptVal, int tdFGVal, int tdVal, int fgVal, int safetyVal) {
    //Base case: if the score is 0, print the current combination
    if (score == 0) {
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG, %d Safety\n", td2pt, tdFG, td, fg, safety);
        return;
    }

    //Check all possible combinations of scoring plays
    if (score >= td2ptVal) 
        findCombinations(score - td2ptVal, td2pt + 1, tdFG, td, fg, safety, td2ptVal, tdFGVal, tdVal, fgVal, safetyVal);
    
    if (score >= tdFGVal) 
        findCombinations(score - tdFGVal, td2pt, tdFG + 1, td, fg, safety, td2ptVal, tdFGVal, tdVal, fgVal, safetyVal);
    
    if (score >= tdVal) 
        findCombinations(score - tdVal, td2pt, tdFG, td + 1, fg, safety, td2ptVal, tdFGVal, tdVal, fgVal, safetyVal);
    
    if (score >= fgVal) 
        findCombinations(score - fgVal, td2pt, tdFG, td, fg + 1, safety, td2ptVal, tdFGVal, tdVal, fgVal, safetyVal);
    
    if (score >= safetyVal) 
        findCombinations(score - safetyVal, td2pt, tdFG, td, fg, safety + 1, td2ptVal, tdFGVal, tdVal, fgVal, safetyVal);
}

//Function to count the number of combinations for a given score
int count_combinations(int points) {
    int count = 0;

    //Iterate through possible combinations
    int td2ptVal = 8, tdFGVal = 7, tdVal = 6, fgVal = 3, safetyVal = 2;

    for (int td2pt = 0; td2pt * td2ptVal <= points; td2pt++) {
        for (int tdFG = 0; td2pt * td2ptVal + tdFG * tdFGVal <= points; tdFG++) {
            for (int td = 0; td2pt * td2ptVal + tdFG * tdFGVal + td * tdVal <= points; td++) {
                for (int fg = 0; td2pt * td2ptVal + tdFG * tdFGVal + td * tdVal + fg * fgVal <= points; fg++) {
                    for (int safety = 0; td2pt * td2ptVal + tdFG * tdFGVal + td * tdVal + fg * fgVal + safety * safetyVal <= points; safety++) {
                        if (td2pt * td2ptVal + tdFG * tdFGVal + td * tdVal + fg * fgVal + safety * safetyVal == points) {
                            count++;
                        }
                    }
                }
            }
        }
    }
    return count;
}

//Function to print all possible combinations of scores
void print_combinations(int points) {
    int td2ptVal = 8, tdFGVal = 7, tdVal = 6, fgVal = 3, safetyVal = 2;
    findCombinations(points, 0, 0, 0, 0, 0, td2ptVal, tdFGVal, tdVal, fgVal, safetyVal);
}

int main() {
    int score;
    int td2ptVal = 8, tdFGVal = 7, tdVal = 6, fgVal = 3, safetyVal = 2;

    //Loop to take user input until a value <= 1 is entered
    while (1) {
        printf("Enter the NFL score: ");
        if (scanf("%d", &score) != 1) {  //validate input
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); //clear input buffer
            continue;
        }

        if (score <= 1) {
            printf("Exiting program...\n");
            break;
        }
        
        printf("Possible combinations of scoring plays for a team’s score of %d:\n", score);
        print_combinations(score);
    }
    
    return 0;
}
