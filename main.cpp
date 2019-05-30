//Kure Dominykas Rakunas :D
#include <bits/stdc++.h>

using namespace std;

int findBiggest(int * logoBalai);

int main()
{
    fstream in("U1.txt");
    ofstream out("U1rez.txt");
    int rows;
    in>>rows;
    int balai[rows][3]; //laikini balai
    int direktoriausBalai[3];
    int logoBalai[4] = {0}; // visi balai
    int logoTaskai[4] = {0}; // papildomi taskai

    for(int i = 0; i<rows; i++){
        in>>balai[i][1];
        in>>balai[i][2];
        in>>balai[i][3];
        if(balai[i][1]>balai[i][2] && balai[i][1]>balai[i][3]){ // tikrina skirti 4,2 ar 0 tasku
            logoBalai[1] += 4;
            logoTaskai[1] += 4;
            logoBalai[1] += balai[i][1]; // prie to pacio ir sumuoja galutini rezultata
            logoBalai[2] += balai[i][2];
            logoBalai[3] += balai[i][3];
        }else if(balai[i][2]>balai[i][1] && balai[i][2]>balai[i][3]){
            logoBalai[2] += 4;
            logoTaskai[2] += 4;
            logoBalai[1] += balai[i][1];
            logoBalai[2] += balai[i][2];
            logoBalai[3] += balai[i][3];
        }else if(balai[i][3]>balai[i][1] && balai[i][3]>balai[i][2]){
            logoBalai[3] += 4;
            logoTaskai[3] += 4;
            logoBalai[1] += balai[i][1];
            logoBalai[2] += balai[i][2];
            logoBalai[3] += balai[i][3];
        }else if(balai[i][1]==balai[i][2]){
            logoBalai[1] += 2;
            logoTaskai[1] += 2;
            logoBalai[2] += 2;
            logoTaskai[2] += 2;
            logoBalai[1] += balai[i][1];
            logoBalai[2] += balai[i][2];
            logoBalai[3] += balai[i][3];
        }else if(balai[i][1] == balai[i][3]){
            logoBalai[1] += 2;
            logoTaskai[1] += 2;
            logoBalai[3] += 2;
            logoTaskai[3] += 2;
            logoBalai[1] += balai[i][1];
            logoBalai[2] += balai[i][2];
            logoBalai[3] += balai[i][3];
        }else if(balai[i][2] == balai[i][3]){
            logoBalai[2] += 2;
            logoTaskai[2] += 2;
            logoBalai[3] += 2;
            logoTaskai[3] += 2;
            logoBalai[1] += balai[i][1];
            logoBalai[2] += balai[i][2];
            logoBalai[3] += balai[i][3];
        }else{
            logoBalai[1] += balai[i][1];
            logoBalai[2] += balai[i][2];
            logoBalai[3] += balai[i][3];
        }
    }

    in>>direktoriausBalai[1];
    in>>direktoriausBalai[2];
    in>>direktoriausBalai[3];

    if(logoBalai[1]==logoBalai[2] || logoBalai[1] == logoBalai[3] || logoBalai[2] == logoBalai[3]){  //Tikrina ar yra lygus rezultatas
        logoBalai[1] += direktoriausBalai[1]; //jei taip tai prideda direktoriaus taskus
        logoBalai[2] += direktoriausBalai[2];
        logoBalai[3] += direktoriausBalai[3];
    }

    out<<logoBalai[1]-logoTaskai[1]<<" "<<logoBalai[2]-logoTaskai[2]<<" "<<logoBalai[3]-logoTaskai[3]<<endl; // isvedimas
    out<<logoTaskai[1]<<" "<<logoTaskai[2]<<" "<<logoTaskai[3]<<endl;
    out<<findBiggest(logoBalai);
    return 0;
}

int findBiggest(int * logoBalai){
    if(logoBalai[1]>logoBalai[2] && logoBalai[1]>logoBalai[3]){ // iesko didziausios reiksmes
            return 1;
    }else if(logoBalai[2]>logoBalai[1] && logoBalai[2]>logoBalai[3]){
            return 2;
    }else{
            return 3;
    }
}





