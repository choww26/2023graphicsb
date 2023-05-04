#include <stdio.h>
int main()
{
    char line[20];

    ///scsanf("%s", line);
    FILE * fin = fopen("file.txt", "r");
    fscanf(fin, "%s", line);
    printf("讀到了:%s\n", line);///馬上印
    fscanf(fin, "%s", line);
    printf("讀到了:%s\n", line);///馬上印
}
