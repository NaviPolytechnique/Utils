#ifndef LISTENER_HEADER_H
#define LISTENER_HEADER_H

#include<iostream>
#include"Serial.h"
#include "Runnable.h"
#include "BlockingQueue.h"




class Listener : public Runnable{
  
public : 
  Listener(const char* portname, BlockingQueue<char*>* queue_);
  ~Listener();
  void* run();
  void start();
  
  void write(char* msg);
  
private : 
  Serial* serialport;
  BlockingQueue<char*>* recvd;
  
  
};

#endif