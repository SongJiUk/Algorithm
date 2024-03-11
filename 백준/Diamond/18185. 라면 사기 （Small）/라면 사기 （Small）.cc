    #include <iostream>
    #include <queue>
    #include <vector>
    #include <algorithm>
    #include <stack>
    #include <string>
    typedef long long ll;

    #define endl '\n'
    #define MAX 1e9
    using namespace std;

    const int three = 7;
    const int two = 5;
    const int one = 3;
    int main(void)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        vector<int> vec;

        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;

            vec.push_back(x);
        }

        int min_count = 0;

        for(int i = 0; i< N; i++)
        {
            if(vec[i +1] > vec[i +2])
            {
                int min_count = min(vec[i], vec[i + 1] - vec[i +2]);

                sum += two * min_count;

                vec[i] -= min_count;
                vec[i+1] -= min_count;

                min_count = min(vec[i], min(vec[i+1], vec[i+2]));
                sum += three * min_count;

                vec[i] -= min_count;
                vec[i+1] -= min_count;
                vec[i+2] -= min_count;
            }
            else
            {
                int min_count = min(vec[i], min(vec[i+1], vec[i+2]));
                
                sum += three * min_count;
                vec[i] -= min_count;
                vec[i+1] -= min_count;
                vec[i+2] -= min_count;

                min_count = min(vec[i], vec[i+1]);
                sum += two * min_count;

                vec[i] -= min_count;
                vec[i +1] -= min_count;
            }

            sum += one * vec[i];
            vec[i] = 0;
        }

       
        cout << sum << endl;
    }
