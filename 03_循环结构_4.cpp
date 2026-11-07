#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 1; t <= T; t++) {
        int n;
        scanf("%d", &n);
        
        int half = (n + 1) / 2; 
        
        for (int i = 1; i <= half; i++) {
           
            for (int x = 1; x <= half - i; x++) {
                printf(" ");
            }
            
            for (int m = 1; m <= 2 * i - 1; m++) {
                printf("*");
            }
            printf("\n");
        }
        
        for (int i = half - 1; i >= 1; i--) {
            
            for (int x = 1; x <= half - i; x++) {
                printf(" ");
            }
            
            for (int m = 1; m <= 2 * i - 1; m++) {
                printf("*");
            }
            printf("\n");
        }
    }
    
    return 0;
}
