#include<stdio.h>
#include<stdlib.h>

int my_strlen(const char *src)
{
    int l=0;
    while(src[l]!='\0') l++;
    return l;
}

char * my_strcpy(char *dst,const char *src)
{
    if (dst==NULL || src == NULL) return NULL;
    int i=0;
    for (i=0;i<my_strlen(src);i++) 
    {
        dst[i] = src[i];
    }
    dst[i] = '\0';
    return dst;
}

char * my_strcat (char *dst, const char *src)
{
    int dstlen = my_strlen(dst);
    return my_strcpy(dst+dstlen,src);
}

int main(void)
{
    char *s1 = (char *)malloc(sizeof(char)*30);
    my_strcpy(s1, "Mustermann");
    printf("s1: %s\n", s1);

    free(s1);
}
