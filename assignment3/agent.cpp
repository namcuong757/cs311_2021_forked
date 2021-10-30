#include <string>
#include <iostream>
#include <queue>
#include <fstream>
using namespace std;
void write_queue_to_file(queue<string>& decisions)
{
	int size = decisions.size();
	ofstream my_file("data.txt", ios::trunc);
	if(my_file.is_open())
	{
		for(int i = 0; i < size; i++)
		{
			my_file << decisions.front() + "\n";
			decisions.pop();
		}
		my_file.close();
	}
	else
	{
		cout << "Error: Cannot open file" << endl;
	}
}

queue<string> load_queue_from_file()
{
	queue<string> loaded_queue;
	string temp;
	ifstream my_file("data.txt");
	if(my_file.is_open())
	{
		while(getline(my_file, temp))
		{
			loaded_queue.push(temp);
		}
		my_file.close();
	}
	else
	{
		cout << "Error: Cannot open file" << endl;
	}
	return loaded_queue;
}

void make_decisions(string opponent_last_move)
{
	queue<string> decisions;
	if(opponent_last_move == "zero")
	{
		decisions.push("confess");
                decisions.push("confess");
		decisions.push("silence");
	}
	else
	{
		queue<string> decisions = load_queue_from_file();
        	decisions.push(opponent_last_move);
	}
	cout << decisions.front() << endl;
	decisions.pop();
	write_queue_to_file(decisions);
}

int main(int argc, char** argv)
{
	make_decisions(argv[1]);
	return 0;
}
