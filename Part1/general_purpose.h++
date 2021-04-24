#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <iostream>

class GeneralPurpose{
public:
    float mean(std::vector<float> input);

    float median(std::vector<float> input);

    float range(std::vector<float> input);

    float variance(std::vector<float> input);

    float sqr(float input);
};