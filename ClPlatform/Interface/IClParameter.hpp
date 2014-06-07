#pragma once

class IClParameter {
public:
    virtual bool isCorrect(int) = 0;
    virtual set<int> getAllPosible() = 0;
};

