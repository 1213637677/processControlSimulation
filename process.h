#ifndef PROCESS_H
#define PROCESS_H

#include <qlist.h>
#include <qqueue.h>

struct PCB{
    int PID;
    int priority;
    PCB()
    {
        PID = 0;
        priority = 0;
    }
};
typedef QQueue<PCB> QUEUEPCB;
typedef QList<PCB> LISTPCB;
class process
{
public:
    process();
    void createProcess(int a,int b);      //创建进程,a PID,b 优先级
    void undoProcess();                    //撤销进程
    void brokeProcess();                        //阻塞进程
    void revokeProcess(int a);                       //唤醒进程
    void timeout();                  //时间片用完


    QUEUEPCB ready;          //就绪状态
    PCB  executive;      //执行状态
    LISTPCB blocked;        //阻塞状态
    LISTPCB::iterator i;
};

#endif // PROCESS_H
