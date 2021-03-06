/******************************************************************************
** (C) Chris Oldwood
**
** MODULE:		ICLIENTSOCKETLISTENER.HPP
** COMPONENT:	Network & Comms Library
** DESCRIPTION:	The IClientSocketListener interface declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef ICLIENTSOCKETLISTENER_HPP
#define ICLIENTSOCKETLISTENER_HPP

#if _MSC_VER > 1000
#pragma once
#endif

// Forward declarations
class CSocket;

/******************************************************************************
**
** The callback interface for client socket events.
**
*******************************************************************************
*/

class IClientSocketListener
{
public:
	//
	// Methods.
	//
	virtual void OnReadReady(CSocket* pSocket) = 0;
	virtual void OnClosed(CSocket* pSocket, int nReason) = 0;
	virtual void OnError(CSocket* pSocket, int nEvent, int nError) = 0;

protected:
	// Make interface.
	virtual ~IClientSocketListener() {};
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif // ICLIENTSOCKETLISTENER_HPP
