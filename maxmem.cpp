#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <atomic>

using namespace std;

atomic<bool> stop(false);

void stress_mem() {
    vector<vector<int>> memory_blocks;
    while(!stop){
        vector<int> block(1024 * 1024, 0);
        
        memory_blocks.push_back(move(block));
    }
    cout << "Memory stress test stopped." <<endl;
}


//Program stopper
void wait_for_enter() {
    cin.get();
    stop = true;
}

int main() {
    thread stress_thread(stress_mem);
    thread input_thread(wait_for_enter);
    
    stress_thread.join();
    input_thread.join();

    return 0;
}  
