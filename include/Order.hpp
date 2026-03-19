#ifndef ORDER_HPP
#define ORDER_HPP

#include <cstdint>

enum class Side { BUY, SELL };

struct Order {
    uint64_t id;
    Side side;
    long price;      // $100.50 ko hum 10050 store karenge
    uint32_t quantity;
};

#endif
