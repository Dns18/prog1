#include <iostream>
#include <vector>
#include <cmath>
#include <thread>

using namespace std;

void stress_cpu(){
    while(true){
        volatile double x = 0;
        for(int i = 0; i < 999999; i++) {
            x += sin(i) * cos(i);

        }
    }
}

int main(){
    unsigned int num_threads = thread::hardware_concurrency();
    vector<thread> threads;

    cout << "Number of threads: " << num_threads << endl;

    for (unsigned int i = 0; i < num_threads; i++){
        threads.emplace_back(stress_cpu);
    }

    for (size_t i = 0; i < threads.size(); i++){
        threads[i].join();
    }
    
}