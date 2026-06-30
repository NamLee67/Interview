#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    printf("Enter string: ");
    scanf("%s", str);

    printf("\n");
    int len = strlen(str);
    printf("len: %d\n", len);
    for(int i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
    
    printf("reversed string: %s", str);
    return 0;
}