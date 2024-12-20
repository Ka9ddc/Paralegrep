#ifndef THREADRANKING_H
#define THREADRANKING_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <mutex>

using namespace std;

class Thread_ranking {
private:
    vector<pair<string, int>> ranking;
    mutex mtx;

public:
    Thread_ranking();
    
    void atualizarRanking(string arquivo, int ocorrencias);
    
    void exibirRanking();
};

#endif
