#include <iostream>
#include "Market.h"

int main()
{
    string s = "Gdasdkasoprowing";
    GrowthModel gM;
    std::cout << gM.getState() << std::endl;

    distributionParams p = gM.getEmissionProperty("G");
    
    std::cout << "Mean: " << p.mean << std::endl;
    std::cout << "Var: " << p.variance << std::endl;

    
}

