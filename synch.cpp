#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void writeNum(ofstream);
void writeLett(ofstream);

int main()
{
    ofstream outFile;
    outFile.open("synch.txt");
    outFile.close();
    thread th1(writeNum, outFile);
    thread th2(writeLett, outFile);

    th1.join();
    th2.join();
    
    return 0;
}

void writeNum(ofstream outFile)
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

void writeLett(ofstream outFile)
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
