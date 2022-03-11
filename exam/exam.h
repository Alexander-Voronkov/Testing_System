#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#define widthh 80
#define ESC 27
#define BACK 8
#define ENTER 13 
#pragma once
#include <iostream>
#include <experimental/filesystem>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <list>
#include <math.h>
#include "Menu.h"

using namespace std::filesystem;
using std::begin;
using std::end;
using std::string;
using std::vector;
using std::ostream;
using std::istream;
using std::map;
using std::cout;
using std::cin;
using std::endl;
using std::find;
using std::list;
using std::_Node_handle;
using std::round;
using std::pair;
using std::advance;
namespace Exam
{
	hash<string>h;
	string adminlog = "admin";
	int gradesystem = 12;

	struct Question
	{
		string question;
		vector<string>answers;
		string rightanswer;
		Question& operator=(const string& obj) { question = obj; }
		Question(string question, vector<string>answers,string rightanswer) :question(question),answers(answers),rightanswer(rightanswer){}
		Question(string q) :question(q) {}
		bool operator==(const Question& obj) { if (this->question == obj.question)return 1; return 0; }
		bool operator!=(const Question& obj) { if (this->question != obj.question)return 1; return 0; }
	};

	struct Test
	{
		string name="";
		vector<Question>questions;
		bool operator==(const Test& obj) { if (this->name == obj.name)return 1; return 0; }
		bool operator!=(const Test& obj) { if (this->name != obj.name)return 1; return 0; }
		Test(string obj) :name(obj) {}
	};

	class UPTest 
	{
	public:
		string testname="";
		vector<Question>questions;
		bool passed = 0;
		int stop=0;
		int countright=0;
		UPTest() {}
		UPTest(Test& obj) :testname(obj.name), questions(obj.questions) {}
		UPTest& operator=(Test& obj) { testname = obj.name; questions = obj.questions; }
		UPTest(string name, vector<Question>questions) { this->questions = questions; this->testname = name; }
		void operator() (string name, vector<Question>questions, int c, int s, bool p) { testname = name; this->questions = questions; countright = c; stop = s; passed = p; }
	};

	struct Topic
	{
		string name;
		vector<Test>vtests;
		bool operator==(const Topic& obj) { if (this->name == obj.name)return 1; return 0; }
		bool operator!=(const Topic& obj) { if (this->name != obj.name)return 1; return 0; }
		Topic(string obj) :name(obj) {}
		Topic(string name, vector<Test>vtests) :vtests(vtests), name(name) {}
	};

	struct GlobalTests
	{
		vector<Topic>topics;
		int count()
		{
			int c = 0;
			for (size_t i = 0; i < topics.size(); i++)
			{
				c += topics[i].vtests.size();
			}
			if (c)
				return c;
			else
				return 1;
		}
		bool findtest(Test a)
		{
			for (size_t i = 0; i < topics.size(); i++)
			{
				if (find(topics[i].vtests.begin(), topics[i].vtests.end() , a) != topics[i].vtests.end() )
				{
					return 1;
				}
			}
			return 0;
		}
	};

	
	class Guest
	{
	protected:
		long long password;
		string login;
		bool isadmin = 0;
	public:
		virtual map<string, UPTest>& getPassedTests() = 0;
		Guest(string log,string pass) :login(log) {
			password = (h(pass));
			if (log == adminlog)
				isadmin = 1;
		}
		virtual string &getLogin() = 0;
		virtual ~Guest()=0;
		virtual void menu(GlobalTests& g, list<Guest*>& users, map<string, long long>& loginlist) = 0;
		bool operator==(const Guest*obj)
		{
			if (this->login==obj->login&&this->password==obj->password&&this->isadmin==obj->isadmin)
			{
				return 1;
			}
			return 0;
		}
		virtual void printStats(GlobalTests& g) = 0;
		virtual bool getStatus() = 0;
	};

	inline Guest::~Guest() {}


