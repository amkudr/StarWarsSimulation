#include <iostream>
#include "Controller.h"
#include "fstream"
#include <sstream>

shared_ptr<Model> Controller::model = nullptr;

void Controller::createWorld(int argc, char **argv) {
    if (argc != 2) {
        throw invalid_argument("Wrong number of arguments!");
    }
    ifstream file(argv[1]);
    if (!file.is_open()) {
        throw invalid_argument("File not found!");
    }
    //Create stations
    string line, name, type;
    char comma;
    float x, y;
    int ContNum = -1, SupNum = -1;
    while (getline(file, line)) {
        istringstream iss(line);
        getline(iss, type, ',');
        iss >> ws;
        getline(iss, name, ',');
        iss >> comma >> x >> comma >> y >> comma >> comma >> ContNum >> comma >> SupNum;
        if (ContNum < 0 || SupNum < 0 || name.empty() || !iss.eof()) {
            cerr << "Wrong input for line:" + line << endl;
        } else model->addStation(name, x, y, ContNum, SupNum);
    }


}

void Controller::run(int argc, char **argv) {
    try {
        createWorld(argc, argv);
    }
    catch (invalid_argument &e) {
        cerr << e.what() << endl;
        return;
    }
    string command;
    int time = 0;
    model->addShuttle("GX", "Peter", 0, 0);
    model->addBomber("Suuuuu", "Pidr", 15, 30);
    model->addFalcon("NAVALNIY", 5,5);
    model->addDestroyer("Putin", "Huilo", 10, 20);
    model->destination("Suuuuu","Facility729D");

    cout << model->view();
    cout << model->status();
    model->start_supply("GX", "Yavin", "DS");
    model->start_supply("GX", "Yavin", "DS");
    model->start_supply("GX", "Facility729D", "DS");
    model->start_supply("GX", "Facility729D", "DS");
    model->position("NAVALNIY", 30, 20);
//    model->destination("Putin", "DS");
    model->course("Putin", 0);
    model->go();
    model->go();
    model->shoot("Putin", 30,20);

    for (int i = 0; i < 600; i++) {
        if(i == 20){
            continue;
        }
        model->go();
//        cout<<i<< endl;
        if (i % 5 == 0) {
            cout << model->view();
            cout << model->status();
        }


//        if (i == 20) {
//
//            model->go();
//            cout << "Hop\n";
//            cout << model->status();
//            cout << model->view();
//            cout << "Hop\n";
//
//        }



//        if (i%5 == 0){
//            cout<<model->status();
////            cout<<model->view();
//        }
    }
    cout << model->status();

    cout << model->view();

    return;
    while (true) {
        cout << "Time: " << time << " Enter command :";
        cin >> command;
        if (command == "exit") {
            break;
        }
        if (command == "show") {
            cout << model->view();
        } else if (command == "create") {
            string type;
            cin >> type;
            if (type == "shuttle") {
                string line;
                getline(cin, line);
                string word;
                vector<string> inputVec;
                istringstream iss(line);
                while (iss >> word) {
                    inputVec.push_back(word);
                }
                if (inputVec.size() == 4) {
                    float x = stof(inputVec[2].substr(1));
                    float y = stof(inputVec[3].substr(0, inputVec[2].size() - 1));
                    model->addShuttle(inputVec[0], inputVec[1], x, y);
                }
            }
        } else {
            string line;
            getline(cin, line);
            string word;
            vector<string> inputVec;
            istringstream iss(line);
            while (iss >> word) {
                inputVec.push_back(word);
            }
//            if (model->getShStatus(command) != NOTEXIST) {
//                if (inputVec[0] == "start_supply" && inputVec.size() == 3) {
//                }
//            } else cout << "Wrong command" << endl;

        }
    }
}

Controller::Controller() {
    model = Model::getInstance();
}
