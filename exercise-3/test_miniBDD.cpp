#include <iostream>

#include "miniBDD.h"

void test1()
{
  miniBDD_mgr mgr;

  BDD x=mgr.Var("x");
  BDD y=mgr.Var("y");
  BDD z=mgr.Var("z");
  BDD f=(x&y&z)|(!x&!y&z);
  y.clear();
  x.clear();
  z.clear();

  //mgr.DumpDot(std::cout);
  mgr.DumpTikZ(std::cout);
}

void test2()
{
  miniBDD_mgr mgr;
  
  BDD a=mgr.Var("a");
  BDD b=mgr.Var("b");
  BDD c=mgr.Var("c");
  BDD d=mgr.Var("d");
  
  BDD final=(a == b) & (c == d);  

  a.clear();
  b.clear();
  c.clear();
  d.clear();

  mgr.DumpTikZ(std::cout, true);
}

void test3()
{
  miniBDD_mgr mgr;
  
  BDD final=mgr.Var("x") & mgr.Var("y");

  mgr.DumpDot(std::cout);
  //mgr.DumpTikZ(std::cout);
  //mgr.DumpTable(std::cout);
}

void test4()
{
  miniBDD_mgr mgr;

BDD x2=mgr.Var("x2");
BDD x3=mgr.Var("x3");
BDD x1=mgr.Var("x1");
BDD x4=mgr.Var("x4");    
  
  BDD final=(x1 & x2 & x3) | (!x2 & x4) | (!x3 & x4);  

  x2.clear();
  x3.clear();
  x4.clear();
  x1.clear();

  mgr.DumpTikZ(std::cout, false);
  //mgr.DumpDot(std::cout);
}

void test5()
{
  miniBDD_mgr mgr;

BDD x0=mgr.Var("x0");
BDD x1=mgr.Var("x1");
BDD y0=mgr.Var("y0");
BDD y1=mgr.Var("y1");
BDD out0=mgr.Var("out0");        
BDD out1=mgr.Var("out1");        
BDD carry=mgr.Var("carry");        
  
//BDD final=(x0 | x1 | y0 | y1 | out0 | out1 | carry )
BDD final=((out1 | out0 | carry) == (x1 | x0 | y1 | y0));

  x0.clear();
  x1.clear();
  y0.clear();
  y1.clear();
  out0.clear();
  out1.clear();
  carry.clear();

  //mgr.DumpTikZ(std::cout, false);
  mgr.DumpDot(std::cout);
}

int main()
{
  test4();
}
