#include "ranking.h"

Thread_ranking::Thread_ranking() {}

void Thread_ranking::atualizarRanking(string arquivo, int ocorrencias) {
    lock_guard<mutex> lock(mtx);

    bool encontrado = false;
    for (auto &entry : ranking) {
        if (entry.first == arquivo) {
            entry.second = ocorrencias;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        ranking.push_back(make_pair(arquivo, ocorrencias));
    }

    sort(ranking.begin(), ranking.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return b.second < a.second;
    });
}


void Thread_ranking::exibirRanking() {
    lock_guard<mutex> lock(mtx);

    cout << "\nRanking Atualizado:" << endl;
    for (size_t i = 0; i < min(ranking.size(), size_t(10)); ++i) {
        cout << i + 1 << ". " << ranking[i].first << " - " << ranking[i].second << " ocorrências" << endl;
    }
}
