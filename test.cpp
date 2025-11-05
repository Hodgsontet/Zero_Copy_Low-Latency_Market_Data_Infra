#include<iostream>
#include "memory_pool.h"
#include "spscqueue.h"
#include "Tick.h"

using namespace std;


int main()
{


   /*Bucket<sizeof(Tick),64> b;
    char* raw = b.allocate();

    Tick* tick = new(raw)Tick{123,27,3};

    cout<<"tick has valaues : "<<tick->event<<" "<<tick->time<<" "<<tick->value<<" "<<"\n";
    b.release(reinterpret_cast<char *>(tick));
    char* raw2 = b.allocate();
    Tick* tick2 = new(raw)Tick{12,25,80};
    cout<<"tick has valaues : "<<tick->event<<" "<<tick->time<<" "<<tick->value<<" ";
    */
   

Memory_Pool<sizeof(Tick),64> b;


    return 0;
}