#include <iostream>
#include <windows.h>
#include <thread>
#include "Svc.h"
#include "ReDir_parent.h"

using namespace std;

HANDLE ghStopThreads;
HANDLE gEvent;

DWORD WINAPI f(LPVOID) {
    for (int i = 0; i < 20; i++) {
        printf("f() initialization\n");
        Sleep(20);
    }

    SetEvent(gEvent);

    while (1) {
        printf("f() Doing something\n");
        Sleep(100);
        if (ghStopThreads) {
            printf("f() is stopping itself\n");
            return 0;
        }
    }

    return 0;
}

int wmain(int argc, TCHAR* argv[])
{
    printf("%S", argv[0]);
    redir_parent(argc, argv);


    //DWORD dwThreadId;

    //gEvent = CreateEvent(nullptr, false, false, (LPWSTR)("ThreadEvent"));
    //ghStopThreads = CreateEvent(nullptr, false, true, (LPWSTR)("StopThreads Event"));
    //SetEvent(ghStopThreads);

    //HANDLE hThread = CreateThread(
    //    NULL,              // no security attribute 
    //    0,                 // default stack size 
    //    f,    // thread proc
    //    nullptr,    // thread parameter 
    //    0,                 // not suspended 
    //    &dwThreadId);      // returns thread ID 

    //if (hThread == NULL)
    //{
    //    printf("CreateThread failed, GLE=%d.\n", GetLastError());
    //    return 0;
    //}
    //else {
    //    printf("Thread created\n");
    //    HANDLE handles[1];
    //    handles[0] = gEvent;
    //    //handles[1] = ghStopThreads;

    //    if (WaitForMultipleObjects(1, handles, true, 3000) != WAIT_OBJECT_0) {
    //        printf("Threads started but didn't return a signal. Terminating this thread\n");
    //        if (TerminateThread(hThread, -1)) {
    //            printf("Thread terminated\n");
    //        }
    //        else {
    //            printf("Error during terminating thread, GLE=%d.\n", GetLastError());
    //        }
    //    }
    //    else {
    //        printf("Thread initialized\n");
    //    }

    //    CloseHandle(hThread);
    //    //CloseHandle(ghStopThreads);
    //}

    

    //service(argc, argv);
}