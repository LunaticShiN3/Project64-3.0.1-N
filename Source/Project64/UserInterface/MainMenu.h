#pragma once
#include <Project64/Settings/UISettings.h>

enum MainMenuID
{
    // File menu
    ID_FILE_OPEN_ROM = 4000, ID_FILE_OPEN_COMBO, ID_FILE_ROM_INFO, ID_FILE_STARTEMULATION,
    ID_FILE_ENDEMULATION, ID_FILE_ROMDIRECTORY, ID_FILE_REFRESHROMLIST, ID_FILE_EXIT, 

    // Language
    ID_LANG_START, ID_LANG_END = ID_LANG_START + 100,

    // Recent files
    ID_RECENT_ROM_START, ID_RECENT_ROM_END = ID_RECENT_ROM_START + 20,

    // Recent directory
    ID_RECENT_DIR_START, ID_RECENT_DIR_END = ID_RECENT_DIR_START + 20,

    // System menu
    ID_SYSTEM_RESET_SOFT, ID_SYSTEM_RESET_HARD, ID_SYSTEM_PAUSE, ID_SYSTEM_BITMAP,
    ID_SYSTEM_LIMITFPS, ID_SYSTEM_SWAPDISK, ID_SYSTEM_RESTORE, ID_SYSTEM_LOAD, ID_SYSTEM_SAVE,
    ID_SYSTEM_SAVEAS, ID_SYSTEM_ENHANCEMENT, ID_SYSTEM_CHEAT, ID_SYSTEM_GSBUTTON,

    //Current save slot
    ID_CURRENT_SAVE_1, ID_CURRENT_SAVE_2, ID_CURRENT_SAVE_3, ID_CURRENT_SAVE_4, ID_CURRENT_SAVE_5,
    ID_CURRENT_SAVE_6, ID_CURRENT_SAVE_7, ID_CURRENT_SAVE_8, ID_CURRENT_SAVE_9, ID_CURRENT_SAVE_10,
    ID_CURRENT_SAVE_11, ID_CURRENT_SAVE_12, ID_CURRENT_SAVE_13, ID_CURRENT_SAVE_14, ID_CURRENT_SAVE_15,
    ID_CURRENT_SAVE_16, ID_CURRENT_SAVE_17, ID_CURRENT_SAVE_18, ID_CURRENT_SAVE_19, ID_CURRENT_SAVE_20,
    ID_CURRENT_SAVE_21, ID_CURRENT_SAVE_22, ID_CURRENT_SAVE_23, ID_CURRENT_SAVE_24, ID_CURRENT_SAVE_25,
    ID_CURRENT_SAVE_26, ID_CURRENT_SAVE_27, ID_CURRENT_SAVE_28, ID_CURRENT_SAVE_29, ID_CURRENT_SAVE_30,
    ID_CURRENT_SAVE_31, ID_CURRENT_SAVE_32, ID_CURRENT_SAVE_33, ID_CURRENT_SAVE_34, ID_CURRENT_SAVE_35,
    ID_CURRENT_SAVE_36, ID_CURRENT_SAVE_37, ID_CURRENT_SAVE_38, ID_CURRENT_SAVE_39, ID_CURRENT_SAVE_40,
    ID_CURRENT_SAVE_41, ID_CURRENT_SAVE_42, ID_CURRENT_SAVE_43, ID_CURRENT_SAVE_44, ID_CURRENT_SAVE_45,
    ID_CURRENT_SAVE_46, ID_CURRENT_SAVE_47, ID_CURRENT_SAVE_48, ID_CURRENT_SAVE_49, ID_CURRENT_SAVE_50,
    ID_CURRENT_SAVE_51, ID_CURRENT_SAVE_52, ID_CURRENT_SAVE_53, ID_CURRENT_SAVE_54, ID_CURRENT_SAVE_55,
    ID_CURRENT_SAVE_56, ID_CURRENT_SAVE_57, ID_CURRENT_SAVE_58, ID_CURRENT_SAVE_59, ID_CURRENT_SAVE_60,
    ID_CURRENT_SAVE_61, ID_CURRENT_SAVE_62, ID_CURRENT_SAVE_63, ID_CURRENT_SAVE_64, ID_CURRENT_SAVE_65,
    ID_CURRENT_SAVE_66, ID_CURRENT_SAVE_67, ID_CURRENT_SAVE_68, ID_CURRENT_SAVE_69, ID_CURRENT_SAVE_70,
    ID_CURRENT_SAVE_71, ID_CURRENT_SAVE_72, ID_CURRENT_SAVE_73, ID_CURRENT_SAVE_74, ID_CURRENT_SAVE_75,
    ID_CURRENT_SAVE_76, ID_CURRENT_SAVE_77, ID_CURRENT_SAVE_78, ID_CURRENT_SAVE_79, ID_CURRENT_SAVE_80,
    ID_CURRENT_SAVE_81, ID_CURRENT_SAVE_82, ID_CURRENT_SAVE_83, ID_CURRENT_SAVE_84, ID_CURRENT_SAVE_85,
    ID_CURRENT_SAVE_86, ID_CURRENT_SAVE_87, ID_CURRENT_SAVE_88, ID_CURRENT_SAVE_89, ID_CURRENT_SAVE_90,
    ID_CURRENT_SAVE_91, ID_CURRENT_SAVE_92, ID_CURRENT_SAVE_93, ID_CURRENT_SAVE_94, ID_CURRENT_SAVE_95,
    ID_CURRENT_SAVE_96, ID_CURRENT_SAVE_97, ID_CURRENT_SAVE_98, ID_CURRENT_SAVE_99,
    ID_CURRENT_SAVE_DEFAULT,

