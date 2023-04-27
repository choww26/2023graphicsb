#include <windows.h> ///step02-1
#include <stdio.h>


int main(int argc, char**argv)
{
    ///咒語:playsound需要 winmm

    ///絕對路徑absolute path
    /*PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\do.wav", NULL, SND_SYNC);
    PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\re.wav", NULL, SND_SYNC);
    PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\mi.wav", NULL, SND_SYNC);*/

    ///相對路徑relative path
    PlaySound("do-re-mi\\do.wav", NULL, SND_SYNC);

    printf("Hello World\n");
}