	class User:public Guest
	{
		map<string, UPTest> PassedTests;
		string FIO;
		string ADD;
		string PHO;
	public:
		map<string, UPTest>& getPassedTests()override { return PassedTests; }
		User(string log, string pass, string FIO = "name", string ADD = "add", string PHO = "xxxxxxxxxx") :Guest(log,pass),FIO(FIO), ADD(ADD), PHO(PHO) { isadmin = 0; }
		~User() {}
		string& getFIO() { return FIO; }
		string& getADD() { return ADD; }
		string& getPHO() { return PHO; }
		long long& getPAS() { return password; }
		string& getLOG() { return login; }
		void setFIO(string&& obj) { FIO = obj; }
		void setADD(string&& obj) { ADD = obj; }
		void setPHO(string&& obj) { PHO = obj; }
		virtual void menu(GlobalTests& g, list<Guest*>& users, map<string, long long>& loginlist)override final;
		void CheckResults();
		void PassTest(GlobalTests& g, map<string, UPTest>& PassedTests);
		map<string, UPTest>& GetPassedTests(){ return PassedTests; }
		virtual bool getStatus()override { return 0; }
		void pass(UPTest& obj)
		{
		retry:
			if (!obj.passed)
			{
				for (int i = obj.stop; i < obj.questions.size(); i++)
				{
					system("cls");
					gotoxy((widthh - 8) / 2, 2);
					cout << "������:";
					gotoxy((widthh - obj.questions[i].question.length()) / 2, 3);
					cout << obj.questions[i].question;
					gotoxy(0, 5);
					for (size_t i = 0; i < widthh; i++)
					{
						cout << "_";
					}
					gotoxy(0, 7);
					vector<string> answersmenu;
					for (size_t j = 0; j < obj.questions[i].answers.size(); j++)
					{
						answersmenu.push_back(obj.questions[i].answers[j]);
					}
					int c = Menu::select_vertical(answersmenu, Center);
					switch (c)
					{
					case -1:obj.passed = 0; obj.stop = i; return; break;
					default:if (obj.questions[i].answers[c] == obj.questions[i].rightanswer)
					{
						system("cls");
						gotoxy((widthh - 7) / 2, 6);
						SetColor(Green, Black);
						cout << "���������!";
						SetColor(White, Black);
						system("pause>0");
						obj.countright++;
					}
						   else
					{
						system("cls");
						gotoxy((widthh - 7) / 2, 6);
						SetColor(Red, Black);
						cout << "�������(";
						SetColor(White, Black);
						system("pause>0");
					}
					}
				}
				obj.passed = 1;
			}
			else if (obj.passed)
			{
				system("cls");
				gotoxy((widthh - 37) / 2, 2);
				cout << "�� ������������� ������ �������� ���";
				gotoxy((widthh - 51) / 2, 3);
				cout << "������� ����������� ����� ����� � ������ ������ ? ";
				gotoxy(0, 5);
				for (size_t i = 0; i < widthh; i++)
				{
					cout << "_";
				}
				int c = Menu::select_vertical({ "��","���" }, Center);
				switch (c)
				{
				case -1:return; break;
				case 0:obj.passed = 0; obj.stop = 0; goto retry; break;
				case 1:return; break;
				}
			}
			system("cls");
			gotoxy((widthh - 14) / 2, 2);
			cout << "���� ������: ";
			gotoxy(0, 4);
			for (size_t i = 0; i < widthh; i++)
			{
				cout << "_";
			}
			Logo l;
			l.print(to_string((int)round((obj.countright * gradesystem) / obj.questions.size())), Center, 10, (((obj.countright * gradesystem) / obj.questions.size()) > 6) ? Green : Yellow);
			system("pause>0");
			SetColor(White,Black);
		}
		void ShowTests(Topic&obj)
		{
			while (true)
			{
				system("cls");
				gotoxy((widthh - obj.name.length()-24) / 2, 2);
				cout << "�������� ���� �� ����: "<<obj.name;
				gotoxy(0,4);
				for (size_t i = 0; i < widthh; i++)
				{
					cout << "_";
				}
				if (!obj.vtests.empty())
				{
					vector<string>v;
					for (size_t i = 0; i < obj.vtests.size(); i++)
					{
						v.push_back(obj.vtests[i].name);
					}
					int c = Menu::select_vertical(v, Center);
					switch (c)
					{
					case -1:return; break;
					default: PassedTests[obj.vtests[c].name] = UPTest(obj.vtests[c]); pass(PassedTests.find(obj.vtests[c].name)->second); break;
					}
				}
			}
		}
		string &getLogin()override { return login; }
		void printStats(GlobalTests&g)override
		{
			gotoxy(4, 7);
			cout << "���: " << FIO;
			gotoxy(4, 8);
			cout << "�����: " << ADD;
			gotoxy(4, 9);
			cout << "����� ��������: " << PHO;
			gotoxy(4, 10);
			cout << "������� ���������� ������: " << (PassedTests.size() / g.count()) * 100 << "%" << endl;
			int count = 0;
			if (PassedTests.empty())
			{
				gotoxy(4,11);
				cout << "������������ �� ������ �� ������ �����.";
				system("pause>0");
				return;
			}
			for (auto i = PassedTests.begin(); i != PassedTests.end(); i++)
			{
				for (size_t j = 0; j < g.topics.size(); j++)
				{
					gotoxy(widthh-30-g.topics[j].name.length(), 8 + count++);
					cout << "������: " << g.topics[j].name;
					for (size_t q = 0; q < g.topics[j].vtests.size(); q++)
					{
						if (PassedTests.find(g.topics[j].vtests[q].name) != PassedTests.end())
							cout << "����: " << g.topics[j].vtests[q].name << " ������: "; SetColor(((((i->second.countright * gradesystem) / (i->second.questions.size())) > gradesystem / 2) ? Green : Yellow), Black);
							cout << (int)round((i->second.countright * gradesystem) / (i->second.questions.size()));
							SetColor(White,Black);
							cout << "������: " << ((i->second.passed) ? "�������" : "�� �������");

					}
				}
			}
			system("pause>0");
			return;
		}
		void PrintSelfInfo(const int &t)
		{
			system("cls");
			gotoxy(((widthh-27)-getLOG().length())/2,2);
			cout << "���������� � ������������ " << getLOG() << endl;
			gotoxy(0,4);
			for (size_t i = 0; i < widthh; i++)
			{
				cout << "_";
			}
			gotoxy(4,7);
			cout << "���: " << FIO;
			gotoxy(4, 8);
			cout << "�����: " << ADD;
			gotoxy(4, 9);
			cout << "����� ��������: " << PHO;
			gotoxy(4, 10);
			cout << "������� ���������� ������: " << (PassedTests.size() / t) * 100 << "%" << endl;
			system("pause>0");
			return;
		}
	};
	inline void User::CheckResults()
	{
		system("cls");
		gotoxy((widthh-29-this->getLOG().length())/2,2);
		cout << "���������� ������������ " << this->getLOG() << " :" << endl;
		gotoxy(0,4);
		for (size_t i = 0; i < widthh; i++)
		{
			cout << "_";
		}
		if (!PassedTests.empty())
		{
			int count = 7;
			for (auto i = PassedTests.begin(); i != PassedTests.end(); i++)
			{
				gotoxy((widthh - 8-i->first.length()) / 2, count++);
				cout << i->first << " --- " << (int)round((i->second.countright*gradesystem)/ i->second.questions.size()) << endl;
			}
		}
		else
		{
			gotoxy((widthh - 19)/2, 10);
			cout << "������ �� �������.";
		}
		system("pause>0");
		return;
	}
	inline void User::PassTest(GlobalTests& g, map<string, UPTest>&PassedTests)
	{
		vector<string>topicnames;
		for (size_t i = 0; i < g.topics.size(); i++)
		{
			topicnames.push_back(g.topics[i].name);
		}
		while (true)
		{
			system("cls");
			gotoxy((widthh - 16) / 2, 2);
			if (g.topics.empty())
			{
				system("cls");
				gotoxy((widthh - 21) / 2, 2);
				cout << "������ ����-��� ���." << endl;
				system("pause>0");
				return;
			}
			cout << "�������� ����: " << endl;
			for (size_t i = 0; i < widthh; i++)
			{
				cout << "_";
			}
			int c = Menu::select_vertical(topicnames, Center);
			switch (c)
			{
			case -1:return; break;
			default:ShowTests(g.topics[c]); break;
			}
		}
		
	}

