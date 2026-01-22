#include <iostream>
#include <vector>
#include <climits>
#include <cstdint>
#include <fstream>
#include <string>


struct order{
    double price;
    const char *title;
    int orderid; //4
    uint16_t prob_basis_point;
    uint32_t trader_id;
    bool active = true; // true = active market
    unsigned char side; // 0 yes 1 no
};

struct TradeEvent {
    uint64_t trade_id;
    uint32_t trader_id;
    uint32_t qty = 0;
    uint64_t timestamp_ns;
};


std::vector<order> orderbook;

//orderbook.reserve(1000);

void add_bid(double price, const char *title,int orderid, uint16_t prob_basis_point ,uint32_t trader_id,bool active, unsigned char side) {
    order newOrder;
    newOrder.orderid = orderid;
    newOrder.title = title;
    newOrder.price = price;
    newOrder.prob_basis_point = prob_basis_point;
    newOrder.trader_id = trader_id;
    newOrder.active = active;
    newOrder.side = side;

    orderbook.push_back(newOrder);
};


void resolve_bid(int id, bool win) {
    for ( auto &bet : orderbook ) {
        if ( bet.orderid == id ) {
            bet.active = false;
        }
    }
};

void print_orderbook(const std::vector<order> &orderbook) {
    for (const auto &order : orderbook) {
        std::cout << order.orderid << "\t" << order.trader_id << "\t" << order.price << "\t" << order.prob_basis_point
        << "\t" << order.active << "\t" << order.side << "\n";
    }
};


void save_bin_snap(const std::vector<order> &orderbook,const std::string& filepath) {
    std::ofstream out(filepath, std::ios::binary | std::ios::trunc);

    uint64_t count = orderbook.size();

    out.write(reinterpret_cast<const char*>(&count), sizeof(count));
    out.write(reinterpret_cast<const char*>(orderbook.data()), count * sizeof(order));

    out.close();
};

    
void replay_bin_snap(const std::string& filepath){
    
    std::ifstream in("ob.txt", std::ios::binary);


    uint64_t count = 0;

    in.read(reinterpret_cast<char*>(&count), sizeof(count));

    std::vector<order> orderbook(count);

    in.read(reinterpret_cast<char*>(orderbook.data()), count * sizeof(order));

    /* 
    -Testing output of regular contents that are debin
    */



    for (auto &ord : orderbook) {
        orderbook.push_back(ord);
    }
    

    in.close();


};




int main() {

    add_bid(90.45, "braves", 1,23, 123, true, 0);
    resolve_bid(1, false);
    add_bid(90.45, "braves", 2,23, 123, true, 0);
    add_bid(90.45, "marlin", 3,23, 123, true, 0);
    add_bid(90.45, "cubs", 4,23, 123, true, 0);
    add_bid(90.45, "braves", 5,23, 123, true, 0);

    save_bin_snap(orderbook, "ob.txt");

    replay_bin_snap("ob.txt");  
  
    print_orderbook(orderbook);

};


