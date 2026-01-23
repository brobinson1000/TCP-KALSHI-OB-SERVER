#include "replay_bin_snap.h"
#include <fstream>

void replay_bin_snap(std::vector<Order>& orderbook, const std::string& filepath) {
    std::ifstream in(filepath, std::ios::binary);

    uint64_t count = 0;
    in.read(reinterpret_cast<char*>(&count), sizeof(count));

    orderbook.resize(count);
    in.read(reinterpret_cast<char*>(orderbook.data()), count * sizeof(Order));
    in.close();
}

