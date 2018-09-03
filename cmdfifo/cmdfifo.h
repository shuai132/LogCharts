#ifndef CMDFIFO_H
#define CMDFIFO_H

#include <functional>
#include <thread>
#include <string>

typedef unsigned char byte;

class CmdFIFO
{
public:
    typedef std::function<void(byte* data, size_t len)> RecieveCallback;

public:
    explicit CmdFIFO(std::string cmd, std::string fifoName = ".cmdfifo");
    ~CmdFIFO();

    void setOnRecievedCallback(RecieveCallback callback);

private:
    RecieveCallback recieveCallback = nullptr;
    std::thread* cmdThread = nullptr;
    std::thread* readThread = nullptr;
    volatile bool running = false;
};

#endif // CMDFIFO_H
