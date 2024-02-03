#include <stdio.h>

int main() {
    int section = 0; // Initialize section variable.
    int rooms[5] = {2, 2, 2, 2, 0}; // Game board initialization with 4 sections and a store.
    
    // Display the initial state of the game board.
    printf("%d %d %d %d | %d\n", rooms[0], rooms[1], rooms[2], rooms[3], rooms[4]);
    
    int last = 0; // Variable to keep track of the last section played.
    
    while (rooms[4] != 8) { // Continue the game until the store has 8 seeds.
        
        if (last == 0) { // Player needs to choose a section if last is 0.
            printf("Choose a section (1-4): ");
            scanf("%d", &section);
            // Validate the chosen section.
            while (section < 1 || section > 4 || rooms[section - 1] == 0) {
                printf("Invalid choice. Choose a section (1-4): ");
                scanf("%d", &section);
            }
        } else {
            // If last is not 0, automatically choose the last section for the next move.
            section = last;
            if (rooms[section - 1] == 0) { // Check if the automatically chosen section is empty.
                last = 0; // Reset last to force player choice if the section is empty.
                continue; // Skip the rest of the loop iteration.
            }
        }
        
        int current = section - 1; // Adjust for 0-based indexing.
        int size = rooms[current];
        rooms[current] = 0; // Remove seeds from the chosen section.
        int next = (current + 1) % 5; // Determine the next section.
        
        for (int i = 0; i < size; i++) {
            rooms[next]++;
            current = next; // Update current to the last updated section.
            next = (next + 1) % 5; // Move to the next section.
        }
        
        last = (current == 4) ? 0 : current + 1; // Determine the next section for the player's move.
        
         // Winning condition check.
        if (rooms[4] == 8) {
            printf("You won!\n");
            break;
        } 
        
        // Display the current state of the game board.
        printf("%d %d %d %d | %d\n", rooms[0], rooms[1], rooms[2], rooms[3], rooms[4]);
        
        
        if (rooms[current] == 1 && current != 4) { // Losing condition based on the last seed's placement.
            printf("You lost because the last counter fell into section %d\n", current + 1); // Adjust for 1-based indexing in user display.
            break;
        } else if (next != 0) {
            printf("Last piece landed in section %d. Continue sowing seeds!\n", current + 1); // Inform the player about the next move.
        }
    }
    
    return 0;
}
