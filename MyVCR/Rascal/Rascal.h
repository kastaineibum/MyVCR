#pragma once
//#include "stdafx.h"

#include <Ks.h>

#include <Aviriff.h>
#include <initguid.h>
#include "AddinManager.h"

#pragma comment (lib,"STRMBASE")
#pragma comment(lib, "winmm.lib")

// {6662E9EC-CD4F-4F2E-947C-60A8BF0D2241}
DEFINE_GUID(CLSID_RASCAL, 
0x6662e9ec, 0xcd4f, 0x4f2e, 0x94, 0x7c, 0x60, 0xa8, 0xbf, 0xd, 0x22, 0x41);

class Rascal : public CTransformFilter 
{
public:
	Rascal();
	~Rascal();

	HRESULT CheckInputType(const CMediaType *mtIn);
	HRESULT GetMediaType(int iPosition, CMediaType *pMediaType);
	HRESULT CheckTransform(
		const CMediaType *mtIn, const CMediaType *mtOut);
	HRESULT DecideBufferSize(
		IMemAllocator *pAlloc, ALLOCATOR_PROPERTIES *pProp);
	HRESULT Transform(IMediaSample *pSource, IMediaSample *pDest);
	HRESULT StopStreaming();
	HRESULT StartStreaming();

	static CUnknown* WINAPI CreateInstance(LPUNKNOWN pUnk, HRESULT *pHr);
	DWORD doProceed(BYTE* pBufferIn, BYTE* pBufferOut);

private:
	CMediaType*				m_inMediaType;
	static AddinManager*	m_pAddinMgr;
	bool subtypeNotSupported(GUID guid);
	bool bitCountSupported(WORD bitCount);
	DWORD m_width;
	DWORD m_height;
	DWORD m_bitCount;
	DWORD m_sampleSize;
};

