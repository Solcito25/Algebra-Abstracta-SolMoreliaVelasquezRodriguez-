#include <iostream>
#define _WIN32_WINNT 0x0501
#include <Windows.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <psapi.h>
#include <bitset>
#include<NTL/ZZ.h>
using namespace std;
using namespace NTL;
int mod(int a,int b){
    int r=a-(b*(a/b));
    if(r<0)
        r=b+r;
    return r;
    }
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

vector<int>LLenarK(){
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
    string k1;
    for(int i=5; i<26;i+=5){
        int t=(int)(al[i]);
        string temp=to_string(t);
        k1+=temp;}
        k1=k1.substr(0,15);
    vector <int> k;
    for(int i=0;i<k1.size();i+=3){
        string temp=k1.substr(i,3);
        int t=stoi(temp);
        while(t>255)
            t>>=1;
        while(t<128)
            t<<=1;
        k.push_back(t);
    }
    vector<int>K;
    for(int i=0;i<256;){
        for(int j=0;j<k.size();j++,i++)
            K.push_back(k[j]);}
    return K;
}
vector<int> RC4(){
    vector<int>k=LLenarK();
    vector<int>s;
    vector<int>Ori;
    vector<int>Or;
    for(int i=0;i<256;i++)
        s.push_back(i);
    int f=0;
    for(int i=0;i<256;i++){
        f=mod(f+k.at(i)+s.at(i),256);
        swap(s.at(i),s.at(f));
    }
    f=0;
    for(int j=0,i=0;j<8;j++){
        i=mod(i+1,256);
        f=mod(f+s.at(i),256);
        swap(s.at(i),s.at(f));
        int t=mod(s.at(i)+s.at(f),256);
        Ori.push_back(s.at(t));
    }
    for(int i=0;i<Ori.size();i++){
        bitset<8>temp=Ori[i];
        string tp=temp.to_string();
        for(int j=0;j<8;j++){
            int tmp=stoi(tp.substr(j,1));
            Or.push_back(tmp);
        }
    }
    return Or;
}
int main()
{
    vector<int>K=RC4();
    for(int m=0;m<K.size();m++)
    cout<<K[m]<<" ";
    cout<<endl;
    int PC_1[56]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
    int PC_2[48]={14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
    vector<int>Ki;
    for(int i=0;i<56;i++){
        Ki.push_back(K.at(PC_1[i]));
    }
    for(int m=0;m<Ki.size();m++)
    cout<<Ki[m]<<" ";
///Impresion de los vectores :D
    /*cout<<"miss aqui esta le vector :D"<<endl;
    for(int i=0;i<k.size();i++)
        cout<<k[i]<<" ";
    cout<<endl;
    for(int i=0;i<s.size();i++)
        cout<<s[i]<<" ";
    cout<<endl<<"CAMBIOS"<<endl;
    for(int i=0;i<s.size();i++)
        cout<<s[i]<<" ";
    for(int m=0;m<Or.size();m++)
    cout<<Or[m]<<" "<<endl;
    for(int m=0;m<Ori.size();m++)
    cout<<Ori[m]<<" ";
    cout<<endl;
    for(int m=0;m<Ori.size();m++)
    cout<<Ori[m];
    cout<<endl;*/



    return 0;
}
/*
#include<windows.h>
int main(){
system("ping 69.171.250.35 > info.txt");///facebook
system("ping 64.233.190.100 > info2.txt");/// google
}

al.push_back((long unsigned)(GetCPULoad()*10000000));
for(int i=0;i<al.size();i++){
        cout<<al[i]<<endl;
*/
