#pragma once

#include <vector>
#include <string>
#include <thread>
#include "Order.h" 
#include "save_bin_snap.h"

void periodic_save(std::vector<Order>& orderbook, const std::string& filepath, int interval_minutes);

