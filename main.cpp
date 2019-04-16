#include<iostream>
#include<list>
#include<queue>
#include <cstdlib>
#include <stack>

using namespace std;
stack<char> ph;
list<char> w;

void verifica(char x){
    int aux = 0;
//    cout<<"x = "<<x<<endl;
//    cout<<"ph topper = "<<ph.top()<<endl;
    if (ph.top() == '(' && x!=')'){
//        ph.push(x);
//        return;
        aux = 1;
    }
    if (x == '('){
            ph.push(x);
            return;
//        aux = 1;
    }
    if(ph.top() == '(' && x==')'){
        ph.pop();
        return;
    }
    while(!ph.empty() && ph.top()!='(') {

         if (x == ')') {
            while (ph.top() != '(') {
                w.push_back(ph.top());
                ph.pop();
            }
            ph.pop();
            return;
        }
        else if ((ph.top() == '+' || ph.top() == '-') && (x == '+' || x == '-')) {
            w.push_back(ph.top());
            ph.pop();
//            ph.push(x);
            aux=1;
        }
        else if ((ph.top() == '+' || ph.top() == '-') && (x != '+' || x != '-')){
//            ph.push(x);
//            return;
            aux=1;
            break;
        }

        else if ((ph.top() == '/' || ph.top() == '*') && x != '^') {
            w.push_back(ph.top());
            ph.pop();
//            ph.push(x);
            aux=1;
        }
        else if ((ph.top() == '/' || ph.top() == '*') && x == '^'){
//            ph.push(x);
//            return;
            aux = 1;
            break;
        }

        else if (ph.top() == '^') {
//            cout<<"entrou aqui"<<endl;
            w.push_back(ph.top());
            ph.pop();
//            ph.push(x);
            aux = 1;
//            if(!ph.empty())cout<<"ph "<<ph.top()<<endl;
        }
//        if(!ph.empty())cout<<ph.top()<<endl;
    }

    if(aux == 1) ph.push(x);
    return;
}

int main()
{
    int t;

    string x;
    cin>>t;
    for(int i = 0; i<t; i++){
        cin>>x;
        for(int j = 0; j<x.size();j++){
//            cout<<"x valendo = "<<x[j]<<endl;
            if((x[j] >= '(' && x[j] <='/') || x[j] == '^'){
                if(ph.empty()){

                    ph.push(x[j]);
                }
                else{
//                    cout<<"entrou "<<x[j]<<endl;
                    verifica(x[j]);
                }
            }
            else{
                w.push_back(x[j]);
            }
        }
        while(!ph.empty()){
            w.push_back(ph.top());
            ph.pop();
        }
        while(!w.empty()){
            cout<<w.front();
            w.pop_front();
        }
        cout<<endl;

    }
    return 0;
}
