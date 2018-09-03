#include "cmdfifo.h"

#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <zconf.h>

#define BUFFER_SIZE PIPE_BUF

CmdFIFO::CmdFIFO(std::string cmd, std::string fifoName)
{
    running = true;

    cmdThread = new std::thread([cmd, fifoName]{
        const char* FIFO_NAME = fifoName.c_str();

        if (access(FIFO_NAME, F_OK) == -1) {
            int res = mkfifo(FIFO_NAME, 0777);
            if (res != 0) {
                fprintf(stderr, "Could not create fifo %s\n", FIFO_NAME);
                exit(EXIT_FAILURE);
            }
        }
        system((cmd + " > " + FIFO_NAME).c_str());
    });

    readThread = new std::thread([this, fifoName]{
        const char* FIFO_NAME = fifoName.c_str();

        int pipe_fd;

        int open_mode = O_RDONLY | O_NONBLOCK;
        unsigned char buffer[BUFFER_SIZE];

        printf("Process %d opeining FIFO O_RDONLY\n", getpid());
        pipe_fd = open(FIFO_NAME, open_mode);
        printf("Process %d result %d\n", getpid(), pipe_fd);

        int len;
        if (pipe_fd != -1) {
            do {
                len = read(pipe_fd, buffer, BUFFER_SIZE);
                if (len > 0) {
                    printf("%s, %d\n", buffer, len);    // risc
                    if(this->recieveCallback) {
                        this->recieveCallback(buffer, len);
                    }
                }
                else {
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
            } while(running);
            close(pipe_fd);
        }
        else {
            exit(EXIT_FAILURE);
        }
    });
}

CmdFIFO::~CmdFIFO()
{
    running = false;

    if (cmdThread) {
        cmdThread->join();
        delete cmdThread;
    }
    if (readThread) {
        readThread->join();
        delete readThread;
    }
}

void CmdFIFO::setOnRecievedCallback(CmdFIFO::RecieveCallback callback)
{
    this->recieveCallback = callback;
}
