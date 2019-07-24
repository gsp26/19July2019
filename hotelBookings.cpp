bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    
    sort(arrive.begin(),arrive.end());
    sort(depart.begin(),depart.end());
    
    int count = 0;
    
    int i=0;
    int j=0;
    
    while ( i < arrive.size() && j < depart.size() )
    {
        if(arrive[i] < depart[j])
        {
            count++;
            if(count > K )
                return false;
            i++;
        }
        else
        {
            j++;
            count--;
        }
    }
    return true;
}
