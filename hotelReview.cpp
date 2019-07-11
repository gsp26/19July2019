struct TrieNode
{
    struct TrieNode * children[26];
    bool isEoW;
};

struct TrieNode * getNode()
{
    TrieNode * pNode = new TrieNode;
    pNode->isEoW = false;
    for(int i=0;i<26;i++)
        pNode->children[i] = NULL;
    return pNode;
}

void insert(TrieNode * root,string key)
{
    TrieNode * pcrawl = root;
    for(int i=0;i<key.length();i++)
    {
        int index = key[i] - 'a';
        if(!pcrawl->children[index])
            pcrawl->children[index] = getNode();
        
        pcrawl = pcrawl->children[index];
    }
    pcrawl->isEoW = true;
}

bool search(TrieNode * root, string key)
{
    TrieNode * pcrawl = root;
    for(int i=0;i<key.length();i++)
    {
        int index = key[i] - 'a';
        if(!pcrawl->children[index])
            return false;
        pcrawl= pcrawl->children[index];
    }
    return (pcrawl != NULL && pcrawl->isEoW);
}


vector<int> Solution::solve(string A, vector<string> &B) {
    TrieNode * root = getNode();
    vector<int> res;
    while(A.length() > 0)
    {
        size_t pos = A.find('_');
        if(pos != string::npos)
        {
            string key = A.substr(0,pos);
            A = A.substr(pos+1);
            insert(root,key);
        }
        else
        {
            insert(root,A);
            break;
        }
    }
    multimap<int,int,greater<int> > rc; //index and good review count
    for(int i=0;i<B.size();i++)
    {
        string str = B[i];
        int count = 0;
        while(str.length() > 0)
        {
            size_t pos = str.find('_');
            if(pos != string::npos)
            {
                string key = str.substr(0,pos);
                str = str.substr(pos+1);
                //cout << "GSP1 " << key << " | " << str << endl;
                if(search(root,key))
                    count++;
            }
            else
            {
                //cout << "GSP2 " << str <<" |"<< search(root,str) << endl;
                if(search(root,str))
                    count++;
                break;
            }
        }
        //cout << "GSP: " << count << i << endl;
        rc.insert(make_pair(count,i));
    }
    for(auto itr = rc.begin();itr != rc.end();itr++)
        res.push_back(itr->second);
    return res;
    
}
