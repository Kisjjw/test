#include<iostream>
using namespace std;
//多态案例-制作饮品
class AbstractDrinking
{
public:

//煮水
virtual void Boil() = 0;
//冲泡
virtual void Brew() = 0;
//倒入杯中
virtual void Pour() = 0;
//加入辅料
virtual void PutSomething() = 0;
//制作饮品
void makeDrink()
{
Boil();
Brew();
Pour();
PutSomething();
}
};
//制作咖啡
class Coffee :public AbstractDrinking
{
public:
//煮水
 void Boil()
{
cout << "把水煮开" << endl;
}
//冲泡
 void Brew()
{
cout << "冲泡咖啡" << endl;
}
//倒入杯中
 void Pour()
{
cout << "倒入杯中" << endl;
}
//加入辅料
 void PutSomething()
{
cout << "加入糖和牛奶" << endl;
}
};
//制作函数
void DoWork(AbstractDrinking* abs)//父类指针指向子类对象AbstractDrinking* abs = new Coffee;
{
abs->makeDrink();
delete abs;//手动释放
//堆区的数据被销毁了但是指针的类型没变
}
//制作
void test()
{
DoWork(new Coffee);
cout << "------我是分割线------" << endl;
}
int main(void)
{
test();
system("pause");
return 0;
}