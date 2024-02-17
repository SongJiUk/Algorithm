#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX 1e9

using namespace std;

class Gradecard
{
    public : 
    string name;
    int kor;
    int eng;
    int math;

    Gradecard(string _name, int _kor, int _eng, int _math)
    {
        this->name = _name;
        this->kor = _kor;
        this->eng = _eng;
        this->math = _math;
    }
};

vector<Gradecard> vec;

bool compare(Gradecard a ,Gradecard b)
{
    //국 영 수
    if(a.kor == b.kor && a.eng == b.eng && a.math == b.math) return a.name < b.name;

    if(a.kor == b.kor && a.eng == b.eng) return a.math > b.math;

    if(a.kor == b.kor) return a.eng < b.eng;

    return a.kor > b.kor;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int N;
    cin >> N;

    for(int i =0; i<N; i++)
    {
        string name;
        int kor, eng, math;
        cin >> name >> kor >> eng >> math;

        vec.push_back(Gradecard(name,kor,eng,math));
    }

    sort(vec.begin(), vec.end(), compare);

    for(int i =0; i<N; i++)
    {
        cout << vec[i].name << endl;
    }
}