#pragma once
#include <iostream>

using namespace std;
template<size_t block_size,size_t block_length>
class Bucket
{
    public:
    Bucket()
    {
        init();
    }
alignas(64)char block[block_size*block_length];
  size_t freeIndex = 0;
  char* freelist[block_length];

 char* allocate()
 {
    if(freeIndex==block_length)return nullptr;
   
    return freelist[freeIndex++];
 }

 bool release(char * p)
 {
    if(freeIndex!=0){
    freelist[--freeIndex] = p; return true;}
    return false;
 }

 void init(){
    for(size_t i =0; i<block_length; i++)
    {
        freelist[i]=block + i*block_size;
    }
 }



};

template<size_t block_size,size_t block_length>
class Memory_Pool{
    public:
    

    Bucket<block_size, block_length> bucket;
    Memory_Pool(){bucket.init();}

    char *allocate(){return bucket.allocate();}
    bool release(char*ptr){return bucket.release(ptr);}
    size_t capacity() const { return block_length; }



};
