//////////////////////////////////////////
// Burak EKİNCİ
// 1306181431
// Date: 2021.05.20
// IDE: Visual Studio 2019
///////////////////////////////////////////
// Ek açıklamalar burada yapılacaktır.
//////////////////////////////////////////

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

void readFile(ifstream& file, map<string, vector<string>>& _map, vector<string>& _paths);




int main()
{
    map<string, vector<string>> map;
    vector<string> paths;
    ifstream inFile;
    inFile.open("input.txt");
    if (inFile.is_open())
    {
        cout << "Input dosyasi basariyla acildi\n";
        readFile(inFile, map, paths);
    }
    else
    {
        cout << "Input dosyasi ACİLAMADİ!!\n";
    }
    return 0;
}

void readFile(ifstream& file, map<string,vector<string>>& _map, vector<string>& _paths)
{
    string tmpStr = " ";

    //read all nodes, first row of input.txt file
    getline(file, tmpStr);

    //get the "Links:" string
    getline(file, tmpStr);
    if (tmpStr == "Links:")
        cout << "Links bulundu\n";
    else
        cout << "Links Bulunamadi!!\n";

    //read only node source and node destinations  like "A1->B1"
    while (getline(file, tmpStr))
    {
        if (tmpStr == "Paths:")
        {
            cout << "Paths bulundu\n";
            break;
        }
        string delimiter = "->";
        string node_src = tmpStr.substr(0, tmpStr.find(delimiter));
        string node_dest = tmpStr.substr(tmpStr.find(delimiter) + 2);
        
        //first check is node_src in the map keys
        //if node_src is not in map then...
        if (_map.find(node_src) == _map.end())
        {
            //add node_src into the map keys with node_dest implemented vector
            _map.insert(pair<string, vector<string>>(node_src, vector<string>{node_dest}));
        }
        //if node_src is in map then...
        else
        {
            //add node_dest into the value vector of node_src 
            map<string, vector<string>>::iterator it = _map.find(node_src);
            it->second.push_back(node_dest);
        }
    }

    //get the paths informations
    while (getline(file, tmpStr))
    {
        _paths.push_back(tmpStr);
    }
}
