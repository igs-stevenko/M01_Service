#ifndef __DO_COMMAND_H__
#define __DO_COMMAND_H__

int do_command(const char *Cmd, unsigned char *RtnBuffer, int *RtnBufferLen);
int do_traceroute(unsigned char *RtnBuffer, int *RtnBufferLen);

#endif

