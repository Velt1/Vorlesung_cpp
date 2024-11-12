#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverse(char s[])
{
    int i;
    int length = strlen(s);
    char* s3 = malloc((length+1) * sizeof(char));
    for  (i = 0; i < length; i++) {
        s3[i] = s[length - i - 1]; /* Hier muss noch ein -1 rein weil sonst der Index nicht stimmt */
    }
    s3[length] = '\0';
    return s3;
}

int main(void)
{
    char *s1 = NULL, *s2 = NULL;
    s1= (char * ) malloc(sizeof(char)* 16);
    s2= (char * ) malloc(sizeof(char)* 16);
    strcpy(s2, "Hans");
    strcpy(s1, "Mustermann der Erste von Eberburg in Sachsen");

    printf("s1,s2: [%s], [%s]\n", s1,s2);
    printf("s3 = %s\n", reverse(s1));
    free(s1);
    free(s2);

    s1=NULL;
    s2=NULL;
    return 0;
}
