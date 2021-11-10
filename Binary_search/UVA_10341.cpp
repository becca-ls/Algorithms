#include <bits/stdc++.h>
using namespace std;

bool compare(double a, double b){
    if(abs(a-b)<0.001) return true;
    return false;
}

double p,q,r,s,t,u,x;
pair<double,double> mini, maxi;

double conta(double k){
    double a = p*exp(-k);
    double b = q*sin(k);
    double c = r*cos(k);
    double d = s*tan(k);
    double e = t*k*k + u;
    return (a+b+c+d+e);
}

double binary_search(){
    int ite=0;
    while(ite<200){
        x = (mini.second+maxi.second)/2;
        double conta_atual = conta(x);
        if(conta_atual==0) return x;
        else{
            if(conta_atual<0){
                mini.first = conta_atual;
                mini.second = x;
            }else{
                maxi.first = conta_atual;
                maxi.second = x;
            }
        }
        ite++;
    }
    return x;
}

double find(){
    double a = conta(0), b = conta(1);
    mini.first = min(a,b);
    if(compare(mini.first,a)){
        mini.second = 0;
        maxi.first = b;
        maxi.second = 1;
    }else {
        mini.second = 1;
        maxi.second = 0;
        maxi.first = a;
    }
    if(min(a,b)>0 || max(a,b)<0) return -1;
    x = binary_search();
    return x;
}

int main(){
    cout << setprecision(4) << fixed;
    while(cin>>p){
        cin >> q >> r >> s >> t >> u;
        x = find();
        if(x==-1) cout << "No solution" << endl;
        else cout << x << endl;
    }    
    return 0;
}
