#include "process.h"

process::process()
{
    executive.PID = 1;
    executive.priority = 1;
}

void process::createProcess(int a,int b) //创建进程,a PID,b 优先级
{
    PCB x;
    x.PID = a;
    x.priority = b;
    ready.push_back(x);
}

void process::undoProcess()         //撤销进程
{
    if(!ready.empty())
    {
        executive = ready.front();
        ready.pop_front();
    }
    else executive.PID = -1;
}

void process::timeout()  //时间片用完
{
    ready.push_back(executive);
    executive = ready.front();
    ready.pop_front();
}

void process::brokeProcess()     //阻塞进程
{
    blocked.push_back(executive);
    if(!ready.empty())
    {
        executive = ready.front();
        ready.pop_front();
    }
    else executive.PID = -1;
}

void process::revokeProcess(int a) //唤醒进程
{
    ready.push_back(blocked.at(a));
    QList<PCB>::iterator i = blocked.begin();
    for (int j = 0; j < a; ++j) ++i;
    blocked.erase(i);
}
