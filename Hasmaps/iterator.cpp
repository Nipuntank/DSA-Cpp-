 #include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
    unordered_map<string,int> ourmap;
    ourmap["abc"]=1;
    ourmap["abc2"]=2;
    ourmap["abc3"]=3;
    ourmap["abc4"]=4;
    ourmap["abc5"]=5;
    ourmap["abc6"]=6;
    unordered_map<string,int>::iterator it=ourmap.begin();

    while(it!=ourmap.end())
    {
        cout<<"Key :"<<it->first<<"Value:"<<it->second<<endl;
        it++;
    } 

    //find
    unordered_map<string,int>::iterator it2=ourmap.find("abc");
    
        ourmap.erase(it,it+2);
    return 0;
}