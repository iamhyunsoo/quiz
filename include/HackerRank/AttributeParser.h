#include <iostream>
#include <unordered_map>

void MakeTable(std::unordered_map<std::string, std::string>& mp, int n, std::string pretag)
{
	if (n == 0) return;

	std::string tag, attr, value, line;

	std::getline(std::cin, line);
	//line1 : <tag1 value = "xxxx" apple = "good">   DONE
	//line2 : <tag2 animal = "monkey">  DONE
	//line3 : </tag2>   IN PROGRESS

	//line4 : <tag3>	
	//line5 : </tag3>
	//last  : </tag1>
	int i = 1;
	if (line[i] == '/')	// </tag2>	// tagVar = "tag1.tag2"
	{
		// when a closing tag
		while (line[i] != '>')
		{
			i++;
		}

		if (pretag.length() > (i - 2))
		{
			tag = pretag.substr(0, pretag.length()-i+1);
		}
		else
		{
			tag = "";
		}
	}
	else
	{
		while (line[i] != ' ' && line[i] != '>') //<tag1>
		{
			i++;
		}

		tag = line.substr(1, i - 1);	// tag2
		if (pretag != "")
		{
			tag = pretag + "." + tag; // tag1.tag2
		}

		int j{ 0 };
		while (line[i] != '>')
		{
			j = ++i;
			while (line[i] != ' ')
			{
				i++;
			}
			attr = line.substr(j, i - j);

			while (line[i] != '\"')
			{
				i++;
			}

			j = ++i;
			while (line[i] != '\"')
			{
				i++;
			}
			value = line.substr(j, i - j);
			i++;

			mp[tag + "~" + attr] = value;
		}
	}
	MakeTable(mp, --n, tag);
}

int main()
{
	int n, q;
	std::cin >> n >> q;
	// []
	// [<tag1>]

	std::cin.ignore();

	std::unordered_map < std::string, std::string > mp;
	MakeTable(mp, n, "");
	// <tag1 value = "xxxx" apple = "good">
	// tagVar = "tag1"
	// {tag1~value, xxxx}
	// {tag1~apple, good}

	//     <tag2 beer = "stellar">
	//     tagVar = "tag1.tag2"
	//	   {tag2~beer, stellar}   ->shouldve been like {tag1.tag2~beer, stellar} 
	//	   </tag2>
	//     tagVar = "tag1"

	// </tag1>

	//  tagVar = ""
	// query : tag1~value   => xxxx : "not found"
	// query : tag1.tag2~beer   => "not found"

	while (q--)
	{
		std::string line;
		std::getline(std::cin, line);

		if (mp.find(line) == mp.end())
		{
			std::cout << "Not Found!" << endl;
		}
		else
		{
			std::cout << mp[line] << endl;
		}
	}
}
