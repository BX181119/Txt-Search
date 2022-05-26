#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
void word_split();

int main()
{
	word_split();
	return 0;
}

void word_split()
{
	vector<string> WordVector;
	fstream fs;
	char filename[20] = { 0 };
	cout << "请输入打开的文件名:";
	cin >> filename;
	fs.open(filename);
	cout << "打开成功" << filename << endl;
	char buf[1024] = { 0 };
	string line, word; 
	while (fs.getline(buf, 1024))
	{
		size_t pos; 
		line = buf;  
		pos = line.find_first_of(",.;:'?!()/\"");
		while (pos != string::npos)
		{
			line.erase(pos, 1); 
			pos = line.find_first_of(",.;:'?!()/\"");
		}
		pos = line.find(" ");  
		while (pos != string::npos)
		{
			word = line.substr(0, pos);
			WordVector.push_back(word);
			line.erase(0, pos + 1);
			pos = line.find(" ");
		}
	}
	//vector<string>::iterator it;
	//for (it = WordVector.begin(); it != WordVector.end(); it++)
	//{
	//	cout << (*it).c_str() << endl;
	//}
	//cout << "总的个数:" << WordVector.size();
	fs.close();
}