	inline void User::menu(GlobalTests& g, list<Guest*>& users, map<string, long long>& loginlist)
	{
		while (true)
		{
			system("cls");
			Logo l;
			l.print("User menu", Center, 2, Yellow);
			int c = Menu::select_vertical({ "����� ����","���������� ����������" ,"�����","����������� ���������� � ����"}, HorizontalAlignment::Center);
				switch (c)
				{					
					case 0:PassTest(g,PassedTests); break;
					case 1:CheckResults(); break;
					case 3:PrintSelfInfo(g.count()); break;
					case -1:case 2:return; break;
				}			
		}
	}


	class Admin :public Guest
	{
	public:
		map<string, UPTest>& getPassedTests() { map<string, UPTest> a; return a; };
		Admin(string log, string pass) : Guest(log, pass) {}
		virtual void menu(GlobalTests& g , list<Guest*>& users, map<string, long long>& loginlist)override final;
		void WatchStats(list<Guest*>& users, GlobalTests& g);
		void TestManaging(GlobalTests& g, list<Guest*>& users);
		string& getLogin() { return login; }
		virtual void printStats(GlobalTests& g)override
		{
			system("cls");
			gotoxy((widthh - 26) / 2, 7);
			cout << "� ������� ��� ����������.";
			system("pause>0");
			return;
		}
		void AddTest(GlobalTests& g);
		void AddNewTest(Topic& g);
		void AddQuestionsToTest(Test& t);
		virtual bool getStatus()override { return 1; }
		void AddTestToTopic(Topic&g)
		{
			while (true)
			{
				system("cls");
				gotoxy((widthh - 22) / 2, 2);
				cout << "���� ������ ������";
				gotoxy(0, 4);
				for (size_t i = 0; i < widthh; i++)
				{
					cout << "_";
				}
				gotoxy((widthh - 27) / 2, 6);
				cout << "�������� ��� �������� ����";
				vector<string>v;
				v.push_back("�����");
				v.push_back("������� �����");
				for (size_t i = 0; i < g.vtests.size(); i++)
				{
					v.push_back(g.vtests[i].name);
				}
				int c = Menu::select_vertical(v, Center);
				switch (c)
				{
				case -1:case 0:return; break;
				case 1:	AddNewTest(g); break;
				default:AddQuestionsToTest(g.vtests[c-2]); break;
				}
			}
		}
		void AddNewTopic(GlobalTests& g)
		{
			string newcat;
			do
			{
				newcat.clear();
				system("cls");
				gotoxy((widthh - 33) / 2, 2);
				cout << "������� �������� ����� ���������";
				gotoxy(0,4);
				for (size_t i = 0; i < widthh; i++)
				{
					cout << "_";
				}
				gotoxy((widthh - 33) / 2, 6);
				getline(cin,newcat);
			} while (find(g.topics.begin(),g.topics.end(),Topic(newcat))!=g.topics.end()||newcat.empty());
			g.topics.push_back(Topic(newcat));
			system("cls");
			gotoxy((widthh-25)/2,2);
			cout << "����� ��������� �������.";
			system("pause>0");
			return;
		}

