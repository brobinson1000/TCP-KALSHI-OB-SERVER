#pragma once

#include <cstdint>

struct Order {
    double price;
    const char *title;
    int orderid;
    uint16_t prob_basis_point;
    uint32_t trader_id;
    bool active = true; // true = active market
    unsigned char side; // 0 yes, 1 no
};