    // Option menu
    ID_OPTIONS_FULLSCREEN, ID_OPTIONS_FULLSCREEN2, ID_OPTIONS_ALWAYSONTOP, ID_OPTIONS_CONFIG_GFX,
    ID_OPTIONS_CONFIG_AUDIO, ID_OPTIONS_CONFIG_CONT, ID_OPTIONS_CONFIG_RSP, ID_OPTIONS_CPU_USAGE,
    ID_OPTIONS_SETTINGS, ID_OPTIONS_DISPLAY_FR, ID_OPTIONS_CHANGE_FR, ID_OPTIONS_INCREASE_SPEED,
    ID_OPTIONS_DECREASE_SPEED,

    // Debugger menu
    ID_DEBUG_SHOW_TLB_MISSES, ID_DEBUG_SHOW_UNHANDLED_MEM, ID_DEBUG_SHOW_PIF_ERRORS,
    ID_DEBUG_SHOW_DLIST_COUNT, ID_DEBUG_SHOW_RECOMP_MEM_SIZE, ID_DEBUG_SHOW_DIV_BY_ZERO,
    ID_DEBUG_RECORD_RECOMPILER_ASM, ID_DEBUG_DISABLE_GAMEFIX, ID_DEBUG_LANGUAGE,
    ID_DEBUGGER_LOGOPTIONS, ID_DEBUGGER_GENERATELOG, ID_DEBUGGER_DUMPMEMORY, ID_DEBUGGER_SEARCHMEMORY,
    ID_DEBUGGER_TLBENTRIES, ID_DEBUGGER_BREAKPOINTS, ID_DEBUGGER_MEMORY, ID_DEBUGGER_R4300REGISTERS,
    ID_DEBUGGER_INTERRUPT_SP, ID_DEBUGGER_INTERRUPT_SI, ID_DEBUGGER_INTERRUPT_AI, ID_DEBUGGER_INTERRUPT_VI,
    ID_DEBUGGER_INTERRUPT_PI, ID_DEBUGGER_INTERRUPT_DP, ID_DEBUGGER_SCRIPTS, ID_DEBUGGER_SYMBOLS, ID_DEBUGGER_DMALOG,
    ID_DEBUGGER_EXCBREAKPOINTS, ID_DEBUGGER_CPULOG, ID_DEBUGGER_STACKTRACE, ID_DEBUGGER_STACKVIEW,

