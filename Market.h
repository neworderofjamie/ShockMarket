#include <iostream>
#include <iomanip>   
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

struct marketEvent 
{
    string name;
    float influence;
};

class GrowthModel
{
    public:
        // constructors, TODO add constructor that loads from JSON file
        GrowthModel();
        GrowthModel(string initialState,
                    string hiddenModelName,
                    float initialTransitionTendency,
                    distributionParams f,
                    distributionParams s,
                    distributionParams g,
                    float thF2S,
                    float thS2G);
        // getter
        string getState();
        float getTransitionTendency();
        float getGrowthRate();
        distributionParams getEmissionProperty(string state);
        
        
        // update function to use to feed events into the growth model and advance it
        void update();
        void update(marketEvent event);

        // log function
        void printLog();

    private:
        // identifier for the state the model is in "G", "S" or "F"
        string state;
        // name of the underlyinng model
        string modelName;
        // Map mapping the State to the relevant distribution info
        std::map<string,distributionParams> emissionProperty; 
        // value between zero and [-1,1] inidcating the tendency to change states
        // [-1:-0.34] -> tendency towards "falling" state
        // [-0.33:0.33] -> tendency towards "stagnating" state
        // [0.34:1] -> tendeny towards "rising" state
        float thFalling2Stagnation;
        float thStagnation2Growing;
        
        
        float transitionTendency;
    
};
