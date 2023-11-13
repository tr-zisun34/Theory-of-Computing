#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int a, b;
int m = 0, n;
string smbl;

//checking if the state is declared as state before or not
bool checkValid(string states[], string state){
    for(int i=0; i<n; i++){
        if(states[i]==state){
            return true;
        }
    }
    return false;
}

// removing duplicate values from the string that made inside addNewState() function
string removeduplicate(string str, int n){
   int index=0;
   for (int i=0;i<n;i++){
        int j;
        for(j=0;j<i;j++){
            if(str[i]==str[j]){
               break;
            }
        }
        if(j==i){
            str[index++]=str[i];
        }
   }
   return str.substr(0, index);
}

//adding new state to the dfa that not been included before
string addNewState(string transitionDFA[][2], string state, int i){

    string indxToAdd;
    for(int j=0; j<state.size(); j++){
        indxToAdd = indxToAdd.append(transitionDFA[j][i]);
    }
    indxToAdd = removeduplicate(indxToAdd, indxToAdd.size());
    
    return indxToAdd;
}


int main(){  

    //taking general infos
    cout << "Enter the number of states of NFA : " << endl;
    cin >> a;
    n = a;
    cout << "Enter the number of symbols of NFA : " << endl;
    cin >> b;
    cout << "Enter the symbols of NFA : " << endl;
    cin >> smbl;

    string transitionNFA[a][b];
    string transitionDFA[20][2];
    string states[20];

    //reading transition table of NFA from File
    fstream file;
    file.open("nfa2dfa.txt", ios::in);
    if(file.is_open()){
        for(int i=0; i<a; i++){
            for(int j=0; j<b; j++){
                getline(file, transitionNFA[i][j]);
                transitionDFA[i][j] = transitionNFA[i][j];
            }
            states[i] = i + '0';
        }
        file.close();
    }

    //finding and adding the states that not been added before in the DFA
    for(int i=0; i<n; i++){
        for(int j=0; j<b; j++){
            if(!checkValid(states, transitionDFA[i][j])){
                for(int k=0; k<b; k++){
                    states[n] = transitionDFA[i][j];
                    transitionDFA[n][k] = addNewState(transitionDFA, transitionDFA[i][j], k);
                }
                n++;
            }
        }
    }

    //Printing DFA
    cout << "\nDFA's transition function is -\n\n";
    for(int i=0; i<n; i++){
        cout << states[i] << "\t";
        for(int j=0; j<b; j++){
            cout << transitionDFA[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}