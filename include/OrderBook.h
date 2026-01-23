#pragma once

#include <string>
#include <vector>
#include "Order.h"

extern std::vector<Order> orderbook; // Global order book vector

// Function declarations
void add_bid(double price, const char* title, int orderid, uint16_t prob_basis_point, uint32_t trader_id, bool active, unsigned char side);
void resolve_bid(int id, bool win);
void print_orderbook(const std::vector<Order>& orderbook);
void save_bin_snap(const std::vector<Order>& orderbook, const std::string& filepath);
void replay_bin_snap(std::vector<Order>& orderbook, const std::string& filepath);


