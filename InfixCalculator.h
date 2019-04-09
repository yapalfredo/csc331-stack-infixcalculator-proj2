#ifndef INFIXCALCULATOR_H
#define INFIXCALCULATOR_H

#include <stack>
#include <iostream>

using namespace std;

template <class T>
class InfixCalculator
{
  private:
    stack<T> values;
    stack<char> operators;
    T evaluateExpression(string);
  public:
    InfixCalculator(){};
    ~InfixCalculator(){};
    T doOperation(T, T, char);
    int getPrecedence(char);
    void getResult(string);
    string stringSeparator(string);
    string charToString(char);
};

#include "InfixCalculator.tpp"
#endif