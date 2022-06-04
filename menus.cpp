//
// Created by Hugo Miguel Fernandes Gomes on 02/06/2022.
//
#include "menus.h"

extern string FILE_NAME;

Menus::Menus(Graph& g) {
    this->g1 = g;
}


void Menus::mainMenu() {
    bool notExit = true;
    int input;
    do {
        cout << "-------- MENU --------" << endl;
        cout << endl;
        cout << "1) The group remains together" << endl;
        cout << "2) The group splits up" << endl;
        cout << "3) Choose dataset" << endl;
        cout << "0) Exit" << endl;
        
        cin >> input;
        while(input != 0 && input != 1 && input != 2 && input != 3){
            cout << "Invalid input, choose an option again!" << endl;
            cin.clear();
            cin >> input;
        }

        switch (input) {
            case 0:
                notExit = false;
                break;
            case 1:
                scenarioOneMenu();
                break;
            case 2:
                scenarioTwoMenu();
                break;
            case 3:
                dataSet();
                break;
        }
    }while(notExit);
}


void Menus::scenarioOneMenu() {
    bool notExit = true;
    pair<int, list<int>> result;
    int src, dest;
    int input;
    do {
        cout << "-------- Scenario One --------" << endl;
        cout << endl;
        cout << "1) Maximise the dimension of the group through any path" << endl;
        cout << "2) Maximise the dimension of the group and minimize the number of transhipments" << endl;
        cout << "0) Exit" << endl;

        cin >> input;
        while(input != 0 && input != 1 && input != 2){
            cout << "Invalid input, choose an option again!" << endl;
            cin.clear();
            cin >> input;
        }

        switch (input) {
            case 0:
                notExit = false;
                break;
            case 1:
                cout << "Insert the source node between 1 and " << g1.getNumberNodes() << ": " << endl;
                cin >> src;
                while(input < 1 || input > g1.getNumberNodes()){
                    cout << "Invalid input, choose a source node again!" << endl;
                    cin.clear();
                    cin >> src;
                }
                cout << "Insert the destination node between 1 and " << g1.getNumberNodes() << ": " << endl;
                cin >> dest;
                while(input < 1 || input > g1.getNumberNodes()){
                    cout << "Invalid input, choose a destination node again!" << endl;
                    cin.clear();
                    cin >> dest;
                }
                result = g1.dijkstraMaximumCapacity(src, dest);
                cout << "Capacity: " << result.first << " Path: ";
                for(auto &i : result.second){
                    cout << i + 1 << " ";
                }
                cout << endl;
                break;
            case 2:
                cout << "Insert the source node between 1 and " << g1.getNumberNodes() << ": " << endl;
                cin >> src;
                while(input < 1 || input > g1.getNumberNodes()){
                    cout << "Invalid input, choose a source node again!" << endl;
                    cin.clear();
                    cin >> src;
                }
                cout << "Insert the destination node between 1 and " << g1.getNumberNodes() << ": " << endl;
                cin >> dest;
                while(input < 1 || input > g1.getNumberNodes()){
                    cout << "Invalid input, choose a destination node again!" << endl;
                    cin.clear();
                    cin >> dest;
                }
                g1.testPaths(src, dest);
                break;
        }
    } while (notExit);
}


