
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
int main(void)
{
    int duration = 5;
    int count = 0;

    printf("You will have %d seconds to click on left mouse button.\n", duration);
    printf("ENTER to start:\n");

    getchar();

    time_t start = time(NULL);

    SHORT prevState = 0;
    while (difftime(time(NULL), start) < duration)
    {
        SHORT state = GetAsyncKeyState(VK_LBUTTON);
        int pressed = (state & 0x8000) ? 1 : 0;
        if (pressed && !prevState)
        {
            count++;
        }
        prevState = pressed;
        Sleep(1);
    }

    double cps = (double)count / (double)duration;

    printf("Total clicks: %d\n", count);
    printf("cps = %f\n", cps);

    return 0;
}
