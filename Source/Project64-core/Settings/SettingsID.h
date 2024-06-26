#pragma once

enum
{
    MaxPluginSetting = 65535
};

enum SettingID
{
    // Default values
    Default_None,
    Default_Constant,

    // Command settings
    Cmd_BaseDirectory,
    Cmd_AppdataDirectory,
    Cmd_RomFile,
    Cmd_ComboDiskFile,
    Cmd_ShowHelp,

    // Support files
    SupportFile_Settings,
    SupportFile_SettingsDefault,
    SupportFile_RomDatabase,
    SupportFile_RomDatabaseDefault,
    SupportFile_VideoRDB,
    SupportFile_VideoRDBDefault,
    SupportFile_AudioRDB,
    SupportFile_AudioRDBDefault,
    SupportFile_CheatDir,
    SupportFile_CheatDirDefault,
    SupportFile_UserCheatDir,
    SupportFile_UserCheatDirDefault,
    SupportFile_EnhancementDir,
    SupportFile_EnhancementDirDefault,
    SupportFile_UserEnhancementDir,
    SupportFile_UserEnhancementDirDefault,
    SupportFile_Notes,
    SupportFile_NotesDefault,
    SupportFile_ExtInfo,
    SupportFile_ExtInfoDefault,

    // Settings
    Setting_ApplicationName,
    Setting_UseFromRegistry,
    Setting_RdbEditor,
    Setting_CN64TimeCritical,
    Setting_AutoStart,
    Setting_CheckEmuRunning,
    Setting_EraseGameDefaults,
    Setting_ForceInterpreterCPU,
    Setting_FixedRdramAddress,

    Setting_AutoZipInstantSave,
    Setting_RememberCheats,
    Setting_UniqueSaveDir,
    Setting_LanguageDir,
    Setting_LanguageDirDefault,
    Setting_CurrentLanguage,
    Setting_EnableDisk,
	Setting_SyncViaAudioEnabled,
	Setting_Enhancement,
    Setting_DiskSaveType,

    // Default settings
    Default_RDRamSize,
	Default_UseHleGfx,
	Default_UseTlb,
	Default_ViRefreshRate,
	Default_AiCountPerBytes,
	Default_CounterFactor,
	Default_32Bit,
	Default_SyncViaAudio,
	Default_FixedAudio,
	Default_UnalignedDMA,
	Default_RandomizeSIPIInterrupts,
	Default_SMM_Protect_Memory,
    Default_DiskSeekTiming,

    // RDB settings
    Rdb_GoodName,
    Rdb_SaveChip,
    Rdb_CpuType,
    Rdb_RDRamSize,
    Rdb_CounterFactor,
    Rdb_UseTlb,
    Rdb_DelayDP,
    Rdb_DelaySi,
    Rdb_32Bit,
    Rdb_FastSP,
    Rdb_FixedAudio,
    Rdb_SyncViaAudio,
    Rdb_RspAudioSignal,
    Rdb_TLB_VAddrStart,
    Rdb_TLB_VAddrLen,
    Rdb_TLB_PAddrStart,
    Rdb_UseHleGfx,
    Rdb_UseHleAudio,
    Rdb_LoadRomToMemory,
    Rdb_ScreenHertz,
    Rdb_FuncLookupMode,
    Rdb_RegCache,
    Rdb_BlockLinking,
    Rdb_SMM_StoreInstruc,
    Rdb_SMM_Cache,
    Rdb_SMM_PIDMA,
    Rdb_SMM_TLB,
    Rdb_SMM_Protect,
    Rdb_SMM_ValidFunc,
    Rdb_ViRefreshRate,
    Rdb_AiCountPerBytes,
    Rdb_AudioResetOnLoad,
    Rdb_AllowROMWrites,
    Rdb_CRC_Recalc,
    Rdb_UnalignedDMA,
    Rdb_RandomizeSIPIInterrupts,
	Rdb_RPCKey,
    Rdb_DiskSeekTiming,

