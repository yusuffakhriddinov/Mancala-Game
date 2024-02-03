#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int section = 1;
    int rooms[5] = {2, 2, 2, 2, 0};
    
    printf("%d %d %d %d | %d \n", rooms[0], rooms[1], rooms[2], rooms[3], rooms[4]);
    int last = 0;
    
    while (rooms[4]!=8){
        
         
        
        if(last==0){
            
            printf("Choose a section (1-4): ");
            scanf("%d", &section);
            while(section<0 || section>5 || rooms[section-1]==0){
                printf("Invalid choice. ");
                printf("Choose a section (1-4): ");
                scanf("%d", &section);
            }
            
        }else{
            section = last;
        }
        
        int current = section - 1;
        int next = (current + 1)%5;
        int size = rooms[current];
        
       int pre_last;
        
        for (int i = 0; i<size; i++){
            pre_last = next;
            rooms[next]++;
            rooms[current]--;
            next = (next+1)%5;
        }
        
        last=next;
        
        if (rooms[4]==8){
            printf("You won!");
        }else if(rooms[pre_last]==1 && pre_last!=4){
            printf("%d %d %d %d | %d \n", rooms[0], rooms[1], rooms[2], rooms[3], rooms[4]);
            printf("You lost because the last counter fell into section %d", next);
            break;
        }
        else{
            printf("%d %d %d %d | %d \n", rooms[0], rooms[1], rooms[2], rooms[3], rooms[4]);
        
        }

        if(next!=0){
            printf("Last piece landed in section %d. Continue sowing seeds! \n", next);
        }

        
    }
    

    return 0;
}