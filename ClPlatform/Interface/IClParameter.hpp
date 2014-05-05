#ifndef ICLPARAMETER_HPP
#define ICLPARAMETER_HPP

class IClParameter {
public:
    virtual bool isCorrect(int) = 0;
    virtual set<int> getAllPosible() = 0;
};

#endif // ICLPARAMETER_HPP
