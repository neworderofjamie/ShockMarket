#include "Market.h"

#define string std::string

GrowthModel::GrowthModel()
{
    // init hidden model params
    modelName = "Markov";
    transitionTendency = 0;
    distributionParams g = {.5f, 1.f, "Normal"};
    distributionParams s = {0.f, 1.f, "Normal"};
    distributionParams f = {-.5f, 1.f, "Normal"};
    
    // store emission distribution parameters for this instance
    emissionProperty.insert(std::pair<string,distributionParams>("G",g));
    emissionProperty.insert(std::pair<string,distributionParams>("S",s));
    emissionProperty.insert(std::pair<string,distributionParams>("F",f));  
    
    // set transition between states
    // [-1:-0.34] -> tendency towards "falling" state
        // [-0.33:0.33] -> tendency towards "stagnating" state
        // [0.34:1] -> tendeny towards "rising" state
    thFalling2Stagnation = -.34f;
    thStagnation2Growing = .33f;
    
    // set starting state
    state = "S";

}

GrowthModel::GrowthModel(string startState,
                    string hiddenModelName,
                    float initialTransitionTendency,
                    string initialState,
                    distributionParams f,
                    distributionParams s,
                    distributionParams g,
                    float thF2S,
                    float thS2G)
{
    // init hidden model params
    modelName = hiddenModelName;
    transitionTendency = initialTransitionTendency;
    // store emission distribution parameters for this instance
    emissionProperty.insert(std::pair<string,distributionParams>("G",g));
    emissionProperty.insert(std::pair<string,distributionParams>("S",s));
    emissionProperty.insert(std::pair<string,distributionParams>("F",f));  
    
    // set transition between states
    thFalling2Stagnation = thF2S;
    thStagnation2Growing = thS2G;
    
    // set starting state
    state = initialState;


    
}

distributionParams GrowthModel::getEmissionProperty(string state)
{

    return this->emissionProperty[state];
}
        
void GrowthModel::update(marketEvent event)
{
    this->transitionTendency = this->transitionTendency+event.influence; 
}

/*
GETTER/SETTER
*/

string GrowthModel::getState()
{
    return this->state;
}

float GrowthModel::getTransitionTendency()
{
    return this->transitionTendency
}