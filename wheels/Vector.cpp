//
// Created by martin on 17-12-17.
//

void sortUnique(vec<int> & vec) {
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
}