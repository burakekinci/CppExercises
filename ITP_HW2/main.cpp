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
using namespace std;


// Data structure to store a graph edge
struct Edge {
    string src, dest;
};


class Graph
{
public:
    vector<vector<string>> adjList;
    Graph();
};

Graph::Graph()
{
    //graph constructor
}

void readFile(ifstream& file, vector<Edge>& edges);

int main()
{
    vector<Edge> edges;
    ifstream inputFile;
    inputFile.open("input.txt");
    if (inputFile.is_open())
    {
        cout << "Input dosyasi basariyla acildi\n";
        readFile(inputFile,edges);
    }
    else
    {
        cout << "Input dosyasi ACİLAMADİ!!\n";
    }

    return 0;
}

void readFile(ifstream& file, vector<Edge>& edges) 
{
    string tmpStr=" ";
    
    //read all nodes, first row of input.txt file
    getline(file, tmpStr);                                  
    
    //Seperate nodes according to commas then push back nodes to the Nodes vector
   /* stringstream ss(tmpStr);
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        nodes.push_back(substr);
    }
    */

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
        string node_dest = tmpStr.substr(tmpStr.find(delimiter)+2);
        
        edges.push_back({ node_src, node_dest });
    }

    //get the paths informations
    while (getline(file, tmpStr))
    {
        cout << tmpStr << "\n";
    }
}