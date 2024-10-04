#include "hw-3.h"

//���� ������, ��������� �������� �� ��� ����������� (��� ������������� �������� � bool)
bool isPalindrome(const std::string& str)
{
	assert(str.size() != 0);
	bool flag = true;
	for (size_t i = 0; i < str.size() / 2 + 1; i++)
	{
		if (str[i] != str[str.size() - 1 - i])
			flag = false;
	}
	return flag;
}

//���� ������, ������������ ������ ������ �������������� ����� � ������� ��������� � ���������� b (0 < b <= 10). ������� ��������������� ����� ����� (��� ������������� �������� � int)
int stringToInt(const std::string& str)
{
	assert(str.find_first_not_of("0123456789") == std::string::npos);
	int num = 0;
	int pow = 1;
	for (size_t i = 0; i < str.size(); i++)
	{
		num += (static_cast<int>(str[str.size() - 1 - i]) - 48) * pow;
		pow *= 10;
	}
	return num;
}

//���� ������, ��������� �� ������� ����, ����������� ��������� (����� ��� �����������). ����� ����� ������ �������� �����
int longestWord(const std::string& str)
{
	int lenght = 0;
	int maxLenght = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			maxLenght = fmax(maxLenght, lenght);
			lenght = -1;
		}
		lenght++;
	}
	maxLenght = fmax(maxLenght, lenght);
	return maxLenght;
}

//��� ������ ����� � ������-�����������. ������������ �� ������� ������� ���� ������ ����������� ������������ ����� ������-�����������
std::string vectorToString(const std::vector<std::string>& vect, const std::string& str)
{
	std::string new_str = "";
	for (size_t i = 0; i < vect.size(); i++)
	{
		new_str += vect[i];
		if (i != vect.size() - 1)
			new_str += str;
	}
	return new_str;
}

//���� ����� ����� N. ������� ������ �� �������� ���������� ���� � ���������� ������� ����� N. ����� ������� 'z' ������ ���� ������ 'a'
std::string alphabetString(int N)
{
	assert(N > 0);
	std::string str = "";
	for (int i = 0; i < N; i++)
		str += static_cast<char>(97 + i % 26);
	return str;
}

//���� ������, ��������� �� ������� ����, ��������� ���������� ������� � ����������� ��������� (����� ��� �����������). ������������ ������ ����, ������������ � ���� ������
std::vector<std::string> stringToVector(const std::string& str)
{
	std::vector<std::string> vect;
	size_t lenght = 0;
	size_t ind = 0;
	bool flag = false;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			vect.push_back(str.substr(ind, lenght));
			lenght = -1;
			flag = true;
		}
		else if (flag && str[i] != ' ')
		{
			ind = i;
			flag = false;
		}
		lenght += 1;
	}
	if (str[str.size() - 1] != ' ')
		vect.push_back(str.substr(ind, lenght));
	return vect;
}

//���� ������, ��������� �� ���������� ����, ��������� ���������� ������� � ����������� ��������� (����� ��� �����������). ������������ ������ �������� �� ��������� ����������� �� ������� ����� � ������: ������� ������ �����, ����� �����
std::vector<Word> stringToWordVector(const std::string& str)
{
	std::vector<Word> vect;
	size_t lenght = 0;
	size_t ind = 0;
	bool flag = false;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			vect.push_back(Word{ str.substr(ind, lenght), ind, lenght });
			lenght = -1;
			flag = true;
		}
		else if (flag && str[i] != ' ')
		{
			ind = i;
			flag = false;
		}
		lenght += 1;
	}
	if (str[str.size() - 1] != ' ')
		vect.push_back(Word{ str.substr(ind, lenght), ind, lenght });
	return vect;
}

void Word::printWord()
{
	std::cout << "�����: " << word << std::endl << "�������: " << poz << std::endl << "�����: " << lenght << std::endl << std::endl;
}