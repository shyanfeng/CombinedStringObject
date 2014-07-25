#ifndef _FILE_REGISTER_H_
#define _FILE_REGISTER_H_

extern unsigned char fileRegisters[4096];

int getFileRegData(int address, int access);
int setFileRegData(int address, int access, int data);

#endif //_FILE_REGISTER_H_