#include "Market.h"

#define string std::string

GrowthModel::GrowthModel()
{
    state = "Hallo";
}

GrowthModel::GrowthModel(string startState)
{
    state = startState;
}

string GrowthModel::getState()
{
    return this->state;
}
        