void Menus::scenarioTwoMenu() {
    bool notExit = true;
    int input, src, dest, groupSize;
    do {
        cout << "-------- Scenario Two --------" << endl;
        cout << endl;
        cout << "1) Determine a path given its dimension" << endl;
        cout << "2) Fix a path so that the dimension can increase" << endl;
        cout << "3) Determine the maximum group size and a path" << endl;
        cout << "4) Determine when the group will meet again" << endl;
        cout << "5) Determine the maximum waiting time" << endl;
        cout << "0) Exit" << endl;

        cin >> input;

        while(input != 0 && input != 1 && input != 2 && input != 3 && input != 4 && input != 5) {
            cout << "Invalid input, choose an option again!" << endl;
            cin.clear();
            cin >> input;
        }

        switch (input) {
            case 0:
                notExit = false;
                break;
            case 1:
                cout << "Insert the source node between 1 and " << g1.getNumberNodes() << ": " << endl;
                cin >> src;
                while(input < 1 || input > g1.getNumberNodes()){
                    cout << "Invalid input, choose a source node again!" << endl;
                    cin.clear();
                    cin >> src;
                }
                cout << "Insert the destination node between 1 and " << g1.getNumberNodes() << ": " << endl;
                cin >> dest;
                while(input < 1 || input > g1.getNumberNodes()){
                    cout << "Invalid input, choose a destination node again!" << endl;
                    cin.clear();
                    cin >> dest;
                }
                cout << "Insert the group size: " << endl;
                cin >> groupSize;
                g1.fordFulkersonGroupSize(src,dest, groupSize);
                break;

            case 2:
                cout << "Insert the source node between 1 and " << g1.getNumberNodes() << ": " << endl;
                cin >> src;
                while(input < 1 || input > g1.getNumberNodes()){
                    cout << "Invalid input, choose a source node again!" << endl;
                    cin.clear();
                    cin >> src;
                }
                cout << "Insert the destination node between 1 and " << g1.getNumberNodes() << ": " << endl;
                cin >> dest;
                while(input < 1 || input > g1.getNumberNodes()){
                    cout << "Invalid input, choose a destination node again!" << endl;
                    cin.clear();
                    cin >> dest;
                }
                cout << "Insert the new group size: " << endl;
                cin >> groupSize;
                g1.fordFulkersonGroupSize(src,dest, groupSize);
                break;

            case 3:
                cout << "Insert the source node between 1 and " << g1.getNumberNodes() << ": " << endl;
                cin >> src;
                while(input < 1 || input > g1.getNumberNodes()){
                    cout << "Invalid input, choose a source node again!" << endl;
                    cin.clear();
                    cin >> src;
                }
                cout << "Insert the destination node between 1 and " << g1.getNumberNodes() << ": " << endl;
                cin >> dest;
                while(input < 1 || input > g1.getNumberNodes()){
                    cout << "Invalid input, choose a destination node again!" << endl;
                    cin.clear();
                    cin >> dest;
                }
                cout << "The maximum capacity is: " << g1.fordFulkerson(src, dest) << endl;
                g1.printGraph();
                break;

            case 4:
                cout << "Insert the source node between 1 and " << g1.getNumberNodes() << ": " << endl;
                cin >> src;
                while(input < 1 || input > g1.getNumberNodes()){
                    cout << "Invalid input, choose a source node again!" << endl;
                    cin.clear();
                    cin >> src;
                }
                cout << "Insert the destination node between 1 and " << g1.getNumberNodes() << ": " << endl;
                cin >> dest;
                while(input < 1 || input > g1.getNumberNodes()){
                    cout << "Invalid input, choose a destination node again!" << endl;
                    cin.clear();
                    cin >> dest;
                }
                g1.fordFulkersonTime(src, dest);
                break;

            case 5:
                cout << "Insert the source node between 1 and " << g1.getNumberNodes() << ": " << endl;
                cin >> src;
                while(input < 1 || input > g1.getNumberNodes()){
                    cout << "Invalid input, choose a source node again!" << endl;
                    cin.clear();
                    cin >> src;
                }
                cout << "Insert the destination node between 1 and " << g1.getNumberNodes() << ": " << endl;
                cin >> dest;
                while(input < 1 || input > g1.getNumberNodes()){
                    cout << "Invalid input, choose a destination node again!" << endl;
                    cin.clear();
                    cin >> dest;
                }
                g1.earliestStart(src, dest);
                break;
        }

    } while (notExit);


}


void Menus::dataSet() {
    int input;
    cout << "-------- Data set --------" << endl;
    cout << endl;
    cout << "Choose a data set between the numbers 1 and 10 " << endl;
    cin >> input;

    while(input < 1 || input > 10) {
        cout << "Invalid input, choose a data set again!" << endl;
        cin.clear();
        cin >> input;
    }
    ostringstream file_name;
    file_name << "in" << setfill('0') << setw(2) << input << ".txt";
    FILE_NAME = file_name.str();
    l.loadBuses(g1);
}

