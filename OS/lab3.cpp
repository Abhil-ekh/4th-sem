#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

queue<int> buffer;
const unsigned int MAX_BUFFER_SIZE = 5;
mutex mtx;
condition_variable cv_producer;
condition_variable cv_consumer;

void producer(int id, int itemsToProduce) {
    for (int i = 1; i <= itemsToProduce; ++i) {
        unique_lock<mutex> lock(mtx);
        cv_producer.wait(lock, [](){ return buffer.size() < MAX_BUFFER_SIZE; });

        buffer.push(i);
        cout << "Producer " << id << " produced: " << i << "\n";

        lock.unlock();
        cv_consumer.notify_one();

        this_thread::sleep_for(chrono::seconds(1)); // simulate work
    }
}

void consumer(int id, int itemsToConsume) {
    for (int i = 1; i <= itemsToConsume; ++i) {
        unique_lock<mutex> lock(mtx);
        cv_consumer.wait(lock, [](){ return !buffer.empty(); });

        int item = buffer.front();
        buffer.pop();
        cout << "Consumer " << id << " consumed: " << item << "\n";

        lock.unlock();
        cv_producer.notify_one();

        this_thread::sleep_for(chrono::seconds(1)); // simulate work
    }
}

int main() {
    int items = 10;

    thread p1(producer, 1, items);
    thread c1(consumer, 1, items);

    p1.join();
    c1.join();

    return 0;
}