    // App logging
    ID_DEBUGGER_APPLOG_FLUSH, ID_DEBUGGER_TRACE_MD5, ID_DEBUGGER_TRACE_SETTINGS, ID_DEBUGGER_TRACE_UNKNOWN, ID_DEBUGGER_TRACE_APPINIT,
    ID_DEBUGGER_TRACE_APPCLEANUP, ID_DEBUGGER_TRACE_N64SYSTEM, ID_DEBUGGER_TRACE_PLUGINS, ID_DEBUGGER_TRACE_GFXPLUGIN,
    ID_DEBUGGER_TRACE_AUDIOPLUGIN, ID_DEBUGGER_TRACE_CONTROLLERPLUGIN, ID_DEBUGGER_TRACE_RSPPLUGIN, ID_DEBUGGER_TRACE_RSP,
    ID_DEBUGGER_TRACE_AUDIO, ID_DEBUGGER_TRACE_REGISTERCACHE, ID_DEBUGGER_TRACE_RECOMPILER, ID_DEBUGGER_TRACE_TLB,
    ID_DEBUGGER_TRACE_PROTECTEDMEM, ID_DEBUGGER_TRACE_USERINTERFACE,

    // Profile menu
    ID_PROFILE_PROFILE, ID_PROFILE_RESETCOUNTER, ID_PROFILE_GENERATELOG,

    // Help menu
    ID_HELP_SUPPORT_PROJECT64, ID_HELP_SUPPORT_LUNA, ID_HELP_DISCORD, ID_HELP_WEBSITE, ID_HELP_ABOUT,

    // New stuff
    ID_FILE_MOUNT_SDCARD, ID_DEBUGGER_ENABLE, ID_DEBUGGER_DISABLE, ID_HELP_OPEN_APPDATA,
};

class CMainMenu :
    public CBaseMenu,
    private CDebugSettings
{
public:
    CMainMenu(CMainGui * Window);
    ~CMainMenu();

    int ProcessAccelerator(HWND hWnd, void * lpMsg);
    bool ProcessMessage(HWND hWnd, DWORD wNotifyCode, DWORD wID);
    void ResetMenu(void);
    void ResetAccelerators(void) { m_ResetAccelerators = true; }

private:
    CMainMenu();
    CMainMenu(const CMainMenu&);
    CMainMenu& operator=(const CMainMenu&);

    void OnOpenRom(HWND hWnd);
    void OnOpenCombo(HWND hWnd);
    void OnRomInfo(HWND hWnd);
    void OnEndEmulation(void);
    void OnScreenShot(void);
    void OnSaveAs(HWND hWnd);
    void OnLodState(HWND hWnd);
    void OnEnhancements(HWND hWnd);
    void OnCheats(HWND hWnd);
    void OnSettings(HWND hWnd);
    void OnSupportProject64(HWND hWnd);

    void FillOutMenu(HMENU hMenu);
    std::wstring GetSaveSlotString(int Slot);
    stdstr GetFileLastMod(const CPath & FileName);
    void RebuildAccelerators(void);
    std::string ChooseFileToOpen(HWND hParent);
    std::string ChooseROMFileToOpen(HWND hParent);
    std::string ChooseDiskFileToOpen(HWND hParent);
    void SetTraceModuleSetttings(SettingID Type);
    void ShortCutsChanged(void);

    static void CALL SettingsChanged(CMainMenu * _this);
    static void CALL stShortCutsChanged(CMainMenu * _this) { return _this->ShortCutsChanged(); }

    typedef std::list<SettingID> SettingList;
    typedef std::list<UISettingID> UISettingList;

    CMainGui * m_Gui;

    void * m_AccelTable;
    bool m_ResetAccelerators;
    CShortCuts m_ShortCuts;
    SettingList m_ChangeSettingList;
    UISettingList m_ChangeUISettingList;
    CriticalSection m_CS;
};
