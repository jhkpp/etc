#ifdef _WIN32

#include "Window.h"
#include "Socket.h"

void OnCreate()
{

}

int WINAPI wWinMain(HINSTANCE ht, HINSTANCE hP, PWSTR cl, int cs)
{
    Window w(ht, hP, cl, cs);

    
    w.Init(L"가가오톡", 200, 700);

    return 0;
}

#else

#include <stdio.h>

int main()
{
    printf("It is not windows.\n");
    return 0;
}

#endif // windows