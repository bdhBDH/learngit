#include <iostream>
#include <vector>
using namespace std;

class Game{
public:
    virtual void initialize(){}
    virtual void startPlay(){}
    virtual void endPlat(){}
    // 不能被子类别重写
    virtual void play() final
    {
        cout << "" << endl;
    }
};
class Cricket:public Game{
public:
    void initialize(){}
    void startPlay(){}
    void endPlay(){}
};
class Football:public Game{
//public:
    void endPlay(){}
    void startPlay(){}
};

int main()
{
    Game* game = new Cricket();
    game->play();
    Game* game2 = new Football();
    game2->play();
    delete game;
    delete game2;
    return EXIT_SUCCESS;
}

