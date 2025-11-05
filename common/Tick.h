#pragma once
#include <iostream>


enum class TickType{ 
    Trade,
    Quote,
    Order
};

struct Tick{
public:
    TickType tickType;
    uint16_t timestamp;
    union Data{

        struct Trade{double price; int size;};
        struct Quote{ double bid, ask; int bidSize, askSize; };
        struct Order{ double price; int size; uint8_t isBid; };

    };
};