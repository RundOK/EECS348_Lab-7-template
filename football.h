#ifndef __LAB_H__
#define __LAB_H__

/* Add any function signatures you need here but do not modify the existing ones */

void find_combinations(int score);
int main();

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
