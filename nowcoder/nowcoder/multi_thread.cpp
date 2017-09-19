
#include <iostream>
#include <thread>

#include <windows.h>

using namespace std;

int worker1(int num) {
    for (int i = 0; i < num; ++i) {
        cout << "thread1 is working!" << endl;
        Sleep(200);
    }

    return 0;
}

int worker2(int num) {
    for (int i = 0; i < num; ++i) {
        cout << "thread2 is working!" << endl;
        Sleep(200);
    }

    return 0;
}

class Runnable {
public:
    virtual ~Runnable(){}

    virtual void Run() = 0;
};

class CThread : public Runnable {
private:
    explicit CThread(const CThread& rhs);
public:
    CThread()
        : m_pRunnable(NULL)
        , m_bRun(false)
    {
        // nothing to do
    }

    CThread(Runnable* pruns)
        : m_pRunnable(pruns)
        , m_bRun(false)
        , m_threadName("")
    {

    }

    CThread(char* thname, Runnable* pruns = NULL)
        : m_pRunnable(pruns)
        , m_threadName(thname)
        , m_bRun(false)
    {

    }

    CThread(string thname, Runnable* pruns = NULL)
        : m_pRunnable(pruns)
        , m_threadName(thname)
        , m_bRun(false)
    {

    }

    ~CThread()
    {

    }

    bool Start(bool bsuspend = false) {
        if (m_bRun) {
            return true;
        }

        return false;
    }

    virtual void Run() {

    }

    void Join(int timeout = -1) {

    }

    void Resume() {

    }

    void Suspend() {

    }

    bool Terminate(unsigned long ExitCode) {
        return false;
    }

    unsigned int GetThreadID() {
        return m_threadID;
    }

    string GetThreadName() {
        return m_threadName;
    }

    void SetThreadName(char* thname) {
        m_threadName = thname;
    }

    void SetThreadName(string thname) {
        m_threadName = thname;
    }

private:
    static unsigned int WINAPI StaticThreadFunc(void* arg) {

    }

private:
    HANDLE m_handle;
    Runnable* const m_pRunnable;
    unsigned int m_threadID;
    string m_threadName;
    volatile bool m_bRun;
};

int test_multi_thread() {
    thread th1(worker1, 5);
    thread th2(worker2, 5);
    //th1.join();
    //th2.join();
    th1.detach();
    th2.detach();

    for (int i = 0; i < 5; ++i) {
        cout << "Main thread is working!" << endl;
        Sleep(200);
    }

    //system("pause");

    return 0;
}