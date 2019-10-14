#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;
ofstream outFile;

void writeNum();
void writeLett();

int main()
{
    outFile.open("synch.txt");
    outFile.close();
   
    thread th1(writeNum);
    thread th2(writeLett);

    th1.join();
    th2.join();
    
    return 0;
}

void writeNum()
{
    mtx.lock();
    outFile.open("synch.txt", ofstream::app);
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<27; j++)
        {
            outFile<<j<<" ";
        }
        outFile<<endl;
    }
    outFile.close();
    mtx.unlock();
}

void writeLett()
{
    mtx.lock();
    outFile.open("synch.txt", ofstream::app);
    char alphabet[27]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
    'M', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    for(int i=0; i<20; i++)
    {
        for(int j=0; j<25; j++)
        {
            outFile<<alphabet[j]<<" ";
        }
        outFile<<endl;
    }
    outFile.close();
    mtx.unlock();
}
