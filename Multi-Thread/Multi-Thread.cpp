#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>

using namespace std;

mutex G_mutex;
int G_count = 0;

void Multiple(void){

    double sum = 0;

    for (int i = 0; i < 20000; ++i){
        for (int j = 0; j < 20000; ++j){
            sum += i*j;
        }
    }
    cout << "Total sum = " << sum << endl;

}

void Sleep(void){

    this_thread::sleep_for(chrono::seconds(3));
    cout << "Wake Up." << endl;

}

void Show(int n, char c){   //display n char

    G_mutex.lock();
    //lock_guard<mutex> lock(G_mutex);  //to avoid multi thread interfere with each other

    for (int i = 0; i < n; ++i){
        cout << c;
        ++G_count;
    }

    cout << endl;

    cout << "count = " << G_count << endl;

    G_mutex.unlock();

}

int main(){

    cout << "Hello Thread." << endl;

    thread oneThread(Multiple);

    cout << "Main Thread" << endl;

    oneThread.join();

    cout << "----------------------------------------" << endl;

    thread twoThread(Sleep);
    cout << "I have done first task." << endl;

    twoThread.detach();

    cout << "I have done second task." << endl;

    cout << "----------------------------------------" << endl;

    thread t3(Show,10,'E');
    thread t4(Show,5,'F');

    t3.join();
    t4.join();

    system("pause");
    return 0;
}
