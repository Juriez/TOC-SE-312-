
#include<bits/stdc++.h>
using namespace std;

int main()
{


    map<char, pair<set<char>, pair<set<char>, set<char> > > > nfa;//    state       epsilon           0            1

    int link, state;
    cout<<"Enter the number of state :"<<endl;
    cin >> state;
    cout<<"Enter the alphabets :"<<endl;
    for(int i=0; i<state; i++)
    {
        char ste;
        cin >> ste;

        nfa.insert({ste, {{}, {{},{}}}});
    }
    cout<<"Enter the number of edge :"<<endl;
    cin >> link;

    cout<<"Enter source & destination for corresponding transition :"<<endl;
    for(int i=0; i<link; i++)
    {
        char source, transition,destination ;
        cin >> source >> transition >> destination;

        if(transition=='e')
        {
            nfa[source].first.insert(destination);
        }
        else if(transition=='0')
        {
            nfa[source].second.first.insert(destination);
        }
        else if(transition=='1')
        {
            nfa[source].second.second.insert(destination);
        }
    }

    //             states            0          1
    vector<pair<set<char>, pair<set<char>, set<char> > > > dfa;
    map<char, set<char> > e_close;
    queue<set<char> > q;
    map<set<char>, bool> vis;

    e_close[NULL]= {};
    // according to dfs concept
    for(auto itr : nfa)
    {
        set<char>st;

        st.insert(itr.first);

        queue<char>qs;

        qs.push(itr.first);

        while(!qs.empty())
        {
            char ch=qs.front();
            qs.pop();

            for(char c : nfa[ch].first)
            {
                qs.push(c);
                st.insert(c);
            }
        }

        e_close.insert({itr.first, st});
    }

    printf("e-closures are : ");

    for(auto it : e_close)
    {
        cout << it.first << "\t";
         cout<<"{";
        for(auto c : it.second)
        {
            cout << c << " ";
        }
        cout << "}"<< "\n";
    }
    cout<<"Enter starting state: \n";
    char start_state, end_state;
    cin >> start_state ;
    cout<<"Enter final state: \n";
    cin>> end_state;

    q.push(e_close[start_state]);

    // bfs er moto
    while(!q.empty())
    {
        set<char> gt;
        char c0=NULL, c1=NULL;

        gt=q.front();

        q.pop();

        if(vis.find(gt)!=vis.end() and vis[gt]==1)
        {
            continue;
        }

        vis[gt]=true;

        for(auto itr : gt)
        {
            for(char ch : nfa[itr].second.first)
            {
                if(ch >= 'a' and ch <= 'z')
                {
                    c0=ch;
                    break;
                }
            }
        }

        for(auto itr : gt)
        {
            for(char ch : nfa[itr].second.second)
            {
                if(ch >= 'a' and ch <= 'z')
                {
                    c1=ch;
                    break;
                }
            }
        }

        dfa.push_back({gt, {e_close[c0], e_close[c1]}});

        if(c0!=NULL)
        {
            q.push(e_close[c0]);
        }

        if(c1!=NULL)
        {
            q.push(e_close[c1]);
        }

        if(c0==c1 and c0!=NULL)
        {
            q.pop();
        }
    }

    printf("\n\nThe DFA table:\n\n");

    for(auto itr=dfa.begin(); itr!=dfa.end(); itr++)
    {

        printf("  ({");

        for(auto itr1=itr->first.begin(); itr1!=itr->first.end(); itr1++)
        {
            cout << *itr1;
            auto itr2=itr1;
            itr2++;
            if(itr2!=itr->first.end())
            {
                cout << ",";
            }
        }
        cout << "}, 0) \t\t= {";

        for(auto itr1=itr->second.first.begin(); itr1!=itr->second.first.end(); itr1++)
        {
            cout << *itr1;
            auto itr2=itr1;
            itr2++;
            if(itr2!=itr->second.first.end())
            {
                cout << ",";
            }
        }
        cout << "}\n";



        printf("  ({");


        for(auto itr1=itr->first.begin(); itr1!=itr->first.end(); itr1++)
        {
            cout << *itr1;
            auto itr2=itr1;
            itr2++;
            if(itr2!=itr->first.end())
            {
                cout << ",";
            }
        }
        cout << "}, 1) \t\t= {";

        for(auto itr1=itr->second.second.begin(); itr1!=itr->second.second.end(); itr1++)
        {
            cout << *itr1;
            auto itr2=itr1;
            itr2++;
            if(itr2!=itr->second.second.end())
            {
                cout << ",";
            }
        }
        cout << "}\n\n";
    }

    printf("Starting state is: { ");

    for(auto ch : e_close[start_state])
    {
        cout << ch << " ";
    }
    cout << "}\n\n";

    printf("Accepting states : ");

    for(auto itr : dfa)
    {
        set<char>get;

        get=itr.first;

        bool has_ending_state=false;

        for(auto ch : get)
        {
            if(ch == end_state)
            {
                has_ending_state=true;
                break;
            }
        }

        if(!has_ending_state)
        {
            continue;
        }

        cout << "{ ";

        for(auto ch : get)
        {
            cout << ch << " ";
        }
        cout << "} ";
    }
    cout << "\n\n";
}

/*
3
a b c
4
a p b
a 0 c
b p c
b 1 c
a c
5
a b c d e
5
a e b
a e c
b 0 d
c 1 d
d 1 e
a e
*/
