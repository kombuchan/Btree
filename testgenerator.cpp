//testgenerator.cpp, selftest.sh, resettest.sh, SeanBTree
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

void generateTestCase(void)
{
    ofstream out("BTreeTest.txt");
    out << "testing file" << endl; //skip first line

    vector<int> inserts;
    vector<int> deletes;

    for(int i = 0; i < 100; i++)
    {
        inserts.push_back(i);
        deletes.push_back(i);
    }
    random_shuffle(inserts.begin(), inserts.end());
    random_shuffle(deletes.begin(), deletes.end());

    while(inserts.size() != 0)
    {
        out << "i" << inserts.back() << " ";
        inserts.pop_back();
    }
    while(deletes.size() != 0)
    {
        out << "d" << deletes.back() << " ";
        deletes.pop_back();
    }
    out.close();
}

void generateArgs(void)
{
    int M = rand() % 8 + 3;
    int L = rand() % 8 + 3;

    ofstream out("args1.sh");
    out << "#! /bin/bash" << endl;
    out << "./BTree BTreeTest.txt ";
    out << M << " "; //3-10 for M
    out << L; //3-7 for 10
    out.close();

    ofstream tout("args2.sh");
    tout << "#! /bin/bash" << endl;
    tout << "./SeanBTree BTreeTest.txt ";
    tout << M << " "; //3-7 for M
    tout << L; //3-7 for L
    tout.close();
}

int main(void)
{
    srand(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
    generateTestCase();
    generateArgs();
}
