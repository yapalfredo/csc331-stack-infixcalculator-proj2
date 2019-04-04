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
  switch(o){ 
      case '+': return a + b; 
      case '-': return a - b; 
      case '*': return a * b; 
      case '/': return a / b; 
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
  cout << evaluateExpression(expression);
}