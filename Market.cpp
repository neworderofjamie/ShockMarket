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

GrowthModel::GrowthModel(string initialState,
                    string hiddenModelName,
                    float initialTransitionTendency,
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
    return this->transitionTendency;
}

void GrowthModel::printLog()
{
    // print internal state
    std::cout << "State: " <<this->getState() << std::endl;
    // print transition properties
    std::cout << "T_tendency: " <<this->getTransitionTendency() << " || " ;
    std::cout << "ThF2S: " <<this->thFalling2Stagnation << " | ";
    std::cout << "ThS2G: " <<this->thStagnation2Growing << std::endl;
    // Distribution Properties
    // "Growth"
    distributionParams p = this->getEmissionProperty("G");
    std::cout << "Growth: " << " || ";
    std::cout << "Mean: " << p.mean << " | ";
    std::cout << "Var: " << p.variance << std::endl;
    // "Stagnation"
    p = this->getEmissionProperty("S");
    std::cout << "Stagnation: " <<" || ";
    std::cout << "Mean: " << p.mean << " | ";
    std::cout << "Var: " << p.variance << std::endl;
    // "Falling"
    p = this->getEmissionProperty("F");
    std::cout << "Falling: " <<" || ";
    std::cout << "Mean: " << p.mean << " | ";
    std::cout << "Var: " << p.variance << std::endl;
}