#pragma once

#include <functional>
#include <vector>
#include <set>

class Function;
using FunctionVector = std::vector<Function>;
using DoubleVector = std::vector<double>;
using IndexesSet = std::set<size_t>;

class Function {
public:
  enum Type {
    Variable = 0,
    Constant,
    Summation,
    Multiplication,
    Negate,
    Absolute,
    SquareRoot,
    Power,
  };

  using EvalFunction = std::function<double(const DoubleVector&, const FunctionVector&)>;
  using DeriveFunction = std::function<double(size_t, const DoubleVector&, const FunctionVector&)>;

  Function(double iValue);
  Function(size_t iInd);
  double Eval(const DoubleVector& iVars) const;
  DoubleVector Derive(const DoubleVector& iVars) const;

  friend Function operator+(Function iLsh, Function iRsh);
  friend Function operator-(Function iLsh, Function iRsh);
  friend Function operator*(Function iLsh, Function iRsh);
  friend Function operator/(Function iLsh, Function iRsh);

  friend Function operator-(Function iArg);

  friend Function Abs(Function iArg);
  friend Function Sqrt(Function iArg);
  friend Function Pow(Function iArg, double iDegree);



  const Type type;

private:
  Function(EvalFunction iEvalFunc, DeriveFunction iDeriveFunc, Type iType, FunctionVector iArgs = FunctionVector());
  double DeriveByIndVar(size_t iIndex, const DoubleVector& iVars) const;

  EvalFunction _evalFunc;
  DeriveFunction _deriveFunc;
  FunctionVector _arguments;
  IndexesSet _dependentIndexes;
};