#ifndef __LAB_H__
#define __LAB_H__

/* Add any function signatures you need here but do not modify the existing ones */

void findCombinations(int score, int td2pt, int tdFG, int td, int fg, int safety, int td2ptVal, int tdFGVal, int tdVal, int fgVal, int safetyVal);

/**
 * @brief Return the number of possible combinations to add up to `points`
 * 
 * @param points
 * @return int 
 */
int count_combinations(int points);

/**
 * @brief Print a formatted table of all possible combinations that add up to
 * `points`
 * 
 * @param points
 */
void print_combinations(int points);

#endif /* __LAB_H__ */
