#ifndef _FILE_REGISTER_H_
#define _FILE_REGISTER_H_

#define	BSR 	0xFE0
extern unsigned char fileRegisters[4096];

int getFileRegData(int address, int access);
int setFileRegData(int address, int access, int data);
int findActualFileRegister(int address, int access);
void clearAllFileRegisters();

#endif //_FILE_REGISTER_H_