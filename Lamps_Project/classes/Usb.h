/**
* This work is licensed under the EPOS Software License v1.0.
* A copy of this license is available at the EPOS system source tree root.
* Note that EPOS Software License applies to both source code and executables.
*
*  You should have received a copy of the EPOS Software License v1.0 along
*  with this program. If not, see
*  <http://epos.lisha.ufsc.br/EPOS+Software+License+v1.0>.
*
******************************************************************************
*/


#include <classes/SmartObject.h>
#include <headers/lamps_project_debugger.h>
#include <headers/array_operations.h>



/**
 * Preprocessor directive designed to cause the current source file to be included only once in a
 * single compilation. Thus, serves the same purpose as #include guards, but with several
 * advantages, including: less code, avoidance of name clashes, and sometimes improvement in
 * compilation speed. In main file this is enabled by default.
 */
#pragma once


/**
 * #define __SYS_NS	   System
 * #define __USING_SYS using namespace __SYS_NS
 */
__USING_SYS;



/**
 * This class implements the EPOSMotes 2 serial USB use. The Startup Board is equipped with and UART
 * to USB transceiver. The UART bus is connected directly to FT232RL chip for a PC interface with
 * the Processing Module, discarding the need of a proper USB stack.
 * 
 * When the USB receives a message it should notify its observer by calling its inherited subject
 * object subject.
 * 
 * @see CommunicationSubject::notifyObserver( const char* ) member class declaration for the subject
 *      object use.
 */
class Usb : private EposMotes2Communication
{
public:
    
    /**
     * @see SmartObject::sendMessage( const char* ) member class declaration.
     */
    void sendMessage( const char* );
    
    /**
     * @see SmartObject::receiveMessage() member class declaration.
     */
    const char* receiveMessage();
    
    
private:
    
    /**
     * Creates an USB object ready to be used by the singleton design pattern.
     */
    Usb();
    
    /**
     * Do not implement it. Disable the copy constructor to avoid multiple singleton object copies.
     */
    Usb( Usb const& );
    
    /**
     * Do not implement it. Disable the assignment operator to avoid multiple singleton object copies.
     */
    void operator=( Usb const& );
    
    // USB magic methods
    
};



/**
 * @see Usb::getInstance() member class declaration.
 */
static Usb& Usb::getInstance()
{
    DEBUGGERLN( 2, "I AM ENTERING ON THE Usb::getInstance(0)" );
    
    static Usb INSTANCE;
    return &INSTANCE;
}

/**
 * @see Usb::Usb() member class declaration.
 */
Usb::Usb()
{
    DEBUGGERLN( 2, "I AM ENTERING ON THE Usb::Usb(0) THE PRIVATE CONSTRUCTOR!" );
}

/**
 * @see Usb::sendMessage( const char* ) member class declaration.
 */
void Usb::sendMessage( const char* message )
{
    DEBUGGERLN( 2, "I AM ENTERING ON THE Usb::sendMessage(1) | message: \n" << message );
}

/**
 * @see Usb::receiveMessage() member class declaration.
 */
const char* Usb::receiveMessage()
{
    DEBUGGERLN( 2, "I AM ENTERING ON THE Usb::receiveMessage(0)" );
    return NULL;
}




