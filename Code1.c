#include <stdio.h>


void calculate_combinations(int score) {
    int td, td_1fg, td_2pt, fg, safety;

    printf("Possible combinations of scoring plays for a score of %d:\n", score);

    
    for (td_2pt = 0; td_2pt <= score / 8; td_2pt++) {
        for (td_1fg = 0; td_1fg <= (score - td_2pt * 8) / 7; td_1fg++) {
            for (td = 0; td <= (score - td_2pt * 8 - td_1fg * 7) / 6; td++) {
                for (fg = 0; fg <= (score - td_2pt * 8 - td_1fg * 7 - td * 6) / 3; fg++) {
                    for (safety = 0; safety <= (score - td_2pt * 8 - td_1fg * 7 - td * 6 - fg * 3) / 2; safety++) {
                        if (td_2pt * 8 + td_1fg * 7 + td * 6 + fg * 3 + safety * 2 == score) {
                            printf("%d TD + 2pt, %d TD + 1pt, %d TD, %d FG, %d Safety\n",
                                   td_2pt, td_1fg, td, fg, safety);
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
        printf("Enter the NFL score (0 or 1 to stop): ");
        scanf("%d", &score);

        if (score <= 1) {
            printf("Program terminated.\n");
            break;
        }

        calculate_combinations(score);
    }

    return 0;
}
