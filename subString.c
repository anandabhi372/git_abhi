/* Program to check if given string 2 is a sub string of the main string */

#include<stdio.h>
#include<string.h>

static int isSubString(char *a, char *b)
{
    printf("len of a=%d\n", strlen(a));
    printf("len of b=%d\n", strlen(b));
    printf("a=%s\n", a);
    printf("b=%s\n", b);
    int i=0,j=0,k=0;
    int count=0;
    int flag=0;
    for(i=0;i<strlen(a);i++)
    {
        if(b[j]==a[i])
        {
            flag=1;
            break;
        }
    }
    printf("i=%d\n",i);
    if(flag==1)
    {
        for(k=j;k<strlen(b);k++)
        {
            if(a[i]==b[k])
            {
                i++;
                count++;
            }
        }
        if(count==strlen(b))
        {
            return 1;
        }
    }
    return 0;
}

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