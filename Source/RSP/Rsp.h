#pragma once 

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdint.h>
#include "Types.h"

#if defined(_WIN32)
#define EXPORT          __declspec(dllexport)
#define CALL            _cdecl
#else
#define EXPORT          __attribute__((visibility("default")))
#define CALL
#endif

// Profiling
#define Default_ProfilingOn			FALSE
#define Default_IndvidualBlock		FALSE
#define Default_ShowErrors			FALSE
#define Default_AudioHle			FALSE

#define PLUGIN_TYPE_RSP				1
#define PLUGIN_TYPE_GFX				2
#define PLUGIN_TYPE_AUDIO			3
#define PLUGIN_TYPE_CONTROLLER		4

typedef struct {
    uint16_t Version;        // Should be set to 0x0101
    uint16_t Type;           // Set to PLUGIN_TYPE_RSP
	char Name[100];      // Name of the DLL

	// If DLL supports memory these memory options then set them to TRUE or FALSE if it does not support it
    int NormalMemory;   // A normal BYTE array
    int MemoryBswaped;  // A normal BYTE array where the memory has been pre-bswap'd on a DWORD (32-bit) boundary
} PLUGIN_INFO;

typedef struct {
    void * hInst;
    int MemoryBswaped;    // If this is set to TRUE, then the memory has been pre-bswap'd on a DWORD (32-bit) boundary
    uint8_t * HEADER;
    uint8_t * RDRAM;
    uint8_t * DMEM;
    uint8_t * IMEM;

    uint32_t * MI_INTR_REG;

    uint32_t * SP_MEM_ADDR_REG;
    uint32_t * SP_DRAM_ADDR_REG;
    uint32_t * SP_RD_LEN_REG;
    uint32_t * SP_WR_LEN_REG;
    uint32_t * SP_STATUS_REG;
    uint32_t * SP_DMA_FULL_REG;
    uint32_t * SP_DMA_BUSY_REG;
    uint32_t * SP_PC_REG;
    uint32_t * SP_SEMAPHORE_REG;

    uint32_t * DPC_START_REG;
    uint32_t * DPC_END_REG;
    uint32_t * DPC_CURRENT_REG;
    uint32_t * DPC_STATUS_REG;
    uint32_t * DPC_CLOCK_REG;
    uint32_t * DPC_BUFBUSY_REG;
    uint32_t * DPC_PIPEBUSY_REG;
    uint32_t * DPC_TMEM_REG;

	void (CALL *CheckInterrupts)( void );
	void (CALL *ProcessDList)( void );
	void (CALL *ProcessAList)( void );
	void (CALL *ProcessRdpList)( void );
	void (CALL *ShowCFB)( void );
} RSP_INFO;

typedef struct {
    long left, top, right, bottom;
} rectangle; // <windows.h> equivalent: RECT
typedef struct {
    void * hdc;
    Boolean fErase;
    rectangle rcPaint;
    Boolean fRestore;
    Boolean fIncUpdate;
    uint8_t rgbReserved[32];
} window_paint; // <windows.h> equivalent: PAINTSTRUCT

typedef struct {
	// Menu
	// Items should have an ID between 5001 and 5100
    void * hRSPMenu;
	void (*ProcessMenuItem) ( int ID );

	// Breakpoints
    int UseBPoints;
	char BPPanelName[20];
	void (CALL *Add_BPoint)      ( void );
    void (CALL *CreateBPPanel) (void * hDlg, rectangle rcBox);
	void (CALL *HideBPPanel)     ( void );
    void (CALL *PaintBPPanel)  (window_paint ps);
	void (CALL *ShowBPPanel)     ( void );
    void (CALL *RefreshBpoints)(void * hList);
    void (CALL *RemoveBpoint)  (void * hList, int index);
	void (CALL *RemoveAllBpoint) ( void );
	
	// RSP command window
	void (CALL *Enter_RSP_Commands_Window) ( void );
} RSPDEBUG_INFO;

typedef struct {
	void (CALL *UpdateBreakPoints)( void );
	void (CALL *UpdateMemory)( void );
	void (CALL *UpdateR4300iRegisters)( void );
	void (CALL *Enter_BPoint_Window)( void );
	void (CALL *Enter_R4300i_Commands_Window)( void );
	void (CALL *Enter_R4300i_Register_Window)( void );
	void (CALL *Enter_RSP_Commands_Window) ( void );
	void (CALL *Enter_Memory_Window)( void );
} DEBUG_INFO;

EXPORT void CALL CloseDLL(void);
EXPORT void CALL DllAbout(void * hParent);
EXPORT uint32_t CALL DoRspCycles(uint32_t Cycles);
EXPORT void CALL GetDllInfo(PLUGIN_INFO * PluginInfo);
EXPORT void CALL GetRspDebugInfo(RSPDEBUG_INFO * DebugInfo);
EXPORT void CALL InitiateRSP(RSP_INFO Rsp_Info, uint32_t * CycleCount);
EXPORT void CALL InitiateRSPDebugger(DEBUG_INFO Debug_Info);
EXPORT void CALL RomOpen(void);
EXPORT void CALL RomClosed(void);
EXPORT void CALL DllConfig(void * hWnd);
EXPORT void CALL EnableDebugging(int Enabled);
EXPORT void CALL PluginLoaded(void);

uint32_t AsciiToHex(char * HexValue);
void DisplayError(char * Message, ...);
int GetStoredWinPos(char * WinName, uint32_t * X, uint32_t * Y);

#define InterpreterCPU	0
#define RecompilerCPU	1

extern int DebuggingEnabled, Profiling, IndvidualBlock, ShowErrors, BreakOnStart, LogRDP, LogX86Code;
extern uint32_t CPUCore;
extern DEBUG_INFO DebugInfo;
extern RSP_INFO RSPInfo;
extern void * hinstDLL;

#if defined(__cplusplus)
}
#endif
