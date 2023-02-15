#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
    unordered_map<string,int>up;

    //insert
    pair<string,int>p("abc",1);
    up.insert(p);
    up["def"]=2;

    //find or access
    cout<<up["abc"]<<endl;
    cout<<up.at("def")<<endl;

    // cout<<up.at("ghi")<<endl;       
    cout<<"Size:"<<up.size()<<endl;
    cout<<up["ghi"]<<endl;
    cout<<"Size:"<<up.size()<<endl;

    // check presence
    if(up.count("ghi")>0)
    {
        cout<<"ghi is present"<<endl;
    }

    //erase
    up.erase("ghi");
    cout<<"Size:"<<up.size()<<endl;
    if(up.count("ghi")>0)
    {
        cout<<"ghi is present"<<endl;
    }
    return 0;
}