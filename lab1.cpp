#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
using namespace std;

srand(time(NULL));

bool in_circle(double& x,double& y){
   if ( sqrt( pow(*x,2) + pow(*x,2) ) < 1) return true;
   else return flase;
}


double estimate_pi(const int& n){
   int x = 0;
   int y = 0;
   in = 0;
   out = 0;
   for(int i = 0; i  < *n; i ++){
     x = rand();
     y = rand();
     x = x / RAND_MAX;
     y = x / RAND_MAX;
     if (in_circle(&x,&y))  in+=1;

     return (in / *n) * 4;
   }
}
double estimate_tri_pi(const int& n){
   int x = 0;
   int y = 0;
   in = 0;
   out = 0;
   for(int i = 0; i  < *n; i ++){
     x = rand();
     y = rand();
     x = x / RAND_MAX;
     y = x / RAND_MAX;
     while( y+x < 1){
       x = rand();
       y = rand();
       x = x / RAND_MAX;
       y = x / RAND_MAX;
     }
     if (in_circle(&x,&y))  in+=1;

     return ((in / *n) * 2) + 2;
   }
}

vector<double>* pi_sequence(const int&){
  vector<double> * v;
  int pi =0;
  for(int i = 1; i < 2001; i++){
    pi=estimates(i);
    v->push_back(pi);
  }
  return v;
}
vector<double>* pi_sequence(const int&){
  vector<double> * v;
  int pi =0;
  for(int i = 1; i < 2001; i++){
    pi=estimates(i);
    v->push_back(pi);
  }
  return v;
}



int int main(int argc, char const *argv[]) {
  double pi = 0;
  double dif = 0
  for(int i = 1; i < 9; i++){
    cout << setw(10) << "N" <<
        setw(10) << "Estimates" <<
        setw(10) << "Difference" <<
        setw(10) <<'\n';
    pi = estimate_pi(&i);
    dif = abs(pi - M_PI);
    cout << setw(10) << i <<
        setw(10) << pi <<
        setw(10) << dif <<
        setw(10) <<'\n';
    i=i*10;
  }
  return 0;
}
