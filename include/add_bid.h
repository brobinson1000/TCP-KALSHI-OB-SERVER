#pragma once

#include "Order.h"

void add_bid(double price, const char* title, int orderid, uint16_t prob_basis_point, uint32_t trader_id, bool active,
unsigned char side);
