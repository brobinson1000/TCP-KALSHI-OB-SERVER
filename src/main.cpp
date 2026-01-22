#include <iostream>
#include <vector>
#include <climits>
#include <cstdint>
#include <fstream>
#include <string>


struct Order{
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


static std::vector<Order> orderbook;


void add_bid(double price, const char *title,int orderid, uint16_t prob_basis_point ,uint32_t trader_id,bool active, unsigned char side) {
    Order new_order;
    new_order.orderid = orderid;
    new_order.title = title;
    new_order.price = price;
    new_order.prob_basis_point = prob_basis_point;
    new_order.trader_id = trader_id;
    new_order.active = active;
    new_order.side = side;

    orderbook.push_back(new_order);
};


void resolve_bid(int id, bool win) {
    for ( auto &bet : orderbook ) {
        if ( bet.orderid == id ) {
            bet.active = false;
        }
    }
};

void print_orderbook(const std::vector<Order> &orderbook) {

    const char* green = "\033[32m";
    const char* red = "\033[31m";
    const char* reset = "\033[0m";

    for (const auto &order : orderbook) {

        if (order.active == true) {
            std::cout << green <<" | " << order.orderid << "\t" << " | " << order.trader_id << "\t" << " | " <<
            order.price << "\t" << " | " << order.prob_basis_point << "\t" << " | " << order.side << "\t" << " | " <<
            std::boolalpha << order.active << "\n" << reset;
        } else {
            std::cout << red << " | " << order.orderid << "\t" << " | " << order.trader_id << "\t" << " | " <<
            order.price << "\t"<< " | " << order.prob_basis_point << "\t" << " | " << order.side << "\t" << " | " <<
            std::boolalpha << order.active << "\n" << reset;
        }
    }
};


void save_bin_snap(const std::vector<Order> &orderbook,const std::string& filepath) {
    std::ofstream out(filepath, std::ios::binary | std::ios::trunc);

    uint64_t count = orderbook.size();

    out.write(reinterpret_cast<const char*>(&count), sizeof(count));
    out.write(reinterpret_cast<const char*>(orderbook.data()), count * sizeof(Order));

    out.close();
};

    
void replay_bin_snap(){
    
    std::ifstream in("ob.txt", std::ios::binary);


    uint64_t count = 0;

    in.read(reinterpret_cast<char*>(&count), sizeof(count));

    std::vector<Order> orderbook(count);

    in.read(reinterpret_cast<char*>(orderbook.data()), count * sizeof(Order));

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

    replay_bin_snap();  
  
    print_orderbook(orderbook);

};


