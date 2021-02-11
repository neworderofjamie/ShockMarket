#include "Market.h"

int main()
{
    string startState = "S";
    string hiddenModelName = "Markov";
    float initialTransitionTendency = 0.f;
    distributionParams f{-1,1,"Normal"};
    distributionParams s{0,1,"Normal"};
    distributionParams g{1,1,"Normal"};
    float thF2S = -.33f;
    float thS2G = .33f;

    GrowthModel gM(startState,
                   hiddenModelName,
                   initialTransitionTendency,
                   f,
                   s,
                   g,
                   thF2S,
                   thS2G);
    
    gM.printLog();
}

