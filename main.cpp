#include "InfixCalculator.h"

int main()
{
  char ans;
  string expression;
  InfixCalculator<int> newInfCalc;

  cout <<"----------------------------------------------------------------";
  cout <<"\nWHEN ENTERING AN EXPRESSION" << endl;
  cout <<"Please separate the operand and operator with a whitespace ' '"<< endl;
  cout <<"For example:" << endl;
  cout <<"20 + 3 * 7" << endl;
  cout <<"88 * ( 41 - 51 )" << endl;
  cout << "200 * ( 12 + 6 ) / 7" << endl;
  cout <<"----------------------------------------------------------------\n\n";
  do
  {
    cout << "Enter expression: ";
    getline(cin, expression);
    newInfCalc.getResult(expression);

    cout <<"\n\n Do you want to try again? y/n ";
    cin >>ans;
    cin.ignore();
  }
  while(ans =='y'|| ans=='Y');

  return 0;
}