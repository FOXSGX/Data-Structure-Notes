#include <iostream>
using namespace std;

struct Monster{
    int ihp; //initial hp;
    int hp;
    bool alive = true;
    bool revived = false;
};

//单兽战斗
int fight(Monster& x,Monster& y){
    if (x.hp == y.hp){
        x.hp = 0;
        x.alive = false;
        y.hp = 0;
        y.alive = false;
        return 0;
    }
    else if (x.hp > y.hp){
        x.hp = x.hp - y.hp;
        y.hp = 0;
        y.alive = false;
        return 1;
    }
    else{
        x.alive = false;
        y.hp = y.hp - x.hp;
        x.hp = 0;
        return -1;
    }
}

//兽群战斗
void battle(Monster* a,Monster* b,int n,int& win_streak){
    int total = 0;
    int s;
    int x = 0;
    int y = 0;

    while (x<n && y<n){
        if (a[x].alive && b[y].alive){
            s = fight(a[x],b[y]);
            x++;
            y++;
            total += s;
        }
        else if (!a[x].alive && !b[y].alive){
            x++;
            y++;
        }
        else if(!a[x].alive) x++;
        else if(!b[y].alive) y++;
    }
    if (total==0){
        win_streak = 0;
        return;
    }
    if (total>0){
        if (win_streak>0) win_streak++;
        else win_streak=1;
        return;
    }
    if (total<0){
        if (win_streak<0) win_streak--;
        else win_streak=-1;
        return;
    }
}

//复活机制
void revive(Monster* a,Monster* b,int n,int& win_streak){
    if (win_streak == 3){
        //触发兽群B复活
        int x = -1;  //复活者编号
        for (int i=0;i<n;i++){
            if (!b[i].alive && !b[i].revived){
                if (x<0) x=i;
                else if (b[i].ihp > b[x].ihp) x=i;
            }
        }
        if (x>=0){
            b[x].hp = b[x].ihp;
            b[x].alive = true;
            b[x].revived = true;
        }
        win_streak = 0;
    }
    else if (win_streak == -3){
        //触发兽群A复活
        int x = -1;  //复活者编号
        for (int i=0;i<n;i++){
            if (!a[i].alive && !a[i].revived){
                if (x<0) x=i;
                else if (a[i].ihp > a[x].ihp) x=i;
            }
        }
        if (x>=0){
            a[x].hp = a[x].ihp;
            a[x].alive = true;
            a[x].revived = true;
        }
        win_streak = 0;
    }
}

//结束判定
int ifend(Monster* a,Monster* b,int n){
    bool a_alive = 0;
    bool b_alive = 0;       //是否还有存活怪兽
    for (int i=0;i<n;i++){
        if (a[i].alive){
            a_alive = 1;
            break;
        }
    }
    for (int i=0;i<n;i++){
        if (b[i].alive){
            b_alive = 1;
            break;
        }
    }
    if (a_alive == 1 && b_alive == 1) return 1;     //双方存活，战斗继续
    else if (a_alive == 1 && b_alive == 0) return 2;     //A获胜
    else if (a_alive == 0 && b_alive == 1) return 3;     //B获胜
    else return 4;     //平局
}

int main(){
    //Initialize
    int n;                      //兽群大小
    cin >> n;
    Monster* a = new Monster[2000];
    Monster* b = new Monster[2000];
    int rounds = 0;             //战斗总轮数
    int win_streak = 0;         //正表示a连胜，负表示b连胜
    int result = 1;
    
    for (int i=0;i<n;i++){
        cin >> a[i].ihp;
        a[i].hp = a[i].ihp;
    }
    for (int i=0;i<n;i++){
        cin >> b[i].ihp;
        b[i].hp = b[i].ihp;
    }

    while (result == 1){
        rounds++;
        battle(a,b,n,win_streak);
        revive(a,b,n,win_streak);
        result = ifend(a,b,n);
    }

    if (result == 2){
        cout << "A\n";
        cout << rounds << "\n";
        bool flag = true;
        for (int i=0;i<n;i++){
            if (a[i].alive){
                if (flag){
                    cout << a[i].hp;
                    flag = false;
                }
                else{
                    cout << " " << a[i].hp;
                }
            }
        }
        cout << "\n" << "EMPTY";
    }
    else if (result == 3){
        cout << "B\n";
        cout << rounds << "\n";
        cout << "EMPTY" <<"\n";
        bool flag = true;
        for (int i=0;i<n;i++){
            if (b[i].alive){
                if (flag){
                    cout << b[i].hp;
                    flag = false;
                }
                else{
                    cout << " " << b[i].hp;
                }
            }
        }
    }
    else if (result == 4){
        cout << "DRAW\n";
        cout << rounds << "\n";
        cout << "EMPTY" << "\n";
        cout << "EMPTY" << "\n";
    }

    delete[] a;
    delete[] b;
    return 0;


}
