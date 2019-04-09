template <class T>
int InfixCalculator<T>::getPrecedence(char o)
{
  if(o == '+'||o == '-')
  {
    return 1; 
  } 
  if(o == '*'||o == '/') 
  {
    return 2;
  }
  return 0;
}

template <class T>
T InfixCalculator<T>::doOperation(T a, T b, char o)
{
  try
  {
    switch(o)
    { 
      case '+': return a + b; 
      case '-': return a - b; 
      case '*': return a * b; 
      case '/': return a / b; 
    } 
  }
  catch (const exception& e)
  {
    cout << e.what();
  }
    return 0;
}

template <class T>
T InfixCalculator<T>::evaluateExpression(string expression)
{

  int i; 
  for(i = 0; i < expression.length(); i++)
  {
    // Current expression is a whitespace, 
    // skip it. 
    if(expression[i] == ' ') 
    continue;
    // Current expression is an opening  
    // brace, push it to 'operators' 
    else if(expression[i] == '(')
    { 
      operators.push(expression[i]); 
    } 
    // Current expression is a number, push  
    // it to stack for numbers. 
    else if(isdigit(expression[i]))
    { 
      T val = 0; 
      // There may be more than one 
      // digits in number. 
      while(i < expression.length() &&  
            isdigit(expression[i])) 
      { 
        val = (val*10) + (expression[i]-'0'); 
        i++; 
      } 
      values.push(val); 
    } 
    // Closing brace encountered, solve  
    // entire brace. 
    else if(expression[i] == ')') 
    { 
      while(!operators.empty() && operators.top() != '(') 
      { 
        T val2 = values.top(); 
        values.pop(); 
          
        T val1 = values.top(); 
        values.pop(); 
          
        char op = operators.top(); 
        operators.pop(); 

        values.push(doOperation(val1, val2, op)); 
      } 
      // pop opening brace. 
      operators.pop(); 
    } 
    // Current expression is an operator. 
    else
    { 
      // While top of 'operators' has same or greater  
      // getgetPrecedence to current expression, which 
      // is an operator. Apply operator on top  
      // of 'operators' to top two elements in values stack. 
      while(!operators.empty() && getPrecedence(operators.top()) 
                >= getPrecedence(expression[i]))
      { 
        T val2 = values.top(); 
        values.pop(); 
          
        T val1 = values.top(); 
        values.pop(); 
          
        char op = operators.top(); 
        operators.pop(); 

        values.push(doOperation(val1, val2, op)); 
      } 
      // Push current expression to 'operators'. 
      operators.push(expression[i]); 
    } 
  }  
  // Entire expression has been parsed at this 
  // point, apply remaining operators to remaining 
  // values. 
  while(!operators.empty())
  { 
    T val2 = values.top(); 
    values.pop(); 
          
    T val1 = values.top(); 
    values.pop(); 
          
    char op = operators.top(); 
    operators.pop(); 
 
    values.push(doOperation(val1, val2, op)); 
  } 
    
  // Top of 'values' contains result, return it. 
  return values.top(); 
}

template <class T>
void InfixCalculator<T>::getResult(string expression)
{
  cout << evaluateExpression(stringSeparator(expression));
}

template <class T>
string InfixCalculator<T>::stringSeparator(string input)
{ 
  string finalInput="";
  int consecSpace = 0;
  bool prevChar = false;
  int position = 0;

  if (input == "") return input;    //if empty
  for (char& c : input)             //put a space before and after 
  {

      if (isspace(c) && position == 0) //ignore space at the beginning
      {
        continue;
      }

      else if(isdigit(c) && position == 0) //if first char is digit, mark prevChar true
      {
        prevChar = true;
        finalInput.append(charToString(c));
      }

      else if (isdigit(c) && prevChar==true && position > 0)     //if next char is still digit continue
      {
        prevChar = true;
        finalInput.append(charToString(c));
      }

      else if (isspace(c) && consecSpace==0) //if next char is space append
      {
        prevChar = false;
        consecSpace++;
        finalInput.append(charToString(c));
      }

      else if (isspace(c) && consecSpace > 0) //if next char is still space ignore
      {
        prevChar = false;
        consecSpace++;
        continue;
      }

      else if (isdigit(c) && prevChar==false && consecSpace > 0) //if next char is digit again
      {
        prevChar = true;
        consecSpace=0;
        finalInput.append(" ");
        finalInput.append(charToString(c));
      }

      else  if (c=='+'||c=='-'||c=='/'||c=='*' || c=='(' || c==')') //if operators
      {
        consecSpace=0;
        finalInput.append(" ");
        finalInput.append(charToString(c));
        finalInput.append(" ");
        prevChar = false;
      }

      if (position >=input.length()) break; // no space at the end
    }
    position++;

    return finalInput;
}

template <class T>
string  InfixCalculator<T>::charToString(char x)
{
  string s(1, x);
  return s;
}