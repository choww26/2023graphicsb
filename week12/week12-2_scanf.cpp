#include <stdio.h>
int main()
{
    char line[20];

    ///scsanf("%s", line);
    FILE * fin = fopen("file.txt", "r");
    fscanf(fin, "%s", line);
    printf("Ū��F:%s\n", line);///���W�L
    fscanf(fin, "%s", line);
    printf("Ū��F:%s\n", line);///���W�L
}
