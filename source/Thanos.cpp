#include <utility>

#include "Thanos.h"

Thanos::Thanos(string file) { // set file name, initialize vector code, load code
    fileName = std::move(file);

    code = new vector<char>;
    loadFile();
}

Thanos::~Thanos() { // free code
    delete code;
    code = nullptr;
}

void Thanos::snapFinger() { // The Hardest Choice Requires the Strongest Wills
    // dramatic dialogue
    cout << "Thanos: You should've..." << endl;
    sleep_for(milliseconds(1000));
    cout << "Thanos: You should've......" << endl;
    sleep_for(milliseconds(2000));
    cout << "Thanos: You should have aimed for the head..." << endl;
    sleep_for(milliseconds(1000));
    cout << "Thor: What?.." << endl;
    sleep_for(milliseconds(500));
    cout << "Thanos: *snap*" << endl;
    sleep_for(milliseconds(1000));
    cout << "Thor: NOOOOOOOoooooo..." << endl;
    sleep_for(milliseconds(2000));

    //uniform_int_distribution prng for the random purge
    random_device rng;
    mt19937 gen(rng());
    uniform_int_distribution<unsigned long> uniform_dist(1, code->size());

    // randomly deleting characters stored in vector code
    unsigned long originalSize = code->size();
    while(code->size()>=(originalSize/2)){
        code->erase(code->begin() + (uniform_dist(gen)%code->size()));
    }

    rewriteFile();

    cout << "\n\n\n\n\n";
    cout << "Perfect Balance, as all things should be" << endl;
}

void Thanos::loadFile() { // open stream in input mode and read to code
    fstream fin;

    fin.open(fileName, fstream::in);

    assert(fin.is_open());

    while(!fin.eof()){
        char letter = (char) fin.get();
        code->push_back(letter);
    }

    fin.close();
}

void Thanos::rewriteFile() { // open stream, truncate and write
    fstream fout;

    fout.open(fileName, fstream::out | fstream::trunc);

    assert(fout.is_open());

    for(auto &item : *code){
        fout << item;
    }

    fout.close();
}






