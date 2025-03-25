#include "football.h"  //including the header file
#include <stdio.h>  

void find_combinations(int score) {  //function to find all possible combination to get a given score
    printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);  
    
    //nested loop to find all possible combinations
    //iterating through all possible numbers of touchdowns with a 2-point conversion (8 points each)
    for (int td2 = 0; td2 * 8 <= score; td2++) {
        //iterating through all possible numbers of touchdowns with an extra point field goal (7 points each)
        for (int td_fg = 0; td_fg * 7 <= score; td_fg++) {
            //iterating through all possible numbers of touchdowns without extra points (6 points each)
            for (int td = 0; td * 6 <= score; td++) {
                //iterating through all possible numbers of field goals (3 points each)
                for (int fg = 0; fg * 3 <= score; fg++) {
                    //iterating through all possible numbers of safeties (2 points each)
                    for (int safety = 0; safety * 2 <= score; safety++) {
                        //checking if the total points sum up to the given score
                        if (td2 * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2 == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", 
                                   td2, td_fg, td, fg, safety); //print each combination once found
                        }
                    }
                }
            }
        }
    }
}

int count_combinations(int score) {
    int count = 0;

    //nested loop to find all possible combinations
    //iterating through all possible numbers of touchdowns with a 2-point conversion (8 points each)
    for (int td2 = 0; td2 * 8 <= score; td2++) {
        //iterating through all possible numbers of touchdowns with an extra point field goal (7 points each)
        for (int td_fg = 0; td_fg * 7 <= score; td_fg++) {
            //iterating through all possible numbers of touchdowns without extra points (6 points each)
            for (int td = 0; td * 6 <= score; td++) {
                //iterating through all possible numbers of field goals (3 points each)
                for (int fg = 0; fg * 3 <= score; fg++) {
                    //iterating through all possible numbers of safeties (2 points each)
                    for (int safety = 0; safety * 2 <= score; safety++) {
                        //checking if the total points sum up to the given score
                        if (td2 * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2 == score) {
                            count++; //if a combination is found, increment combination count
                        }
                    }
                }
            }
        }
    }

    return count;  //returning count
}

int main() {  
    int score; //initilizing score as an int
    
    while (1) { //while loop to keep prompting the user for input 
        printf("Enter the NFL score (0 or 1 to STOP): ");
        scanf("%d", &score);  //scanning for user input
        
        if (score <= 1) { //if user inputs a score of 0 or 1,
            break;  //loop breaks 
        }
        
        find_combinations(score); //calling find_combinations to print all possible combinations for given score
    }
    
    return 0;
}

//I ran the workflow and it passed without adding main. The exe works as intended.