#include "InfixCalculator.h"
#include "string"

int main()
{
  char ans;
  string expression;
  InfixCalculator<int> newInfCalc;

  cout <<"----------------------------------------------------------------" <<endl;

  cout <<"P L E A S E   E N T E R   A N   E X P R E S S I O N"<< endl;

  cout <<"----------------------------------------------------------------\n\n";
  do
  {
    cout << "Enter expression: ";
    getline(cin, expression);
    try
    {
      newInfCalc.getResult(expression);
    } catch (const exception& e)
    {
      cout << "0";
    }

    cout <<"\n\n Do you want to try again? y/n ";
    cin >>ans;
    cin.ignore();
  }
  while(ans =='y'|| ans=='Y');

  return 0;
}