// 4.14.Chú lùn Hugo đang bị lạc vào một mê cung hình chữ nhật gồm M dòng và N  cột, M, N≤100. Các dòng (cột) đánh số từ 1 đến M (từ 1 đến N) từ trên xuống (từ trái sang). Hugo đang đứng ở ô (X,Y). Từ một ô bất kỳ, trong mỗi bước di chuyển,  Hugo có thể di chuyển đến 1 trong 8 ô chung quanh. Mỗi ô của mê cung ứng với  một số trong phạm vi 0 đến 255 với ý nghĩa quy định những hướng Hugo có thể di  chuyển từ ô đó. Quy định đó như sau: 
// Giả sử biểu diễn với 8 bit của số tại ô Hugo đang đứng (ghi chữ H) là  b0b1b2b3b4b5b6b7, ta đánh số các ô chung quanh ô đó với các số 7..0, với 0≤I≤7,  Hugo di chuyển theo hướng I nếu và chỉ nếu bit bi=1.
// Bài tập Kỹ thuật lập trình – Trần Công Tú Trang 1/2 
// Yêu cầu: Hãy chỉ cho Hugo một hành trình qua ít ô nhất để có thể thoát khỏi  mê cung nếu có thể. Chú ý rằng Hugo có thể di chuyển ra một ô biên nhưng từ ô  biên đó Hugo không đi ra ngoài mê cung được. 
// Dữ liệu: Vào từ file HUGO.INP trong đó dòng thứ nhất ghi 2 số M, N, tiếp  theo là M dòng, dòng thứ I ghi N số tương ứng với các ô dòng thứ I của mê  cung. Dòng cuối cùng ghi 2 số X,Y. 
// Kết quả: Ghi ra file HUGO.OUT như sau: dòng thứ nhất ghi số nguyên  không âm C mà C=0 nếu Hugo không ra khỏi mê cung được, nếu C>0, đó chính  là số ô trên hành trình Hugo đi ra khỏi mê cung. Nếu C>0, trong C dòng tiếp  theo, mỗi dòng ghi chỉ số dòng và chỉ số cột của một ô lần lượt trên hành trình  của Hugo bắt đầu từ ô (X,Y) và cuối cùng là ô trên biên mà từ ô đó Hugo có thể 
// ra khỏi mê cung. 
#include <iostream>
using namespace std;

int M, N;
int maze[105][105];
bool visited[105][105];
pair<int,int> parent[105][105];

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

bool inside(int x, int y){
    return x>=1 && x<=M && y>=1 && y<=N;
}

int main(){
    cin >> M >> N;
    for(int i=1;i<=M;i++)
        for(int j=1;j<=N;j++)
            cin >> maze[i][j];

    int X, Y;
    cin >> X >> Y;

    queue<pair<int,int>> q;
    q.push({X,Y});
    visited[X][Y] = true;

    pair<int,int> exitCell = {-1,-1};

    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();

        if(x==1 || x==M || y==1 || y==N){
            exitCell = {x,y};
            break;
        }

        int val = maze[x][y];
        for(int i=0;i<8;i++){
            if(val & (1<<i)){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(inside(nx,ny) && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    parent[nx][ny] = {x,y};
                    q.push({nx,ny});
                }
            }
        }
    }

    if(exitCell.first == -1){
        cout << 0;
        return 0;
    }

    vector<pair<int,int>> path;
    for(auto cur = exitCell; cur.first!=0; ){
        path.push_back(cur);
        cur = parent[cur.first][cur.second];
    }
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for(auto &p : path)
        cout << p.first << " " << p.second << "\n";
}