		bool operator==(const Admin& obj)
		{
			if (this->login == obj.login && this->password == obj.password && this->isadmin == obj.isadmin)
			{
				return 1;
			}
			return 0;
		}
		bool operator!=(const Admin& obj)
		{
			if (this->login == obj.login && this->password == obj.password && this->isadmin == obj.isadmin)
			{
				return 0;
			}
			return 1;
		}
	};

	inline void Admin::AddQuestionsToTest(Test& t)
	{
		vector<Question>v;
		int count = 0;
		while (true)
		{
				system("cls");
				if (count >= 2)
				{
					count = 0;
					gotoxy((widthh - 36) / 2, 2);
					cout << "�� ������ �������� ��� ���� ������?";
					gotoxy(0, 4);
					for (size_t i = 0; i < widthh; i++)
					{
						cout << "_";
					}
					int c = Menu::select_vertical({ "��","���" }, Center);
					switch (c)
					{
					case -1:case 1:
					for (size_t i = 0; i < v.size(); i++)
					{
						t.questions.push_back(v[i]);
					}
					return; break;
					case 0:break;
					}
				}
			string question;
			vector<string>answers;
			string rightanswer;
			string tempanswer;
			question.clear();
			answers.clear();
			rightanswer.clear();
			tempanswer.clear();
			do {
				system("cls");
				question.clear();
				gotoxy((widthh - 18) / 2, 2);
				cout << "�������� ������: ";
				gotoxy(0, 4);
				for (size_t i = 0; i < widthh; i++)
				{
					cout << "_";
				}
				gotoxy((widthh - 18) / 2, 6);
				getline(cin, question);
				if (find(t.questions.begin(), t.questions.end(), Question(question)) != t.questions.end())
				{
					system("cls");
					gotoxy((widthh-37)/2,2);
					cout << "������ ��������� ���������� �������.";
					system("pause>0");
				}
			} while (find(t.questions.begin(),t.questions.end(),Question(question))!=t.questions.end()||question.empty());
			do {
				rightanswer.clear();
				system("cls");
				gotoxy((widthh - 27) / 2, 2);
				cout << "������� ���������� �����: ";
				gotoxy(0, 4);
				for (size_t i = 0; i < widthh; i++)
				{
					cout << "_";
				}
				gotoxy((widthh - 27) / 2, 6);
				getline(cin, rightanswer);
			} while (rightanswer.empty());
			answers.push_back(rightanswer);
			count++;
			bool stop = 0;			
				do
				{
					if (count > 1)
					{
						system("cls");
						gotoxy((widthh - 32) / 2, 2);
						cout << "������ �������� ��� ���� �����?";
						int c = Menu::select_vertical({ "��","���" }, Center);
						switch (c)
						{
						case 0:break;
						case 1:stop = 1; goto next; break;
						}
					}
					do {
						do {
							system("cls");
							tempanswer.clear();
							gotoxy((widthh - 50) / 2, 2);
							cout << "�������� �����: (������� - 2, ������� ����������)";
							gotoxy(0, 4);
							for (size_t i = 0; i < widthh; i++)
							{
								cout << "_";
							}
							gotoxy((widthh - 50) / 2, 6);
							getline(cin, tempanswer);
						} while (tempanswer.empty());
						if (find(answers.begin(), answers.end(), tempanswer) != answers.end())
						{
							system("cls");
							gotoxy((widthh - 36) / 2, 2);
							cout << "������ ��������� ���������� ������.";
							system("pause>0");
						}
					} while (find(answers.begin(), answers.end(), tempanswer) != answers.end());
						count++;
						answers.push_back(tempanswer);
				
				} while (!stop);
			next:
			v.push_back(Question(question,answers,rightanswer));
		}
		for (size_t i = 0; i < v.size(); i++)
		{
			t.questions.push_back(v[i]);
		}
		return;
		
	}
	inline void Admin::AddNewTest(Topic& g)
	{
		string name;
		do {
			system("cls");
			gotoxy((widthh - 22) / 2, 2);
			cout << "���������� ������ �����";
			gotoxy(0, 4);
			for (size_t i = 0; i < widthh; i++)
			{
				cout << "_";
			}
			gotoxy((widthh - 25) / 2, 6);
			cout << "������� �������� �����: ";
			gotoxy((widthh - 25) / 2, 8);			
			name.clear();
			getline(cin, name);
		} while (find(g.vtests.begin(),g.vtests.end(),Test(name))!=g.vtests.end()||name.empty());
		g.vtests.push_back(Test(name));
		system("cls");
		gotoxy((widthh-22)/2,10);
		cout << "���� ������� ��������.";
		system("pause>0");
		return;
	}
	inline void Admin::WatchStats(list<Guest*>& users,GlobalTests&g)
	{
		while (true)
		{
			system("cls");
			gotoxy((widthh - 66) / 2, 2);
			cout << "�������� ������������, ���������� �������� �� ������ ����������: ";
			gotoxy(0, 4);
			for (size_t i = 0; i < widthh; i++)
			{
				cout << "_";
			}
			vector<string>u;
			for (auto i = users.begin(); i != users.end(); i++)
			{
				u.push_back((*i)->getLogin());
			}
			int c = Menu::select_vertical(u, Center);
			switch (c)
			{
			case -1:return; break;
			default:
				system("cls");
				gotoxy((widthh - 46) / 2, 2);
				cout << "��� ��� ��������� ���������� �� ������������ " << u[c];
				gotoxy(0, 4);
				for (size_t i = 0; i < widthh; i++)
				{
					cout << "_";
				}
				for (auto i = users.begin(); i != users.end(); i++)
				{
					if((*i)->getLogin()==u[c])
					(*i)->printStats(g);
				}
				break;
			}
		}
	}
	inline void Admin::AddTest(GlobalTests& g)
	{
		while (true)
		{
			system("cls");
			gotoxy((widthh - 22) / 2, 2);
			cout << "���� ������ ���������";
			gotoxy(0, 4);
			for (size_t i = 0; i < widthh; i++)
			{
				cout << "_";
			}
			gotoxy((widthh - 27) / 2, 6);
			cout << "�������� ��� �������� ����";
			vector<string>v;
			v.push_back("�����");
			v.push_back("������� �����");
			for (size_t i = 0; i < g.topics.size(); i++)
			{
				v.push_back(g.topics[i].name);
			}

			int c = Menu::select_vertical(v, Center);
			switch (c)
			{
			case -1:case 0:return; break;
			case 1:	AddNewTopic(g); break;
			default:AddTestToTopic(g.topics[c-2]); break;
			}
		}
	}
	inline void Admin::TestManaging(GlobalTests& g , list<Guest*>& users)
	{
		while (true)
		{
			system("cls");
			gotoxy((widthh-24)/2,2);
			cout << "���� ���������� �������";
			gotoxy(0,4);
			for (size_t i = 0; i < widthh; i++)
			{
				cout << "_";
			}
			int c = Menu::select_vertical({ "�������� ����","�����"}, Center);
			switch (c)
			{
			case -1:case 1:return; break;
			case 0:AddTest(g); break;
			}
			
		}
	}

