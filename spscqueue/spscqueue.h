#pragma once
#include<iostream>
#include <atomic>
#include <cstddef>

using namespace std;

/*
---------------------------------------
   |     |     |     |      |     |
---------------------------------------
^       ^
|       |
h       t


*/
template<typename T,size_t C>
class SPSCQUEUE{
    alignas(64) atomic<size_t> head=0;
    alignas(64) atomic<size_t> tail=0;
    alignas(64)   T buffer[C];
    
    SPSCQUEUE()
    {
       
    }
   void push(T obj)
   {

     size_t t = tail.load(std::memory_order_relaxed);
        size_t nextTail = (t + 1) % C;

          while (nextTail == head.load(std::memory_order_acquire)) {
            // low-latency pause hint
        }
    
        buffer[t] = obj;
         tail.store(nextTail, std::memory_order_release);
        
    
      
   }
   bool pop(){
     size_t h = head.load(std::memory_order_acquire);
        size_t t = tail.load(std::memory_order_acquire);
    if(h ==t)
    {
         return false;
      
    }
    head.store((h+1)%C, std::memory_order_release);
    return true;
   }


   T* front_pointer()
   {size_t h = head.load(std::memory_order_acquire);
    size_t t = tail.load(std::memory_order_acquire);
    if(h==t)
    {
        return nullptr;
    }
    return &buffer[h];
    
    
   }

   bool front_ref(T& out)
   {
    size_t h = head.load(std::memory_order_acquire);
    size_t t = tail.load(std::memory_order_acquire);
    if(h!=t)
    {
        out = buffer[h];
        return true;
    }
    return false;

      
   }


   size_t size()
   {
    return ((tail.load(std::memory_order_acquire)+C )- head.load(std::memory_order_acquire))%C;
   }
 


};