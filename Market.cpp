#include "Market.h"

#define string std::string

GrowthModel::GrowthModel()
{
    state = "G";
    transitionTendency = 0;
    distributionParams g = {0.f, 1.f, "Normal"};
    emissionProperty.insert(std::pair<string,distributionParams>("G",g));  
}

GrowthModel::GrowthModel(string startState)
{
    state = startState;
    
}

string GrowthModel::getState()
{
    return this->state;
}

distributionParams GrowthModel::getEmissionProperty(string state)
{

    return this->emissionProperty[state];
}
        

