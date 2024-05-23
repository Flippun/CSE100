#ifndef FASTSAGA_H
#define FASTSAGA_H
#include <string>
#include <vector>
using namespace std;

/**
 * Class to represent the Fast (& Furious) Saga
 */
class FastSaga {
    private:
        /**
         * Store the Fast (& Furious) Saga movie titles
         */
        vector<string> titles;

    public:
        /**
         * FastSaga Constructor
         */
        FastSaga();

        /**
         * Returns an iterator to the beginning
         *
         * @return An iterator to the beginning
         */
        vector<string>::iterator begin();

        /**
         * Returns an iterator to the end (just past the last element)
         *
         * @return An iterator to the end
         */
        vector<string>::iterator end();
};
#endif
