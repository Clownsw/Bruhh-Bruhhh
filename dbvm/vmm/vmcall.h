#ifndef VMCALL_H_
#define VMCALL_H_

#include "vmmhelper.h"
#include "vmcallstructs.h"

#define VMCALL_GETVERSION 0
#define VMCALL_CHANGEPASSWORD 1
#define VMCALL_READ_PHYSICAL_MEMORY 3
#define VMCALL_WRITE_PHYSICAL_MEMORY 4
#define VMCALL_REDIRECTINT1 9
#define VMCALL_INT1REDIRECTED 10
#define VMCALL_CHANGESELECTORS 12
#define VMCALL_BLOCK_INTERRUPTS 13
#define VMCALL_RESTORE_INTERRUPTS 14

#define VMCALL_REGISTER_CR3_EDIT_CALLBACK 16
#define VMCALL_RETURN_FROM_CR3_EDIT_CALLBACK 17
#define VMCALL_GETCR0 18
#define VMCALL_GETCR3 19
#define VMCALL_GETCR4 20
#define VMCALL_RAISEPRIVILEGE 21
#define VMCALL_REDIRECTINT14 22
#define VMCALL_INT14REDIRECTED 23
#define VMCALL_REDIRECTINT3 24
#define VMCALL_INT3REDIRECTED 25

//dbvm v6+
#define VMCALL_READMSR 26
#define VMCALL_WRITEMSR 27

#define VMCALL_ULTIMAP 28
#define VMCALL_ULTIMAP_DISABLE 29


//dbvm v7
#define VMCALL_SWITCH_TO_KERNELMODE 30
#define VMCALL_DISABLE_DATAPAGEFAULTS 31
#define VMCALL_ENABLE_DATAPAGEFAULTS 32
#define VMCALL_GETLASTSKIPPEDPAGEFAULT 33

#define VMCALL_ULTIMAP_PAUSE 34
#define VMCALL_ULTIMAP_RESUME 35

#define VMCALL_ULTIMAP_DEBUGINFO 36

#define VMCALL_PSODTEST 37

//dbvm11
#define VMCALL_GETMEM 38
#define VMCALL_JTAGBREAK 39
#define VMCALL_GETNMICOUNT 40

#define VMCALL_WATCH_WRITES 41
#define VMCALL_WATCH_READS 42
#define VMCALL_WATCH_RETRIEVELOG 43
#define VMCALL_WATCH_DELETE 44

#define VMCALL_CLOAK_ACTIVATE 45
#define VMCALL_CLOAK_DEACTIVATE 46
#define VMCALL_CLOAK_READORIGINAL 47
#define VMCALL_CLOAK_WRITEORIGINAL 48

#define VMCALL_CLOAK_CHANGEREGONBP 49
#define VMCALL_CLOAK_REMOVECHANGEREGONBP 50

#define VMCALL_EPT_RESET 51

#define VMCALL_LOG_CR3VALUES_START 52
#define VMCALL_LOG_CR3VALUES_STOP 53

#define VMCALL_REGISTERPLUGIN 54
#define VMCALL_RAISEPMI 55
#define VMCALL_ULTIMAP2_HIDERANGEUSAGE 56

#define VMCALL_ADD_MEMORY 57
//#define VMCALL_DISABLE_EPT 58 dus nut wurk


#ifdef STATISTICS
#define VMCALL_GET_STATISTICS 59
#endif

#define VMCALL_WATCH_EXECUTES 60
#define VMCALL_SETTSCADJUST   61
#define VMCALL_SETSPEEDHACK   62
#define VMCALL_CAUSEDDEBUGBREAK 63

#define VMCALL_DISABLE_TSCADJUST 64

#define VMCALL_CLOAKEX_ACTIVATE 65

#define VMCALL_DISABLETSCHOOK 66
#define VMCALL_ENABLETSCHOOK 67



#define VMCALL_KERNELMODE 100
#define VMCALL_USERMODE 101


extern int hasEPTsupport;
extern int hasNPsupport;



int handleVMCall(pcpuinfo currentcpuinfo, VMRegisters *vmregisters);

void returnFromCR3Callback(pcpuinfo currentcpuinfo, VMRegisters *vmregisters, unsigned long long newcr3);
QWORD readMSRSafe(DWORD msr);
void writeMSRSafe(DWORD msr, QWORD value);

int raiseInvalidOpcodeException(pcpuinfo currentcpuinfo); //
int raisePagefault(pcpuinfo currentcpuinfo, UINT64 address);

void psod(void); //freezes DBVM

#endif /*VMCALL_H_*/
