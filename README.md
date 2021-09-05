# AutoDiff

My experiments in creating auto-differentiable functions on C++.

This functions provides API which allow to apply arithmetic operators on this functions to create a new function. Any fuction provide caculation of derivative by any variable by index.

Some example:
```C++
Function a(0), b(1), c(2);

Function equation = a * a + b * b + c * c - 1.0;
std::vector<double> variables = {1, 2, 3};

double value = eqution.Eval(variables);
std::vector<double> derivatives = equation.Derive(variables);
```
