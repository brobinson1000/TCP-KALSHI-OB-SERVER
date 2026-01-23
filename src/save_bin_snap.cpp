#include "save_bin_snap.h"
#include <fstream>

void save_bin_snap(const std::vector<Order>& orderbook, const std::string& filepath) {
    std::ofstream out(filepath, std::ios::binary | std::ios::trunc);

    uint64_t count = orderbook.size();
    out.write(reinterpret_cast<const char*>(&count), sizeof(count));
    out.write(reinterpret_cast<const char*>(orderbook.data()), count * sizeof(Order));
    out.close();
}

