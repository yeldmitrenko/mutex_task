#include <iostream>
#include <string>
#include <mutex>
#include <thread>

using namespace std;

class Third
{
	public:
		static void Print(string str);
}; 


class WorkerOne
{
	public:
		Third w_one;
};

class WorkerTwo
{
	public:
		Third w_two;
};

mutex mtx;

void Third::Print(string str)
{
	mtx.lock();

	string res = "Hello" + str;
	cout << res << endl;

	mtx.unlock();
}


int main()
{

	WorkerOne worker_one;
	WorkerTwo worker_two;
	
	thread th1(worker_one.w_one.Print, "WorkerOne");
	thread th2(worker_two.w_two.Print, "WorkerTwo");

	th1.join();
	th2.join();

	return 0;
}

