#include <stdio.h>
#include <string.h>

struct actors {
    char name[50];
    int pop_score;
    int suc_rate;
    int fees;
};

int main() {
    int pop_weight, suc_weight, fees_weight;
    float scores[5]; 
    
    struct actors act[5]= {{"Shah Rukh Khan",95,85,100},{"Amitabh Bachchan",92,80,50},{"Alia Bhatt",89,70,30},{"Akshay Kumar",89,75,60},{"Ranbir Kapoor",86,78,45}};
    // Input the weights for the criteria
    printf("NOTE: Total weight of popularity score, success rate, and fees should be equal to 100\n(If entered zero then no restriction)\n");
    printf("Enter the weight of popularity score(0-100): ");
    scanf("%d", &pop_weight);
    printf("Enter the weight of success rate(0-100): ");
    scanf("%d", &suc_weight);
    printf("Enter the weight of fees(0-100): ");
    scanf("%d", &fees_weight);

    // Check if total weights are valid
    if (pop_weight + suc_weight + fees_weight != 100 ||pop_weight<0||suc_weight<0||fees_weight<0) {
        printf("Error: Total weights must equal 100. Exiting program.\n");
        return 0;
    }

    // Calculate scores
    for (int i = 0; i < 5; i++) {
        scores[i] = (act[i].pop_score * pop_weight) + (act[i].suc_rate * suc_weight) - (act[i].fees * fees_weight); 
        printf("%f\n",scores[i]);
    }

    // sorting using bubble sort in descending
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) 
        {
            if (scores[j] < scores[j + 1]) 
            {
                // Swap scores
                float temp_score = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp_score;

                // Swap corresponding actors
                struct actors temp_actor = act[j];
                act[j] = act[j + 1];
                act[j + 1] = temp_actor;
            }
        }
    }

    // Display results 
    printf("-------------------------------------------------------------------------------------\n");
    printf("\n%-20s %-15s %-15s %-10s %-10s\n", "Actor Name", "Popularity", "Success Rate", "Fees", "Score");
    printf("-------------------------------------------------------------------------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("%-20s %-15d %-15d %-10d %-10.2f\n",
               act[i].name, act[i].pop_score, act[i].suc_rate, act[i].fees, scores[i]);
    }
    printf("-------------------------------------------------------------------------------------\n");
    return 0;
}
