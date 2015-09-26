#include <iostream>
#include "Serial.h"
#include "Runnable.h"
#include "Listener.h"
#include "Thread.h"
#include "BlockingQueue.h"

using namespace std;

Listener::Listener(const char* portname, BlockingQueue<char*>* queue_):recvd(queue_){
    serialport = new Serial(portname, 9600);
}

Listener::~Listener(){};



void* Listener::run(){
  char* line = new char[128];
  while(true){
    int status = serialport->readLine(line);
    recvd->add(line);
  }
};


void* Listener::start(){
    Thread *th;
    th = new Thread(std::auto_ptr<Runnable>(this),false,Thread::FIFO,2);
    th->start();

};