    // Individual game settings
    Game_IniKey,
    Game_File,
    Game_UniqueSaveDir,
    Game_GameName,
    Cfg_GoodName,
    Game_TempLoaded,
    Game_SystemType,
    Game_EditPlugin_Gfx,
    Game_EditPlugin_Audio,
    Game_EditPlugin_Contr,
    Game_EditPlugin_RSP,
    Game_Plugin_Gfx,
    Game_Plugin_Audio,
    Game_Plugin_Controller,
    Game_Plugin_RSP,
    Game_SaveChip,
    Game_CpuType,
    Game_LastSaveSlot,
    Game_FixedAudio,
    Game_SyncViaAudio,
    Game_32Bit,
    Game_SMM_Cache,
    Game_SMM_Protect,
    Game_SMM_ValidFunc,
    Game_SMM_PIDMA,
    Game_SMM_TLB,
    Game_SMM_StoreInstruc,
    Game_CurrentSaveState,
    Game_LastSaveTime,
    Game_RDRamSize,
    Game_CounterFactor,
    Game_UseTlb,
    Game_DelayDP,
    Game_DelaySI,
    Game_FastSP,
    Game_FuncLookupMode,
    Game_RegCache,
    Game_BlockLinking,
    Game_ScreenHertz,
    Game_RspAudioSignal,
    Game_UseHleGfx,
    Game_UseHleAudio,
    Game_LoadRomToMemory,
    Game_ViRefreshRate,
    Game_AiCountPerBytes,
    Game_AudioResetOnLoad,
    Game_AllowROMWrites,
    Game_CRC_Recalc,
    Game_Transferpak_ROM,
    Game_Transferpak_Sav,
    Game_LoadSaveAtStart,
    Game_OverClockModifier,
    Game_FullSpeed,
    Game_UnalignedDMA,
    Game_RandomizeSIPIInterrupts,
	Game_RPCKey,
    Game_DiskSeekTiming,

    // General game running info
    GameRunning_LoadingInProgress,
    GameRunning_CPU_Running,
    GameRunning_CPU_Paused,
    GameRunning_CPU_PausedType,
    GameRunning_InstantSaveFile,
    GameRunning_LimitFPS,
    GameRunning_ScreenHertz,
    GameRunning_InReset,
    GameRunning_InputDelay,

    // User interface
    UserInterface_BasicMode,
    UserInterface_ShowCPUPer,
    UserInterface_DisplayFrameRate,
    UserInterface_FrameDisplayType,

    // Directory info
    Directory_Plugin,
    Directory_PluginInitial,
    Directory_PluginSelected,
    Directory_PluginUseSelected,
    Directory_PluginSync,
    Directory_PluginSyncInitial,
    Directory_PluginSyncSelected,
    Directory_PluginSyncUseSelected,
    Directory_SnapShot,
    Directory_SnapShotInitial,
    Directory_SnapShotSelected,
    Directory_SnapShotUseSelected,
    Directory_NativeSave,
    Directory_NativeSaveInitial,
    Directory_NativeSaveSelected,
    Directory_NativeSaveUseSelected,
    Directory_InstantSave,
    Directory_InstantSaveInitial,
    Directory_InstantSaveSelected,
    Directory_InstantSaveUseSelected,
    Directory_Texture,
    Directory_TextureInitial,
    Directory_TextureSelected,
    Directory_TextureUseSelected,
    Directory_Log,
    Directory_LogInitial,
    Directory_LogSelected,
    Directory_LogUseSelected,

    // ROM list
    RomList_RomListCache,
    RomList_RomListCacheDefault,
    RomList_GameDir,
    RomList_GameDirInitial,
    RomList_GameDirSelected,
    RomList_GameDirUseSelected,
    RomList_GameDirRecursive,
    RomList_ShowFileExtensions,
    RomList_7zipCache,
    RomList_7zipCacheDefault,

    // File info
    File_DiskIPLPath,
    File_DiskIPLUSAPath,
    File_DiskIPLTOOLPath,

