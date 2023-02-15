 Trie t;
    t.insertWord("and");
    t.insertWord("ans");
    t.insertWord("bed");
    t.insertWord("bank");
    cout<<t.search("ans")<<endl;
    t.remove("ans");
    cout<<t.search("ans")<<endl;