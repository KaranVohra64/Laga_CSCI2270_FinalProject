#include <iostream>
#include <fstream>
#include <string>

#include "BinaryTree.h"


using namespace std;

int main(){

    string command;
    string strLine;
    ifstream inFile;
    string data[12];
    string delimiter = ",";

    inFile.open("PokemonList.txt");

    if(inFile.fail()){
        cout<<"The file was not successfully opened"<<endl;
    }else{
        PokeTree pokeList;
        getline(inFile, strLine);
        while(!inFile.eof()){
            getline(inFile, strLine);
            for(int j = 0; j < 12; j++){
                data[j] = strLine.substr(0, strLine.find(delimiter));
                strLine.erase(0, strLine.find(delimiter) + delimiter.length());
            }

            pokeList.addPokeNode(atoi(data[0].c_str()),data[1],atoi(data[3].c_str()),atoi(data[4].c_str())
                                ,data[6],data[7],data[8],data[9],data[10],data[11]);
        }

        inFile.close();

        cout<<"Welcome to the Pokedex! This Pokedex contains the \noriginal 150 Pokemon from Pokemon Red and Blue."<<endl;
        cout<<"This Pokedex contains information about index, name, \nheight, weight, type, ability, and evolutions."<<endl;
        cout<<"The height is listed in centimeters and the weight \nis listed in hectograms (divide by 10 to get kg)."<<endl;
        cout<<"Please type everything using lowercase letters or numbers where applicable.\n\n"<<endl;

        while(command != "11"){
            cout<<"======Main Menu====="<<endl;
            cout<<"1. Search for Pokemon"<<endl;
            cout<<"2. Print Pokedex"<<endl;
            cout<<"3. Remove Pokemon"<<endl;
            cout<<"4. Count Pokemon"<<endl;
            cout<<"5. Search for type"<<endl;
            cout<<"6. Search for ability"<<endl;
            cout<<"7. Add Pokemon"<<endl;
            cout<<"8. List Pokemon types"<<endl;
            cout<<"9. List Pokemon abilities"<<endl;
            cout<<"10. Pokemon Counters"<<endl;
            cout<<"11. Quit"<<endl;
            getline(cin,command);
            if(command == "1"){
                string name;
                cout<<"Enter Pokemon name: ";
                getline(cin, name);
                pokeList.searchPokeTree(name);
            }else if(command == "2"){
                pokeList.printPokeInventory();
            }else if(command == "3"){
                string name;
                cout<<"Enter Pokemon name: ";
                getline(cin, name);
                pokeList.deletePokeNode(name);
            }else if(command == "4"){
                pokeList.countPokeNodes();
            }else if(command == "5"){
                string type;
                cout<<"Enter Pokemon type: ";
                getline(cin, type);
                pokeList.findType(type);

            }else if(command == "6"){
                string ability;
                cout<<"Enter Pokemon ability: ";
                getline(cin, ability);
                pokeList.findAbility(ability);
            }else if(command == "7"){
                cout<<"Enter Pokedex number: "<<endl;
                getline(cin, data[0]);
                cout<<"Enter Pokemon name: "<<endl;
                getline(cin, data[1]);
                cout<<"Enter Pokemon height: "<<endl;
                getline(cin, data[3]);
                cout<<"Enter Pokemon weight: "<<endl;
                getline(cin, data[4]);
                cout<<"Enter Pokemon primary type: "<<endl;
                getline(cin, data[6]);
                cout<<"Enter Pokemon secondary type (none if N/A)): "<<endl;
                getline(cin, data[7]);
                cout<<"Enter Pokemon primary ability: "<<endl;
                getline(cin, data[8]);
                cout<<"Enter unevolved version (none if Pokemon does not evolve): "<<endl;
                getline(cin, data[9]);
                cout<<"Enter first evolution version (none if N/A): "<<endl;
                getline(cin, data[10]);
                cout<<"Enter final evolution version (none if N/A): "<<endl;
                getline(cin, data[11]);

                cout<<"Is all information correct? Y/N"<<endl;
                getline(cin, strLine);
                if(strLine == "Y" || strLine == "Yes" || strLine == "yes" || strLine == "y"){
                    pokeList.addPokeNode(atoi(data[0].c_str()),data[1],atoi(data[3].c_str()),atoi(data[4].c_str())
                                    ,data[6],data[7],data[8],data[9],data[10],data[11]);
                }else{
                    cout<<"Information not added"<<endl;
                }
            }else if(command == "8"){
                //this will print out the types of pokemon available //added by Amy Chen (shaochee)
                cout << "The types of Pokemon in this Pokedex are:" << endl;
                pokeList.printPokeTypes();
            }else if(command == "9"){
                //this will print out the abilities of pokemon available //added by Amy Chen (shaochee)
                cout << "The abilities of the Pokemon in this Pokedex are:" << endl;
                pokeList.printPokeAbilities();
            }else if(command == "10")
            {
                pokeList.whatCountersType();
                getline(cin, command);
            }
        }
        //~pokeList;
    }

    return 0;
}
