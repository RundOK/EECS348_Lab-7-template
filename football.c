#include "football.h"
#include <stdio.h>

void find_combinations(int score) {
    printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);
    
    for (int td2 = 0; td2 * 8 <= score; td2++) {
        for (int td_fg = 0; td_fg * 7 <= score; td_fg++) {
            for (int td = 0; td * 6 <= score; td++) {
                for (int fg = 0; fg * 3 <= score; fg++) {
                    for (int safety = 0; safety * 2 <= score; safety++) {
                        if (td2 * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2 == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", 
                                   td2, td_fg, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;
    
    while (1) {
        printf("Enter the NFL score (0 or 1 to STOP): ");
        scanf("%d", &score);
        
        if (score <= 1) {
            break;
        }
        
        find_combinations(score);
    }
    
    return 0;
}
