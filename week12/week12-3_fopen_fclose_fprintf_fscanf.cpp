#include <stdio.h>
int main()
{
    int a[10] = {10,20,30,40,50,60,70,80,90,100};
    FILE * fout = fopen("file3.txt", "w");
    for(int i=0; i<10; i++){
        fprintf(fout, "%d ", a[i]);///寫到檔案裡
        printf("%d ", a[i]); ///同時印出
    }
    fclose(fout);

    int b[10];
    FILE * fin = fopen("file3.txt", "r");
    for(int i=0; i<10; i++){
        fscanf(fin, "%d", &b[i]);///讀到陣列b[i]裡
        printf("%d ", b[i]); ///同時印出
    }
    fclose(fin);

}