    // Debugger
    Debugger_Enabled,
    Debugger_ShowTLBMisses,
    Debugger_ShowUnhandledMemory,
    Debugger_ShowPifErrors,
    Debugger_ShowDivByZero,
    Debugger_RecordRecompilerAsm,
    Debugger_DisableGameFixes,
    Debugger_AppLogLevel,
    Debugger_AppLogFlush,
    Debugger_ShowDListAListCount,
    Debugger_ShowRecompMemSize,
    Debugger_DebugLanguage,
    Debugger_RecordExecutionTimes,
    Debugger_SteppingOps,
    Debugger_SkipOp,
    Debugger_HaveExecutionBP,
    Debugger_WriteBPExists,
    Debugger_ReadBPExists,
    Debugger_WaitingForStep,
    Debugger_CPULoggingEnabled,
    Debugger_CPULogBufferSize,
    Debugger_ExceptionBreakpoints,
    Debugger_FpExceptionBreakpoints,
    Debugger_IntrBreakpoints,
    Debugger_RcpIntrBreakpoints,

    // Trace
    Debugger_TraceMD5,
    Debugger_TraceThread,
    Debugger_TracePath,
    Debugger_TraceSettings,
    Debugger_TraceUnknown,
    Debugger_TraceAppInit,
    Debugger_TraceAppCleanup,
    Debugger_TraceN64System,
    Debugger_TracePlugins,
    Debugger_TraceGFXPlugin,
    Debugger_TraceAudioPlugin,
    Debugger_TraceControllerPlugin,
    Debugger_TraceRSPPlugin,
    Debugger_TraceRSP,
    Debugger_TraceAudio,
    Debugger_TraceRegisterCache,
    Debugger_TraceRecompiler,
    Debugger_TraceTLB,
    Debugger_TraceProtectedMEM,
    Debugger_TraceUserInterface,
    Debugger_TraceRomList,
    Debugger_TraceExceptionHandler,

    // Plugins
    Plugin_RSP_Current,
    Plugin_RSP_CurVer,
    Plugin_GFX_Default,
    Plugin_GFX_Current,
    Plugin_GFX_CurVer,
    Plugin_AUDIO_Current,
    Plugin_AUDIO_CurVer,
    Plugin_CONT_Default,
    Plugin_CONT_Current,
    Plugin_CONT_CurVer,
    Plugin_UseHleGfx,
    Plugin_UseHleAudio,
    Plugin_EnableAudio,

    Logging_GenerateLog,
    Logging_LogRDRamRegisters,
    Logging_LogSPRegisters,
    Logging_LogDPCRegisters,
    Logging_LogDPSRegisters,
    Logging_LogMIPSInterface,
    Logging_LogVideoInterface,
    Logging_LogAudioInterface,
    Logging_LogPerInterface,
    Logging_LogRDRAMInterface,
    Logging_LogSerialInterface,
    Logging_LogPRDMAOperations,
    Logging_LogPRDirectMemLoads,
    Logging_LogPRDMAMemLoads,
    Logging_LogPRDirectMemStores,
    Logging_LogPRDMAMemStores,
    Logging_LogControllerPak,
    Logging_LogCP0changes,
    Logging_LogCP0reads,
    Logging_LogTLB,
    Logging_LogExceptions,
    Logging_NoInterrupts,
    Logging_LogCache,
    Logging_LogRomHeader,
    Logging_LogUnknown,

	FirstUISettings = MaxPluginSetting + 1, LastUISettings = FirstUISettings + MaxPluginSetting,
    FirstRSPDefaultSet, LastRSPDefaultSet = FirstRSPDefaultSet + MaxPluginSetting,
    FirstRSPSettings, LastRSPSettings = FirstRSPSettings + MaxPluginSetting,
    FirstGfxDefaultSet, LastGfxDefaultSet = FirstGfxDefaultSet + MaxPluginSetting,
    FirstGfxSettings, LastGfxSettings = FirstGfxSettings + MaxPluginSetting,
    FirstAudioDefaultSet, LastAudioDefaultSet = FirstAudioDefaultSet + MaxPluginSetting,
    FirstAudioSettings, LastAudioSettings = FirstAudioSettings + MaxPluginSetting,
    FirstCtrlDefaultSet, LastCtrlDefaultSet = FirstCtrlDefaultSet + MaxPluginSetting,
    FirstCtrlSettings, LastCtrlSettings = FirstCtrlSettings + MaxPluginSetting,
};
