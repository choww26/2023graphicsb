#include <windows.h> ///step02-1
#include <stdio.h>


int main(int argc, char**argv)
{
    ///�G�y:playsound�ݭn winmm

    ///������|absolute path
    /*PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\do.wav", NULL, SND_SYNC);
    PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\re.wav", NULL, SND_SYNC);
    PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\mi.wav", NULL, SND_SYNC);*/

    ///�۹���|relative path
    PlaySound("do-re-mi\\do.wav", NULL, SND_SYNC);

    printf("Hello World\n");
}
