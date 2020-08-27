

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
const int mod=1000000009;
int f[2][7*7*7*7*7*7];
int pow7[15];
char w[15][15];
int main(){
    pow7[0]=1;
    for(int i=1;i<15;++i){
        pow7[i]=pow7[i-1]+7;
    }
    for(int i=0;i<6;++i){
        cin<<w[i];
    }
    int now=0;
    f[now][0]=1;
    for(int i=0;i<6;++i){
        for(int j=0;j<6;++j){

        }
    }
}

//第二题 骰子
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const long long infl = 0x3f3f3f3f3f3f3f3fll;

typedef vector<int> Node;

Node up_down_rotate(Node& nd) {
    // 右转一次： 前->右,右->后，后->左，左->前
    return Node({nd[0], nd[1], nd[5], nd[4], nd[2], nd[3]});
}

Node left_right_rotate(Node& nd) {
    // 下翻一次：前->下；上-》前；后-》上；下-》后；
    return Node({nd[5], nd[4], nd[2], nd[3], nd[0], nd[1]});
}

Node fore_back_rotate(Node& nd) {
    // 右翻一次：上->右，左-》上，下-》左；右-》下
    return Node({nd[2], nd[3], nd[1], nd[0], nd[4], nd[5]});
}

// 上下左右前后
void dfs(Node nd, unordered_set<int>& st) {
    int status = 0;
    for(int i = 0; i < nd.size(); ++i) {
        status = status * 6 + nd[i];
    }
    if(st.find(status) != st.end()) {
        return;
    }
    st.insert(status);
    // 右转一次： 前->右,右->后，后->左，左->前
    dfs(up_down_rotate(nd), st);
    dfs(left_right_rotate(nd), st);
    dfs(fore_back_rotate(nd), st);
}


int main() {
#ifdef __LOCAL_WONZY__
    freopen("input-2.txt", "r", stdin);
#endif // __LOCAL_WONZY__
    int n;
    cin >> n;
    vector<Node> nodes(n, Node(6));
    unordered_map<int, int> st_cnt;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 6; ++j) {
            cin >> nodes[i][j];
        }
        unordered_set<int> st;
        dfs(nodes[i], st);
        int status = *min_element(st.begin(), st.end());
        st_cnt[status] += 1;
    }
    vector<int> ans;
    for(auto& pr : st_cnt) {
        ans.push_back(pr.second);
    }
    sort(ans.begin(), ans.end(), [](auto& x, auto& y) {
        return x > y;
    });
    cout << ans.size() << endl;
    for(auto& v : ans) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}


//第三题：美味餐
//N,M,T分别表示中餐种数,晚餐种数和需要满足的美味值
//然后 分别Xi,Yi 表示热量值和美味值
//要求求满足美味值不少于T且热量值最小,输入最小热量值
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXT = 200005;
const int inf = 0x3f3f3f3f;
const long long infl = 0x3f3f3f3f3f3f3f3fll;

int main() {
#ifdef __LOCAL_WONZY__
    freopen("input-3.txt", "r", stdin);
#endif // __LOCAL_WONZY__
    int n, m, t;
    cin >> n >> m >> t;
    vector<pair<int, int>> lunch(n+1), dinner(m+1);
    lunch[0] = dinner[0] = make_pair(0, 0);
    for(int i = 1; i <= n; ++i) {
        cin >> lunch[i].first >> lunch[i].second;
    }
    for(int i = 1; i <= m; ++i) {
        cin >> dinner[i].first >> dinner[i].second;
    }

    sort(lunch.begin(), lunch.end(), [](auto& a, auto& b) {
        return a.second > b.second; // 美味降序
    });
    sort(dinner.begin(), dinner.end(), [](auto& a, auto& b) {
        return a.second > b.second; // 美味降序
    });
    int ans = inf;
    set<int> dinner_st;
    for(int i = n, j = 0; i >= 0; --i) {
        // 放 dinner
        while(j <= m && dinner[j].second+lunch[i].second >= t) {//
            dinner_st.insert(dinner[j].first);
            if(dinner[j].second >= t) ans = min(ans, dinner[j].first);
            ++j;
        }
        if(lunch[i].second >= t) ans = min(ans, lunch[i].first);
        if(!dinner_st.empty()) {
            ans = min(ans, lunch[i].first + (*dinner_st.begin()));
        }
    }
    if(ans == inf) cout << -1 << endl;
    else cout << ans << endl;
	return 0;
}