#include"subString.h"

int main()
{
    char a[20];
    printf("Enter the main string\n");
    fgets(a, 20, stdin);
    a[strlen(a) -1] = '\0';
    char b[20];
    printf("Enter the sub string\n");
    fgets(b, 20, stdin);
    b[strlen(b) -1] = '\0';
    int ret = isSubString(a,b);
    printf("ret=%d\n",ret);
    if(ret==1)
    {
        printf("Is a sub string\n");
    }
    else
    {
        printf("Not a sub string\n");
    }
    return 0;
}