	inline void Admin::menu(GlobalTests& g,list<Guest*>&users, map<string, long long>&loginlist)
	{
		while (true)
		{
			system("cls");
			Logo l;
			l.print("Admin menu", Center, 2, Red);
			int c = Menu::select_vertical({"�������� ����������","���������� ��������������","�����" }, HorizontalAlignment::Center);
			switch (c)
			{
			case 0:WatchStats(users,g); break;
			case 1:TestManaging(g,users); break;
			case -1:case 2:return; break;
			}
		}
	}

	


	class Application
	{
		GlobalTests g;
		map<string, long long>loginlist;
		list<Guest*>users;
		void SignUp();
		void SignIn();
		/*void save();*/
	public:	
		void startmenu();
	};
	inline void Application::startmenu()
	{
		while (true)
		{
			system("cls");
			SetColor(Green, Black);
			gotoxy(0, 0);
			for (size_t i = 0; i < widthh; i++)
			{
				cout << "_";
			}
			Logo l;
			l.print("Test", Center, 2, Green);
			gotoxy(0, 7);
			for (size_t i = 0; i < widthh; i++)
			{
				cout << "_";
			}
			cout << endl;
			int c = Menu::select_vertical({ "����","�����������","�����" }, HorizontalAlignment::Center);
			switch (c)
			{
			case 0:SignIn(); break;
			case 1:SignUp(); break;
			case -1:case 2:/*save();*/ return; break;
			}
		}
	}
	inline void Application::SignUp()
	{
		string login;
		char c;
		do
		{
			login.clear();
			system("cls");
			gotoxy((widthh - 14) / 2, 2);
			cout << "������� �����:" << endl;
			gotoxy(0,4);
			for (size_t i = 0; i < widthh; i++)
			{
				cout << "_";
			}
			cout << endl;
			gotoxy(((widthh/2)-(15/2)),6);
			while (true)
			{
				c = _getch();
				switch (c)
				{
				case ENTER:if (login.length() >= 4||login==adminlog)goto next1; break;
				case ESC:return; break;
				case BACK:if (login.length() != 0) {gotoxy(((widthh / 2) - (16 / 2)) + login.length(), 6); cout << " "; login.pop_back(); gotoxy(((widthh / 2) - (16 / 2)) + login.length()+1, 6);} break;
				default:login.push_back((char)c); cout << c; break;
				}
			}		
			next1:
			if (loginlist.find(login) != loginlist.end())
			{
				system("cls");
				gotoxy((widthh - 57) / 2, 2);
				cout << "������������ � ������� "<<login<<" ��� ����������. ������� ����� ������." << endl;
				system("pause>0");
			}
		} while (loginlist.find(login) != loginlist.end());
			
			system("cls");
			gotoxy((widthh-16)/2,2);
			cout << "������� ������:" << endl;
			string pass="";
			gotoxy(0, 4);
			for (size_t i = 0; i < widthh; i++)
			{
				cout << "_";
			}
			gotoxy(((widthh / 2) - (16 / 2)), 6);
			while (true)
			{
				c = _getch();
				switch (c)
				{
				case ENTER:if (pass.length() >= 8)goto next; break;
				case ESC:return; break;
				case BACK:if (pass.length()!=0) { gotoxy(((widthh / 2) - (16 / 2)) + pass.length()-1, 6); cout << " "; pass.pop_back();  gotoxy(((widthh / 2) - (16 / 2)) + pass.length(), 6); } break;
				default:pass.push_back((char)c); cout << "*";break;
				}							
			}
			next:
			if (login == adminlog)
			{
				Guest* guest=new Admin(login, pass);
				loginlist[login] = h(pass);
				users.push_back(guest);
				guest->menu(g, users, loginlist);
			}
			else if (login != adminlog)
			{
				string FIO;
				string ADD;
				string PHO; 
				system("cls");
				gotoxy((widthh-13)/2,2);
				cout << "������� ���:" << endl;
				gotoxy(0, 4);
				for (size_t i = 0; i < widthh; i++)
				{
					cout << "_";
				}
				gotoxy((widthh-13)/2, 6);
				getline(cin,FIO);
				system("cls");
				gotoxy((widthh - 15) / 2, 2);
				cout << "������� �����:" << endl;
				gotoxy(0, 4);
				for (size_t i = 0; i < widthh; i++)
				{
					cout << "_";
				}
				gotoxy((widthh - 15) / 2, 6);
				getline(cin, ADD);
				do
				{
					PHO.clear();
					system("cls");
					gotoxy((widthh - 24) / 2, 2);
					cout << "������� ����� ��������:" << endl;
					gotoxy(0, 4);
					for (size_t i = 0; i < widthh; i++)
					{
						cout << "_";
					}
					gotoxy((widthh - 24) / 2, 6);
					cout << "+";
					getline(cin, PHO);
				} while (PHO.length()!=12);
				system("cls");
				Guest* guest = new User(login, pass, FIO, ADD, PHO);
				loginlist[login] = h(pass);
				users.push_back(guest);
				guest->menu(g, users, loginlist);
				}
			

	}
	inline void Application::SignIn() 
	{
		string login;
		char c;
		do
		{
			login.clear();
			system("cls");
			gotoxy((widthh - 14) / 2, 2);
			cout << "������� �����:" << endl;
			gotoxy(0, 4);
			for (size_t i = 0; i < widthh; i++)
			{
				cout << "_";
			}
			cout << endl;
			gotoxy(((widthh / 2) - (15 / 2)), 6);
			while (true)
			{
				setlocale(0,"");
				c = _getch();
				switch (c)
				{
				case ENTER:if (login.length() >= 4 || login == adminlog)goto next1; break;
				case ESC:return; break;
				case BACK:if (login.length() > 0) { gotoxy(((widthh / 2) - (16 / 2)) + login.length(), 6); cout << " "; login.pop_back(); gotoxy(((widthh / 2) - (16 / 2)) + login.length()+1, 6); } break;
				default:login.push_back((char)c); cout << c; break;
				}
			}
		next1:
			if (loginlist.find(login) == loginlist.end())
			{
				system("cls");
				gotoxy((widthh - 57-login.length()) / 2, 2);
				cout << "������������ � ������� " << login << " �� ������. ������� ����� ������." << endl;
				system("pause>0");
			}
		} while (loginlist.find(login) == loginlist.end());
		string pass ;
		int trycount = 4;
		do
		{
			pass.clear();
			system("cls");
			gotoxy((widthh - 16) / 2, 2);
			cout << "������� ������:" << endl;			
			gotoxy(0, 4);
			for (size_t i = 0; i < widthh; i++)
			{
				cout << "_";
			}
			gotoxy(((widthh / 2) - (16 / 2)), 6);		
			while (true)
			{
				setlocale(0, "");
				c = _getch();
				switch (c)
				{
				case ENTER:if (pass.length() >= 8)goto next; break;
				case ESC:return; break;
				case BACK:if (pass.length() > 0) { gotoxy(((widthh / 2) - (16 / 2)) + pass.length() - 1, 6); cout << " "; pass.pop_back();  gotoxy(((widthh / 2) - (16 / 2)) + pass.length(), 6); } break;
				default:pass.push_back((char)c); cout << "*"; break;
				}
			}
			next:
			if (loginlist.find(login)->second != h(pass)&&trycount!=1)
			{
				system("cls");
				gotoxy((widthh-45)/2,2);
				SetColor(Red,Black);
				cout << "�������� ������ ��������. ���������� �����.";
				gotoxy((widthh - 20) / 2, 3);
				cout<<"������� �������� : "<< --trycount << endl;
				system("pause>0");
				SetColor(White,Black);
			}
			else if (loginlist.find(login)->second != (h(pass)) && trycount == 1)
			{
				system("cls");
				gotoxy((widthh-26)/2,2);
				cout << "�� ��������� ��� �������." << endl;
				system("pause>0");
				trycount = 4;
				return;
			}
		} while ((loginlist.find(login)->second)!= (h(pass)));
		if (login == adminlog && h(pass) == loginlist.find(login)->second)
		{
			Guest* guest = new Admin(login,pass);
			find(users.front(),users.back()+1, guest)->menu(g,users,loginlist);
			delete guest;
		}
		if (login != adminlog)
		{
			Guest* guest = new User(login, pass);
			find(users.front(), users.back()+1, guest)->menu(g, users, loginlist);
			delete guest;
		}
	}
	/*inline void Application::save() 
	{
		if (!loginlist.empty())
		{
			ofstream out("loginlist.txt");
			for (auto i = loginlist.begin(); i !=loginlist.end(); i++)
			{
				out << i->first << endl << i->second << endl;
			}
			out.close();
			CreateDirectoryA("users", NULL);
			for (auto i = users.begin(); i !=users.end(); i++)
			{
				string t = "users//" + ((*i)->getLogin());
				CreateDirectoryA(t.c_str(),NULL);
				for (auto j = (*i)->getPassedTests().begin(); j != (*i)->getPassedTests().end(); j++)
				{
					out.open(t+"//"+j->second.testname+".txt");
					out<< j->second.testname <<endl<< j->second.stop << endl << j->second.passed << endl << j->second.countright<<endl;
					out.close();
				}
			}
		}
		if (!g.topics.empty())
		{
			ofstream out;
			CreateDirectoryA("topics",NULL);
			for (size_t i = 0; i < g.topics.size(); i++)
			{
				string t = "topics//topic"+to_string(i);
				CreateDirectoryA(t.c_str(), NULL);
				out.open(t+"//topicname.txt");
				out << g.topics[i].name;
				out.close();
				t = "topics//tests";
				CreateDirectoryA(t.c_str(), NULL);
				for (size_t s = 0; s < g.topics[i].vtests.size(); s++)
				{
					out.open(t+"//testname.txt");
					out << g.topics[i].vtests[s].name;
					out.close();
					string l = t + "//questions";
					CreateDirectoryA(l.c_str(),NULL);
					for (size_t k = 0; k < g.topics[i].vtests[s].questions.size(); k++)
					{
						out.open(l + "//question" + to_string(k));
						out << g.topics[i].vtests[s].questions[k].question << endl << g.topics[i].vtests[s].questions[k].rightanswer << endl;
						for (size_t w = 0; w < g.topics[i].vtests[s].questions[k].answers.size(); w++)
						{
							out << g.topics[i].vtests[s].questions[k].answers[w] << endl;
						}
						out.close();
					}
					
				}
			}
		}

	}*/
};