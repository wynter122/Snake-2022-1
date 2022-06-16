#include <vector>
#include "Snake.h"
using namespace std;
/*############################
전역 변수 느낌으로 사용하는 클래스
1. 맵 업데이트시 정보갱신 -> allWallLoc, wallLoc
    allWallLock: 스네이크의 머리가 움직이는 부분 (머리위치가 변하는 부분) 에서 사용 -> die
                맵 내부에 벽이 있는 경우 item 리젠시 사용 (맵 위치와 일치하면 다시 난수 생성)
    wallLoc: gate 생성시 이 값들 중에서 사용

2. 스네이크 움직임시 정보갱신 -> snakeLoc
    item 리젠시 사용 (스네이크 바디 위치와 일치하면 다시 난수 생성)

3. item 리젠될때마다 정보갱신 -> growthLoc, poisonLoc
    스네이크 머리가 움직이는 부분 (머리위치가 변하는 부분) 에서 사용 -> score +/-

4. gate 생길때마다 정보갱신 -> gateLoc
    스네이크 머리가 움직이는 부분에서 사용 -> 두 gate 중 남은 gate 값으로 스네이크 이동
############################*/
class Info
{
public:
    static vector<vector<int>> snakeLoc;   // snake body 위치 ((x, y), (x, y)...)
    static vector<vector<int>> allWallLoc; // 모든 벽 위치 (immune wall 포함)
    static vector<vector<int>> wallLoc;    // 벽 위치 (immune wall 제외)
    static vector<vector<int>> planeLoc;
    static vector<int> growthLoc;       // growth 위치 (x, y)
    static vector<int> poisonLoc;       // poison 위치 (x, y)
    static vector<vector<int>> gateLoc; // gate 위치 (1번:(x, y), 2번(x, y))

    Info();
    static void setSnakeLoc(Snake snake);
    void setAllWallLoc(vector<int> v);
    void setWallLoc(vector<int> v);
    void setPlaneLoc(vector<int> v);
    void setGrowthLoc(int x, int y);
    void setPoisonLoc(int x, int y);
    void setGateLoc(vector<int> v);
};
