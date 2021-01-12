#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int gcd(int a,int h) {
    int temp;
    while(1){   temp = a%h; 
                if(temp==0) return h; 
                a=h; h=temp; 
            }
}

/* RSA logic */
double P = 2, Q = 7;
vector<double> encrypt(vector<double> message){    
    double N = P*Q;
    double Phi = (P-1)*(Q-1);
    double e = 2;
    while(e<Phi){
        if(gcd(e,Phi)==1)break;
        else e++;
    }
    
    vector<double> ret;
    for(int i=0; i<message.size(); i++){
        /* pow() result can be more than 32bit or 64bit number
         implement this number as a linkedlist ?    */ 
        double num = pow(message[i],e); 
        num = fmod(num,N);
        ret.push_back(num);      
    }
    return ret;
}
vector<double> decrypt(vector<double> message){
    double N = P*Q;
    double Phi = (P-1)*(Q-1);
    double e = 2;
    while(e<Phi){
        if(gcd(e,Phi)==1)break;
        else e++;
    }
    int k = 2;
    double d = (1+(k*Phi))/e; /* This calculation is getting WRONG */
    d = 11; // TEST CHANGE LATER

    vector<double> ret;
    for(int i=0; i<message.size(); i++){
        double num = pow(message[i],d); 
        num = fmod(num,N);
        ret.push_back(num);      
    }
    return ret;
}

int main(){

    cout<<"message size\n";   
    int N;  
    cin>>N;
    cout<<"message\n";    
    vector<double> message;    
    for(int i=0; i<N; i++){ 
        double temp; 
        cin>>temp; 
        message.push_back(temp); 
    }

    vector<double> secret = encrypt(message);
    for(int i=0; i<secret.size(); i++) 
        cout<<secret[i]<<" ";    
    cout<<"\n";

    vector<double> ret = decrypt(secret);
    for(int i=0; i<ret.size(); i++) 
        cout<<ret[i]<<" ";
    cout<<"\n";

    return 0;
}
