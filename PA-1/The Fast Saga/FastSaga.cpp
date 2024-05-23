#include "FastSaga.h"

/**
 * Implement FastSaga constructor by adding all movie titles to vector
 */
FastSaga::FastSaga() {
    titles.push_back("The Fast and the Furious");
    titles.push_back("2 Fast 2 Furious");
    titles.push_back("The Fast and the Furious: Tokyo Drift");
    titles.push_back("Fast & Furious");
    titles.push_back("Fast Five");
    titles.push_back("Fast & Furious 6");
    titles.push_back("Furious 7");
    titles.push_back("The Fate of the Furious");
    titles.push_back("Fast & Furious Presents: Hobbs & Shaw");
    titles.push_back("F9");
    titles.push_back("Fast X");
}

/**
 * Implement begin() by leveraging the vector class's iterators
 */
vector<string>::iterator FastSaga::begin() {
    return titles.begin();
}

/**
 * Implement end() by leveraging the vector class's iterators
 */
vector<string>::iterator FastSaga::end() {
    return titles.end();
}
