/******************************************************************************
** (C) Chris Oldwood
**
** MODULE:		UDPCLTSOCKET.HPP
** COMPONENT:	Network & Comms Library
** DESCRIPTION:	The CUDPCltSocket class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef UDPCLTSOCKET_HPP
#define UDPCLTSOCKET_HPP

/******************************************************************************
** 
** A client side UDP socket.
**
*******************************************************************************
*/

class CUDPCltSocket : public CUDPSocket
{
public:
	//
	// Constructors/Destructor.
	//
	CUDPCltSocket();
	virtual ~CUDPCltSocket();
	
	//
	// Methods.
	//
	void Connect(const char* pszHost, uint nPort);

protected:
	//
	// Members.
	//
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline void CUDPCltSocket::Connect(const char* pszHost, uint nPort)
{
	CSocket::Connect(pszHost, nPort);
}

#endif // UDPCLTSOCKET_HPP
