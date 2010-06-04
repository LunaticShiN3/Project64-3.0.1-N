#include "stdafx.h"

CFunctionMap::CFunctionMap() :
	m_FunctionTable(NULL)
{
}

CFunctionMap::~CFunctionMap()
{
	if (m_FunctionTable)
	{
		for (int i = 0, n = 0x100000; i < n; i++)
		{
			if (m_FunctionTable[i] != NULL)
			{
				delete m_FunctionTable[i];
			}
		}
		VirtualFree( m_FunctionTable, 0 , MEM_RELEASE);
		m_FunctionTable = NULL;
	}
}

bool CFunctionMap::AllocateMemory()
{
	if (m_FunctionTable == NULL)
	{
		m_FunctionTable = (PCCompiledFunc_TABLE *)VirtualAlloc(NULL,0xFFFFF * sizeof(CCompiledFunc *),MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE);
		if (m_FunctionTable == NULL) {
			_Notify->FatalError(MSG_MEM_ALLOC_ERROR);
			return false;
		}
		memset(m_FunctionTable,0,0xFFFFF * sizeof(CCompiledFunc *));
	}
	return true;
}

/*

CFunctionMap::~CFunctionMap()
{
	Reset(false);
}

void * CFunctionMap::CompilerFindFunction( CFunctionMap * _this, DWORD vAddr )
{
	return _this->FindFunction(vAddr);
}

CCompiledFunc * CFunctionMap::FindFunction( DWORD vAddr, int Length )
{
	DWORD SectionEnd = (vAddr + Length + 0xFFF) >> 0xC;
	for (DWORD Section = (vAddr >> 0x0C); Section < SectionEnd; Section++)
	{
		CCompiledFunc table = m_FunctionTable[Section];
		if (table == NULL)
		{
			continue;
		}

		DWORD Start = 0;
		/*if (Section == (vAddr >> 0x0C))
		{
			Start = ((vAddr & 0xFFF) >> 2);
		}*/
		/*int SearchEnd = (Length - ((Section - (vAddr >> 0x0C)) * (0x1000 >> 2))) >> 2;
		if (Start + SearchEnd > (0x1000 >> 2))
		{
			SearchEnd = (0x1000 >> 2);
		}
		for (int i = Start; i < SearchEnd; i++)
		{
			PCCompiledFunc & info = table[i];
			if (info)
			{
				if (info->VEndPC() < vAddr)
				{
					continue;
				}
				return info;
			}
		}
	}

	return NULL;
}

void CFunctionMap::Reset( bool AllocateMemory )
{
	if (m_FunctionTable)
	{
		for (int i = 0; i < 0xFFFFF; i ++)
		{
			if (m_FunctionTable[i] == NULL)
			{
				continue;
			}
	
			CCompiledFunc table = m_FunctionTable[i];
			for (int x = 0; x < (0x1000) >> 2; x++)
			{
				PCCompiledFunc info = table[x];
				if (info == NULL)
				{
					continue;
				}
				while (info->Next)
				{
					PCCompiledFunc todelete = info;
					info = info->Next;
					delete todelete;
				}

				delete info;
			}

			delete table;
		}
		if (!AllocateMemory)
		{
			VirtualFree(m_FunctionTable,0,MEM_RELEASE);
			m_FunctionTable = NULL;
		}
	}

	if ( AllocateMemory)
	{
		if (m_FunctionTable == NULL)
		{
			m_FunctionTable = (CCompiledFunc *)VirtualAlloc(NULL,0xFFFFF * sizeof(CCompiledFunc *),MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE);
			if (m_FunctionTable == NULL) {
				Notify().FatalError(MSG_MEM_ALLOC_ERROR);
			}
		}
		memset(m_FunctionTable,0,0xFFFFF * sizeof(DWORD));
	}
}


CCompiledFunc * CFunctionMap::AddFunctionInfo( DWORD vAddr, DWORD pAddr )
{
	CCompiledFunc & table = m_FunctionTable[vAddr >> 0xC];
	if (table == NULL) 
	{
		table = new PCCompiledFunc[(0x1000 >> 2)]; 
		if (table == NULL)
		{
			Notify().FatalError(MSG_MEM_ALLOC_ERROR);
		}
		memset(table,0,sizeof(PCCompiledFunc) * (0x1000 >> 2));
	}

	PCCompiledFunc & info = table[(vAddr & 0xFFF) >> 2];
	if (info != NULL)
	{
		PCCompiledFunc old_info = info;
		info = new CCompiledFunc(vAddr,pAddr);
		info->Next = old_info;
	} else {	
		info = new CCompiledFunc(vAddr,pAddr);
	}

	return info;
}

void CFunctionMap::Remove(CCompiledFunc * info)
{
	DWORD vAddr = info->VStartPC();
	CCompiledFunc & table = m_FunctionTable[vAddr >> 0xC];
	if (table == NULL) 
	{
		return;
	}

	PCCompiledFunc & current_info = table[(vAddr & 0xFFF) >> 2];
	if (current_info == NULL)
	{
		return;
	}

	if (current_info == info)
	{
		delete info;
		table[(vAddr & 0xFFF) >> 2] = NULL;
	} else {
		Notify().BreakPoint(__FILE__,__LINE__);
	}
}
*/