/******************************************************************************
** (C) Chris Oldwood
**
** MODULE:		DDELINK.HPP
** COMPONENT:	Network & Comms Library
** DESCRIPTION:	The CDDELink class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef DDELINK_HPP
#define DDELINK_HPP

#if _MSC_VER > 1000
#pragma once
#endif

#include "DDEFwd.hpp"

/******************************************************************************
**
** This is the data class for a DDE link.
**
*******************************************************************************
*/

class CDDELink /*: private NotCopyable*/
{
public:
	//
	// Properties.
	//
	uint           RefCount() const;
	CDDEConv*	   Conversation() const;
	const CString& Item() const;
	uint           Format() const;

	IDDELinkData*  AppData() const;
	void           SetAppData(IDDELinkData* pAppData);

	//
	// Clipboard methods.
	//
	static bool CopyLink(HWND hOwner, const CDDELink* pLink);
	static bool CopyLink(HWND hOwner, const tchar* pszService, const tchar* pszTopic, const tchar* pszItem);

	static bool CanPasteLink();
	static bool PasteLink(CString& strLink);
	static bool PasteLink(CString& strService, CString& strTopic, CString& strItem);

	//
	// Parsing methods.
	//

	//! Parse the DDE link into its separate parts.
	static bool ParseLink(const tstring& link, tstring& service, tstring& topic, tstring& item);

protected:
	//
	// Members.
	//
	uint			m_nRefCount;	// The reference count.
	CDDEConv*		m_pConv;		// The parent conversation.
	CString			m_strItem;		// The item name.
	uint			m_nFormat;		// The data format.
	IDDELinkData*	m_pAppData;		// Custom data.

	//
	// Constructors/Destructor.
	//
	CDDELink(CDDEConv* pConv, const tchar* pszItem, uint nFormat);
	CDDELink(const CDDELink&);
	~CDDELink();

	// Friends.
	friend class CDDECltConv;
	friend class CDDESvrConv;

private:
	// NotCopyable.
	CDDELink& operator=(const CDDELink&);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CDDELink::~CDDELink()
{
	ASSERT(m_nRefCount == 0);
}

inline uint CDDELink::RefCount() const
{
	return m_nRefCount;
}

inline CDDEConv* CDDELink::Conversation() const
{
	return m_pConv;
}

inline const CString& CDDELink::Item() const
{
	return m_strItem;
}

inline uint CDDELink::Format() const
{
	return m_nFormat;
}

inline IDDELinkData* CDDELink::AppData() const
{
	return m_pAppData;
}

inline void CDDELink::SetAppData(IDDELinkData* pAppData)
{
	m_pAppData = pAppData;
}

#endif // DDELINK_HPP
