#include <iostream>
#define _WIN32_WINNT 0x0501
#include <Windows.h>
#include <stdio.h>
#include <vector>
#include <psapi.h>
using namespace std;


void PrintMemoryInfo(DWORD processID,vector <unsigned long> &al)
{
    HANDLE hProcess;
    PROCESS_MEMORY_COUNTERS pmc;
    hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
        PROCESS_VM_READ,
        FALSE, processID);
    if (NULL == hProcess)
        return;

    if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
    {

        al.push_back(pmc.PageFaultCount);
        al.push_back(pmc.WorkingSetSize);
        al.push_back(pmc.QuotaPeakPagedPoolUsage);
        al.push_back(pmc.QuotaPeakNonPagedPoolUsage);
        al.push_back(pmc.QuotaNonPagedPoolUsage);
    }

    CloseHandle(hProcess);
}
static float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
   static unsigned long long _previousTotalTicks = 0;
   static unsigned long long _previousIdleTicks = 0;

   unsigned long long totalTicksSinceLastTime = totalTicks-_previousTotalTicks;
   unsigned long long idleTicksSinceLastTime  = idleTicks-_previousIdleTicks;

   float ret = 1.0f-((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);

   _previousTotalTicks = totalTicks;
   _previousIdleTicks  = idleTicks;
   return ret;
}

static unsigned long long FileTimeToInt64(const FILETIME & ft) {return (((unsigned long long)(ft.dwHighDateTime))<<32)|((unsigned long long)ft.dwLowDateTime);}

float GetCPULoad()
{
   FILETIME idleTime, kernelTime, userTime;
   return  GetSystemTimes(&idleTime, &kernelTime, &userTime)? CalculateCPULoad(FileTimeToInt64(idleTime), FileTimeToInt64(kernelTime)+FileTimeToInt64(userTime)): -1.0f;
}

int main()
{
    DWORD aProcesses[1024], cbNeeded, cProcesses;
    unsigned int i;vector <unsigned long> al;

    if (EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
    {
       cProcesses = cbNeeded / sizeof(DWORD);



    for (i = 0; i < cProcesses; i++)
    {
        PrintMemoryInfo(aProcesses[i],al);
    }



    }


    al.push_back((long unsigned)(GetCPULoad()*10000000));
     for(int i=0;i<al.size();i++){
        cout<<al[i]<<endl;
    }

    return 0;
}
/*
#include<windows.h>
int main(){
system("ping 69.171.250.35 > info.txt");
system("ping 64.233.190.100 > info2.txt");


}

*/

