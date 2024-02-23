#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;
// List is vector of pair of string and character, string will store the task and character will store the state of task
vector<pair<string,char>>List;
// this function will display the list of all tasks along with its status
void print_list()
{
	if (List.empty())// if list is empty the display empty state message and return
	{
		cout << "List is Empty." << endl;
		return;
	}
	int i = 1;// will be used as counter variable
	cout << "No.	  List Items             Status" << endl << endl;
	// this loop will traverse vector elements one by one
	for (vector<pair<string, char>>::const_iterator it = List.cbegin(); it != List.cend(); ++it, ++i)
	{
		cout << i << "	  " << it->first << "            ";
		if (it->second == 'C')
			cout << "Completed";
		else
			cout << "Pending";
		cout << endl;
	}
	return;
}
// this function will add new task to the list
void add_task(const string & task)
{
	List.push_back({task, 'P'});// by default task state will be pending
}
// this function will mark the task as the completed . (if duplicates exist then first pending task will be marked as completed )
void mark_completed(const string & task)
{
	bool flag = 0;// will be used to decide if task is not found or it was already completed
	vector<pair<string, char>>::iterator it = List.begin();
	for ( ;it != List.end(); ++it)// this loop will traverse the vector untill the required element found
	{
		if (it->first.compare(task) == 0)
		{
			if (it->second == 'P')// if found then state will be checked if state is pending it will be marked as completed and return
			{
				it->second = 'C';
				return;
			}
			// if state is already completed then loop will continue towards next pending task
			flag = 1;
		}
	}
	if (flag)
		cout << "Already Completed" << endl;
	else
		cout << "Not Found" << endl;
	return;
}
// this function will remove the task from list . (if duplicates exist then first  task will be removed from list )
void remove_task(const string & task)
{
	vector<pair<string, char>>::const_iterator it = List.cbegin();
	for (; it != List.cend(); ++it)
	{
		if (it->first.compare(task) == 0)
		{
			List.erase(it);
			return;
		}
	}
	cout << "Not Found" << endl;
	return;
}
// this funtion will remove extra spaces from option string to comfort user
void remove_extra_spaces(string & str)
{
	while (str.length() > 0 && str[0] == ' ')// remove the staring spaces
	{
		str.erase(str.begin());
	}
	int i = 0;
	while (str.length() > i && str[i] != ' ')// this loop will skip all non-space character untill space appear or end string
	{
		++i;
	}
	for (; i < str.length();)
	{
		str.erase(str.begin() + i);
	}
}

int main(int argc,char * argv[])
{

	string option;// will be used as selection variable from menu
	while (true)// the loop execute untill the user enter Exit or exit option
	{
		cout << endl;
		cout << "*****  Options Menu  *****" << endl << endl;
		cout << "Add/add            : To Add new Task to List" << endl;
		cout << "View/view          : To Display All Tasks of List " << endl;
		cout << "Complete/complete  : To Marks Task as completed" << endl;
		cout << "Remove/remove      : To Remove Task from List" << endl;
		cout << "Clear/clear        : To Clear/Delete all Tasks from List" << endl;
		cout << "Exit/exit          : To Quit Program" << endl;
		cout << endl;
		cout << "Enter Option from above Options Menu :";
		getline(cin, option);// input option from user
		remove_extra_spaces(option);
		if (option.compare("Add") == 0 || option.compare("add") == 0)
		{
			string task;
			cout << "Enter New Task :";
			getline(cin, task);
			add_task(task);
		}
		else if (option.compare("View") == 0 || option.compare("view") == 0)
		{
			print_list();
		}
		else if (option.compare("Complete") == 0 || option.compare("complete") == 0)
		{
			string task;
			cout << "Enter Task to Mark as Completed :";
			getline(cin, task);
			mark_completed(task);
		}
		else if (option.compare("Remove") == 0 || option.compare("remove") == 0)
		{
			string task;
			cout << "Enter Task to be Removed :";
			getline(cin, task);
			remove_task(task);
		}
		else if (option.compare("Clear") == 0 || option.compare("clear") == 0)
		{
			string task;
			List.clear();
		}
		else if (option.compare("Exit") == 0 || option.compare("exit") == 0)
		{
			// if user enter Exit or exit then the loop will terminate and the program will be finished.
			cout << "Program Finished." << endl;
			break;
		}
		else
		{
			cout << "You Have Entered Invalid Option. Please! Try again." << endl;
		}
	} 


	return 0;
}
