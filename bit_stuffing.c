#include <stdio.h>
#include <string.h>

#define FLAG 0x7E //flag sequence 01111110
#define ESC 0x7D //escape sequence 01111101

int main() {
    char input[1000], output[2000];
    int i, j, count;
    
    printf("Enter data: ");
    scanf("%s", input);
    
    count = 0;
    j = 0;
    output[j++] = FLAG;
    
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == 0x1) {
            count++;
        } else {
            count = 0;
        }
        
        output[j++] = input[i];
        
        if (count == 5) {
            output[j++] = ESC;
            output[j++] = 0x0;
            count = 0;
        }
    }
    
    output[j++] = FLAG;
    output[j] = '\0';
    
    printf("\nStuffed data: %s", output);
    
    return 0;
}
