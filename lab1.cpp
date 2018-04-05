#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <time.h>
#include <iomanip>      // std::setw
#include <fstream>
using namespace std;



bool in_circle(double& x,double& y){
   if ( sqrt( pow(x,2) + pow(y,2) ) < 1) return true; // checking if its inside the circle by checking if the radious of the points less than 1
   else return false;
}


double estimate_pi(const int& n){ // estimating pi by getting random numbers between 1 and 0
  srand(time(NULL));
   double x = 0;
   double y = 0;
   double in = 0;
   double out = 0;
   for(int i = 0; i  < n; i ++){ // getting n random numbers
     x = rand();
     y = rand();
     x = x / RAND_MAX;
     y = y / RAND_MAX;
     if (in_circle(x,y)){ in+=1; }
     else{out+=1;}
   }
   double result = (in / (in+out)) * 4; // using the formula (totals inside the circle / total points ) * 4 to get pi
   return result;
}
double estimate_tri_pi(const int& n){ // estimating pi by getting ramdom number using the triangle method
   srand(time(NULL));
   double x = 0;
   double y = 0;
   double in = 0;
   double out = 0;
   for(int i = 0; i  < n; i ++){ // get n random numbers
     x = rand();
     y = rand();
     x = x / RAND_MAX;
     y = x / RAND_MAX;
     while( (y+x) < 1){ // if it's not in the triangle then keep getting random numbers untill you get one inside the triangle
       x = rand();
       y = rand();
       x = x / RAND_MAX;
       y = y / RAND_MAX;
     }
     if (in_circle(x,y))  {in+=1;} // check if its in the lens
     else{out+=1;}
   }
     return ((in / (out+in)) * 2) + 2; // using the formula total inside the cirucl /(total inside trinagle) * 2 + 2 to get pi
}

vector<double>* pi_sequence(const int&n){ // get n estimations of pi. if n is 10 it gets estimations of pi from 1 random point to 10 random points
  vector<double> * v= new vector<double>(n);
  double pi =0;
  for(int i = 0; i < n; i++){
    pi=estimate_pi(i+1);
    v->at(i) = pi;
  }
  return v;
}
vector<double>* new_pi_sequence(const int& n){ // get n estimations of pi. if n is 10 it gets estimations of pi from 1 random point to 10 random points using the trinagle
  vector<double> * v= new vector<double>(n);
  double pi =0;
  for(int i = 0; i < n; i++){
    pi=estimate_tri_pi(i+1);
    v->at(i) = pi;
  }
  return v;
}

int main(int argc, char const *argv[]) {
  double pi = 0;
  double dif = 0;
  int limit= 10000000;
  cout << setw(20) << "N" <<
      setw(20) << "Estimates" <<
      setw(20) << "Difference" <<
      setw(20) <<'\n';
  for(int i = 1; i <= limit;i=i*10){ // getting the estimations the Difference off pie and the estimation
    pi = estimate_pi(i);
    dif = abs(pi - M_PI);
    cout << setw(20) << i <<
        setw(20) << pi <<
        setw(20) << dif <<
        setw(20) <<'\n';
  }
cout << "The approximation using the triangle and the lens \n";
cout << setw(20) << "N" <<
    setw(20) << "Estimates" <<
    setw(20) << "Difference" <<
    setw(20) <<'\n';
for(int i = 1; i <= limit;i=i*10){ // getting the estimations the Difference off pie and the estimation with the trinagle method
  pi = estimate_tri_pi(i);
  dif = abs(pi - M_PI);
  cout << setw(20) << i <<
      setw(20) << pi <<
      setw(20) << dif <<
      setw(20) <<'\n';
}
  // getting 6 pi sequence to plot  6 sequences with the triangle method
  vector<vector<double> *>v;
  vector<double> *v1 = new_pi_sequence(2000);
  v.push_back(v1);
  vector<double> *v2 = new_pi_sequence(2000);
  v.push_back(v2);
  vector<double> *v3 = new_pi_sequence(2000);
  v.push_back(v3);
  vector<double> *v4 = new_pi_sequence(2000);
  v.push_back(v4);
  vector<double> *v5 = new_pi_sequence(2000);
  v.push_back(v5);
  vector<double> *v6 = new_pi_sequence(2000);
  v.push_back(v6);
  vector<double> *v7 =  pi_sequence(2000);
  v.push_back(v7);
  vector<double> *v8 =  pi_sequence(2000);
  v.push_back(v8);
  vector<double> *v9 =  pi_sequence(2000);
  v.push_back(v9);
  vector<double> *v10 = pi_sequence(2000);
  v.push_back(v10);
  vector<double> *v11 = pi_sequence(2000);
  v.push_back(v11);
  vector<double> *v12 = pi_sequence(2000);
  v.push_back(v12);
  // putting the sequences into a file to plot them
  ofstream file;
  file.open("data.txt");
  for(int i = 0; i < v.size();i++){
     vector<double> *temp = v.at(i);
     for(int j = 0; j < temp->size();j++){
       file << temp->at(j);
       file << ",";
     }
     file << "\n";
     file << "\n";
  }


  return 0;
}
