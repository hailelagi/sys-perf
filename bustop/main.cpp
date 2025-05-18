#include <iostream>
#include "lib.h"

int main() {
    //  saturation, error metrics
    /*
   bustop alias `bu`
    buses       cpu    load average
    KB/t  tps  MB/s  us sy id   1m   5m   15m
   15.53  714 10.83  16 10 74  5.99 5.90 5.27
    */
    std::cout << "A top/iostat like tool that shows physical bus or interconnect utilization" << std::endl;
    return 0;
}
