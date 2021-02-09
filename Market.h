#include <iostream>
#include <string>
#include "./Eigen/Core"
#include <random>
#include <map>

#define string std::string

// struct to contain necessary info about the distribution
struct distributionParams
{
    float mean;
    float variance;
    string distName;
};

class GrowthModel
{
    public:
        GrowthModel();
        GrowthModel(string startState);
        GrowthModel(string startState, std::map<string,distributionParams> emissionProperty);
        string getState();
        distributionParams getEmissionProperty(string state);
        float getEmission();
    private:
        // identifier for the state the model is in "G", "S" or "F"
        string state;
        // Map mapping the State to the relevant distribution info
        std::map<string,distributionParams> emissionProperty; 
        // value between zero and [-1,1] inidcating the tendency to change states
        // [-1:-0.34] -> tendency towards "falling" state
        // [-0.33:0.33] -> tendency towards "stagnating" state
        // [0.34:1] -> tendeny towards "rising" state
        float transitionTendency;
    
};
